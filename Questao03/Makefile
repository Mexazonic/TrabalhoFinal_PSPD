CC = gcc
CFLAGS = -fopenmp -lm
OBJFILES = lib_julia.o fractalomp.c

.PHONY: all clean

all: fractalomp

fractalomp: $(OBJFILES)
	$(CC) $(OBJFILES) $(CFLAGS) -o fractalomp

lib_julia.o: lib_julia.c
	$(CC) -c lib_julia.c

clean:
	rm -f *.o fractalomp

run: 
	export OMP_NUM_THREADS=$(V_THREADS) && ./fractalomp $(N_FRACTAL)
