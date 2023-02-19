#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>

void selection_sort(int *v, int n) {
    int i, j, min, tmp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;

        tmp = v[i];
        v[i] = v[min];
        v[min] = tmp;
    }
}

struct MaxIndex {
    int value;
    int index;
};

#pragma omp declare reduction(max_reduction : struct MaxIndex : omp_out = omp_in.value > omp_out.value ? omp_in : omp_out)

void parallel_selection_sort(int *arr, int size) {
    for (int i = size - 1; i > 0; i--) {
        struct MaxIndex max_val;
        max_val.value = arr[i];
        max_val.index = i;

        #pragma omp parallel for reduction(max_reduction : max_val)
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > max_val.value) {
                max_val.value = arr[j];
                max_val.index = j;
            }
        }

        int temp = arr[i];
        arr[i] = max_val.value;
        arr[max_val.index] = temp;
    }
}

// void omp_selection_sort(int *v, int n) {
// 	int i, j, min, tmp;
// 	#pragma omp parallel for shared(n,v, j,min, i) private(tmp)  
// 	for(i = 0; i < n - 1; i++){
// 		min = i;
// 		for(j = i + 1; j < n; j++)
// 			if(v[j] < v[min])
// 				min = j;
// 		tmp = v[i];
// 		v[i] = v[min];
// 		v[min] = tmp;
// 	}
// }


// Funcionou apenas até N = 5
// void ompsort(int *a, int *out, int count){
// 	#pragma omp parallel for num_threads(8)
// 		for (int i = 0; i < count; i++){
// 			int min = 0;
// 			for (int j = 0; j < count; j++){
// 				if (a[j] < a[i]){
// 					min++;
// 				}
// 			}
// 			out[min] = a[i];
// 		}
// }

int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}


int main(int argc, char **argv) {
    char *resposta[] = {"errada", "ok"};
    int *vector, *test, *out;
    int i, n, is_ok;
    double elapsed_q, start_q, end_q;
    double elapsed_s, start_s, end_s;

    if (argc < 2) {
        fprintf(stderr, "Uso: %s <número de elementos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);
    n *= 10e3;

    printf("Número de elementos: %d * 10E3\n", (int)(n / 10e3));
    vector = (int *)malloc(n * sizeof(int));
    out = (int *)malloc(n * sizeof(int));
    if (vector == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }

    test = (int *)malloc(n * sizeof(int));
    if (test == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    printf("Size Elementos: %d\n", n);

    for (i = 0; i < n; i++) {
        vector[i] = rand();
        test[i] = vector[i];
    }

    start_q = omp_get_wtime();
    qsort(test, n, sizeof(int), compare);
    end_q = omp_get_wtime();

    elapsed_q = end_q - start_q;

    start_s = omp_get_wtime();
    // selection_sort(vector, n);
    parallel_selection_sort(vector, n);
    // omp_selection_sort(vector,  n);

    printf("\n");
    for (int i = 0; i < 20; i++)
        printf("%d ", test[i]);
    printf("\n");

    for (int i = 0; i < 20; i++)
        printf("%d ", vector[i]);
    printf("\n");

    end_s = omp_get_wtime();

    elapsed_s = end_s - start_s;

    is_ok = (memcmp(vector, test, n * sizeof(int)) == 0);

    printf("A ordenação de valores está %s\nq_time: %.3f seconds\ns_time: %.3f seconds\n", resposta[is_ok], elapsed_q, elapsed_s);

    free(vector);
    free(test);

    return 0;
}
