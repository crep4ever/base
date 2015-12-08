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
#include "benchmark.hh"

#include <cassert>
#include "timer.hh"
#include "exception.hh"
#include "logger.hh"

FILE * CBenchmark::_fileDescriptor = 0;

CBenchmark::CBenchmark(){}

CBenchmark::~CBenchmark()
{
  fclose(_fileDescriptor);
}

FILE * CBenchmark::fd()
{
  if (!_fileDescriptor)
  {
    CError error = ERROR(ERROR_SINGLETON);
    error.addInfo("Invalid Benchmark file");
    throw CException(error);
  }

  return _fileDescriptor;
}

void CBenchmark::file(const std::string & p_filePath)
{
  if (_fileDescriptor)
  {
    fclose(_fileDescriptor);
  }

  _fileDescriptor = fopen(p_filePath.c_str(), "w+");

  if (!_fileDescriptor)
  {
    CError error = ERROR(ERROR_BAD_IO);
    error.addInfo("Can't write benchs to file [%s]", p_filePath.c_str());
    throw CException(error);
  }
}

////////////////////////////////////////////////////////////////////////////////

const std::string CScopedBenchmark::_separator = ",";
const std::string CScopedBenchmark::_startLabel = "start";
const std::string CScopedBenchmark::_stopLabel = "stop";
const std::string CScopedBenchmark::_stepLabel = "step";

CScopedBenchmark::CScopedBenchmark(const std::string & p_label) : m_label(p_label)
{
  if (CBenchmark::fd())
  {
    char buffer[BENCHMARK_STR_BUFFER_SIZE];
    sprintf(buffer, "%s%s%s%s%s%s",
            currentDateTime().c_str(),
            _separator.c_str(),
            m_label.c_str(),
            _separator.c_str(),
            _startLabel.c_str(),
            _separator.c_str());

    fprintf(CBenchmark::fd(), "%s\n", buffer);	\
  }
}

CScopedBenchmark::~CScopedBenchmark()
{
  if (CBenchmark::fd())
  {
    char buffer[BENCHMARK_STR_BUFFER_SIZE];
    sprintf(buffer, "%s%s%s%s%s%s", currentDateTime().c_str(),
            _separator.c_str(),
            m_label.c_str(),
            _separator.c_str(),
            _stopLabel.c_str(),
            _separator.c_str());

    fprintf(CBenchmark::fd(), "%s\n", buffer);	\
  }
}

void CScopedBenchmark::addStep(const std::string & p_str)
{
  if (CBenchmark::fd())
  {
    char buffer[BENCHMARK_STR_BUFFER_SIZE];
    sprintf(buffer, "%s%s%s%s%s%s%s", currentDateTime().c_str(),
            _separator.c_str(),
            m_label.c_str(),
            _separator.c_str(),
            _stepLabel.c_str(),
            _separator.c_str(),
            p_str.c_str());

    fprintf(CBenchmark::fd(), "%s\n", buffer);	\
  }
}
