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
#ifndef __ERROR_H_
#define __ERROR_H_

#include <vector>
#include <string>
#include <sstream>
#include "error-code.hh"

#define ERROR_STR_BUFFER_SIZE 1024

#define ERROR(p_code)	                                    \
  CError(p_code, __FILE__, __LINE__, __PRETTY_FUNCTION__)	\

class CError
{
public:
  CError();
  CError(const ErrorCode p_code,
         const std::string & p_file,
         const int p_line,
         const std::string & p_function);

  virtual ~CError();

  ErrorCode code() const;
  const std::string & file() const;
  int line() const;
  const std::string & function() const;
  const std::vector<std::string> info() const;

  void addInfo(const std::string & p_formatted);
  void addInfo(const char* p_format, ...);
  void operator<<(const std::string & p_str);

  std::string toString(const bool p_verbose = true) const;

private:
  ErrorCode m_code;
  std::string m_file;
  int m_line;
  std::string m_function;
  std::vector<std::string> m_info;
};

#endif // __ERROR_H_
