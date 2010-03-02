/*
 Copyright 2010 Tim Skinner

 ********************************************************************************
 * This program is free software: you can redistribute it and/or modify it      *
 * under the terms of the GNU General Public License as published by the Free   *
 * Software Foundation, either version 3 of the License, or (at your option)    *
 * any later version.                                                           *
 *                                                                              *
 * This program is distributed in the hope that it will be useful, but WITHOUT  *
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
 * more details.                                                                *
 *                                                                              *
 * You should have received a copy of the GNU General Public License along with *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                   *
 ********************************************************************************
*/ 
#include <sys/types.h>
#include <sys/stat.h>
#include <glib.h>
#include <gmodule.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <usblcd.h>
#include "lcd_module.h"

lcd_module* load_module(const char* path, const char* name) {
    struct stat buf;
    if(!path || !name) {
        fprintf(stderr,"Plugin loading failure, invalid name or path\n");
        return NULL;
    }
    if(stat(path, &buf)) {
        printf("Cannot load plugin \"%s\" - %s\n",name,strerror(errno));
        return NULL;
    }
    lcd_module* m = g_malloc0(sizeof(lcd_module));
    if(NULL == (m->module = g_module_open(path,G_MODULE_BIND_LOCAL))) {
        fprintf(stderr,"Unknown failure while attemping to load module\n");
        g_free(m);
        return NULL;
    }
    g_module_symbol(m->module, "plugin_init", (gpointer)m->init);
    g_module_symbol(m->module, "plugin_exit", (gpointer)m->exit);
    g_module_symbol(m->module, "plugin_view", (gpointer)m->view);
    g_module_symbol(m->module, "plugin_view", (gpointer)m->run);
    if(NULL == m->init || NULL == m->run || NULL == m->view){
        fprintf(stderr,"Plugin does not contain the required symbols, not loading\n");
        unload_module(m);
        return NULL;
    }
    return m;
}

void unload_module(lcd_module* m) {
    if(!m) return;
    if(m->module) g_module_close(m->module);
    g_free(m);
}
