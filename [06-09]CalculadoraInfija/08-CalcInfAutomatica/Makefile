TARGET = Calc.exe
CC = gcc
CFLAGS = -std=c18 -g

FLEXL = Scanner.l
FLEXC = Scanner.c

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@

$(FLEXC): $(FLEXL)
	flex -o$(FLEXC) $(FLEXL)

clean:
	-rm -f *.o
	-rm -f $(TARGET)