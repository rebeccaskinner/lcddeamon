#include <usblcd.h>
#include <stdio.h>
#include <string.h>
#include "lcdkeys.h"

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

