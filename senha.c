
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void sorteia_valores(int *senha, int dificuldade, int teste);
//Sorteia 3 ou 4 valores de acordo com a dificuldade. Valores entre 0 e 9.
bool TesteRepetidos(int *senha, int lim, int c);
//Função que garante que os valores gerados não sejam repetidos.
void ler_senha(int *senhausuario, int dificuldade);
//Recebe como parametro os valores informados pelo usuario, admitindo apenas valores entre 0 e 9.
void compara_senha(int *senha, int *senhausuario, int *qtdacertospc, int *qtdacertospe, int dificuldade);
//Compara a senha gerada aleatoriamente com os valores informados pelo usuario.
bool TesteSenha(int *senha, int *senhausuario, int dificuldade, int i);
//Função complementar a 'compara_senha', que testa cada algarismo individualmente, garantindo a possibilidade de informar
//o usuario de possiveis acertos, tanto em posiçoes corretas quanto em posiçoes erradas.

void sorteia_valores(int *senha, int dificuldade, int teste)
{
    int c;
    if(teste == 0)
        puts("\nSENHA:");
    srand((unsigned)time(NULL));
    for(int i = 0; i < dificuldade; i++)
    {
        c = rand() %10;
        while(TesteRepetidos(senha,i,c))
        {
            c = rand() %10;
        }
        *(senha+i) = c;
        if(teste == 0)
            printf("%d ",*(senha+i));
    }   
}

bool TesteRepetidos(int *senha, int lim, int c)
{
    for (int i = 0; i < lim; i++)
    {
        if(*(senha+i) == c) return true;
    }
    return false;   
}

void ler_senha(int *senhausuario, int dificuldade)
{
    int c;
    puts("\nInforme a senha, um valor por vez.\n");
    for (int i = 0; i < dificuldade; i++)
    {
        scanf("%d",&c);
        while (c > 9 || c < 0)
        {
            puts("Valor Invalido!");
            scanf("%d",&c);
        }
        *(senhausuario+i) = c; 
    } 
}

void compara_senha(int *senha, int *senhausuario, int *qtdacertospc, int *qtdacertospe, int dificuldade)
{
    for (int i = 0; i < dificuldade; i++)
    {
        if((TesteSenha(senha,senhausuario,dificuldade,i)))
        {
            if(*(senhausuario+i) == *(senha+i))
                *qtdacertospc+=1;
            else
                *qtdacertospe+=1;
        }
    }
    if(*qtdacertospc == dificuldade)
    {
        printf("\nWINS!!\n\n");
    }
    else 
    {
        printf("\nAcertos na posição certa: %d\nAcertos na posição errada: %d\n",*qtdacertospc,*qtdacertospe);
        *qtdacertospc = 0;
        *qtdacertospe = 0;
    }
}

bool TesteSenha(int *senha, int *senhausuario, int dificuldade, int i)
{
    for(int j = 0; j < dificuldade; j++)
    {
        if(*(senhausuario+i) == *(senha+j)) return true;
    }
    return false;
}

