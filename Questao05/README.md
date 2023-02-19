## Questão 05

Para execução basta digitar
```bash
    make
    make run N=20

```
Este é um programa em linguagem C que realiza a ordenação de um vetor de inteiros usando o algoritmo selection sort e o algoritmo qsort da biblioteca padrão da linguagem.

Este código implementa o selection sort, que ordena um array de inteiros em ordem decrescente. Ele também usa OpenMP para paralelizar o processo de encontrar o máximo valor em uma sub-sequência do array.

O algoritmo funciona da seguinte forma:

Para cada posição i do array de entrada, encontra-se o valor máximo na sub-sequência do array [0, i-1].
Em seguida, troca-se o valor na posição i com o valor máximo encontrado na sub-sequência [0, i-1].
O laço externo percorre o array da última posição até a segunda posição, enquanto o laço interno encontra o valor máximo na sub-sequência [0, i-1] para cada posição i do array.

O OpenMP é usado para paralelizar a busca do valor máximo na sub-sequência [0, i-1]. Temos que #pragma omp parallel for é usada para distribuir as iterações do laço interno entre vários threads. A cláusula reduction é usada para encontrar o máximo valor na sub-sequência de cada thread e, em seguida, combinar os resultados finais em um único valor máximo. A estrutura Compare é usada para armazenar o valor máximo e seu índice.

No geral, este algoritmo tem complexidade O(n^2) no pior caso, onde n é o tamanho do array de entrada. É importante notar que o uso do OpenMP pode melhorar o desempenho do algoritmo em sistemas com múltiplos núcleos de processamento.





