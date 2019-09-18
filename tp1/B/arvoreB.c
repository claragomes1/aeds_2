#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


#define M 2
#define MM 4

using namespace std;

typedef long TipoChave;

typedef struct TipoItem {
	int Chave;
	long int dado1;
	char dado2[1000];
	// outros componentes
} TipoItem;

typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina {
	short n;
	TipoItem r[MM]; // tem que ter o define do MM antes???
	TipoApontador p[MM+1];
} TipoPagina;

TipoItem* inicializaChave(int chave){
	TipoItem* i = new TipoItem;
	i->Chave = chave;
	return i; 
}

TipoApontador inicializa(){
	TipoApontador Arvore = NULL;
	return Arvore;
}

int pesquisa(TipoItem* x, TipoApontador Ap){
	long i = 1;
	if ( Ap != NULL ){
		// pesquisa sequencial para se encontrar o intervalo desejado
		while ( i < Ap->n && x->Chave > Ap->r[i-1].Chave ) i++;
		if ( x->Chave == Ap->r[i-1].Chave ){ // verifica se a Chave desejada foi localizada
			*x = Ap->r[i-1];
			return 1;
		}

		// ativação recursiva da pesquisa em uma das subárvores (esquerda ou direita)
		if ( x->Chave < Ap->r[i-1].Chave )
			pesquisa(x, Ap->p[i-1]);
		else
			pesquisa(x, Ap->p[i]);
	} // se ap == null, significa que a página em questão está vazia
		printf("O item não está presente na árvore\n");
		return 0;
}

void insereNaPagina(TipoApontador Ap, TipoItem Reg, TipoApontador ApDir){
	int k;
	k = Ap->n;
	while ( k > 0 ) { // enquanto não achar a posição
		if ( Reg.Chave >= Ap->r[k-1].Chave ){
			k = -1;
		} else {
			Ap->r[k] = Ap->r[k-1];
			Ap->p[k+1] = Ap->p[k];
			k--;
		}
	}
	Ap->r[k] = Reg;
	Ap->p[k+1] = ApDir;
	Ap->n++;
}

void Ins(TipoItem Reg, TipoApontador Ap, bool* Cresceu, TipoItem *RegRetorno, TipoApontador* ApRetorno){
	long i = 1;
	long j;
	TipoApontador ApTemp;
	if ( Ap == NULL ){
		*Cresceu = true;
		*RegRetorno = Reg;
		*ApRetorno = NULL;
		return;
	}
	while ( i < Ap->n && Reg.Chave > Ap->r[i-1].Chave ) i++;
	if ( Reg.Chave == Ap->r[i-1].Chave ){
		printf("Erro: Registro já está presente\n");
		*Cresceu = false;
		return;
	}
	if ( Reg.Chave < Ap->r[i-1].Chave ) i--;
	Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);
	if ( ! *Cresceu ) return;
	if ( Ap->n < MM ){ // indica que ainda há espaço na página
		insereNaPagina(Ap, *RegRetorno, *ApRetorno);
		*Cresceu = false;
		return;
	}
	// OVERFLOW: a página tem que ser dividida
	ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
	ApTemp->n = 0;
	ApTemp->p[0] = NULL;
	if ( i < M + 1 ){
		insereNaPagina(ApTemp, Ap->r[MM-1], Ap->p[MM]);
		Ap->n--;
		insereNaPagina(Ap, *RegRetorno, *ApRetorno);
	}
	else insereNaPagina(ApTemp, *RegRetorno, *ApRetorno);
	for ( j = M + 2 ; j < MM ; j++ )
		insereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j]);
	Ap->n = M;
	ApTemp->p[0] = Ap->p[M+1];
	*RegRetorno = Ap->r[M];
	*ApRetorno = ApTemp;
}

int main (){

	FILE* bin;
	TipoItem item;
	
	if((bin = fopen("arqBin.bin", "rb")) == NULL){
		puts("Arquivo não pode ser aberto!\n");
		exit(1);
	}
	
	cout << 1;
	TipoApontador Arvore = inicializa();
	cout << 1;
	bool c = false;
	TipoItem* rr = NULL;
	TipoApontador* apR = NULL;
	rewind(bin);
	while(fread(&item, sizeof(TipoItem), 1, bin) == 1){
	    cout << 5;
	   // Ins(item, Arvore, &c, rr, apR);
  	}
  	cout << 6;

  	int chave;
  	cin >> chave;

  	TipoItem* i = inicializaChave(chave);

	if(pesquisa(i, Arvore))
	    printf("Item %s (codigo %d) foi localizdo\n", item.dado2, item.Chave);
	else
		printf("Item de codigo %d nao foi localizdo\n", item.Chave);

	fclose(bin);

	return 0;
}