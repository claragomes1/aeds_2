#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct {
    int chave;
    char dado2[30];
    float dado3[4];
}Registro;

Remove_Item(arq*FILE, int chave);

int main(){

    Registro reg;
    char opc;

    FILE* arq = fopen("registro.bin", "w+b");

    if(arq == NULL){
        cout << "Erro na abertura do arquivo..." << endl;
        exit(1);
    }

    do{
        cout << "chave : "; cin >> reg.chave;
        cout << "dado2 : "; cin.getline(reg.dado2, 30);
        cout << "dado3 : "; cin >> dado3[0] >> dado3[1] >> dado3[2] >> dado3[3];
        fwrite(&reg, sizeof(reg), 1, arq);
        cout << "Deseja inserir mais algum registro? \n "; cin >> opc;
    }while(opc == 's' || opc == 'S');




}

Remove_Item(arq*FILE, int chave){

   Registro reg;
   
   while(fread(&reg) {
       
   }
}