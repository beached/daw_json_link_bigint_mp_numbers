// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "myclass2_json.h"

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <daw/json/daw_json_link.h>
#include <string_view>
#include <vector>

std::string ToMyClass2::operator( )(
  const boost::multiprecision::cpp_dec_float<100> &value ) {
	return value.str( 100, std::ios::fmtflags{ } );
}

boost::multiprecision::cpp_dec_float<100>
FromMyClass2::operator( )( std::string_view sv ) {
	auto const str = static_cast<std::string>( sv );
	return boost::multiprecision::cpp_dec_float<100>( str.c_str( ) );
}

std::vector<myclass2> parse_myclass2( std::string_view json_document ) {
	return daw::json::from_json_array<myclass2>( json_document );
}

std::string serialize_myclass2( std::vector<myclass2> const &values ) {
	return daw::json::to_json_array( values );
}
