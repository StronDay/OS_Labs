TARGET = read.exe write.exe destroy.exe
CC = gcc
CFLAGS = -g -Wall
OBJS = ./src/sharedMemory.o

PREF_SRC = ./src/

all: $(TARGET)

%.exe : $(PREF_SRC)%.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: $(PREF_SRC)%.c $(PREF_SRC)%.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(PREF_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET)