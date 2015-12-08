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
#ifndef __ERROR_CODE_H_
#define __ERROR_CODE_H_

#include <string>

enum ErrorCode
{
  NO_ERROR = 0,
  ERROR_UNKNOWN = 1,
  ERROR_BAD_IO = 2,
  ERROR_NO_MATCH_FOUND = 3,
  ERROR_SINGLETON = 4
};

inline const std::string ErrorDescription(const ErrorCode p_code)
{
  switch (p_code)
  {
    case NO_ERROR:
    return "No error";

    case ERROR_UNKNOWN:
    return "Unknown error";

    case ERROR_BAD_IO:
    return "Invalid file access";

    case ERROR_NO_MATCH_FOUND:
    return "No match found";

    case ERROR_SINGLETON:
    return "Invalid use of singleton pattern";
  }

  return std::string();
}

#endif //__ERROR_CODE_H_
