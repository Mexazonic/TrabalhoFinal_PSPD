## Trabalho Final PSPD
Nome: Bruno Henrique Sousa Duarte


### Questão 1

Compilação e execução (Localmente)
```shell

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpiserial.c -o fractalmpiserial -lm
mpirun -n 8 ./fractalmpiserial 1000

```


Compilação e execução para mais de uma máquina (Chococcino)
```shell

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpi_io.c -o fractalmpi_io -lm
mpirun -host cm1,cm2,cm3,cm4 -n 8 ./frac 1000

```
![](https://imgur.com/IwhI4ck.png)


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
![](https://imgur.com/jVTFuuj.png)


### Questão 3



Setar Número de Threads
```
export OMP_NUM_THREADS=4
echo $OMP_NUM_THREADS

```

Compilação e Execução
```shell
gcc -c lib_julia.c
gcc lib_julia.o fractalomp.c -fopenmp -lm -o fractalomp
./fractalomp 1000

```
### Questão 4
A questão 4 completa está presente no pdf acima com mais detalhes acerca da tabela bem [aqui](./Questão04.pdf)
| Fractal                       | 100      | 500      | 1000     | 10000   |
| ----------------------------- | -------- | -------- | -------- | ------- |
| MPI - Questão 1  (-n 4)        | 0.724s   | 0.825s   | 0.962s   | 24.370s |
| MPI - Questão 2 (-n 4)        | 0.923s   | 0.829s   | 1.076s   | 27.520s |
| MPI - Questão 1 (-n 7)        | 1.195s   | 1.388s   | 1.421s   | 20.598s |
| MPI - Questão 2  (-n 7)        | 1.193s   | 1.337s   | 1.531s   | 30.419s |
| OpenMP $OMP_NUM_THREADS = 16 | 0.016s   | 0m0.157s | 0.249s   | 15.648s |
| OpenMP $OMP_NUM_THREADS = 8  | 0.020s   | 0.132s   | 0.239s   | 15.660s |
| OpenMP $OMP_NUM_THREADS = 4  | 0m0.205s | 0m0.102s | 0m0.232s | 15.213s |

### Questão 5
```shell
gcc ordena_vetor.c -fopenmp -o sort
./sort
```
![](https://imgur.com/M9L1jfE.png)

