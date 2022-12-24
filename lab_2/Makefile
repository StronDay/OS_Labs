CC = clang
CFLAGS = -g -Wall
TARGET = fifo pipe

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.dSYM *.o $(TARGET)