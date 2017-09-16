# Listas-sequencial-encadeada

Relembrando os velhos tempos de Estrutura de Dados 1, a melhor materia do curso, resolvi em C ++ a primeira prova da materia.

Exercicios:

01) Escreva uma funcao que faz a juncao de duas Listas Encadeadas Dinamicas?. A função deve juntar a Lista 2 ao final da Lista 1. Ela nao posui retorno e deve alterar os ponteiros "first" das duas listas passadas de forma que apontem para a nova lista unica.

	Funcao: ?void listJoin(ListD* l1, ListD* l2);

	Exemplo:
	// antes? da juncao
	// lista1: first -> {5} -> {2} -> {3}
	// lista2: first -> {8} -> {4}
	
	listJoin(lista1, lista2);
	// apos? a juncao
	// lista1: first -> {5} -> {2} -> {3} -> {8} -> {4}
	// lista2: first -> {5} -> {2} -> {3} -> {8} -> {4}

02) Considere uma Lista Encadeada Dinamica ?defeituosa na qual o ultimo elemento esta apontando para o primeiro. Escreva uma funcao que a conserta, definindo corretamente o valor do campo Node::next do ultimo elemento para NULL.

	Funcao?: void listFix(ListD* list);

03) ?Escreva uma funcao que recebe um array de inteiros e devolve uma Lista Encadeada Dinamica contendo os mesmos valores (na mesma ordem). O array original nao ser alterado.

	Funcao?: ListD* listFromArray(int v[ ], int n);

04) ?Escreva uma funcao que recebe uma Lista Sequencial Estatica ?desordenada e devolve uma nova lista, com os elementos da primeira em ordem crescente. A lista original nao ser alterada.

	Funcao?: ListS* cloneSorted(ListS* list);

-------------------------------------------------------

ESTRUTURA DE DADOS

Lista Sequencial Estatica

struct ListS {
	static const int MAX = 10;
	int size;
	int data[MAX];
}
Lista Encadeada Dinamica

struct ListD {
	Node* first;
}

struct Node {
	int e;
	Node* next;
}