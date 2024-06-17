#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaSequencial(unsigned long int x, int n, unsigned long int v[], int *contador){
	*contador=0;
	int i =0;
	while(i<n){
		*contador = *contador + 1;
		if(v[i] == x) return i;
		//else
		i++;
	}
	return i;
}

int buscaSequencialB(unsigned long int x, int n, unsigned long int v[], int *contador){
	*contador=0;
	int i =0;
	while(i<n && v[i] < x){
		*contador = *contador + 1;
		if(v[i] == x) return i;
		//else
		i++;
	}
	return i;
}

//int buscaSequencialB(unsigned long int x, int n, unsigned long int v[], int *contador){

//int buscaBinaria(unsigned long int x, int n, unsigned long int v[], int *contador){

int main(){
	srand(time(NULL));
	//CRIA O VETOR DE DADOS
	int MAX=1E5;
	unsigned long int v[MAX];
	for (int i=0; i<MAX; i++) v[i] = i;

 
	//FAZ A BUSCA SEQUENCIAL 1	
	int TESTES = 1000;
	int Ncomparacoes=0;	
	int posicao;
	float soma=0;
	for(int i=0; i<TESTES; i++){
		unsigned long int x = rand()%MAX; //gera um numero para procurar no vetor
		posicao = buscaSequencialB(x,MAX,v,&Ncomparacoes);
		soma = soma + Ncomparacoes;
	}
	printf("Média=%10.2f\n",(double)soma/TESTES);
}
