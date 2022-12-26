TARGET = read write destroy
CC = gcc
CFLAGS = -g -Wall
PREF_SRC = ./src/

all: $(TARGET)

read: $(PREF_SRC)read.c $(PREF_SRC)sharedMemory.c
	$(CC) $(CFLAGS) $(PREF_SRC)read.c $(PREF_SRC)sharedMemory.c -o read

write: $(PREF_SRC)write.c $(PREF_SRC)sharedMemory.c
	$(CC) $(CFLAGS) $(PREF_SRC)write.c $(PREF_SRC)sharedMemory.c -o write

destroy: $(PREF_SRC)destroy.c $(PREF_SRC)sharedMemory.c
	$(CC) $(CFLAGS) $(PREF_SRC)destroy.c $(PREF_SRC)sharedMemory.c -o destroy

clean:
	rm $(TARGET)