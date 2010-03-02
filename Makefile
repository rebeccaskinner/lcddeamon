CC=gcc
CFLAGS= -g                                \
        -Wall                             \
        -Wextra                           \
        -Werror                           \
        -Os                               \
        --std=gnu99                       \
        `pkg-config --cflags glib-2.0`    \
        `pkg-config --cflags gmodule-2.0` 

LFLAGS= `pkg-config --libs glib-2.0`    \
        `pkg-config --libs gmodule-2.0` \
	-lpicoLCD

OBJS=lcdd.o lcdkeys.o lcd_module.o

all: lcdd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lcdd:$(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@

clean:
	-rm -f *.o
	-rm -f lcdd

.PHONY: clean all
