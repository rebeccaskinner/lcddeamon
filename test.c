#include <usblcd.h>
#include <stdio.h>
#include <string.h>

int get_key_updown(usblcd_operations* screen)
{
    int val;
    usblcd_event* e;
    do
    {
        e = screen->read_events(screen);
    }while(e->type);
    return (int)(e->data[0]);
}

int keypoll(usblcd_operations* screen)
{
    int key_data = get_key_updown(screen);
    if(0 != get_key_updown(screen))
    {
        printf("Error, expected key to be released\n");
        return -1;
    }
    return key_data;
}

const char* key_tostr(int key)
{
    switch(key)
    {
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

int main(void)
{
    usblcd_operations *mylcd;
    /* init hid device and usblcd_operations structure */
    mylcd = new_usblcd_operations();
    /* init the USB LCD */
    mylcd->init(mylcd);
    /* sets backlight to on */
    mylcd->backlight(mylcd,1);
    printf("%s\n",key_tostr(keypoll(mylcd)));
    /* close the USB LCD device */
    mylcd->close(mylcd);
    return 0;
}

