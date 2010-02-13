CC=gcc
CFLAGS= -g                              \
        -O2                             \
        --std=gnu99                     \
        `pkg-config --cflags glib-2.0` 

LFLAGS= `pkg-config --libs glib-2.0` \
	-lpicoLCD

OBJS=test.o lcdkeys.o

all: lcdd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lcdd:$(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@

clean:
	-rm -f *.o
	-rm -f lcdd

.PHONY: clean all
