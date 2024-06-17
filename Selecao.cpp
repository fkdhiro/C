#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp; 
}

int ordenacao_selecao(int arr[], int tamanho, int *comparacoes){
    int indice_min;
    *comparacoes = 0;
    for(int i = 0; i < tamanho - 1; i++){
        indice_min = i;
        for(int j = i + 1; j < tamanho; j++){
            if(arr[j] < arr[indice_min]){
                indice_min = j;
                (*comparacoes)++;
            }
        }
        troca(arr, i, indice_min);
    }
    return 0;
}

int main(int argc, char **argv){
    int tamanho = atoi(argv[1]);
    int *arr = (int*) malloc(sizeof(int) * tamanho);
    int comparacoes;
    for(int i = 0; i < tamanho; i++){
        arr[i] = rand() % 10000;
    }

    clock_t inicio = clock();
    ordenacao_selecao(arr, tamanho, &comparacoes);
    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Total de comparacoes: %d\n", comparacoes);
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);

		printf("Array ordenado:\n");
	    for(int i = 0; i < tamanho; i++)
  		printf("%d\t", arr[i]);

    free(arr);
    return 0;
}
