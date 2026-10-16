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
    TipoApontador Fundo;
    TipoApontador Topo;
    int TAM;
} TipoPilha;

TipoPilha Pilha;
TipoItem x;

void FPVazia (TipoPilha *Pilha)
{
    Pilha->Topo = (TipoApontador)malloc(sizeof(TipoCelula));
    Pilha->Fundo = Pilha->Topo;
    Pilha->Topo->Prox = NULL;
    Pilha->TAM = 0;
}

int Vazia(TipoPilha Pilha)
{
    return(Pilha.Topo == Pilha.Fundo);
}

void Empilhar (TipoItem x, TipoPilha *Pilha)
{
    TipoApontador aux;
    aux = (TipoApontador)malloc(sizeof(TipoCelula));
    Pilha->Topo->Item = x;
    aux->Prox = Pilha->Topo;
    Pilha->Topo = aux;
    Pilha->TAM = Pilha->TAM +1;
}

void ImprimeTopoFundo(TipoPilha Pilha)
{
    TipoApontador aux;
    aux = Pilha.Topo->Prox;

    while(aux != NULL)
    {
        printf("Codigo: %d\n", aux->Item.cod);
        printf("Idade: %d\n\n", aux->Item.idade);
        aux = aux->Prox;
    }
}

void Desempilha(TipoItem *x, TipoPilha *Pilha)
{
    TipoApontador q;
    if(Vazia(*Pilha))
    {
        printf("PILHA VAZIA!\n");
    }
    else
    {
        q = Pilha->Topo;
        Pilha->Topo = q->Prox;
        *x = q->Prox->Item;
        printf("O Elemento retirado foi o de:\n");
        printf("Codigo: %d\n", x->cod);
        printf("Idade: %d\n", x->idade);
        free(q);
        Pilha->TAM = Pilha->TAM -1;
    }
}

void Procura(TipoPilha Pilha, TipoItem x)
{
    TipoApontador aux;
    int encontrou = 0;
    aux = Pilha.Topo->Prox;

    if(Vazia(Pilha))
    {
        printf("Pilha Vazia!\n");
        return 0;
    }
    else
    {
       while(aux != NULL)
       {
         if(aux->Item.cod == x.cod)
         {
           encontrou = 1;
           break;
         }
         aux = aux->Prox;
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

void QId(TipoPilha Pilha, TipoItem x)
{
    int qtdp = 0;
    int qtdi = 0;
    TipoApontador aux;
    aux = Pilha.Topo->Prox;

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
    int opcao, resposta;
    FPVazia(&Pilha);
    do
    {
        printf("\n\n--------MENU---------\n");
        printf("0 - Sair.\n");
        printf("1 - Esvaziar Pilha.\n");
        printf("2 - Verificar Pilha.\n");
        printf("3 - Inserir elemento.\n");
        printf("4 - Imprimir elementos.\n");
        printf("5 - Desempilhar.\n");
        printf("6 - Procurar elemento pelo codigo.\n");
        printf("7 - Quantidades de idades pares e impares.\n");

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
            FPVazia(&Pilha);
            printf("\nPilha Esvaziada\n");
            break;
            }
        case 2:
            {
            resposta = Vazia(Pilha);
            if(resposta == 1)
            {
                printf("PILHA ESTA VAZIA\n");
            }
            else
            {
                printf("PILHA NAO ESTA VAZIA\n");
            }
            break;
            }
        case 3:
            {
                printf("Digite o codigo:\n");
                scanf("%d", &x.cod);
                printf("Digite a idade:\n");
                scanf("%d", &x.idade);
                Empilhar(x, &Pilha);
                break;
            }
        case 4:
            {
                resposta = Vazia(Pilha);
                if(resposta == 1)
            {
                printf("PILHA ESTA VAZIA\n");
            }
            else
            {
                ImprimeTopoFundo(Pilha);
            }
            break;
            }
        case 5:
            {
                Desempilha(&x, &Pilha);
                break;
            }
        case 6:
            {
                printf("Digite o elemento que procura\n");
                scanf("%d", &x.cod);
                Procura(Pilha, x);
                break;
            }
        case 7:
            {
                QId(Pilha, x);
                break;
            }
        default:
            printf("\nOpcao invalida\n\n");
        }
        _getch();
        system("cls");
    }while (opcao != 0);

}
