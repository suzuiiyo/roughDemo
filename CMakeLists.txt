cmake_minimum_required(VERSION 3.17)
project(CLionCode)

set(CMAKE_CXX_STANDARD 14)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    include_directories(${INC_DIR})
    link_directories(${LINK_DIR})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
