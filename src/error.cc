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
#include "error.hh"

#include <sstream>
#include <cstdarg>
#include <cstdio>
#include "types.hh"

CError::CError(const ErrorCode p_code,
               const std::string & p_file,
               const int p_line,
               const std::string & p_function) :
  m_code(p_code),
  m_file(p_file),
  m_line(p_line),
  m_function(p_function),
  m_info()
{}

CError::CError() :
  m_code(NO_ERROR),
  m_file(),
  m_line(0),
  m_function(),
  m_info()
{}

CError::~CError()
{}

ErrorCode CError::code() const
{
  return m_code;
}

const std::string & CError::file() const
{
  return m_file;
}

int CError::line() const
{
  return m_line;
}

const std::string & CError::function() const
{
  return m_function;
}

const std::vector<std::string> CError::info() const
{
  return m_info;
}

void CError::addInfo(const std::string & p_formatted)
{
  m_info.push_back(p_formatted);
}

void CError::addInfo(const char* p_format, ...)
{
  char buffer[ERROR_STR_BUFFER_SIZE];
  va_list args;
  va_start (args, p_format);
  vsnprintf (buffer, ERROR_STR_BUFFER_SIZE, p_format, args);
  va_end (args);

  addInfo(std::string(buffer));
}

void CError::operator<<(const std::string & p_str)
{
  addInfo(p_str);
}

std::string CError::toString(const bool p_verbose) const
{
  std::stringstream ss;
  ss << "\n";
  ss << "CODE: " << (int) m_code << "\n";
  ss << "FILE: " << m_file << "\n";
  ss << "LINE: " << m_line << "\n";
  ss << "FUNCTION: " << m_function << "\n";
  ss << "DESCRIPTION: " << ErrorDescription(m_code) << "\n";

  if (p_verbose)
  {
    ss << "INFO: ";
    for (uint i = 0; i < m_info.size(); ++i)
    {
      ss << m_info[i] << "\n";
    }
    // TODO: backtrace
  }

  return ss.str();
}
