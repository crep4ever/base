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
#ifndef _PARAMETER_H_
#define _PARAMETER_H_

#include <string>
#include "variant.hh"

class CParameter
{
public:
  CParameter();

  CParameter(const std::string & p_category,
             const std::string & p_subcategory,
             const std::string & p_name,
             const std::string & p_value);

  ~CParameter();

  const std::string & name() const;
  const std::string & category() const;
  const std::string & subcategory() const;
  const CVariant & value() const;
  std::string toString() const;

private:
  std::string m_name;
  std::string m_category;
  std::string m_subcategory;
  CVariant m_value;
};

#endif //_PARAMETER_H_
