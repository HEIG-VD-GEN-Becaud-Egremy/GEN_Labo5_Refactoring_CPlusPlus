cmake_minimum_required(VERSION 3.16)
project(GEN_Labo5)

# stop GoogleTest from generating error with deprecated functions
set(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
		WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
		)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
		WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
		)

set(DCMAKE_SH="CMAKE_SH-NOTFOUND")
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
		"${CMAKE_BINARY_DIR}/googletest-build"
		)
# Add executable and link googletest libs
add_executable(GEN_Labo5
		src/Customer.h
		src/Customer.cpp
		src/Movie.h
		src/Movie.cpp
		src/PriceCode/PriceCode.h
		src/PriceCode/PriceCode.cpp
		src/PriceCode/PriceCodeRegular.h
		src/PriceCode/PriceCodeRegular.cpp
		src/PriceCode/PriceCodeNewRelease.h
		src/PriceCode/PriceCodeNewRelease.cpp
		src/PriceCode/PriceCodeChildrens.h
		src/PriceCode/PriceCodeChildrens.cpp
		src/Rental.h
		src/Rental.cpp
		test/CustomerTest.cpp
		test/PriceCodeTest.cpp
		test/PriceCodeRegularTest.cpp
		test/PriceCodeNewReleaseTest.cpp
		test/PriceCodeChildrensTest.cpp
		test/MovieTest.cpp)

target_link_libraries(GEN_Labo5 gtest gmock_main)