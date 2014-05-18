# Credit to ehouse
CC=clang
CFLAGS=
SOURCE=$(wildcard src/*.c)
LIB=
OUT=-o
TARGET=frank4-uvb

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(LIB) $(OUT) $(TARGET) $(SOURCE)

clean:
	rm $(TARGET)
