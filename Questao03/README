## Questão 03
Para executar
```shell
    make
    make run V_THREADS=8 N_FRACTAL=1000
```

Este é um código em linguagem C que gera uma imagem do conjunto de Julia, usando paralelismo com OpenMP.

O código começa com a definição de algumas bibliotecas e a declaração de algumas constantes e variáveis. Em seguida, o programa verifica se foi fornecido um argumento na linha de comando. Esse argumento é o tamanho da imagem que será gerada. Se não houver um argumento ou o valor do argumento for menor que 1, o programa termina. Caso contrário, a variável n recebe o valor do argumento e um arquivo de saída é aberto.

A partir daí, o programa calcula a altura e a largura da imagem, e escreve o cabeçalho de um arquivo BMP no arquivo de saída.

Agora começa a parte paralela do código. A diretiva #pragma omp parallel for inicia um loop paralelo que é dividido em iterações que são executadas em paralelo por várias threads. Cada iteração é responsável por gerar uma linha de pixels da imagem.

Dentro do loop paralelo, a função omp_julia é chamada para gerar a linha de pixels. Esta função recebe um array de pixels, a altura da imagem e o número da linha que deve ser gerada. A função omp_julia usa a função compute_julia_pixel da biblioteca lib_julia.h para gerar cada pixel da linha.

Após gerar a linha de pixels, a função pwrite é usada para escrever a linha de pixels no arquivo de saída. A variável offset é usada para especificar onde a linha deve ser escrita no arquivo. A função pwrite escreve os dados de maneira assíncrona, o que significa que várias threads podem escrever no arquivo ao mesmo tempo sem interferir uma na outra.

A variável thistograma é usada para contar quantas linhas cada thread gerou. Isso é feito para verificar se cada thread está realmente gerando uma quantidade semelhante de trabalho.

Finalmente, depois que o loop paralelo termina, o arquivo de saída é fechado e o programa termina.

