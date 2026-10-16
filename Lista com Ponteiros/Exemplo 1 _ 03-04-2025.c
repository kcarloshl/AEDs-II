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
    TipoApontador Primeiro, Ultimo;
} TipoLista;

TipoLista Lista;
TipoItem x;

int tam = 0;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    tam = 0;
}

int Vazia(TipoLista Lista)
{
    return(Lista.Ultimo == Lista.Primeiro);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    tam ++;
}

void Imprime(TipoLista Lista)
{
    TipoApontador aux;

    aux = Lista.Primeiro->Prox;

    while(aux != NULL)
    {
        printf("Codigo: %d\n", aux->Item.cod);
        printf("Idade: %d\n", aux->Item.idade);
        aux = aux->Prox;
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *x)
{
    TipoApontador q, z;

    q = Lista->Primeiro->Prox;

    if(Vazia(*Lista)){
        printf("A lista esta vazia.\n");
        return 0;
    }

    if(q ->Prox == NULL)
    {
        *x = q->Item;
        printf("O Elemento retirado foi o de:\n");
        printf("Codigo: %d\n", x->cod);
        printf("Idade: %d\n", x->idade);
        Lista->Ultimo = Lista->Primeiro;
        Lista->Primeiro->Prox = NULL;
    }
    else
    {
        while(q->Prox != NULL)
        {
            z = q;
            q = q->Prox;
        }

        *x = q->Item;
        printf("O Elemento retirado foi o de:\n");
        printf("Codigo: %d\n", x->cod);
        printf("Idade: %d\n", x->idade);
        Lista->Ultimo = z;
        z->Prox = NULL;
    }
    free(q);
}

void Procura (TipoLista Lista, TipoItem x)
{
    TipoApontador q;
    int encontrou = 0;
    q = Lista.Primeiro->Prox;

    if(Vazia(Lista))
    {
        printf("Lista Vazia!\n");
        return 0;
    }
    else
    {
       while(q != NULL)
       {
         if(q->Item.cod == x.cod)
         {
           encontrou = 1;
           break;
         }
         q = q->Prox;
       }

       if(encontrou == 1)
       {
          printf("Elemento Encontrado.\n");
       }
       else
       {
          printf("Elemento nao encontrado.\n");
       }
    }
}

int main()
{
    FLVazia(&Lista);
    int opcao, resposta;

    do
    {
        printf("\n\nMENU\n\n");
        printf("\nDigite a opcao desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar a Lista.\n");
        printf("2 - Verificar se Lista esta vazia.\n");
        printf("3 - Inserir Elementos na Lista.\n");
        printf("4 - Imprimir Elementos da Lista.\n");
        printf("5 - Retira Ultimo Elemento da Lista.\n");
        printf("6 - Procurar um elemento na lista.\n");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            {
            printf("PROGRAMA ENCERRADO");
            break;
            }
        case 1:
            {
                FLVazia(&Lista);
                printf("\nA LISTA VAZIA\n");
                break;
            }
        case 2:
            {
                resposta = Vazia(Lista);
                if(resposta == 1)
                {
                    printf("\nLISTA ESTA VAZIA\n");
                }
                else
                {
                    printf("\nLISTA NAO ESTA VAZIA\n");
                }
                break;
            }
        case 3:
            {
                printf("Digite o codigo:\n");
                scanf("%d", &x.cod);
                printf("Digite a idade:\n");
                scanf("%d", &x.idade);
                Insere(x, &Lista);
                break;
            }
        case 4:
            {
                Imprime(Lista);
                break;
            }
        case 5:
            {
                RetiraUltimo(&Lista, &x);
                break;
            }
        case 6:
            {
                printf("Digite o elemento que procura\n");
                scanf("%d", &x.cod);
                Procura(Lista, x);
                break;
            }
        default:
            printf("\nOpcao Invalida\n\n");
        }
        _getch();
        system("cls");
    } while (opcao != 0);

    return(0);
}
