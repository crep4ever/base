set(LIBNAME tinyxml)

set(SOURCES
  tinystr.cpp
  tinyxml.cpp
  tinyxmlerror.cpp
  tinyxmlparser.cpp
  )

set(HEADERS
  tinyxml.h
  )

add_library(${LIBNAME} ${SOURCES})
install (TARGETS ${LIBNAME} DESTINATION bin)
install (FILES ${HEADERS} DESTINATION include)
