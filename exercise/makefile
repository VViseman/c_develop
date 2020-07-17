CFLAGS=-I. -Wall -Werror -O2 -march=native
INCS=
OBJS=test.c
LIBS=
TARGET=test
CC := gcc

all: $(TARGET)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf $(TARGET) *.o
