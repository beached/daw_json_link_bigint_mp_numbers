cmake_minimum_required(VERSION 3.17)
project(bigint_test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)

find_package( Boost REQUIRED )

include( FetchContent )
set( FETCHCONTENT_UPDATES_DISCONNECTED ON )
FetchContent_Declare(
        daw_json_link
        GIT_REPOSITORY https://github.com/beached/daw_json_link
        GIT_TAG release
)
FetchContent_MakeAvailable(daw_json_link)

add_executable(bigint_test main.cpp myclass_json.cpp myclass_json.h myclass.h myclass2_json.cpp myclass2_json.h myclass2.h)
target_link_libraries( bigint_test daw::json_link Boost::boost )
