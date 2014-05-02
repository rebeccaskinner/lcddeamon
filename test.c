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
#include <usblcd.h>
#include <stdio.h>
#include <string.h>
#include "lcdkeys.h"

int main(int argc, char** argv)
{
    usblcd_operations *mylcd;
    /* init hid device and usblcd_operations structure */
    mylcd = new_usblcd_operations();
    /* init the USB LCD */
    mylcd->init(mylcd);
    /* sets backlight to on */
    mylcd->backlight(mylcd,1);
    printf("%s\n",key_tostr(keypoll(mylcd)));
    mylcd->clear(mylcd);
    mylcd->settext(mylcd, 0, 0, "Hello World");
    mylcd->settext(mylcd, 1, 10, "Hello");
    /* close the USB LCD device */
    mylcd->close(mylcd);
    return 0;
}

