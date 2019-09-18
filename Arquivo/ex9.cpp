#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct {
    int conta[5];
    char nome[40];
    float saldo;
}registro;

int main(){

    char opc, tipoMov;
    registro r;
    int cont;

    FILE* arq = fopen("contas.bin", "w+b");
    if(arq == NULL){
        cout << "Problemas na abertura do arquivo..." << endl;
        exit(1);
    }

    FILE* arq2 = fopen("moviment.bin", "w+b");
    if(arq2 == NULL){
        cout << "Problemas na abertura do arquivo 2 ..." << endl;
        exit(1);
    }

    do{
        cout << "Conta : " ; cin >> r.conta[0] >> r.conta[1] >> r.conta[2] >> r.conta[3] >> r.conta[4];
        cout << "Nome : "; cin.getline(r.nome, 40);
        cout << "Saldo : "; cin >> r.saldo;
        cout <<"ADD CONTA ? " ; cin >> opc;
        fprintf(arq, "%d %s %f", r.conta, r.nome, r.saldo);
    }while(toupper(opc) == 'S');

    cout << "Movimentaçoes..." << endl;

    do{
        cout << "Conta : " ; cin >> cont;
        cout << "Tipo mov : "; cin >> tipoMov;
        cout << "ADD TRANSAÇÂO? "; cin >> opc;
        fprintf(arq2, "%d %f", cont, tipoMov);
    }while(toupper(opc) == 'S');



    return 0;
}