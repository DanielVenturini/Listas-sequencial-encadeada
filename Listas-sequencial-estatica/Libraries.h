#include <iostream>

using namespace std;

struct ListS {
    static const int MAX = 10;
    int size;
    int data[MAX];
};

struct Node {
    int e;
    Node* next;
};

struct ListD {
    Node* first;
};

/////////////////////////////////////////////////////////

ListS *listSCreate(){
    ListS *l = new ListS;
    l->size = 0;

    return l;
}

ListD *listDCreate(){
    ListD *l = new ListD;
    l->first = NULL;

    return l;
}

Node *nodeCreate(int e){
    Node *n = new Node;
    n->e = e;
    n->next = NULL;

    return n;
}

//////////////////////////////////////////////////////////////

void insertLast(ListD *l, Node *n){

    if(!l->first){
        l->first = n;
        return;
    }

    Node *nn = l->first;
    while(nn->next){
        nn = nn->next;
    }

    nn->next = n;
}

void insertLast(ListS *l, int e){

    if(l->size >= l->MAX){  //se a lista jah estiver cheia
        cout << "ERRO: Inserir elemento " << e << " em lista cheia." << endl;
        return;
    }

    l->data[l->size] = e;   //insere na ultima posicao valida, na qual se considera como valida a posicao do 'size'
    l->size ++;             //incrementa o size, dizendo que foi inserido mais um elemento
}

void remove(ListD *l){

    if(!l->first){      //se nao tiver nenhum elemento na lista
        cout << "ERRO: Removendo de lista vazia." << endl;
        return;
    }

    Node *n = l->first;
    Node *prev = NULL;
    while(n->next){     //percorrendo ate o ultimo
        prev = n;
        n = n->next;
    }

    if(!prev){          //se soh tiver um elemento na lista, o prev vai ser null
        l->first = NULL;
        return;
    }

    prev->next = NULL;  //removendo o ultimo
}

void remove(ListD *l, Node *n){

    if(!l->first){
        cout << "ERRO: Removendo de lista vazia." << endl;
        return;
    }

    Node *nn = l->first;
    Node *prev = NULL;
    while(n->e != nn->e){   //percorre enquanto nao achar o no para remover
        prev = nn;
        nn = nn->next;
    }

    prev->next = nn->next;  //anterior recebe o proximo do 'n', assim tirando o 'n' da lista
}

void remove(ListS *l){

    if(l->size == 0){
        cout << "ERRO: Removendo de lista vazia." << endl;
        return;
    }

    l->size --; //apenas decrementa o contador, assim a lista soh eh considerada valida de 0...size
}

void remove(ListS *l, int e){

    if(l->size == 0){
        cout << "ERRO: Removendo de lista vazia." << endl;
        return;
    }

    for(int i = 0; i < l->size; i ++){

        if(l->data[i] == e){

            while(i < l->size-1){
                l->data[i] = l->data[i+1];
                i ++;
            }

            l->size --;
            return;
        }
    }

    cout << "ERRO: Removendo da lista elemento inexistente." << endl;
}

void print(ListD *l){

    if(!l->first){
        cout << "ERRO: Imprimindo lista vazia." << endl;
        return;
    }

    cout << "Lista Dinamica." << endl;

    Node *n = l->first;
    while(n){
        cout << "{" << n->e << "} ";
        n = n->next;
    }
    cout << endl;
}

void print(ListS *l){

    if(l->size == 0){
        cout << "ERRO: Imprimindo lista vazia." << endl;
        return;
    }

    cout << "Lista Sequencial." << endl;

    for(int i = 0; i < l->size; i ++){
        cout << "[" << l->data[i] << "] ";
    }
    cout << endl;
}

void listJoin(ListD* l1, ListD* l2){

    if(!l1->first || !l2->first){   //verificando se uma das listas estao vazias
        cout << "ERRO: Concatenando uma das listas vazias.";
        return;
    }

    Node *n = l1->first;    //pega o primeiro elemento
    while(n->next){         //enquanto tiver proximo elemento
        n = n->next;
    }

    n->next = l2->first;    //quando nao tiver mais proximo, entao coloca o ponteiro do primeiro elemento da segunda lista

    l2->first = l1->first;  //a segunda lista agora esta apontando para a primeira
}

void listFix(ListD* l){

    if(!l->first){      //se a lista for vazia
        cout << "ERRO: Lista vazia." << endl;
        return;
    }

    Node *n = l->first;     //pega o proximo elemento depois do primeiro
    while(n->next->e != l->first->e){   //enquanto nao chegarmos no ultimo, o proximo do 'n' vai ser diferente do 'first'
        n = n->next;
    }

    n->next = NULL; //entao coloca NULL no proximo do ultimo
}

ListD* listFromArray(int v[], int n){

    if(n == 0){
        cout << "ERRO: Tentando criar uma lista a partir de um vetor nulo." << endl;
        return NULL;
    }

    ListD *l = listDCreate();
    for(int i = 0; i < n; i ++){
        Node *n = nodeCreate(v[i]);     //criando um novo elemento com o valor do vetor
        insertLast(l, n);               //inserindo o elemento
    }

    return l;
}

ListS* cloneSorted(ListS* l){

    if(l->size == 0){
        cout << "ERRO: Tentando criar uma lista a partir de uma nula." << endl;
        return NULL;
    }

    ListS *newList = listSCreate();
    for(int i = 0; i < l->size; i ++){  //percorrer para cada elemento

        int e = l->data[i]; //pega o elemento a ser adicionado na nova lista
        int j;

        for(j = i; j > 0; j --){    //enquanto o j for maior do que zero, ou seja, este eh o algoritmo de ordenacao insertion sort
            if(newList->data[j-1] > e){
                newList->data[j] = newList->data[j-1];
            } else {
                break;
            }
        }

        newList->data[j] = e;   //quando achamos a posicao do elemento 'e', soh falta inserir
        newList->size ++;       //e incrementa no 'size' da nova lista
    }

    return newList;             //retorna a nova lista
}
