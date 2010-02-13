#include <usblcd.h>
#include <stdio.h>

int read_loop(usblcd_operations* screen)
{
    usblcd_event* e;
    while(e  = screen->read_events(screen))
    {
        printf("got %d bytes of data from input:\n",e->length);
        switch(e->type)
        {
            case 0:
                printf("input type=keypad\n");
                break;
            case 1:
                printf("input type=IR\n");
                break;
            default:
                printf("Unknown input type(%d)\n",e->type);
                break;
        }
    }
    return 0;
}

int main(void)
{
    usblcd_operations *mylcd;
    /* init hid device and usblcd_operations structure */
    mylcd = new_usblcd_operations();
    /* init the USB LCD */
    mylcd->init(mylcd);
    /* sets backlight to on */
    mylcd->backlight(mylcd,0);
    read_loop(mylcd);
    /* close the USB LCD device */
    mylcd->close(mylcd);
    return 0;
}

