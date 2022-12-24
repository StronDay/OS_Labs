CC = clang
CFLAGS = -g -Wall
TARGET = program

all: $(TARGET)

$(TARGET): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf *.dSYM *.o $(TARGET)
