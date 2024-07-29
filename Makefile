
CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -lm

SRC = src/matrix.c src/activation.c src/neuron.c main.c
OBJ = $(SRC:.c=.o)
EXEC = neural_network

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
