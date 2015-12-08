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
#include "parameter.hh"

#include <sstream>

CParameter::CParameter() :
m_name(),
m_category(),
m_subcategory(),
m_value(std::string())
{}

CParameter::CParameter(const std::string & p_category,
                       const std::string & p_subcategory,
                       const std::string & p_name,
                       const std::string & p_value) :
  m_name(p_name),
  m_category(p_category),
  m_subcategory(p_subcategory),
  m_value(p_value)
{}

CParameter::~CParameter()
{}

const std::string & CParameter::name() const
{
  return m_name;
}

const std::string & CParameter::category() const
{
  return m_category;
}

const std::string & CParameter::subcategory() const
{
  return m_subcategory;
}

const CVariant & CParameter::value() const
{
  return m_value;
}

std::string CParameter::toString() const
{
  std::stringstream ss;
  ss << category()    << " / ";
  ss << subcategory() << " / ";
  ss << name()        << " = ";
  ss << value().toString();
  return ss.str();
}
