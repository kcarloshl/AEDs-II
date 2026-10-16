#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
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
    int tam;
} TipoLista;

TipoLista Lista;
TipoLista Lista2;
TipoLista Lista3;
TipoItem x;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
    Lista->tam = 0;
}

int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista)
{
    Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
    Lista->tam++;
}

void Imprime(TipoLista Lista)
{
    TipoApontador aux;
    aux = Lista.Primeiro->Prox;

    while (aux != NULL)
    {
        printf("Cod: %d\n", aux->Item.cod);
        aux = aux->Prox;
    }
}

void ImprimeDivididas(TipoLista *Lista)
{
    if (Vazia(*Lista))
        printf("ERRO: A Lista esta Vazia!\n");
    else
    {
        TipoApontador aux = Lista->Primeiro->Prox;
        while (aux != NULL)
        {
            printf("Cod: %d\n", aux->Item.cod);
            aux = aux->Prox;
        }
    }
}

void RetiraUltimo(TipoLista *Lista, TipoItem *x)
{
    TipoApontador q, z;
    q = Lista->Primeiro->Prox;

    if (Vazia(*Lista))
    {
        printf("A lista esta vazia.\n");
        return 0;
    }

    if (q->Prox == NULL)
    {
        *x = q->Item;
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Lista->Ultimo = Lista->Primeiro;
        Lista->Primeiro->Prox = NULL;
    }
    else
    {
        while (q->Prox != NULL)
        {
            z = q;
            q = q->Prox;
        }
        *x = q->Item;
        printf("O elemento retirado foi o de codigo %d\n", x->cod);
        Lista->Ultimo = z;
        z->Prox = NULL;
    }

    free(q);
    Lista->tam--;
}

void Procura(TipoLista Lista, TipoItem x)
{
    TipoApontador q;
    q = Lista.Primeiro->Prox;
    int encontrou = 0;

    if (Vazia(Lista))
    {
        printf("A lista esta vazia.\n");
        return 0;
    }
    else
    {
        while (q != NULL)
        {
            if (q->Item.cod == x.cod)
            {
                encontrou = 1;
                break;
            }
            q = q->Prox;
        }

        if (encontrou == 1)
        {
            printf("Elemento Encontrado.\n");
        }
        else
        {
            printf("Elemento nao encontrado.\n");
        }
    }
}

void RemoverEspecifico(TipoLista *Lista, TipoItem x)
{
    if (Vazia(*Lista))
    {
        printf("ERRO: A Lista esta Vazia!\n");
    }
    else
    {
        int remove = 0;
        TipoApontador aux = Lista->Primeiro->Prox, aux2;

        if (aux->Prox == NULL)
        {
            if (aux->Item.cod == x.cod)
            {
                Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
                Lista->Ultimo = Lista->Primeiro;
                Lista->Ultimo->Prox = NULL;
                remove = 1;
            }
        }
        else
        {
            while (aux->Prox != NULL)
            {
                if (aux->Item.cod == x.cod)
                {
                    free(Lista->Primeiro);
                    Lista->Primeiro = aux;
                    remove = 1;
                    break;
                }

                aux2 = aux;
                aux = aux->Prox;

                if (aux->Item.cod == x.cod && aux->Prox != NULL)
                {
                    aux2->Prox = aux->Prox;
                    free(aux);
                    remove = 1;
                    break;
                }
                else if (aux->Item.cod == x.cod && aux->Prox == NULL)
                {
                    Lista->Ultimo = aux2;
                    Lista->Ultimo->Prox = NULL;
                    free(aux);
                    remove = 1;
                    break;
                }
            }
        }

        if (remove = 1)
        {
            printf("\nElemento %d removido\n", x.cod);
            Lista->tam--;
        }
        else
        {
            printf("\nElemento %d nao encontrado\n", x.cod);
        }
    }
}

void RemoverN(TipoLista *Lista, TipoItem x)
{
    if (Vazia(*Lista))
        printf("ERRO: A Lista esta Vazia!\n");
    else
    {
        if (x.cod > Lista->tam)
        {
            FLVazia(Lista);
            printf("\nA Lista esta Vazia!\n");
        }
        else
        {
            int con = 2;
            TipoApontador aux2, aux = Lista->Primeiro->Prox;
            while (aux->Prox != NULL && con <= x.cod)
            {
                aux2 = aux;
                aux = aux->Prox;
                free(aux2);
                con++;
            }
            Lista->Primeiro = aux;
            Lista->tam -= x.cod;
            printf("\nA LISTA:\n\n");
            ImprimeDivididas(Lista);
        }
    }
}

void DividirLista(TipoLista *Lista, TipoLista *Lista2, TipoLista *Lista3, TipoItem *x)
{
    if (Vazia(*Lista))
        printf("ERRO: A Lista esta Vazia!\n");
    else
    {
        FLVazia(Lista2);
        FLVazia(Lista3);
        TipoApontador aux = Lista->Primeiro->Prox;
        while (aux != NULL)
        {
            Insere(aux->Item, Lista2);
            if (aux->Item.cod == x->cod)
            {
                aux = aux->Prox;
                break;
            }
            aux = aux->Prox;
        }
        while (aux != NULL)
        {
            Insere(aux->Item, Lista3);
            aux = aux->Prox;
        }
        printf("\nPrimeira Lista:\n");
        ImprimeDivididas(Lista2);
        printf("\n\nSegunda Lista:\n");
        ImprimeDivididas(Lista3);
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
        printf("7 - Remover elemento especifico.\n");
        printf("8 - Remover n primeiros elementos.\n");
        printf("9 - Dividir a lista em duas.\n");

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
            if (resposta == 1)
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
        case 7:
        {
            printf("Digite o elemento que deseja retirar.\n");
            scanf("%d", &x.cod);
            RemoverEspecifico(&Lista, x);
            break;
        }
        case 8:
        {
            printf("Digite a quantidade de elementos que deseja remover.\n");
            scanf("%d", &x.cod);
            RemoverN(&Lista, x);
            break;
        }
        case 9:
        {
            printf("Digite a partir de qual elemento deseja dividir a lista principal.\n");
            scanf("%d", &x.cod);
            DividirLista(&Lista, &Lista2, &Lista3, &x);
            break;
        }
        default:
            printf("\nOpcao Invalida\n\n");
        }
        _getch();
        system("cls");
    } while (opcao != 0);

    return (0);
}