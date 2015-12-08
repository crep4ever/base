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
#ifndef _TIMER_H
#define _TIMER_H

#include <sys/time.h>
#include <time.h>
#include <cstdio>

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss.zzz
inline static const std::string currentDateTime()
{
  timeval curTime;
  gettimeofday(&curTime, NULL);
  const int ms = curTime.tv_usec / 1000;

  // TODO: WARNING !!! localtime not re-entrant (see localtime_r)
  char buffer [24];
  strftime(buffer, 24, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

  char currentTime[28];
  sprintf(currentTime, "%s.%03d", buffer, ms);

  return currentTime;
}

#endif // _TIMER_H
