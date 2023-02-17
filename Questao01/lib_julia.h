#ifndef LIB_JULIA_H
#define LIB_JULIA_H

int compute_julia_pixel(int x, int y, int largura, int altura, float tint_bias, unsigned char *rgb);
int write_bmp_header(FILE *f, int largura, int altura);

#endif