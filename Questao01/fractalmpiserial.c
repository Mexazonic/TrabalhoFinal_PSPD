#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <unistd.h>
#include "lib_julia.h"

#define OUTFILE "QUESTAO_01_out_julia_normal.bmp"

int intervalos[1000][3]; //processos até 1000 basta atualizar

void limits(int v, int n) {
    int divisor = v / n;  // divisão inteira
    int resto = v % n;  // resto da divisão

    for (int i = 0; i < n; i++) {
        int inicio = i * divisor;
        int fim = inicio + divisor - 1;

        if (i == n-1) {
            fim += resto;
        }

        intervalos[i][0] = inicio;
        intervalos[i][1] = fim;
    }
}

// A função worker_write_pixel_lines é responsável por escrever um conjunto de linhas de pixels em um arquivo BMP. Ela recebe como entrada o ponteiro para o arquivo output_file, as dimensões da imagem largura e altura, a linha inicial
// start_line e o número de linhas num_lines que serão escritas no arquivo, além do ponteiro para o array de pixels pixel_array.
// A função utiliza a função fseek para mover o ponteiro do arquivo para a posição correta, calculada a partir da linha inicial e do tamanho da linha. Em seguida, ela escreve as linhas de pixels no arquivo usando a função fwrite.

void worker_write_pixel_lines(FILE *output_file, int largura, int altura, int start_line, int num_lines, unsigned char* pixel_array) {
    int line_size = largura * 3;

    for (int i = 0; i < num_lines; i++) {
        int offset = 54 + (start_line + i) * line_size;
        fseek(output_file, offset, SEEK_SET);
        fwrite(pixel_array + i * line_size, sizeof(unsigned char), line_size, output_file);
    }
}

int main(int argc, char *argv[]) {
    int n;
    int area = 0, largura = 0, altura = 0, local_i = 0;
    FILE *output_file;
    unsigned char *pixel_array, *rgb;

    if ((argc <= 1)|(atoi(argv[1])<1)){
        fprintf(stderr,"Entre 'N' como um inteiro positivo! \n");
        return -1; 
    }
    

    n = atoi(argv[1]);

    MPI_Init(&argc,&argv);
    int rank, nprocs;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    char maquina[200];
    gethostname(maquina, 199);
    limits(n, nprocs);


    if(rank == 0)
        printf("================================QUESTÃO 01================================\n");

    output_file= fopen(OUTFILE, "wb");
    altura = n;
    largura = 2*n;
    area = altura * largura * 3;
    pixel_array = calloc(area, sizeof(unsigned char));
    rgb = calloc(3, sizeof(unsigned char));

    // printf("Computando linhas de pixel %d até %d, para uma área total de %d\n", 0, n-1, area);

    for (int i = intervalos[rank][0]; i < intervalos[rank][1]; i++) {
        for (int j = 0; j < largura*3; j += 3) {
            compute_julia_pixel(j/3, i, largura, altura, 1.0, rgb);
            pixel_array[local_i] = rgb[0];
            local_i++;
            pixel_array[local_i] = rgb[1];
            local_i++;
            pixel_array[local_i] = rgb[2];
            local_i++;
        }
    }

    free(rgb);

    output_file = fopen(OUTFILE, "r+");
    write_bmp_header(output_file, largura, altura);
    int line_size = largura * 3;
    int start_line = intervalos[rank][0];

    // Abrindo arquivo para poder escrever
    worker_write_pixel_lines(output_file, largura, altura, start_line, intervalos[rank][1] - intervalos[rank][0], pixel_array);
    printf("[maquina=%s] - rank[%d]: intervalos: %d %d\n", maquina, rank, intervalos[rank][0], intervalos[rank][1]);

    fclose(output_file);
    free(pixel_array);
    MPI_Finalize();

    return 0;
}
