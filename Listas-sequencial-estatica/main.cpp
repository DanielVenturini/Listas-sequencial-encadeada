#include "Libraries.h"

void testeExercicios(int exercicio){
    cout << endl;

    switch (exercicio){
        case 1:
            {
            ListD *l1 = listDCreate();
            insertLast(l1, nodeCreate(2));
            insertLast(l1, nodeCreate(3));
            insertLast(l1, nodeCreate(5));
            insertLast(l1, nodeCreate(1));
            insertLast(l1, nodeCreate(7));
            insertLast(l1, nodeCreate(9));

            ListD *l2 = listDCreate();

            insertLast(l2, nodeCreate(2));
            insertLast(l2, nodeCreate(3));
            insertLast(l2, nodeCreate(5));
            insertLast(l2, nodeCreate(1));
            insertLast(l2, nodeCreate(7));
            insertLast(l2, nodeCreate(9));

            print(l1);
            print(l2);

            listJoin(l1, l2);

            print(l1);
            print(l2);
            break;
            }
        case 2:
            {
            ListD *l = listDCreate();
            insertLast(l, nodeCreate(2));
            insertLast(l, nodeCreate(3));
            insertLast(l, nodeCreate(5));
            insertLast(l, nodeCreate(1));
            insertLast(l, nodeCreate(7));
            insertLast(l, nodeCreate(9));
            Node *n = nodeCreate(0);
            n->next = l->first;
            insertLast(l, n);

            listFix(l);

            print(l);
            break;
            }
        case 3:
            {
                int v[] = {2, 3, 5, 1, 7, 9, 6, 2, 8, 5, 4};
                ListD* l = listFromArray(v, 11);

                print(l);
                break;
            }
        case 4:
            {
                ListS *l = listSCreate();

                insertLast(l, 2);
                insertLast(l, 3);
                insertLast(l, 5);
                insertLast(l, 1);
                insertLast(l, 7);
                insertLast(l, 8);

                ListS* l1 = cloneSorted(l);

                print(l1);
                break;
            }
        default:
            cout << "ERRO: Exercicio nao existe." << endl;
    }
}

int main(){

//    ListD *ld = listDCreate();
//
//    insertLast(ld, nodeCreate(2));
//    insertLast(ld, nodeCreate(3));
//    insertLast(ld, nodeCreate(5));
//    insertLast(ld, nodeCreate(1));
//    insertLast(ld, nodeCreate(7));
//    insertLast(ld, nodeCreate(9));
//
//    remove(ld, nodeCreate(3));
//
//    insertLast(ld, nodeCreate(8));
//
//    print(ld);


//    ListS *ls = listSCreate();
//
//    insertLast(ls, 2);
//    insertLast(ls, 3);
//    insertLast(ls, 5);
//    insertLast(ls, 1);
//    insertLast(ls, 7);
//    insertLast(ls, 9);
//
//    remove(ls, 3);
//
//    insertLast(ls, 8);
//
//    print(ls);

    int numExercicio;

    cout << "Digite o numero do exercicio: ";
    cin >> numExercicio;

    testeExercicios(numExercicio);  //funcao para testar os exercicios

    return 0;
}
