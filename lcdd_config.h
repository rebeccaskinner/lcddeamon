#ifndef __LCDD_CONFIG_H__
#define __LCDD_CONFIG_H__
#include <glib.h>
#include <sys/types.h>

typedef struct
{
    char*  plugin_path;
    time_t display_timeout;
    time_t refresh_freq;
}lcdd_settings;

#endif
