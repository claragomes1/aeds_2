#include <bits/stdc++.h>

using namespace std;

struct Participante {
  char sexo, fumante;
  int idade;
};

int main (){

  Participante* p = new Participante[50];
  FILE* arquivo = fopen("arquivo.bin", "w+b");
  char opcao;
  int cont1 = 0, cont2 = 0, cont3 = 0, cont = 0, contH = 0, contM = 0;

  if ((arquivo = fopen("livros.bin","wb")) == NULL){
    cout << "Erro na criação do arquivo\n";
    return 0;
  }

  do {
    cin >> p[cont].sexo >> p[cont].fumante >> p[cont].idade;
    fwrite(&p, sizeof(p), 1, arquivo);
    cout << "Adiciona outro participante (S/N)? ";
    cin >> opcao;
    cont++;
  } while (toupper(opcao) == 'S');

  for(int i = 0; i < cont; i++){
    fread(&p, sizeof(p), 1, arquivo);
    if (p[i].fumante == 'S' || p[i].fumante == 's')cont1++;
    else if((p[i].fumante == 'N' || p[i].fumante  == 'n')&& p[i].idade < 40 && p[i].sexo == 'M')cont2++;
    else if(p[i].sexo == 'F' && p[i].idade > 40 && p[i].fumante == 'S') cont3++;
    if(p[i].sexo == 'M') contH++;
    else contM++;

  }

  if( cont != 0 )cout << "1 - " << (cont1*100)/cont << " por cento" << endl;
  if( contH != 0 )cout << "2 - " << (cont2*100)/contH << " por cento" << endl;
  if( contM != 0 )cout << "3 - " << (cont3*100)/contM << " por cento" << endl;


  delete p;
  fclose(arquivo);

  return 0;
}
