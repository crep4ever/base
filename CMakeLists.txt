cmake_minimum_required (VERSION 2.8)
project (examples)

add_subdirectory(src)
include_directories (src)

# {{{ CFLAGS
if (CMAKE_BUILD_TYPE MATCHES "Release")
  message(STATUS "Compiling in Release mode")
  add_definitions(-O2 -march=native)
elseif( CMAKE_COMPILER_IS_GNUCXX )
  message(STATUS "Compiling in Debug mode with GCC")
  # Add additional GCC options.
  add_definitions(
    -g -O -Wall -pedantic
    -pedantic-errors -Wextra -Wcast-align
    -Wcast-qual -Wchar-subscripts -Wcomment
    -Wdisabled-optimization
    -Werror -Wformat -Wformat=2
    -Wformat-nonliteral -Wformat-security
    -Wformat-y2k
    -Wimport  -Winit-self -Winline
    -Winvalid-pch
    -Wunsafe-loop-optimizations -Wlong-long -Wmissing-braces
    -Wmissing-field-initializers -Wmissing-format-attribute
    -Wmissing-include-dirs -Wmissing-noreturn
    -Wpacked  -Wparentheses  -Wpointer-arith
    -Wredundant-decls -Wreturn-type
    -Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector
    -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch
    -Wswitch-enum -Wtrigraphs  -Wuninitialized
    -Wunknown-pragmas -Wunreachable-code -Wunused
    -Wunused-function -Wunused-label -Wunused-parameter
    -Wunused-value -Wunused-variable -Wno-variadic-macros
    -Wvolatile-register-var  -Wwrite-strings
    )
elseif( CMAKE_CXX_COMPILER MATCHES "clang" )
  message(STATUS "Compiling in Debug mode with Clang")
  add_definitions( -Wall -Wextra )
endif()

add_executable(example1 examples/example1.cc)
target_link_libraries(example1 base)

