CC = gcc

CFLAGS = -Isrc

SRCS = src/main.c src/hash_table.c src/prime.c

OBJS = build/main.o build/hash_table.o build/prime.o

TARGET = build/my_first_c_program

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build/*
