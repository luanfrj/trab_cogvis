# Um makefile bem simples
CC = gcc
CFLAGS = -std=c99
TARGET_1 = convert_data
TARGET_2 = ajust_data
TARGET_3 = teste_final

all:
	$(CC) $(CFLAGS) -o $(TARGET_1) $(TARGET_1).c
	$(CC) $(CFLAGS) -o $(TARGET_2) $(TARGET_2).c
	$(CC) $(CFLAGS) -o $(TARGET_3) $(TARGET_3).c

clean: 
	rm $(TARGET_1)
	rm $(TARGET_2)
	rm $(TARGET_3)
