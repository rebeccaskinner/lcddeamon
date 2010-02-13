#include <usblcd.h>

int main(void)
{
    usblcd_operations *mylcd;
    /* init hid device and usblcd_operations structure */
    mylcd = new_usblcd_operations();
    /* init the USB LCD */
    mylcd->init(mylcd);
    /* sets backlight to on */
    mylcd->backlight(mylcd,0);
    /* close the USB LCD device */
    mylcd->close(mylcd);
    return 0;
}

