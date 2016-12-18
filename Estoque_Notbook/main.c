#include <stdio.h>
#include <stdlib.h>
#include "notbook.h"

char menu()
{
    printf("***********************\n");
    printf("* Estoque de Notbooks *\n");
    printf("***********************\n\n");
    printf("  1 - INSERIR Notbook\n");
    printf("  2 - REMOVER Notbook\n");
    printf("  3 - ALTERAR dados de um Notbook\n");
    printf("  4 - CONSULTAR lista de Notbooks pelo PRECO\n");
    printf("  5 - CONSULTAR lista de Notbooks pela MARCA\n");
    printf("  6 - CONSULTAR lista de Notbooks pelo PROCESSADOR\n");
    printf("  7 - CONSULTAR lista de Notbooks filtrada pela MARCA\n");
    printf("  8 - CONSULTAR lista de Notbooks filtrada pelo PROCESSADOR\n");
    printf("  0 - SAIR do aplicativo\n");
    printf("\n  Escolha uma op%c%co: ",135,198);
    return getchar();

}

int main()
{
    struct listaNot lisNotbook;
    lisNotbook.nco = 0;
    struct Not notb;
    int rb;
    int alterado = 0;
    char k = 'B';
    char p = 'A';
    char z[10];
    char u[10];
    FILE *fp;
    fp = fopen("Notbooks.arq","rb");
    if(fp != NULL)
        fread(&lisNotbook,sizeof(struct listaNot),1,fp);
    fclose(fp);
    while(k == '0','1','2','3','4','5','6','7','8')
    {
        k = menu();
        switch(k)
        {
            lb();
            case '1':
                    lb();
                    AdicionarNotbook(&lisNotbook,notb);
                    while(p!='s' && p!='S' && p!='n' && p!='N')
                    {
                        printf("\n  Salvar Notbook? (s/n): ");
                        p = getchar();
                        if(p=='S' || p=='s')
                        {
                            printf("\n\n  **** Notbook Inserido ****\n\n");
                            alterado = 1;
                            lb();
                        }
                        if(p == 'n' || p == 'N')
                        {
                            printf("\n\n");
                            lb();
                        }

                        if(p!='N' && p!='n'&& p!='s' && p!= 'S')
                        {
                            printf("\n\n**** Pressione S ou N ****\n\n");
                            lb();
                        }

                    }
                    p = 'A';
                    break;
            case '2':
                lb();
                printf("\n\n**** Remover Notbook ****\n\n");
                printf("Digite o Codec do Notbook: ");
                gets(notb.codec);
                rb = buscaNot(&lisNotbook,notb.codec);
                if(rb < 0)
                {
                   printf("\n\n**** Notbook inexistente ****\n\n");
                }

                else
                {
                     while(p!='s' && p!='S' && p!='n' && p!='N')
                    {
                        printf("\n\nExcluir %s e salvar? (s/n):  ",notb.codec);
                        p = getchar();
                        if(p=='S' || p=='s')
                        {   removeNot(&lisNotbook,notb.codec);
                            printf("\n\n**** Notbook Excluido ****\n\n");
                            alterado = 1;
                            lb();
                        }
                        if(p == 'N',p == 'n')
                        {
                            printf("\n\n");
                            lb();
                        }

                        if(p!='N' && p!='n'&& p!='s' && p!= 'S')
                        {
                            printf("\n\n  **** Pressione S ou N ****\n\n");
                            lb();
                        }
                    }
                }
                p = 'A';
                break;

            case '3':
                lb();
                printf("\n\n**** Modificar Notbook ****\n\n");
                printf("Digite o Codec do Notbook: ");
                gets(notb.codec);
                rb = buscaNot(&lisNotbook,notb.codec);
                if(rb < 0)
                {
                    printf("\n\n**** Notbook  Ineexistente ****\n\n");
                }
                else
                {
                    while(p!='s' && p!='S' && p!='n' && p!='N')
                    {
                        printf("\n\nModificar %s e salvar? (s/n):  ",notb.codec);
                        p = getchar();
                        if(p=='S' || p=='s')
                        {   lb();
                            mudaNot(&lisNotbook,notb.codec);
                            printf("\n\n**** Dados de Notbook Modificados ****\n\n");
                            alterado = 1;
                            lb();
                        }
                        if(p == 'N' && p == 'n')
                        {
                            printf("\n\n");
                            lb();
                        }
                        if(p!='N' && p!='n'&& p!='s' && p!= 'S')
                        {
                            printf("\n\n**** Pressione S ou N ****\n\n");
                            lb();
                        }
                    }
                }
                p = 'A';
                break;

            case '4':
                if(lisNotbook.nco < 2)
                {
                    printf("\n\nE necessario pelo menos dois Notbooks para se ordenar a lista\n\n");
                    lb();
                    break;
                }
                else
                {
                    lb();
                    qsort(lisNotbook.Notb,lisNotbook.nco,sizeof(struct Not),ordenaPreco);
                    mostreLN(&lisNotbook);
                    break;
                }
            case '5':
                if(lisNotbook.nco < 2)
                {
                    printf("\n\nE necessario pelo menos dois Notbooks para se ordenar a lista\n\n");
                    lb();
                    break;
                }
                else
                {
                    lb();
                    qsort(lisNotbook.Notb,lisNotbook.nco,sizeof(struct Not),ordenaMarca);
                    mostreLN(&lisNotbook);
                    break;
                }
            case '6':
                if(lisNotbook.nco < 2)
                {
                    printf("\n\nE necessario pelo menos dois Notbooks para se ordenar a lista\n\n");
                    lb();
                    break;
                }
                else
                {
                    lb();
                    qsort(lisNotbook.Notb,lisNotbook.nco,sizeof(struct Not),ordenaPro);
                    mostreLN(&lisNotbook);
                    break;
                }
            case '7':
                lb();
                printf("\n\n--- Digite o nome da Marca do Notbook ---\n\n");
                printf("Marca:  ");
                scanf("%s",u);
                mostFilterM(&lisNotbook,u);
                lb();
                break;
            case '8':
                lb();
                printf("\n\n--- Digite o nome da Processador do Notbook ---\n\n");
                printf("Processador:  ");
                scanf("%s",z);
                mostFilterP(&lisNotbook,z);
                lb();
                break;
            case '0':
                 lb();
                 if(alterado)
                {
                    printf("\n\nArquivo alterado. Deseja salvar as altera%c%ces? (s/n): ",135,228);
                    p = getchar();
                    if(p=='S' || p=='s')
                    {
                        fp = fopen("Notbooks.arq","wb");
                        fwrite(&lisNotbook,sizeof(struct listaNot),1,fp);
                        fclose(fp);
                        printf("\n  **** O arquivo foi salvo ****\n");
                        return 0;
                    }
                    if(p=='N'|| p=='n')
                    {
                        return 0;
                    }
                     if(p!='N' && p!='n'&& p!='s' && p!= 'S')
                     {
                        printf("\n\n**** Pressione S ou N ****\n\n");
                        lb();
                    }

                }
                else
                {
                    return 0;
                }

            default:
                lb();
                printf("\n\n**** Entrada invalida ****\n\n");
                break;
        }
    }

    printf("\n");
    return 0;

}
