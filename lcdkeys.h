#ifndef __LCD_KEYS_H
#define __LCD_KEYS_H
#include <usblcd.h>
#include "keymap.h"
int get_key_updown(usblcd_operations* screen);
int keypoll(usblcd_operations* screen);
const char* key_tostr(int key) __attribute__((pure));
#endif
