cmake_minimum_required(VERSION 2.8)
project(C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_custom_command(
	OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
	COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
	DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
)

add_custom_target( runscript DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(C C/main.cpp C/main.h)

add_dependencies(C runscript)
add_subdirectory(B)
add_library(header A/index.cpp)

target_link_libraries(C header)
target_link_libraries(C lib)

add_executable(CTest C/main_test.cpp C/proj_test.cpp)
target_link_libraries(CTest header)
target_link_libraries(CTest lib)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread)
enable_testing()
