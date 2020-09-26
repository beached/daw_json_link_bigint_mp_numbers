#include <iostream>

#include "myclass.h"
#include "myclass2.h"

#include <daw/json/daw_json_assert.h>
#include <fstream>
#include <iostream>
#include <iterator>

std::string read_file( std::string const &fname ) {
	auto config_file = std::fstream( fname );
	if( not config_file ) {
		std::cerr << "Could not open '" << fname << "'\n";
		exit( 1 );
	}
	std::string json_doc;
	std::copy( std::istreambuf_iterator<char>( config_file ),
	           std::istreambuf_iterator<char>( ),
	           std::back_inserter( json_doc ) );
	return json_doc;
}

int main( int argc, char **argv ) {
	if( argc <= 2 ) {
		std::cerr << "You must supply myclass.json and myclass2.json files\n";
		exit( 1 );
	}
	std::string json_doc0 = read_file( argv[1] );
	std::string json_doc1 = read_file( argv[2] );
	try {
		std::vector<myclass> vals = parse_myclass( json_doc0 );

		for( auto const &val : vals ) {
			std::cout << "myclass had a value of: " << val.value << '\n';
		}
	} catch( daw::json::json_exception const &je ) {
		std::cerr << "Error parsing myclass file '" << argv[1]
		          << "': " << to_formatted_string( je ) << '\n';
		exit( 1 );
	}

	try {
		std::vector<myclass2> vals = parse_myclass2( json_doc1 );

		for( auto const &val : vals ) {
			std::cout << "myclass2 had a value of: " << val.value.str( 100,std::ios::fmtflags{} )
			          << '\n';
		}

		std::cout << serialize_myclass2( vals ) << '\n';
	} catch( daw::json::json_exception const &je ) {
		std::cerr << "Error parsing myclass2 file '" << argv[1]
		          << "': " << to_formatted_string( je ) << '\n';
		exit( 1 );
	}

	return 0;
}
