project(Mappings CXX)
cmake_minimum_required(VERSION 2.8)

# We require std::array, which may only work if the compiler is c++0x
# compliant.  If you are using a different compiler, this may need to be
# modified to include the appropriate c++0x/11x compilation flag.
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")
endif()

# Build the test
add_executable(test_mappings test_mappings.cc)

# The header file is the only thing that needs to be installed
install(FILES mappings.h DESTINATION include)
