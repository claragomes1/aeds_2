#include <bits/stdc++.h>

using namespace std;

struct Aluno {
  string matricula, nome;
  double n1, n2, n3, media;
};

int main (){
  Aluno* a = new Aluno[2];
  FILE* arquivo = fopen("arquivo.bin", "w+b");
  for ( int i = 0 ; i < 2 ; i ++ ){
    cin >> a[i].matricula >> a[i].nome >> a[i].n1 >> a[i].n2 >> a[i].n3;
    fwrite(&a, sizeof(a), 1, arquivo);
  }

  for ( int i = 0 ; i < 2 ; i ++ ){
    fread(&a, sizeof(a), 1, arquivo);
    a[i].media = (a[i].n1 + a[i].n2 + a[i].n3) / 3;
    cout << "MEDIA: " << a[i].media << endl;

    if ( a[i].media >= 8.5 ) cout << "Excelente" << endl;
    else if ( a[i].media >= 7 && a[i].media < 8.5 ) cout << "Bom" << endl;
    else cout << "Preocupante" << endl;
  }

  fclose(arquivo);

  return 0;
}
