## Experimento sobre OpenMP e MPI
Nome: Bruno Henrique Sousa Duarte

Matrícula: 170138551


### [Questão 1](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao01/README.md)
Para mais detalhes da questão 1, clique [aqui](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao01/README.md)

Compilação e execução (Localmente)
```console

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpiserial.c -o fractalmpiserial -lm
mpirun -n 8 ./fractalmpiserial 1000

```


Compilação e execução para mais de uma máquina (Chococcino)
```console

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpiserial.c -o fractalmpiserial -lm
mpirun -host cm1,cm2,cm3,cm4,gpu1,gpu2,gpu3 -n 7 ./fractalmpiserial 1000
```
ou
```console
    make
    mpirun -host cm1,cm2,cm3,cm4,gpu1,gpu2,gpu3 -n 7 ./fractalmpiserial 1000
```

![](https://imgur.com/kzBsbwb.png)
Exemplo Resultado:
![](https://imgur.com/IwhI4ck.png)


### [Questão 02](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao02/README.md)
Para mais detalhes da questão 2, clique [aqui](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao02/README.md)


Compilação e execução (Localmente)
```console

gcc -c lib_julia.c
mpicc lib_julia.o fractalmpi_io.c -o fractalmpi_io -lm
mpirun -n 4 ./fractalmpi_io 1000

```


Compilação e execução para mais de uma máquina (Chococcino)
```console
gcc -c lib_julia.c
mpicc lib_julia.o fractalmpi_io.c -o fractalmpi_io -lm
mpirun -host cm1,cm2,cm3,cm4 -n 4 ./fractalmpi_io 1000
```
ou

```console
    make
    mpirun -host cm1,cm2,cm3,cm4,gpu1,gpu2,gpu3 -n 7 ./fractalmpi_io 1000
```




![](https://imgur.com/JSCxPPe.png)
Exemplo:
![](https://imgur.com/jVTFuuj.png)


### [Questão 3](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao03/README.md)


Leia mais [aqui](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao03/README.md)

Setar Número de Threads
```console
export OMP_NUM_THREADS=4
echo $OMP_NUM_THREADS

```

Compilação e Execução
```console
gcc -c lib_julia.c
gcc lib_julia.o fractalomp.c -fopenmp -lm -o fractalomp
./fractalomp 1000
```
ou

```console
    make
    make run V_THREADS=8 N_FRACTAL=1000
```
![](https://imgur.com/K0tB7aR.png)

### [Questão 4](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao04/Quest%C3%A3o04.pdf)
A questão 4 completa está presente no pdf acima com mais detalhes acerca da tabela bem [aqui](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao04/Quest%C3%A3o04.pdf)
| Fractal                       | 100      | 500      | 1000     | 10000   | 15000 |	18918 |
| ----------------------------- | -------- | -------- | -------- | ------- | ------- | ------- |
| MPI - Questão 1  (-n 4)        | 0.724s   | 0.825s   | 0.962s   | 24.370s |55.922s | 1m30.632s|
| MPI - Questão 2 (-n 4)        | 0.923s   | 0.829s   | 1.076s   | 27.520s | 0m57.021s|1m38.878s|
| MPI - Questão 1 (-n 7)        | 1.195s   | 1.388s   | 1.421s   | 20.598s |1m0.662s|1m17.485s|
| MPI - Questão 2  (-n 7)        | 1.193s   | 1.337s   | 1.531s   | 30.419s |1m1.853s|1m43.642s|
| OpenMP $OMP_NUM_THREADS = 16 | 0.016s   | 0m0.157s | 0.249s   | 15.648s |0m45.942s|1m8.951s|
| OpenMP $OMP_NUM_THREADS = 8  | 0.020s   | 0.132s   | 0.239s   | 15.660s |0m41.699s|1m0.472s|
| OpenMP $OMP_NUM_THREADS = 4  | 0m0.205s | 0m0.102s | 0m0.232s | 15.213s |0m41.065s|1m4.008s|


![](https://imgur.com/vTphnCc.png)

### [Questão 5](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao05/README.md)
Para mais detalhes, leia [aqui](https://github.com/Mexazonic/TrabalhoFinal_PSPD/blob/main/Questao05/README.md)
```shell
gcc ordena_vetor.c -fopenmp -o sort
./sort
```
ou

```console
    make
    make run N=5
```
![](https://imgur.com/M9L1jfE.png)