int main(void)
{
    int *senha, *senhausuario, *qtdacertospc, *qtdacertospe, dificuldade, tentativas, parar=0;
    for(;parar != 1;)
    {
        puts("\nDIFICULDADE\n1-FACIL\n2-DIFICIL\n3-TESTE\n4-SAIR\n");
        scanf("%d",&dificuldade);
        while (dificuldade != 1 && dificuldade != 2 && dificuldade != 3 && dificuldade != 4)
        {
            puts("Opcao Invalida!");
            scanf("%d",&dificuldade);
        }
        switch (dificuldade)
        {
        case 1:
        {
            puts("\nInforme o número de tentativas que desejar.\n");
            scanf("%d",&tentativas);

            while(tentativas <= 0)
            {
                puts("Valor Invalido!");
                scanf("%d",&tentativas);
            }
            senha=(int *)malloc(sizeof(int)*3);
            if(senha == NULL) return 0;
            sorteia_valores(senha, 3, -1);

            senhausuario=(int *)malloc(sizeof(int)*3);
            if(senhausuario == NULL) return 0;
            qtdacertospc=(int *)malloc(sizeof(int));
            if(qtdacertospc == NULL) return 0;
            qtdacertospe=(int *)malloc(sizeof(int));
            if(qtdacertospe == NULL) return 0;
            *qtdacertospc = 0;
            *qtdacertospe = 0;

            for(int i = 0; i < tentativas; i++)
            {
                ler_senha(senhausuario, 3);
                compara_senha(senha, senhausuario, qtdacertospc, qtdacertospe, 3);

                if(*qtdacertospc == 3)
                    i = tentativas;
            }
            puts("\nPARA SAIR DIGITE 1\nPARA CONTINUAR DIGITE OUTRO VALOR\n");
            scanf("%d",&parar);

            free(senha); senha = NULL;
            free(senhausuario); senhausuario = NULL;
            free(qtdacertospc); qtdacertospc = NULL;
            free(qtdacertospe); qtdacertospe = NULL;
        }break;

        case 2:
        {
            puts("\nInforme o número de tentativas que desejar.\n");
            scanf("%d",&tentativas);
            while(tentativas <= 0)
            {
                puts("Valor Invalido!");
                scanf("%d",&tentativas);
            }
            senha=(int *)malloc(sizeof(int)*4);
            if(senha == NULL) return 0;
            sorteia_valores(senha, 4, -1);

            senhausuario=(int *)malloc(sizeof(int)*4);
            if(senhausuario == NULL) return 0;
            qtdacertospc=(int *)malloc(sizeof(int));
            if(qtdacertospc == NULL) return 0;
            qtdacertospe=(int *)malloc(sizeof(int));
            if(qtdacertospe == NULL) return 0;
            *qtdacertospc = 0;
            *qtdacertospe = 0;

            for(int i = 0; i < tentativas; i++)
            {
                ler_senha(senhausuario, 4);
                compara_senha(senha, senhausuario, qtdacertospc, qtdacertospe, 4);

                if(*qtdacertospc == 4)
                    i = tentativas;
            }
            puts("\nPARA SAIR DIGITE 1\nPARA CONTINUAR DIGITE OUTRO VALOR\n");
            scanf("%d",&parar);

            free(senha); senha = NULL;
            free(senhausuario); senhausuario = NULL;
            free(qtdacertospc); qtdacertospc = NULL;
            free(qtdacertospe); qtdacertospe = NULL;
        }break;

        case 3:
        {
            puts("\nInforme o número de tentativas que desejar.\n");
            scanf("%d",&tentativas);
            while(tentativas <= 0)
            {
                puts("Valor Invalido!");
                scanf("%d",&tentativas);
            }
            senha=(int *)malloc(sizeof(int)*4);
            if(senha == NULL) return 0;
            sorteia_valores(senha, 4, 0);

            senhausuario=(int *)malloc(sizeof(int)*4);
            if(senhausuario == NULL) return 0;
            qtdacertospc=(int *)malloc(sizeof(int));
            if(qtdacertospc == NULL) return 0;
            qtdacertospe=(int *)malloc(sizeof(int));
            if(qtdacertospe == NULL) return 0;
            *qtdacertospc = 0;
            *qtdacertospe = 0;

            for(int i = 0; i < tentativas; i++)
            {
                ler_senha(senhausuario, 4);
                compara_senha(senha, senhausuario, qtdacertospc, qtdacertospe, 4);

                if(*qtdacertospc == 4)
                    i = tentativas;
            }
            puts("\nPARA SAIR DIGITE 1\nPARA CONTINUAR DIGITE OUTRO VALOR\n");
            scanf("%d",&parar);

            free(senha); senha = NULL;
            free(senhausuario); senhausuario = NULL;
            free(qtdacertospc); qtdacertospc = NULL;
            free(qtdacertospe); qtdacertospe = NULL;
        }break;
        
        case 4:
        {
            return 0;
        }break;

        default:
            break;
        }
    }
}
