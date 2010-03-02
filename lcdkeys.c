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
#include <stdio.h>
#include <usblcd.h>
#include "lcdkeys.h"
#include "keymap.h"

int get_key_updown(usblcd_operations* screen)
{
    usblcd_event* e;
    int dat;
    do { e = screen->read_events(screen); }while(!e);
    if(e->type) dat = -1;
    else dat = (int)(e->data[0]);
    free(e);
    return dat;
}

int keypoll(usblcd_operations* screen) {
    int key_data = get_key_updown(screen);
    if(0 != get_key_updown(screen)) return -1;
    return key_data;
}

const char* key_tostr(int key) {
    switch(key) {
        case KEY_RELEASED: return "KEY_RELEASED"; 
        case KEY_PLUS:     return "KEY_PLUS"; 
        case KEY_MINUS:    return "KEY_MINUS"; 
        case KEY_F1:       return "KEY_F1"; 
        case KEY_F2:       return "KEY_F2"; 
        case KEY_F3:       return "KEY_F3"; 
        case KEY_F4:       return "KEY_F4"; 
        case KEY_F5:       return "KEY_F5"; 
        case KEY_LEFT:     return "KEY_LEFT"; 
        case KEY_RIGHT:    return "KEY_RIGHT"; 
        case KEY_UP:       return "KEY_UP"; 
        case KEY_DOWN:     return "KEY_DOWN"; 
        case KEY_ENTER:    return "KEY_ENTER"; 
        default:           return "KEY_UNKNOWN";
    }
}
