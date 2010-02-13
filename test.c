#include <usblcd.h>
#include <stdio.h>

int read_loop(usblcd_operations* screen)
{
    usblcd_event* e;
    while(e = screen->read_events(screen))
    {
        if(e->type) //not keyboard
            continue;
        int dval = *((int*)(e->data));
        if(dval)
            printf("read key:\n%d\tdec\n%x\thex\n",dval,dval);
        else
            printf("key released\n");
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

