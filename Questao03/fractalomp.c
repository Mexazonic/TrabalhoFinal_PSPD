#include <fcntl.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "lib_julia.h"


#define OUTFILE "QUESTAO_03_out_julia_normal.bmp"

int thistograma[100] = {0};


void omp_julia(char *pixel_array, int height, int init, int end) {
    unsigned char *rgb;

    int area = 0, largura = 0, altura = 0, local_i = 0;

    rgb = calloc(3, sizeof(unsigned char));

    altura = height;largura = 2 * height;area = altura * largura * 3;

    for (int i = init; i <= end; i++) {
        for (int j = 0; j < largura * 3; j += 3) {
            compute_julia_pixel(j / 3, i, largura, altura, 1.0, rgb);
            pixel_array[local_i++] = rgb[0];
            pixel_array[local_i++] = rgb[1];
            pixel_array[local_i++] = rgb[2];
        }
    }

    free(rgb);
}


int main(int argc, char *argv[]) {

    int n;
    int area = 0, largura = 0, altura = 0, local_i = 0;
    
        fprintf(stderr,"Entre 'N' como um inteiro positivo! \n");
    if ((argc <= 1)|(atoi(argv[1])<1)){
        return -1; 
    }

    n = atoi(argv[1]);
    FILE *output_file = fopen(OUTFILE, "wb");

    altura = n; 
    largura = 2*n; 
    area=altura*largura*3;
    write_bmp_header(output_file, largura, altura);
    
    // printf("Computando linhas de pixel %d até %d, para uma área total de %d\n", 0, n-1, area);

    int output_file_aux = open(OUTFILE, O_RDWR, 0644);


    #pragma omp parallel for schedule(dynamic, 1)
     for (int i = 0; i < altura; i++) {
        unsigned char *pixel_array = calloc(6*n, sizeof(unsigned char));
        int offset = i * 6*n + 54;

        omp_julia(pixel_array, altura, i, i);


        pwrite(output_file_aux, pixel_array, area, offset);
        thistograma[omp_get_thread_num()]++;
        free(pixel_array);
        }


    for (int i = 0; i < omp_get_max_threads(); i++) 
        printf("Thread[%d] =  %d linhas.\n", i, thistograma[i]);
    

    // free(rgb);
    fclose(output_file);
    // free(pixel_array);
    
    return 0;
}
