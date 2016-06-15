# Um makefile bem simples
CC = gcc
CFLAGS = -std=c99
TARGET_1 = convert_data
TARGET_2 = ajust_data

all:
	$(CC) $(CFLAGS) -o $(TARGET_1) $(TARGET_1).c
	$(CC) $(CFLAGS) -o $(TARGET_2) $(TARGET_2).c

clean: 
	rm $(TARGET_1)
	rm $(TARGET_2)
