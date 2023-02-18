## Questão 05

Para execução basta digitar
```bash
    make
    make run N=5

```
Este é um programa em linguagem C que realiza a ordenação de um vetor de inteiros usando o algoritmo selection sort e o algoritmo qsort da biblioteca padrão da linguagem.

Primeiro ocorre a inclusão das bibliotecas stdio.h, stdlib.h, string.h, time.h e omp.h. A Declaração da função selection_sort, que recebe um ponteiro para um vetor de inteiros e o número de elementos do vetor, e realiza a ordenação do vetor usando o algoritmo selection sort e de semlhante forma a declaração da função ompsort, que recebe um ponteiro para um vetor de inteiros, um ponteiro para um vetor de saída e o número de elementos do vetor, e realiza a ordenação do vetor usando o algoritmo selection sort em paralelo usando OpenMP.
Aloca memória para os vetores de entrada (vector) e de saída (out), ambos com tamanho n e a loca memória para um vetor de teste (test) com tamanho n.
Preenche o vetor vector com números inteiros aleatórios usando a função rand(). Copia o conteúdo do vetor vector para o vetor test.
Chama a função qsort para ordenar o vetor test em ordem crescente e mede o tempo de execução. Chama a função ompsort para ordenar o vetor vector em ordem crescente usando OpenMP e mede o tempo de execução. Exibe os primeiros 20 elementos do vetor test e do vetor out para verificar se a ordenação foi feita corretamentee compara o conteúdo dos vetores test e out para verificar se a ordenação foi feita corretamente.
Exibe uma mensagem indicando se a ordenação foi feita corretamente e os tempos de execução do qsort e do ompsort, e por fim, libera a memória alocada para os vetores.
