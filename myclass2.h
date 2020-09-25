// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <string_view>
#include <vector>

struct myclass2 {
	boost::multiprecision::cpp_dec_float<100> value;
};

std::vector<myclass2> parse_myclass2( std::string_view json_document );
std::string serialize_myclass2( std::vector<myclass2> const &values );
