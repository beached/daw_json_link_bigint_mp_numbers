// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <string_view>
#include <vector>

struct myclass {
	boost::multiprecision::cpp_int value;
};

std::vector<myclass> parse_myclass( std::string_view json_document );
