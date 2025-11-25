#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da BST
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

// Tamanho da árvore
int altura(No* raiz) {
    if (raiz == NULL) return 0;
    int es = altura(raiz->esq);
    int di = altura(raiz->dir);
    return (es > di ? es : di) + 1;
}

int bubbleSort(int vetor[], int tamanho) {
    int comparacoes = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            comparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    return comparacoes;
}

int selectionSort(int vetor[], int tamanho) {
    int comparacoes = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tamanho; j++) {
            comparacoes++;
            if (vetor[j] < vetor[min]) min = j;
        }
        int temp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = temp;
    }
    return comparacoes;
}

int insertionSort(int vetor[], int tamanho) {
    int comparacoes = 0;
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            comparacoes++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        if (j >= 0) comparacoes++;
        vetor[j + 1] = chave;
    }
    return comparacoes;
}

void mostrarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("\n");
}

// Programa Principal
int main() {
    char nomes[3][50] = {
        "Joao Henrique Cabral Mota da Silva",
        "Ernandes Alves Ferreira",
        "Gabriel Jose Ferreira da Silva"
    };
    char matriculas[3][15] = {
        "202408461267",
        "202408159821",
        "202408160178"
    };

    printf("Integrantes do grupo:\n");
    for (int i = 0; i < 3; i++)
        printf("%s - %s\n", nomes[i], matriculas[i]);

    int vetor[20];
    int copia[20];
    int num, repetido;

    srand(time(NULL));

    // Gerador
    for (int i = 0; i < 20;) {
        num = (rand() % 500) + 1;
        repetido = 0;
        for (int j = 0; j < i; j++) {
            if (vetor[j] == num) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            vetor[i] = num;
            i++;
        }
    }

    for (int i = 0; i < 20; i++) copia[i] = vetor[i];

    printf("\nVetor original:\n");
    mostrarVetor(vetor, 20);

    int compBubble, compSelection, compInsertion;
    int vetorBubble[20], vetorSelection[20], vetorInsertion[20];
    for (int i = 0; i < 20; i++) {
        vetorBubble[i] = vetor[i];
        vetorSelection[i] = vetor[i];
        vetorInsertion[i] = vetor[i];
    }

    compBubble = bubbleSort(vetorBubble, 20);
    compSelection = selectionSort(vetorSelection, 20);
    compInsertion = insertionSort(vetorInsertion, 20);

    printf("\nBubble Sort:\n");
    mostrarVetor(vetorBubble, 20);
    printf("Comparacoes realizadas: %d\n", compBubble);

    printf("\nSelection Sort:\n");
    mostrarVetor(vetorSelection, 20);
    printf("Comparacoes realizadas: %d\n", compSelection);

    printf("\nInsertion Sort:\n");
    mostrarVetor(vetorInsertion, 20);
    printf("Comparacoes realizadas: %d\n", compInsertion);

    No* raiz = NULL;
    for (int i = 0; i < 20; i++)
        raiz = inserir(raiz, copia[i]);

    printf("\nPercurso Pre-Ordem:\n");
    preOrdem(raiz);
    printf("\n");

    printf("\nPercurso Em-Ordem:\n");
    emOrdem(raiz);
    printf("\n");

    printf("\nPercurso Pos-Ordem:\n");
    posOrdem(raiz);
    printf("\n");


//O resultado da arvoré
    printf("\nAltura da arvore: %d\n", altura(raiz));

    return 0;
}
