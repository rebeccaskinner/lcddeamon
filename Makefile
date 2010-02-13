CC=gcc
CFLAGS= -g                              \
        -O2                             \
        --std=gnu99                     \
        -I/usr/local/include            \
        `pkg-config --cflags glib-2.0`

LFLAGS= -lusblcd                        \
        `pkg-config --libs glib-2.0`

OBJS=test.o

all: lcdd

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

lcdd:$(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $@

clean:
	-rm -f *.o
	-rm -f lcdd

.PHONY: clean all
