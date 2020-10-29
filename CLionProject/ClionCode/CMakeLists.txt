cmake_minimum_required(VERSION 3.17)
project(ClionCode)

set(CMAKE_CXX_STANDARD 14)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
add_executable (${exe} ${file} Swap.cpp InheritanceFuncCover.cpp)
message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
