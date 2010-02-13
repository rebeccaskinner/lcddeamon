#include <stdio.h>
#include <usblcd.h>
#include "lcdkeys.h"
#include "keymap.h"

int get_key_updown(usblcd_operations* screen)
{
    int val;
    int type = 0;
    usblcd_event* e = screen->read_events(screen);
    while(e && e->type) e=screen->read_events(screen);
    return (int)(e->data[0]);
}

int keypoll(usblcd_operations* screen) {
    int key_data = get_key_updown(screen);
    if(0 != get_key_updown(screen))
        return -1;
    return key_data;
}

const char* key_tostr(int key) {
    switch(key) {
        case 0x0:
            return "KEY_RELEASED"; 
        case 0x1:
            return "KEY_PLUS"; 
        case 0x2:
            return "KEY_MINUS"; 
        case 0x3:
            return "KEY_F1"; 
        case 0x4:
            return "KEY_F2"; 
        case 0x5:
            return "KEY_F3"; 
        case 0x6:
            return "KEY_F4"; 
        case 0x7:
            return "KEY_F5"; 
        case 0x8:
            return "KEY_LEFT"; 
        case 0x9:
            return "KEY_RIGHT"; 
        case 0xa:
            return "KEY_UP"; 
        case 0xb:
            return "KEY_DOWN"; 
        case 0xc:
            return "KEY_ENTER"; 
        default:
            return "KEY_UNKNOWN";
    }
}
