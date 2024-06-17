#include <time.h>
#include <stdio.h>
#include <stdlib.h>



void merge(int v[], int inicio, int meio, int fim){
    int i = inicio, j = meio + 1, k = inicio;
    int vaux[fim - inicio + 1]; 

    while(i <= meio && j <= fim){
        if(v[i] <= v[j]){
            vaux[k - inicio] = v[i];
            i++;
        }else{
            vaux[k - inicio] = v[j];
            j++;
        }
    k++;
    } 
    while (i <= meio){
        vaux[k - inicio] = v[i];
        i++;
        k++;
    }

    while (j <= fim){
        vaux[k - inicio] = v[j];
        j++;
        k++;
    }

    
    for (int i = inicio; i <= fim; i++){
        v[i] = vaux[i - inicio];
    }
}

void mergeSort(int v[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

int main(){
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    int *v = (int*) malloc(sizeof(int) * n);

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        v[i]= rand()%10000;
    }
    mergeSort(v, 0, n - 1);


    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}