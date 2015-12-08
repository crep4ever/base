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
#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_

#include <vector>
#include <string>
#include "error-code.hh"
#include "error.hh"

#define EXCEPTION(p_code)     \
  CException(ERROR(p_code));  \

class CException: public std::exception
{
public:
    CException(const std::string & p_message);
    CException(const CError & p_error);
    virtual ~CException() throw ();

    const CError & error() const;

    virtual const char* what() const throw ();

    std::string toString(const bool p_verbose = true) const;

private:
    CError m_error;
};


#endif // __EXCEPTION_H_
