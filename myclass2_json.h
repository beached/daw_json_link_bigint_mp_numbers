// Copyright (c) Darrell Wright
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#pragma once

#include "myclass2.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <daw/json/daw_json_link.h>
#include <string_view>
#include <tuple>

struct ToMyClass2 {
	std::string operator( )( boost::multiprecision::cpp_dec_float<100> const &value );
};

struct FromMyClass2 {
	boost::multiprecision::cpp_dec_float<100> operator( )( std::string_view sv );
};

namespace daw::json {
	template<>
	struct json_data_contract<myclass2> {
		static constexpr char const value[] = "value";
		using type =
		  json_member_list<json_custom<value, boost::multiprecision::cpp_dec_float<100>,
		                               FromMyClass2, ToMyClass2>>;

		static constexpr auto to_json_data( myclass2 const &v ) {
			return std::forward_as_tuple( v.value );
		}
	};
} // namespace daw::json
