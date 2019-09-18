#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[]) {

  FILE* arquivo;

  if((arquivo = fopen("votos.txt", "w+")) == NULL){
    puts ("Arquivo nao pode ser aberto...");
    exit(1);
  }

  char votos[10];


  for(int i=0; i<10; i++){
    cin >> votos[i];
    putc(votos[i],arquivo);
  }
  rewind(arquivo);

  int cont = 0, cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;
  char ch = getc(arquivo);


  while( ch != EOF){
    ch = getc(arquivo);
    if( ch == '1') cont1++;
    else if( ch == '2') cont2++;
    else if( ch == '3') cont3++;
    else if( ch == '4') cont4++;
    else if( ch == '5') cont5++;
    else cont++;
  }

  if(cont1 > cont2 && cont1 > cont3  && cont1 > cont4 && cont1 > cont5 && cont1 > cont )
    cout << "Maior é o 1 com " << cont1 << "votos" << endl;
  else if(cont2 > cont1 && cont2 > cont3  && cont2 > cont4 && cont2 > cont5 && cont2 > cont )
    cout << "Maior é o 2 com " << cont2 << "votos" << endl;
  else if(cont3 > cont1 && cont3 > cont2  && cont3 > cont4 && cont3 > cont5 && cont3 > cont )
    cout << "Maior é o 3 com " << cont3 << "votos" << endl;
  else if(cont4 > cont2 && cont4 > cont3  && cont4 > cont1 && cont4 > cont5 && cont4 > cont )
    cout << "Maior é o 4 com " << cont4 << "votos" << endl;
  else if(cont5 > cont2 && cont5 > cont3  && cont5 > cont4 && cont5 > cont1 && cont5 > cont )
    cout << "Maior é o 5 com " << cont5 << "votos" << endl;
  else if(cont > cont2 && cont > cont3  && cont > cont4 && cont > cont5 && cont > cont1 )
    cout << "Maior é NULO com " << cont << "votos" << endl;
  else
    cout << "EMPATE , NÂO TEMOS UM VENCEDOR " << endl;

    if(cont1 < cont2 && cont1 < cont3  && cont1 < cont4 && cont1 < cont5 && cont1 < cont )
      cout << "Menor é o 1 com " << cont1 << "votos" << endl;
    else if(cont2 < cont1 && cont2 < cont3  && cont2 < cont4 && cont2 < cont5 && cont2 < cont )
      cout << "Menor é o 2 com " << cont2 << "votos" << endl;
    else if(cont3 < cont1 && cont3 < cont2  && cont3 < cont4 && cont3 < cont5 && cont3 < cont )
      cout << "Menor é o 3 com " << cont3 << "votos" << endl;
    else if(cont4 < cont2 && cont4 < cont3  && cont4 < cont1 && cont4 < cont5 && cont4 < cont )
      cout << "Menor é o 4 com " << cont4 << "votos" << endl;
    else if(cont5 < cont2 && cont5 < cont3  && cont5 < cont4 && cont5 < cont1 && cont5 < cont )
      cout << "Menor é o 5 com " << cont5 << "votos" << endl;
    else if(cont < cont2 && cont < cont3  && cont < cont4 && cont < cont5 && cont < cont1 )
      cout << "Menor é NULO com " << cont << "votos" << endl;
    else
      cout << "EMPATE , NÂO TEMOS UM VENCEDOR " << endl;



      cout << "QUANTIDADE DE VOTOS NULOS: " << cont << endl;

      fclose(arquivo);








  return 0;
}
