#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

int contagemSelection = 0;
int contagemQuick = 0;
int contagemHeap = 0;
unsigned long long int contagemBubble = 0;


void Swap(int *n1, int *n2){
    int aux;

    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}



void selection_sort(int num[], int tam) {
    int i, j, Min, aux;
    for (i = 0; i < (tam-1); i++){
        Min = i;

        for (j = (i+1); j < tam; j++) {
            if(num[j] < num[Min]){
                Min = j;

                contagemSelection++;
            }
        }

        if (num[i] != num[Min]) {
            aux = num[i];
            num[i] = num[Min];
            num[Min] = aux;
        }
    }
}



void selection_sort_inverso(int num[], int tam) {
    int i, j, Max, aux;
    for (i = 0; i < (tam-1); i++){
        Max = i;

        for (j = (i+1); j < tam; j++) {
            if(num[j] > num[Max]){ //
                Max = j;

                contagemSelection++;
            }
        }

        if (num[i] != num[Max]) {
            aux = num[i];
            num[i] = num[Max];
            num[Max] = aux;
        }
    }
}



void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;

                contagemBubble++;

            }
        }
    }
}



void bubble_sort_inverso (int vetor[], int n) {
    int k, j, aux;

    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {

            if (vetor[j] < vetor[j + 1]) { //
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;

                contagemBubble++;
            }
        }
    }
}



void quick_sort(int vetor[], int inicio, int fim){

    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = vetor[meio];

    do{
        while (vetor[i] < pivo){
            i = i + 1;
            contagemQuick++;
        }

        while (vetor[j] > pivo){
            j = j - 1;
            contagemQuick++;
        }

        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }

    }while(j > i);

    if(inicio < j) quick_sort(vetor, inicio, j);
    if(i < fim) quick_sort(vetor, i, fim);
}



void quick_sort_inverso(int vetor[], int inicio, int fim){

    int pivo, aux, i, j, meio;

    i = inicio;
    j = fim;

    meio = (int) ((i + j) / 2);
    pivo = vetor[meio];

    do{
        while (vetor[i] > pivo){ //
            i = i + 1;
            contagemQuick++;
        }

        while (vetor[j] < pivo){ //
            j = j - 1;
            contagemQuick++;
        }

        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }

    }while(j > i);

    if(inicio < j) quick_sort_inverso(vetor, inicio, j);
    if(i < fim) quick_sort_inverso(vetor, i, fim);
}



void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]){ //
        largest = l;
        contagemHeap++;
    }

    if (r < n && arr[r] > arr[largest]){ //
        largest = r;
        contagemHeap++;
    }

    if (largest != i){
        Swap(&(arr[i]), &(arr[largest]));
        contagemHeap++;
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n){

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--){
        Swap(&(arr[0]), &(arr[i]));
        heapify(arr, i, 0);
    }
}



void heapify_inverso(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[largest]){ //
        largest = l;
        contagemHeap++;
    }

    if (r < n && arr[r] < arr[largest]){ //
        largest = r;
        contagemHeap++;
    }

    if (largest != i){
        Swap(&(arr[i]), &(arr[largest]));
        contagemHeap++;
        heapify(arr, n, largest);
    }
}
void heap_sort_inverso(int arr[], int n){

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_inverso(arr, n, i);

    for (int i=n-1; i>=0; i--){
        Swap(&(arr[0]), &(arr[i]));
        heapify_inverso(arr, i, 0);
    }
}



int* criarVetor(int tam){
    int i;

    int* vetor = (int*) malloc (sizeof(int)*tam);

    for(i = 0; i < tam; i++){
        vetor[i] = rand()%tam;
    }

    return vetor;
}



int main(){

    srand(time(NULL));

    int* vetor10 = criarVetor(10);
    int* vetor100 = criarVetor(100);
    int* vetor1000 = criarVetor(1000);
    int* vetor10000 = criarVetor(10000);
    int* vetor100000 = criarVetor(100000);

    int i;

    contagemQuick = 0;
    quick_sort(vetor10, 0, 10);
    printf("\n%d", contagemQuick);

    contagemQuick = 0;
    quick_sort(vetor100, 0, 100);
    printf("\n%d", contagemQuick);

    contagemQuick = 0;
    quick_sort(vetor1000, 0, 1000);
    printf("\n%d", contagemQuick);

    contagemQuick = 0;
    quick_sort(vetor10000, 0, 10000);
    printf("\n%d", contagemQuick);

    contagemQuick = 0;
    quick_sort(vetor100000, 0, 100000);
    printf("\n%u", contagemQuick );

    return 0;
}
