#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    int idade;
} TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct
{
    TipoApontador Frente, Tras;
} TipoFila;

TipoFila Fila;
TipoItem x;
int tam = 0;

void FFVazia(TipoFila *Fila)
{
    Fila->Frente = (TipoApontador)malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Frente->Prox = NULL;
}

int Vazia(TipoFila Fila)
{
    return(Fila.Frente == Fila.Tras);
}

void Insere(TipoFila *Fila, TipoItem x)
{
    Fila->Tras->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item = x;
    Fila->Tras->Prox = NULL;
    tam += 1;
}

void Imprime(TipoFila Fila)
{
    TipoApontador aux;

    aux = Fila.Frente->Prox;

    while(aux != NULL)
    {
        printf("\nCodigo: %d\n", aux->Item.cod);
        printf("Idade: %d\n", aux->Item.idade);
        aux = aux->Prox;
    }
}

void Retira(TipoFila *Fila, TipoItem *x)
{
    TipoApontador q;

    q = Fila->Frente;

    if(Vazia(*Fila)){
        printf("A fila esta vazia.\n");
        return 0;
    }
    else
    {
        Fila->Frente = q->Prox;
        *x=Fila->Frente->Item;
        printf("\nCodigo: %d\n", x->cod);
        printf("Idade: %d\n", x->idade);
        printf("ELEMENTO RETIRADO!\n");

        free(q);
        tam--;
    }
}

void Procura (TipoFila Fila, TipoItem x)
{
    TipoApontador q;
    int encontrou = 0;
    q = Fila.Frente->Prox;

    if(Vazia(Fila))
    {
        printf("Fila esta vazia!\n");
        return 0;
    }
    else
    {
       while(q != NULL)
       {
         if(q->Item.cod == x.cod)
         {
           encontrou = 1;
           printf("\nCodigo: %d\n", x.cod);
           printf("Idade: %d\n", x.idade);
           break;
         }
         q = q->Prox;
       }

       if(encontrou == 1)
       {
          printf("\nElemento Encontrado.\n");
       }
       else
       {
          printf("\nElemento nao encontrado.\n");
       }
    }
}

void IdadePeI(TipoFila Fila, TipoItem x)
{
    int qtdp = 0;
    int qtdi = 0;
    TipoApontador aux;
    aux = Fila.Frente->Prox;

    while(aux != NULL)
    {
    if(aux->Item.idade % 2 == 0)
    {
        qtdp++;
    }
    else
    {
        qtdi++;
    }
    aux = aux->Prox;
    }

    printf("A Quantidade de Idades Pares: %d\n", qtdp);
    printf("A Quantidade de Idades Impares: %d\n", qtdi);
}

int main()
{
    FFVazia(&Fila);
    int op, respo;

    do
    {
        printf("\n\nMENU\n\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar a Fila.\n");
        printf("2 - Verificar se Fila esta vazia.\n");
        printf("3 - Inserir Elementos na Fila.\n");
        printf("4 - Imprimir Elementos da Fila.\n");
        printf("5 - Retira Elemento da Fila.\n");
        printf("6 - Procura Elemento na Fila.\n");
        printf("7 - Tamanho da Fila.\n");
        printf("8 - Idades Pares e Impares.\n");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            {
                printf("PROGRAMA ENCERRADO!\n");
                break;
            }
        case 1:
            {
                FFVazia(&Fila);
                printf("\nA FILA ESTA VAZIA\n");
                break;
            }
        case 2:
            {
                respo = Vazia(Fila);
                if(respo == 1)
                {
                    printf("\nFILA ESTA VAZIA\n");
                }
                else
                {
                    printf("\nFILA NAO ESTA VAZIA\n");
                }
                break;
            }
        case 3:
            {
                printf("Digite o codigo:\n");
                scanf("%d", &x.cod);
                printf("Digite a idade:\n");
                scanf("%d", &x.idade);
                Insere(&Fila, x);
                break;
            }
        case 4:
            {
                Imprime(Fila);
                break;
            }
        case 5:
            {
                Retira(&Fila, &x);
                break;
            }
        case 6:
            {
                printf("Digite o elemento que procura\n");
                scanf("%d", &x.cod);
                Procura(Fila, x);
                break;
            }
        case 7:
            {
                respo = Vazia(Fila);
                if(respo == 1)
                {
                    printf("\nFILA ESTA VAZIA\n");
                }
                else
                {
                    printf("\nA Fila tem %d Elemento(s):\n", tam);
                }
                break;
            }
        case 8:
            {
                respo = Vazia(Fila);
                if(respo == 1)
                {
                    printf("\nFILA ESTA VAZIA\n");
                }
                else
                {
                    IdadePeI(Fila, x);
                }
                break;
            }
        default:
            {
                printf("\n\nOPCAO INVALIDA!!\n\n");
            }
        }
        _getch();
        system("cls");
    } while(op != 0);

    return(0);
}