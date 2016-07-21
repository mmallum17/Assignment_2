cmake_minimum_required(VERSION 3.5)
project(Assignment_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES wordsearch_option1.c wordsearch_option3.c)
add_executable(Assignment_2 ${SOURCE_FILES})