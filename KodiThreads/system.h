#pragma once

/*
 *      Copyright (C) 2005-2016 Team KODI
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kodi; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */



#include <util/StringUtils.h>

extern int g_LOGERROR;
extern int g_LOGDEBUG;
extern int g_LOGINFO;
extern int g_LOGNOTICE;

typedef void (*LogCallback_t)(int loglevel, const char *format, ...);

void KodiThreadsLogger(int LogLevel, const char *format, ...);
void SetKodiThreadsLogger(LogCallback_t LoggerCallback);
void ReleaseKodiThreadsLogger();

#define LOG         KodiThreadsLogger
#define LOGERROR    g_LOGERROR
#define LOGDEBUG    g_LOGDEBUG
#define LOGINFO     g_LOGINFO
#define LOGNOTICE   g_LOGNOTICE
