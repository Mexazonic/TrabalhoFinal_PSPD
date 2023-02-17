## Trabalho Final PSPD
Nome: Bruno Henrique Sousa Duarte


### Questão 1

Compilação e execução (Localmente)
```shell

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpiserial.c -o fractalmpiserial -lm
mpirun -n 4 ./fractalmpiserial 1000

```


Compilação e execução para mais de uma máquina (Chococcino)
```shell

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpi_io.c -o fractalmpi_io -lm
mpirun -host cm1,cm2,cm3,cm4 -n 4 ./frac 1000

```


### Questão 2


Compilação e execução (Localmente)
```shell

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpi_io.c -o fractalmpi_io -lm
mpirun -n 4 ./fractalmpi_io 1000

```


Compilação e execução para mais de uma máquina (Chococcino)
```shell
gcc -c lib_julia.c
mpicc lib_julia.o fractalmpiserial.c -o frac -lm
mpirun -host cm1,cm2,cm3,cm4 -n 4 ./fractalmpiserial 1000

```

### Questão 3



Setar Número de Threads
```
export OMP_NUM_THREADS=4
echo $OMP_NUM_THREADS

```

Compilação e Execução (Local)
```shell

gcc -c lib_julia.c
gcc lib_julia.o fractalomp.c -fopenmp -lm -o fractalomp
./fractalomp 1000

```



### Questão 5
```shell
gcc ordena_vetor.c -fopenmp -o sort
./sort
```


