# gzsize

SRC=src
TARGET=gzsize

CC=gcc
CFLAGS=-g -Wall -Wextra -Wundef -Wpointer-arith -std=gnu99 -I$(SRC)

.DEFAULT: all
.PHONY: clean cleanall

all: $(TARGET)

$(TARGET): $(SRC)/gzsize.c
	$(CC) -o $@ $^ $(CFLAGS) -lz

%.o: %.c %.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	find . -name "*~" -delete
	find . -name "*.o" -delete

cleanall: clean
	rm -f $(TARGET)
