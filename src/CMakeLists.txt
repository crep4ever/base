set(LIBNAME base)

set(SOURCES
  variant.cc
  parameter.cc
  error.cc
  exception.cc
  logger.cc
  benchmark.cc
  configuration.cc
  )

set(HEADERS
  types.hh
  timer.hh
  terminal-colors.hh
  variant.hh
  parameter.hh
  error-code.hh
  error.hh
  exception.hh
  singleton.hh
  logger.hh
  benchmark.hh
  configuration.hh
)

include_directories (tinyxml)
add_subdirectory (tinyxml)

add_library (${LIBNAME} ${SOURCES})
target_link_libraries(base tinyxml)
install (TARGETS ${LIBNAME} DESTINATION bin)
install (FILES ${HEADERS} DESTINATION include)
