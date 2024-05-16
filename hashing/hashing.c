#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // Tamanho inicial da tabela de hash

// Estrutura para o nó da lista ligada
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Estrutura para a tabela de hash
typedef struct HashTable {
    Node** array;
    int size;
} HashTable;

// Função de criação de um novo nó da lista ligada
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função de criação da tabela de hash
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a tabela de hash.\n");
        exit(EXIT_FAILURE);
    }
    hashTable->size = size;
    hashTable->array = (Node**)malloc(size * sizeof(Node*));
    if (hashTable->array == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o array da tabela de hash.\n");
        exit(EXIT_FAILURE);
    }
    // Inicializa cada posição do array com NULL
    for (int i = 0; i < size; i++) {
        hashTable->array[i] = NULL;
    }
    return hashTable;
}

// Função para calcular o índice na tabela de hash
int hashCode(int key, int size) {
    return key % size;
}

// Função de inserção na tabela de hash
void insert(HashTable* hashTable, int key, int value) {
    int index = hashCode(key, hashTable->size);
    Node* newNode = createNode(key, value);
    // Se o slot estiver vazio, insere o novo nó
    if (hashTable->array[index] == NULL) {
        hashTable->array[index] = newNode;
    } else { // Se o slot estiver ocupado, adiciona o novo nó no final da lista ligada
        Node* current = hashTable->array[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Função para remover um elemento da tabela de hash
void removeElement(HashTable* hashTable, int key) {
    int index = hashCode(key, hashTable->size);
    Node* current = hashTable->array[index];
    Node* prev = NULL;
    // Procura o elemento na lista ligada
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    // Se o elemento for encontrado, remove-o da lista
    if (current != NULL) {
        if (prev == NULL) {
            hashTable->array[index] = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Função para imprimir a tabela de hash
void printHashTable(HashTable* hashTable) {
    printf("Tabela de Hash:\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("[%d]: ", i);
        Node* current = hashTable->array[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// Função principal
int main() {
    HashTable* hashTable = createHashTable(SIZE);

    // Inserção de elementos
    insert(hashTable, 10, 100);
    insert(hashTable, 21, 200);
    insert(hashTable, 32, 300);
    insert(hashTable, 43, 400);
    insert(hashTable, 54, 500);

    // Imprimir a tabela de hash após inserção
    printHashTable(hashTable);

    // Remover um elemento
    removeElement(hashTable, 32);

    // Imprimir a tabela de hash após remoção
    printf("\nApós remover o elemento 32:\n");
    printHashTable(hashTable);

    return 0;
}
