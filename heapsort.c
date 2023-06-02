#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX 1000000

// Função para construir o Heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior como raiz
    int l = 2 * i + 1; // Esquerda = 2*i + 1
    int r = 2 * i + 2; // Direita = 2*i + 2
 
    // Se o filho esquerdo for maior que a raiz
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // Se o filho direito for maior que a raiz
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // Se o maior não é a raiz
    if (largest != i) {
        // Troca a raiz pelo maior elemento
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        // Chama a função recursivamente no sub-heap afetado
        heapify(arr, n, largest);
    }
}

// Função para ordenar o array utilizando o HeapSort
void heapSort(int arr[], int n) {
    // Constrói o Heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Extrai um por um os elementos do Heap
    for (int i = n - 1; i > 0; i--) {
        // Move o atual elemento raiz para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        // Chama a função heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função para capturar e mostrar o tempo de execução em segundos
void printElapsedTime(struct timeval start, struct timeval end) {
    long int elapsed_time_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    printf("Tempo de execução: %ld microssegundos\n", elapsed_time_us);
}

int main() {
    int arr[MAX], n;
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    printf("Digite o número de elementos a serem ordenados (no máximo %d): ", MAX);
    scanf("%d", &n);

    // Preenche o array com números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    printf("////////////Array desordenado////////////\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Captura o tempo de execução antes de chamar a função de ordenação
    struct timeval start, end;
    gettimeofday(&start, NULL);

    heapSort(arr, n); // Chama a função de ordenação

    // Captura o tempo de execução depois de chamar a função de ordenação
    gettimeofday(&end, NULL);

    printf("////////////Array ordenado////////////\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printElapsedTime(start, end);
}