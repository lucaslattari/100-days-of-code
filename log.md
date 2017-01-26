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

Testei todos os algoritmos que implementei com vetores de 200 mil elementos e verifiquei que o QuickSort os ordena em 0.037 segundos. Muito melhor do que o BubbleSort, que demora quase 5 minutos =)

E agora vamos para as árvores!

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 4: 3 de Janeiro de 2017

>Progresso do dia:

Dessa vez decidi programar algo diferente dos dias anteriores. Planejei "brincar" um pouco com TensorFlow e Python. No entanto, acabei precisando fazer uma série de atualizações no Linux Mint e preparar o ambiente para isso. Enquanto esperava, decidi mexer com um projeto antigo: brincar com o código-fonte do Quake 3 Arena.

Comecei do começo: criando uma série de classes que fazem a leitura do formato de arquivo .BSP, bem como um conjunto de estrutura de dados que armazenarão as informações gráficas e de informações dos mapas.

O código que fiz hoje já carrega parte do arquivo, funcionando sem problemas (ao menos pros poucos testes que fiz =P)

>Conclusões:

Achei que seria interessante mudar um pouco em relação aos códigos anteriores, e de fato foi positivo. Relembrei boa parte do formato de arquivo do Quake 3 Arena, e espero mexer logo com OpenGL e com a renderização dos mapas propriamente ditos.

Também foi interessante ter noção do TensorFlow e de como se monta seu ambiente. Em breve pretendo mexer com ele também!

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 5: 4 de Janeiro de 2017

>Progresso do dia:

Senti que meu progresso não foi tão bom assim =( continuei trabalhando em classes para fazer leitura e escrita de informações contidas em arquivos .BSP e notei que seria importante criar uma classe Lump usando Programação Genérica (Templates). Fiz e por enquanto não funcionou... Bora continuar tentando!

>Conclusões:

Acho que é assim mesmo, tem dias que se rende bastante com código e em outros nem tanto. No entanto, foi bom mexer com Templates e relembrar como eles funcionam.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 6: 5 de Janeiro de 2017

>Progresso do dia:

Agora sim! Consegui corrigir bugs e fazer funcionar meu parser de informaçõex extraídas dos arquivos de mapas do Quake 3! Sem falar que ele imprime um log em arquivos de texto pra mostrar que tudo está sendo carregado corretamente. Cada lump é representado como um vetor de templates, o que realmente economiza muito esforço de código. Espero terminar esse parser amanhã.

>Conclusões:

Consegui adiantar o que eu havia iniciado ontem e aprender muito mais sobre programação genérica em C++. Espero começar a mexer com OpenGL logo!

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 7: 9 de Janeiro de 2017

>Progresso do dia:

Fiquei uns dias sem mexer =( No entanto, retornei estudando bastante TensorFlow. Fiz uma série de códigos introdutórios seguindo os conceitos do livro "Getting Started with TensorFlow"

>Conclusões:

Foi interessante começar a ter noções dessa importante biblioteca do Google. Parece um bom caminho para mexer com Deep Learning.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 8: 10 de Janeiro de 2017

>Progresso do dia:

Fiz uma série de códigos do capítulo 2 do livro "Getting Started with TensorFlow" (basicamente uma revisão sobre operações matemáticas avançadas em Python) e implementei parte de uma árvore binária de busca em C++.

>Conclusões:

Dei continuidade a uma série de aprendizados! Amanhã será interessante, principalmente por mexer com Machine Learning mesmo.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 9: 11 de Janeiro de 2017

>Progresso do dia:

Muito progresso! Consegui implementar todas as principais funções de Binary Search Trees em C++ e toda a parte introdutória de Machine Learning do livro "Getting Started with TensorFlow".

>Conclusões:

Visivelmente rendi mais hoje do que ontem. Amanhã teremos redes neurais e talvez a famigerada árvore rubro-negra...

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 10: 12 de Janeiro de 2017

>Progresso do dia:

Dessa vez implementei apenas a inserção da árvore rubro-negra... Fiquei muito tempo tentando arrumar o código, bugs e fazer uma herança com a classe de Árvore Binária de Busca. O ideal talvez seria usar classe abstrata, mas está bom por hoje. Outro fato intrigante é que aparentemente o pseudocódigo do Sedgewick parecia ter um erro. Precisei adicionar uma verificação a mais pra funcionar pra todos os casos. Inseri todas as letras do alfabeto (uma pra cada nó, totalizando 25 nós no meu teste definitivo), desenhei a árvore rubro-negra e assim conclui que todas as propriedades dela estavam sendo respeitadas.

>Conclusões:

Algo interessante da implementação que eu fiz é o fato dela ser diferente do usual. Tentei fazer uma série de melhorias em relação ao sugerido pelo Sedgewick, que simplesmente replicava o código de árvores binárias de busca com mais coisas. Gastei muito tempo verificando na mão o funcionamento dela.

Minha noção sobre esse assunto melhorou mais ainda. Próximo passo é implementar a exclusão de nós de árvore rubro-negra e tabelas hash.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 11: 19 de Janeiro de 2017

>Progresso do dia:

Quase terminei meu parser da BSP do Quake 3 =( No entanto, dessa vez é bem provável que eu termine amanhã.

>Conclusões:

Uns dias viajando me fizeram perder ritmo e progresso... Bom, tudo bem. De volta ao trabalho, quase acabando essa parte meio chata e braçal da BSP =)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 12: 20 de Janeiro de 2017

>Progresso do dia:

Terminei o parser de BSP! Não sei se funciona 100%, descobrirei com o tempo =P

>Conclusões:

Aliviado de ter terminado isso! Agora vem a parte boa, gráficos 3D e OpenGL =)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 13: 21 de Janeiro de 2017

>Progresso do dia:

Comecei a mexer com OpenGL. Realizei toda a configuração, comecei a implementar a câmera, mas acabei "perdendo tempo" estudando álgebra linear e computação gráfica para os próximos passos...

>Conclusões:

Foi bom revisar computação gráfica, mas falta muita coisa ainda.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Dia 14: 25 de Janeiro de 2017

>Progresso do dia:

Infelizmente não foi muito bom =/ tentei fazer uma câmera 3D FPS do zero, mas fazer isso em OpenGL moderno é menos fácil do que esperava... O jeito é estudar mais OpenGL moderno.

>Conclusões:

Está sendo produtivo, pois o OpenGL que eu sabia nem de hoje é o que se aplica atualmente...
