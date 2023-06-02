#include <stdio.h>
#include <stdlib.h>

// Função para fazer a junção de duas sub-listas ordenadas em uma lista ordenada
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criando as duas sub-listas
    int L[n1], R[n2];

    // Copiando os elementos das duas metades em sub-listas temporárias
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclando as sub-listas temporárias novamente na lista original
    i = 0; // Índice inicial da primeira sub-lista
    j = 0; // Índice inicial da segunda sub-lista
    k = l; // Índice inicial da lista mesclada
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes da sub-lista L, se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes da sub-lista R, se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para realizar o merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontrando o ponto médio para dividir a lista em duas metades
        int m = l + (r - l) / 2;

        // Recursivamente classificando a primeira e a segunda metade da lista
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclando as duas metades classificadas
        merge(arr, l, m, r);
    }
}

// Função para imprimir a lista
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar o Merge Sort
int main() {
    int arr[10000], i, n;

    // Lendo o número de elementos
    printf("Entre com o número de elementos:\n");
    scanf("%d", &n);

    // Lendo os elementos da lista
    printf("Entre com os elementos:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Classificando a lista usando o Merge Sort
    mergeSort(arr, 0, n - 1);

    // Imprimindo a lista classificada
    printf("Lista ordenada:\n");
    printArray(arr, n);
    return 0;
}