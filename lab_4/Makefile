TARGET = read write destroy
CC = gcc
CFLAGS = -g -Wall
#OBJS =
#SRC =

PREF_SRC = ./src/

all: $(TARGET)

read: $(PREF_SRC)read.c $(PREF_SRC)sharedMemory.c  $(PREF_SRC)synchron.c
	$(CC) $(CFLAGS) $(PREF_SRC)read.c $(PREF_SRC)sharedMemory.c  $(PREF_SRC)synchron.c -o read

write: $(PREF_SRC)write.c $(PREF_SRC)sharedMemory.c  $(PREF_SRC)synchron.c
	$(CC) $(CFLAGS) $(PREF_SRC)write.c $(PREF_SRC)sharedMemory.c  $(PREF_SRC)synchron.c -o write

destroy: $(PREF_SRC)destroy.c $(PREF_SRC)sharedMemory.c  $(PREF_SRC)synchron.c
	$(CC) $(CFLAGS) $(PREF_SRC)destroy.c $(PREF_SRC)sharedMemory.c  $(PREF_SRC)synchron.c -o destroy

clean:
	rm $(TARGET)