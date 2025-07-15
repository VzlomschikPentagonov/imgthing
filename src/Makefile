CC = g++
CFLAGS = -Wall -O2
TARGET = main

all: $(TARGET)

$(TARGET): main.o bitmap.o
	$(CC) $(CFLAGS) main.o bitmap.o -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

bitmap.o: ../func_bitmap/bitmap.cpp
	$(CC) $(CFLAGS) -c ../func_bitmap/bitmap.cpp

clean:
	rm -f $(TARGET) *.o
