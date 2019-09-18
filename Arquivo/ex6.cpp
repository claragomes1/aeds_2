#include <bits/stdc++.h>

using namespace std;

struct Participante {
  char sexo, fumante;
  int idade;
};

int main (){

  Participante* p = new Participante[50];
  FILE* arquivo = fopen("numeros.bin", "w+b");
  char opcao;

  if ((arquivo = fopen("numeros.bin","wb")) == NULL){
    cout << "Erro na criação do arquivo\n";
    return 0;
  }

  do {
    cin >> p[cont].sexo >> p[cont].fumante >> p[cont].idade;
    fwrite(&p, sizeof(p), 1, arquivo);

  } while (toupper(opcao) == 'S');

  delete p;
  fclose(arquivo);

  return 0;
}
