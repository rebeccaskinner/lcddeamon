/*
 Copyright 2010,2014 Rebecca Skinner

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
#ifndef __LCD_MODULE_H
#define __LCD_MODULE_H
#include <glib.h>
#include <gmodule.h>

typedef struct {
    int (*init)(usblcd_operations* ops);
    int (*run)(usblcd_operations* ops);
    int (*view)(char* toprow, char* bottomrow);
    int (*exit)();
    GModule* module;
}lcd_module;

GSList* load_modules(const char* path);
void    unload_module(lcd_module* m);

#endif
