cmake_minimum_required(VERSION 3.9)
# Keep the version below in sync with the one in db.h
project(skiplist VERSION 1.0.0 LANGUAGES C CXX)




# C++ standard can be overridden when this is used as a sub-project.
if (NOT CMAKE_CXX_STANDARD)
    # This project requires C++11.
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif (NOT CMAKE_CXX_STANDARD)


enable_testing()

# Prevent overriding the parent project's compiler/linker settings on Windows.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(install_gtest OFF)
set(install_gmock OFF)
set(build_gmock OFF)

# This project is tested using GoogleTest.
#add_subdirectory("third_party/googletest")

include_directories(
        "${PROJECT_BINARY_DIR}/include"
        "."
        "${PROJECT_BINARY_DIR}/dscl"
)

set(INC_DIR C:\\OpenSSL-Win64\\include)
set(LINK_DIR C:\\OpenSSL-Win64\\lib)

# GTest for SkipList
function(my_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
            PRIVATE
            "${test_file}"
            "${PROJECT_SOURCE_DIR}/src/"
            "${PROJECT_SOURCE_DIR}/benchmarks/"
            )
    include_directories(${INC_DIR})
    link_directories(${LINK_DIR})
#    link_libraries(ssl crypto)
    target_link_libraries("${test_target_name}")  #
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
endfunction(my_test)
my_test("example/my_test.cc")
my_test("benchmarks/conext-figure5.cc")
my_test("benchmarks/conext-table3.cc")
my_test("src/bitsutil_test.cc")
#my_test("benchmarks/bulk-insert-and-query.cc")



