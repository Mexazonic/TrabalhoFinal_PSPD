#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <unistd.h>
#include "lib_julia.h"

#define OUTFILE "QUESTAO_02_out_julia_normal.bmp"

int intervalos[1000][3]; // nprocs até 1000 basta atualizar

void limits(int v, int n) {
    int divisor = v / n;  // divisão inteira
    int resto = v % n;    // resto da divisão

    for (int i = 0; i < n; i++) {
        int inicio = i * divisor;
        int fim = inicio + divisor - 1;

        if (i == n - 1) {
            fim += resto;
        }

        intervalos[i][0] = inicio;
        intervalos[i][1] = fim;
    }
}

int main(int argc, char *argv[]) {

    int n;
    int area = 0, largura = 0, altura = 0, local_i = 0;
    FILE *output_file;
    char maquina[200];
    unsigned char *pixel_array, *rgb;

    if ((argc <= 1) | (atoi(argv[1]) < 1)) {
        fprintf(stderr, "Entre 'N' como um inteiro positivo! \n");
        return -1;
    }

    n = atoi(argv[1]);

    MPI_Init(&argc, &argv);
    int rank, nprocs;
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    gethostname(maquina, 199);

    limits(n, nprocs);

    output_file = fopen(OUTFILE, "wb");

    altura = n;
    largura = 2 * n;
    area = altura * largura * 3;

    pixel_array = calloc(area, sizeof(unsigned char));
    rgb = calloc(3, sizeof(unsigned char));

    // printf("Computando linhas de pixel %d até %d, para uma área total de %d\n", 0, n-1, area);

    for (int i = intervalos[rank][0]; i < intervalos[rank][1]; i++) {
        for (int j = 0; j < largura * 3; j += 3) {
            compute_julia_pixel(j / 3, i, largura, altura, 1.0, rgb);
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

    MPI_File imagem;
    MPI_Offset offset = start_line * largura * 3 + 54;
    MPI_File_open(MPI_COMM_WORLD, OUTFILE, MPI_MODE_WRONLY, MPI_INFO_NULL, &imagem);
    MPI_File_seek(imagem, offset, MPI_SEEK_SET);




    // MPI_File_write(imagem, pixel_array, largura * 3 * (intervalos[rank][1] - intervalos[rank][0]), MPI_CHAR, &status);
    MPI_File_write_at(imagem, offset, pixel_array, largura * 3 * (intervalos[rank][1] - intervalos[rank][0]), MPI_CHAR, &status);

    // MPI_File_write_at vs MPI_File_write (Extra)
    // O MPI_File_write_at é semelhante ao MPI_File_write, mas permite que o processo escreva em um deslocamento específico no arquivo, 
    // em vez de começar a escrever no início do arquivo. Isso pode ser útil em situações em que os processos precisam escrever em diferentes 
    // locais do arquivo, sem precisar coordenar essas operações.





    MPI_File_close(&imagem);
    printf("[maquina=%s] - rank[%d]: intervalos: %d %d\n", maquina, rank, intervalos[rank][0], intervalos[rank][1]);


    fclose(output_file);
    free(pixel_array);

    MPI_Finalize();
    return 0;
}
