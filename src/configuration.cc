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
#include "configuration.hh"

#include <stdlib.h>
#include "tinyxml.h"
#include "logger.hh"
#include "exception.hh"
#include "error.hh"

std::map<std::string, CParameter> CConfiguration::_parameters = std::map<std::string, CParameter>();

CConfiguration::CConfiguration(){}

CConfiguration::~CConfiguration(){}

CParameter CConfiguration::find(const std::string & p_key) const
{
  try
  {
    return _parameters.at(p_key);
  }
  catch (std::exception& e)
  {
    CError error = ERROR(ERROR_NO_MATCH_FOUND);
    error.addInfo("Can't find parameter %s", p_key.c_str());
    throw CException(error);
  }
}
void CConfiguration::file(const std::string & p_filePath)
{
  _parameters.clear();

  TiXmlDocument doc(p_filePath.c_str());
  if (!doc.LoadFile())
  {
    CError error = ERROR(ERROR_BAD_IO);
    error.addInfo("Can't load configuration file [%s]", p_filePath.c_str());
    throw CException(error);
  }

  TiXmlHandle handle(&doc);
  TiXmlElement* current;
  TiXmlHandle root(0);

  {
    current = handle.FirstChildElement().Element();
    assert(current); // should always have a valid root
    root = TiXmlHandle(current);
  }

  TiXmlElement* cat  = root.FirstChild().ToElement();
  for (; cat; cat = cat->NextSiblingElement())
  {
    TiXmlElement*  subcat = TiXmlHandle(cat).FirstChild().ToElement();
    for (; subcat; subcat = subcat->NextSiblingElement())
    {
      current = TiXmlHandle(subcat).FirstChild().ToElement();
      for (; current; current = current->NextSiblingElement())
      {
        const char *name = current->Value();
        if (name)
        {
          const char *value = current->GetText();
          const std::string key = std::string(cat->Value()) + std::string(subcat->Value()) + std::string(name);
          printf("KEY: %s\n", key.c_str());
          _parameters[key] = CParameter(cat->Value(), subcat->Value(), name, value);
        }
      }
    }
  }

  LOG_DEBUG("Read %d parameters from conf [%s]", (int) _parameters.size(), p_filePath.c_str());
}
