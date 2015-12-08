// Copyright (C) 2015, Romain Goffe <romain.goffe@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301, USA.
//******************************************************************************
#ifndef _LOGGER_H
#define _LOGGER_H

#include <stdio.h>
#include <string>
#include <cassert>
#include "singleton.hh"
#include "timer.hh"
#include "terminal-colors.hh"

#define LOG_STR_BUFFER_SIZE 1024

#define LOG_DEBUG(p_str, ...)                           \
  do						                                        \
  {						                                          \
    char buffer[LOG_STR_BUFFER_SIZE];		                \
    sprintf(buffer, "%s\t%s::%s\t" p_str,               \
	    currentDateTime().c_str(),	                      \
	    __FILE__,				                                  \
	    __FUNCTION__,			                                \
	    __VA_ARGS__);			                                \
    printf("%s\n", buffer);			                        \
    fprintf(CLogger::instance().fd(), "%s\n", buffer);  \
  }						                                          \
  while (false)					                                \

#define LOG_INFO(p_str, ...)	                          \
  do						                                        \
  { 						                                        \
    char buffer[LOG_STR_BUFFER_SIZE];		                \
    sprintf(buffer, "%s\t%s::%s\t" p_str,               \
	          currentDateTime().c_str(),	                \
	          __FILE__,				                            \
	          __FUNCTION__,						                    \
	          __VA_ARGS__);						                    \
    printf("%s%s%s\n", TERMINAL_COLOR_CYAN, buffer,     \
                       TERMINAL_COLOR_NORMAL);          \
    fprintf(CLogger::instance().fd(), "%s\n", buffer);  \
  } 									                                  \
  while (false)								                          \

#define LOG_ERROR(p_str, ...)                           \
  do						                                        \
  {						                                          \
    char buffer[LOG_STR_BUFFER_SIZE];		                \
    sprintf(buffer, "%s\t%s::%s\t" p_str,               \
	          currentDateTime().c_str(),	                \
	          __FILE__,				                            \
	          __FUNCTION__,			                          \
	          __VA_ARGS__);						                    \
    printf("%s%s%s\n", TERMINAL_COLOR_RED, buffer,      \
                       TERMINAL_COLOR_NORMAL);          \
    fprintf(CLogger::instance().fd(), "%s\n", buffer);  \
  }									                                    \
  while (false)								                          \

class CLogger : public Singleton<CLogger>
{
private:
  friend class Singleton<CLogger>;
  CLogger();
  ~CLogger();

public:
  FILE *fd() const;
  static void file(const std::string & p_filePath);

 private:
  static FILE * _fileDescriptor;
};

#endif // _LOGGER_H
