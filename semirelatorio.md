- Que Estrutura(s) de Dados foi(ram) escolhida(s) para modelar o problema?
- Justifique.
Foi utilizado um array estático do tamanho do número de cidades para armazenar os vértices e uma lista simplesmente encadeada para o armazenamento das informações referentes as arestas de cada vértice
Sua utilização se justifica por conta de sua capacidade de crescimento não estático, o que possibilita a adição de arestas adicionais

- Quais vantagens e limitações a(s) estrutura(s) escolhida(s) apresenta(m)?
A vantagem do array é a possibilidade de acessar diretamente uma cidade e verificar suas arestas.
A vantagem da lista é a facilidade no seu processo de inserção.
A maior desvantagem da lista para esse problema é que para um vértice com um grande número de arestas, o algoritmo de pesquisa se torna consideravelmente lento.

- Explique claramente a lógica utilizada para resolver o problema.
Para resolvermos o problema, modelamos o gráfico utilizando um array e uma lista de adjacencias, em sequência geramos um caminho
padrão para n vértices: 1 - 2 .. - n e permutamos suas posições assim gerando uma nova rota. Para cada trajeto gerado calculamos
a distância total da rota e comparamos e atualizamos o mínimo global e o melhor caminho.


