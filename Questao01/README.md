## Questão 01

### Local
```bash
    make
    make run NPROCS=4 N_FRACTAL=1000

```
### Chococino
```bash
    make
    mpirun -host cm1,cm2,cm3,cm4,gpu1,gpu2,gpu3 -n 7 ./fractalmpiserial 1000
```

Este código é um programa em C que calcula a imagem de um fractal Julia em paralelo usando MPI (Message Passing Interface). O programa é dividido em vários processos que executam a computação em paralelo, e o resultado é escrito em um arquivo de imagem BMP.

O código começa definindo o nome do arquivo de saída e uma matriz que irá armazenar os intervalos de linhas que cada processo irá computar. A função limits() é responsável por dividir o trabalho entre os processos. Ela recebe o número de linhas da imagem e o número de processos e, em seguida, calcula os intervalos de linhas que cada processo deve computar.

A função worker_write_pixel_lines() é usada para escrever um conjunto de linhas de pixels em um arquivo BMP. Ela recebe o ponteiro para o arquivo de saída, as dimensões da imagem, a linha inicial, o número de linhas a serem escritas e o ponteiro para o array de pixels. A função usa a função fseek() para mover o ponteiro do arquivo para a posição correta e, em seguida, escreve as linhas de pixels usando a função fwrite().

Em seguida, a função main() começa lendo o número de linhas da imagem como argumento de linha de comando e, em seguida, inicializa MPI. A função gethostname() é usada para obter o nome da máquina em que o processo está sendo executado.

Em seguida, o programa aloca memória para o array de pixels e para um array de três elementos usado para armazenar a cor de cada pixel. O programa, em seguida, executa um loop para cada intervalo de linhas atribuído a este processo. Para cada pixel, o programa chama a função compute_julia_pixel() (definida no arquivo lib_julia.h) para calcular sua cor e armazená-la no array de pixels.

O programa, em seguida, abre o arquivo de saída e chama a função worker_write_pixel_lines() para escrever as linhas de pixels calculadas por este processo no arquivo de saída. Finalmente, o programa desaloca a memória alocada e encerra a execução do MPI.