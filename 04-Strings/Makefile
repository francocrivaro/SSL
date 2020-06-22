SRC = String.c StringTest.c
BIN = Test.out
OBJ = String.o StringTest.o
CC = gcc
CFLAGS = -std=c18

$(BIN): $(OBJ)
		$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
		$(BIN)

$(OBJ): $(SRC)
		$(CC) -c $(SRC) $(CFLAGS)