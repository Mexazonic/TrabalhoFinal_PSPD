void selection_sort(int *v, int n) {
    int i, j, min, tmp;

    #pragma omp parallel for private(i, j, min, tmp) shared(v, n)
    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }

        tmp = v[i];
        v[i] = v[min];
        v[min] = tmp;
    }
}

int main(){

	return 0;
}
