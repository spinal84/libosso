/**
 * @file osso-log.c
 *
 * This file is part of libosso
 *
 * Copyright (C) 2005 Nokia Corporation. All rights reserved.
 *
 * Contact: Kimmo Hämäläinen <kimmo.hamalainen@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */
                
#include <stdarg.h>
#include <syslog.h>
#include <assert.h>

#include "osso-internal.h"
#include "log-functions.h"

void osso_log(int level, const char *format, ...) 
{
    va_list args;
    va_start(args,format);

    vsyslog(level,format,args);
    

    va_end(args);
    
}


inline void d_log(const char *file,int line, int level, 
                const char *format, ...)
{
#ifdef LIBOSSO_DEBUG
    va_list args;
    char *prefix_format;
    int len;

    len = strlen(file)+strlen(":%d: ")+strlen(format)+2;
   
/*    dprint("file [%s], line [%d], format [%s], len [%d]\n",file,line,format,
                    len);*/
    prefix_format = g_malloc(len);
    assert(prefix_format != NULL);

    g_snprintf(prefix_format,len,"%s:%d: %s",
                    file,line,format);

/*    dprint("Prefixed format [%s]\n",prefix_format);    */
    va_start(args, format);
    
    vsyslog(level|LOG_USER,prefix_format,args);
    
    va_end(args);

    g_free(prefix_format);
#endif
}




