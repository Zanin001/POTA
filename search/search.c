#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    char INFO;
    struct NO *PROX;
} NODO;

NODO *LISTA;

void ESPERAR(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

char MENU(void)
{
    char op;
    do 
    {
        system("cls");
        printf("1 - Inserir\n");
        printf("2 - Excluir\n");
        printf("3 - Exibir\n");
        printf("4 - Busca Sequencial\n");
        printf("5 - Busca Binaria\n");
        printf("0 - FIM\n");
        printf("Opcao: ");
        op = getchar();
    } while (op < '0' || op > '5');
    return op;
}

void INSERIR(void)
{
    NODO *P1, *P2, *P3;
    P1 = (NODO *)malloc(sizeof(NODO));      
    if (P1 == NULL)  
    {
        printf("\nOverflow. Memoria Cheia");
        ESPERAR(); 
		exit(0); 
    }
    else
    {
        printf("\n=====INSERINDO=====\nDigite um caracter : ");
        scanf(" %c", &P1->INFO);
        P1->PROX = NULL;
        if (LISTA == NULL)
            LISTA = P1;
        else
        {
            P2 = LISTA;
            while (P2 != NULL)
                if (P1->INFO < P2->INFO)
                    if (P2 == LISTA)
                    {
                        LISTA = P1;
                        P1->PROX = P2;
                        P2 = NULL;
                    }
                    else
                    {
                        P3->PROX = P1;
                        P1->PROX = P2;
                        P2 = NULL;
                    }
                else
                {
                    P3 = P2;
                    P2 = P2->PROX;
                    if (P2 == NULL)
                        P3->PROX = P1;
                }
        }
    }
}
                    
void EXCLUIR(void)
{
    NODO *P1;
    if (LISTA == NULL)
    {
        printf("\nLista Vazia");
		printf("\n\n<=======Digite qualquer tecla para continuar=======>");
        ESPERAR();
    }
    else
    {
        P1 = LISTA;
        LISTA = LISTA->PROX;
        free(P1);
        printf("\nValor removido do topo da fila");
		printf("\n\n<=======Digite qualquer tecla para continuar=======>");
        ESPERAR();
    }
}
                
void EXIBIR(void)
{
    NODO *P1;
    int I = 0;
    P1 = LISTA;
    if (P1 == NULL)
        printf("\nLista Vazia");
    else
        while (P1 != NULL)
        {
            printf("\nCaracter %2d : %c", ++I, P1->INFO);
            P1 = P1->PROX;
        }
	printf("\n\n<=======Digite qualquer tecla para continuar=======>");

    ESPERAR();
}

void LIMPAR(void)
{
    NODO *P1, *P2;
    P1 = LISTA;
    if (P1 == NULL)
        printf("\nLista Vazia");
    else
        while (P1 != NULL)
        {
            P2 = P1;
            P1 = P1->PROX;
            free(P2);
        }
}

int BUSCA_SEQUENCIAL(NODO *no, char chave, int indice) 
{
    if (no == NULL)
        return -1;
    if (no->INFO == chave)
        return indice;
    return BUSCA_SEQUENCIAL(no->PROX, chave, indice + 1);
}

int TAMANHO_LISTA(NODO *inicio) {
    int tamanho = 0;
    NODO *atual = inicio;
    while (atual != NULL) {
        tamanho++;
        atual = atual->PROX;
    }
    return tamanho;
}

int BUSCA_BINARIA(NODO *inicio, char valor, int inicioIndex, int fimIndex) 
{
    if (inicioIndex > fimIndex)
        return -1;

    int meio = (inicioIndex + fimIndex) / 2;
    NODO *meioNo = inicio;
    int i;
    for (i = 0; i < meio; i++) {
        meioNo = meioNo->PROX;
    }

    if (meioNo->INFO == valor)
        return meio;
    else if (meioNo->INFO < valor)
        return buscaBinariaRecursiva(meioNo->PROX, valor, meio + 1, fimIndex);
    else
        return buscaBinariaRecursiva(inicio, valor, inicioIndex, meio - 1);
}

int BUSCA_BINARIA(NODO *inicio, char valor, int index) 
{
    if (inicio == NULL) 
        return -1;
    if (inicio->INFO == valor)
        return index;
    return BUSCA_BINARIA(inicio->PROX, valor, index + 1);
}

int main() 
{
    int laco = 1;
    LISTA = NULL;
    do 
    {
        switch (MENU())
        {
            case '1' :  INSERIR();
                        break;
            case '2' :  EXCLUIR();
                        break;
            case '3' :  EXIBIR();
                        break;
            case '4' : 
            {
                        char chave;
                        printf("\nDigite o caracter que deseja buscar: ");
                        scanf(" %c", &chave);
                        int index = BUSCA_SEQUENCIAL(LISTA, chave, 0);
                        if (index != -1)
                            printf("\nCaracter encontrado na posicao %d (Busca Sequencial Recursiva)", index);
                        else
                            printf("\nCaracter nao encontrado (Busca Sequencial Recursiva)");
                        ESPERAR();
                        break;
            }
            case '5' : 
            {
                        char valor;
                        printf("Digite o valor a ser buscado: ");
                        scanf(" %c", &valor);
                        int tamanho = TAMANHO_LISTA(LISTA);
                        int index = BUSCA_BINARIA(LISTA, valor, 0, tamanho - 1);
                        if (index != -1)
                            printf("\nCaracter encontrado na posicao %d (Busca Binaria Recursiva)", index);
                        else 
                            printf("\nCaracter nao encontrado (Busca Binaria Recursiva)");
                        ESPERAR();
                        break;
            }
            case '0' :  laco = 0;
                        break;
        }
    } while (laco);
    LIMPAR();
    printf("\n\n\nFIM");  
    return 0;
} 
