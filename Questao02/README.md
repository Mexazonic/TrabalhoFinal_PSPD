## Questão 02
Para executar localmente
```shell
    make
    make run NPROCS=4 N_FRACTAL=1000

```
Já no choccino
```shell
    make
    mpirun -host cm1,cm2,cm3,cm4,gpu1,gpu2,gpu3 -n 7 ./fractalmpiserial 1000
```

Na questão 2 temos um programa em C que usa MPI (Interface de Passagem de Mensagens) para calcular uma imagem da fractal de Julia e salvar a imagem em um arquivo BMP. O código é semelhante ao anterior(Questão 01), mas agora é dividido em intervalos para que vários processos possam calcular pixels diferentes e, em seguida, gravá-los no arquivo BMP usando MPI_File_write_at().

Aqui estão as principais partes do código:

* #include: Inclui as bibliotecas necessárias, incluindo MPI.
int intervalos[1000][3]: Uma matriz que armazena o intervalo de linhas que cada processo deve calcular.

* limits(): Uma função que calcula os limites de linha para cada processo com base no número total de linhas e no número de processos.
* MPI_Init(), MPI_Comm_rank(), MPI_Comm_size(), MPI_Status: Funções MPI para inicializar o MPI, obter o número de processos e o ID do processo, bem como definir o status da mensagem.
for (int i = intervalos[rank][0]; i < intervalos[rank][1]; i++): Um loop que itera pelas linhas que este processo deve calcular com base no seu ID de processo.
* compute_julia_pixel(): Uma função que calcula a cor de um pixel com base em sua posição na imagem e em alguns parâmetros de entrada. Essa função é definida em um arquivo de biblioteca separado chamado lib_julia.h.
* MPI_File_write_at(): Uma função MPI que grava o buffer de pixels em um arquivo BMP. Ele grava a partir de um deslocamento específico no arquivo para que cada processo grave na posição correta.
* MPI_Finalize(): Uma função MPI que finaliza o MPI.

Em geral, o programa divide o cálculo de pixels em várias partes para que diferentes processos possam trabalhar em diferentes partes da imagem. Cada processo calcula seus pixels e, em seguida, grava-os em um arquivo BMP usando MPI_File_write_at().
