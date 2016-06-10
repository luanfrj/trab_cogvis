# Um makefile bem simples
CC = gcc
CFLAGS = -std=c99
TARGET = convert_data

all: convert_data.c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean: 
	rm $(TARGET)
