cmake_minimum_required (VERSION 2.6)
project (TEST)

include_directories (${TEST_SOURCE_DIR}) #$
include_directories (${TEST_SOURCE_DIR}/eigen)
include_directories (${TEST_SOURCE_DIR}/tests) #$

include(ExternalProject)
ExternalProject_Add(
	Eigen
	SOURCE_DIR ${TEST_SOURCE_DIR}/eigen
	INSTALL_COMMAND echo "Skipping install"
)

# search for Boost version 1.34
# link against dynamic libraries
add_definitions(-DBOOST_ALL_DYN_LINK)

find_package( Boost COMPONENTS unit_test_framework)
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )
message(${Boost_LIBRARIES})

add_executable (
    test1
    ${TEST_SOURCE_DIR}/tests/test1.cpp
)

target_link_libraries(
	test1
	${Boost_LIBRARIES}
)


add_executable (
    test2
    ${TEST_SOURCE_DIR}/tests/test2.cpp
    )

target_link_libraries(
	test2
	${Boost_LIBRARIES}
)

add_executable (
    test3
    ${TEST_SOURCE_DIR}/tests/test3.cpp
)

target_link_libraries(
	test3
	${Boost_LIBRARIES})

add_executable (
    test4
    ${TEST_SOURCE_DIR}/tests/test4.cpp
)

target_link_libraries(
	test4
	${Boost_LIBRARIES}
)



enable_testing()

ADD_TEST ( NAME test1 COMMAND test1 )
ADD_TEST ( NAME test2 COMMAND test2 )
ADD_TEST ( NAME test3 COMMAND test3 )
ADD_TEST ( NAME test4 COMMAND test4 )
