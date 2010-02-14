#include <usblcd.h>
#include <glib.h>

int   plugin_init(usblcd_operations* ops);
int   plugin_run(usblcd_operations* ops);
char* get_title();
char* get_modname();
char* plugin_view();
