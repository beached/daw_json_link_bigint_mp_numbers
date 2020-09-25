// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "myclass_json.h"

#include <daw/json/daw_json_link.h>
#include <string_view>
#include <vector>

std::vector<myclass> parse_myclass( std::string_view json_document ) {
	return daw::json::from_json_array<myclass>( json_document );
}
