cmake_minimum_required(VERSION 3.13)
project(PAA_zkouska)

set(CMAKE_CXX_STANDARD 17)

set(WARNINGS "-Wall -Weffc++ -pedantic -Wextra -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment -Wconversion -Wdisabled-optimization -Wfloat-equal -Wformat -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport -Winit-self -Winline -Winvalid-pch -Wunsafe-loop-optimizations -Wlong-long -Wmissing-braces -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wparentheses -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wsign-compare -Wstack-protector -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch -Wswitch-default -Wswitch-enum -Wtrigraphs -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-value -Wunused-variable -Wvariadic-macros -Wvolatile-register-var -Wwrite-strings -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference -Wold-style-cast -Wuseless-cast -Wdouble-promotion")

include_directories(include)

set(HEADER_FILES
	stl_reader/stl_reader.h
	include/main.hpp
	include/global.hpp
	include/Lattice.hpp
	include/RowSelector.hpp
)

set(SOURCE_FILES
	src/main.cpp
	src/Lattice.cpp
	src/RowSelector.cpp
)

add_executable(PAA ${HEADER_FILES} ${SOURCE_FILES})

add_custom_command(
    TARGET PAA POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:PAA>
)