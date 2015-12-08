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
#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#include <stdlib.h>
#include <map>
#include <string>
#include "singleton.hh"
#include "error.hh"
#include "parameter.hh"

#define GET_CONF_VALUE(t, n) 42;

#define GET_CONF_PARAM(n) CConfiguration::instance().find(#n);

class CConfiguration : public Singleton<CConfiguration>
{
private:
  friend class Singleton<CConfiguration>;
  CConfiguration();
  ~CConfiguration();

public:
  static void file(const std::string & p_filePath);
  CParameter find(const std::string & p_key) const;

private:
  static std::map<std::string, CParameter> _parameters;
};

#endif // _CONFIGURATION_H
