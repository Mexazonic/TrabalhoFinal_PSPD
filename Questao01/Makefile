CC=mpicc
CFLAGS=-c -Wall
LDFLAGS=-lm
SOURCES=lib_julia.c fractalmpiserial.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fractalmpiserial
NPROCS=<número de processos>
N_FRACTAL=<valor>

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	mpicc $(OBJECTS) -o $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

run:
	mpirun -n $(NPROCS) ./$(EXECUTABLE) $(N_FRACTAL)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
