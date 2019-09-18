#include <iostream>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

typedef struct{
    int num;
    char cod;
    int qtd;
    float valor;
}Registro;

float saldo(char cod, int qtd, float valor){
    float saldo = 0;
    if(cod == 'V'){
        return saldo+(qtd*valor);
    }
    else{
        return saldo-(qtd*valor);
    }
}


int main(){

    Registro reg;
    char opc;
    int cliente;

    FILE* arq = fopen("boleta.bin", "w+b");
    if(arq == NULL){
        cout << "Erro na abertura do arquivo..." << endl;
        exit(1);
    }

    FILE* arqTexto = fopen("result.txt", "w+");
    if(arqTexto == NULL){
        cout << "Erro na abertura do arquivo texto..." << endl;
        exit(1);
    }

    do{
        cout << "Numero do cliente: "; cin >> reg.num;
        cout << "Operação: "; cin >> reg.cod;
        cout << "Quant titulos: "; cin >> reg.qtd;
        cout << "Valor titulo: "; cin >> reg.valor;
        fwrite(&reg, sizeof(reg), 1, arq);
        cout << "S ou N?" << endl;
        cin >> opc;

    }while(toupper(opc) == 'S');

    cliente = reg.num;
    float s = 0;
    char tipo;
    rewind(arq);

    while(fread(&reg, sizeof(reg), 1, arq) == 1){
        cout << reg.num << endl;
        cout << cliente << endl;
        if(cliente == reg.num){
            s += saldo(reg.cod, reg.qtd, reg.valor); 
            if( s > 0) tipo = 'D';
            else tipo = 'C';
            fprintf(arqTexto, "%1-14d%f%c ", reg.num, s, tipo);
            fflush(stdout);
        }
        else{
            s = 0;
            cliente = reg.num;
        }
    }

    fclose(arq);
    fclose(arqTexto);

    return 0;
}