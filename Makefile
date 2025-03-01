CC = cc
CFLAGS = -Wall -Wextra -O2
TARGET = csleep
SRC = csleep.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

install:
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

clean:
	rm -f $(TARGET)

