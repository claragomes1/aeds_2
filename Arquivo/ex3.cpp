#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	FILE* arquivo = fopen("temperatura.txt", "w+b");
	float temp, menor, maior, media = 0;
	int diasMaior = 0, diasMenor = 0;
	
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		fprintf(arquivo, "%f\n",temp);
		fscanf(arquivo, "%f\n", temp);
		media += temp;

		if ( i == 0 ){
		 menor = temp;
		 maior = temp;
		} else if(temp < menor){
			menor = temp;
		} else if (temp > maior){
			maior = temp;
		}
	}

	media = media/4;

	for (int i = 0; i < 4; i++) {
		rewind(arquivo);
		fscanf(arquivo, "%f\n", temp);
		
		if(temp < media){
			diasMenor++;
		} else if(temp > media){
			diasMaior++;
		}
	}

	cout << "MENOR = " << menor << endl;
	cout << "MAIOR = " << maior << endl;
	cout << "MEDIA = " << media << endl;
	cout << "DIAS MAIOR = " << diasMaior << endl;
	cout << "DIAS MENOR = " << diasMenor << endl;

	fclose(arquivo);

	return 0;
}