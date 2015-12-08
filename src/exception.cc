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
#include "exception.hh"
#include "types.hh"

CException::CException(const std::string & p_message) :
m_error(ERROR(ERROR_UNKNOWN))
{
  m_error << p_message;
}

CException::CException(const CError & p_error) : m_error(p_error)
{}

CException::~CException() throw ()
{}

const CError & CException::error() const
{
  return m_error;
}

const char* CException::what() const throw ()
{
  return m_error.toString().c_str();
}

std::string CException::toString(const bool p_verbose) const
{
  std::stringstream ss;
  ss << "\n";

  if (p_verbose || m_error.info().empty())
  {
    ss << m_error.toString();
  }
  else
  {
    std::vector<std::string> info = m_error.info();
    for (uint i = 0; i < info.size(); ++i)
    {
      ss << info[i] << "\n";
    }
  }

  return ss.str();
}
