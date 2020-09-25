// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include "myclass.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <daw/json/daw_json_link.h>
#include <string_view>
#include <tuple>

namespace daw::json {
	template<>
	struct json_data_contract<myclass> {
		static constexpr char const value[] = "value";
		using type =
		  json_member_list<json_number<value, boost::multiprecision::cpp_int,
		                               LiteralAsStringOpt::Maybe>>;

		static constexpr auto to_json_data( myclass const &v ) {
			return std::forward_as_tuple( v.value );
		}
	};
} // namespace daw::json

