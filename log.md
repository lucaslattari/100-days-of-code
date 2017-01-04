Dia 1: 30 de Dezembro de 2016

>Progresso do dia:

Comecei a escrever um conjunto de algoritmos de ordenação para serem usados como conteúdo complementar para a disciplina de Algoritmos e Estruturas de Dados 3. Estes são: BubbleSort, SelectionSort e InsertionSort.

Além disso, inclui uma série de funções extras que permitem analisar melhor estes algoritmos e compará-los: uma função que gera um vetor aleatório de inteiros com tamanho passado por parâmetro, além de outra para calcular o tempo que levou para a execução de cada algoritmo e, finalmente, quantas iterações e trocas entre posições do vetor que cada algoritmo realizou.

Com isso, ficaria mais fácil entender a eficiência de cada um deles. Está bem simples pra qualquer pessoa entender e executá-los. Basta abrir o projeto que foi criado no IDE CodeBlocks, em C/C++.

>Conclusões:

Não foi exatamente difícil, mas considero um bom aquecimento. Foi curioso ver como é possível perder prática de programação quando não se programa continuamente.

Tive a ideia de construir uma classe abstrata "AbstractSort" que fosse estendida por classe referente a cada algoritmo de ordenação, mas temo que isso confunda os alunos do terceiro período. Por enquanto, melhor simplificar.

Templates em C++ (Programação Genérica) também é uma ideia que pode ficar pro futuro.

Espero em breve trabalhar com outros algoritmos mais complexos, como os que envolvem árvores de dados, grafos, programação dinâmica etc. No entanto, pretendo priorizar os algoritmos da disciplina de AEDS 3.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 2: 31 de Dezembro de 2016

>Progresso do dia:

Dei continuidade ao conjunto de algoritmos de ordenação que tenho escrito. Dessa vez fiz versões do MergeSort e QuickSort. 

Diferente do dia anterior, dessa vez perdi mais tempo corrigindo bugs. No entanto, consegui resolvê-los hoje ainda.

>Conclusões:

Essa dificuldade gradativa está sendo positiva. No entanto, hoje foi bem mais corrido do que o habitual. Acredito que amanhã será mais ainda.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 3: 2 de Janeiro de 2017

>Progresso do dia:

Perdi um dia, mas consegui dar continuidade hoje. Adicionei um método que carrega um conjunto de dados numéricos via arquivo de texto. Função bem simples, porém que se adapta ao total de dados inseridos, sem precisar informar novo tamanho do vetor.

Além disso, também implementei uma versão eficaz do HeapSort. Este e os demais algoritmos que implementei baseiam-se no livro do Sedgewick (https://www.amazon.com.br/Algorithms-Robert-Sedgewick-ebook/dp/B004P8J1NA/ref=sr_1_1?ie=UTF8&qid=1483411660&sr=8-1&keywords=sedgewick)

Finalmente, corrigi alguns bugs bobinhos de desalocação de memória e comecei a implementar uma árvore binária de busca usando orientação a objetos do C++.

>Conclusões:

Perdi mais tempo do que esperava no HeapSort, mas funcionou sem nenhum problema. Tive a impressão do livro do Sedgewick ser meio "confuso" nessa parte. 

Testei todos os algoritmos que implementei com vetores de 200 mil elementos e verifiquei que o QuickSort a ordena em 0.037 segundos. Muito melhor do que o BubbleSort, que demora quase 5 minutos =)

E agora vamos para as árvores!
