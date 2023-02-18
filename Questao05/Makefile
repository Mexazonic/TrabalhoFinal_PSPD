CC = gcc
CFLAGS = -fopenmp
EXEC = sort

all: $(EXEC)

$(EXEC): ordena_vetor.c
	$(CC) $(CFLAGS) $< -o $@

run:
	./$(EXEC) $(N)

clean:
	rm -f $(EXEC)

.PHONY: all clean run
