# The name of our project is "HELLO". CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6)
project (TEST)

include_directories (${TEST_SOURCE_DIR}/eigen)
link_directories (${TEST_SOURCE_DIR}/eigen)

include(ExternalProject)
ExternalProject_Add(
	Eigen
	SOURCE_DIR ${TEST_SOURCE_DIR}/eigen
	INSTALL_COMMAND echo "Skipping install"
)

add_executable (
	test1
	${TEST_SOURCE_DIR}/test1.cpp
)
add_executable (
	test2
	${TEST_SOURCE_DIR}/test2.cpp
)
add_executable (
	test3
	${TEST_SOURCE_DIR}/test3.cpp
)
add_executable (
	test4
	${TEST_SOURCE_DIR}/test4.cpp
)

enable_testing()

ADD_TEST ( NAME test1 COMMAND test1 )
ADD_TEST ( NAME test2 COMMAND test2 )
ADD_TEST ( NAME test3 COMMAND test3 )
ADD_TEST ( NAME test4 COMMAND test4 )
