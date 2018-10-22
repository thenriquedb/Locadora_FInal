#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/gestao.h"

void filClientes_Todos() {
    Strc_Clientes* Cliente = return_Clientes();
    int contC = returnCont_Clientes();
    int i;

    system("clear");

    if (Cliente != NULL) {
        printf("====== | VISUALIZAR TODOS CLIENTES CADASTRADOS | ======\n");

        for (i = 0; i < contC; i++) {
            printf("====== | %dº CLIENTE | ======\n", i + 1);
            imprimeClientes(i);
        }

        printf("Total de resultados: %d \n", i);
    } else {
        printf("Nenhum cliente cadastrado. \n");

    }
}
//-------------------------------------------------------------------------------

void filClientes_Codigo() {
    Strc_Clientes* Cliente = return_Clientes();
    int cont = 0, contC = returnCont_Clientes();
    int i, cod;

    system("clear");

    if (Cliente != NULL) {
        do {
            printf("====== | FILTRAR POR CODIGO | ======\n");
            printf("Digite o codigo que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CODIGO | ======\n");
            for (i = 0; i < contC; i++) {
                if (cod == Cliente[i].codigo) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                    break;
                }
            }

            printf("Nenhum resultado encontrado. \n");
            cont = 0;
            
        } while (chamarMenu_Relatorio() != 0);

    } else {
        printf("Nenhum cliente cadastrado. \n");

    }
}
//-------------------------------------------------------------------------------

void filClientes_FaixaCodigo() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, codInicio, codFim, contC = returnCont_Clientes();

    system("clear");
    do {
        printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n\n");

        if (Cliente != NULL) {
            do {
                printf("Digite o codigo inicial que deseja buscar: ");
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contC) {
                    printf("Valor maior que o número de clientes cadastrados. \n");
                }
            } while (codFim > contC);

            system("clear");
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n\n");
            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº CLIENTE | ======\n", cont + 1);
                imprimeClientes(i);
                cont++;
            }
        } else {
            printf("Nenhum cliente cadastrado. \n");
            break;
        }
    } while (chamarMenu_Relatorio() != 1);
}
//-------------------------------------------------------------------------------

void filClientes_Nome() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, contC = returnCont_Clientes();
    char nome[100];

    system("clear");
    if (Cliente != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME | ======\n");
            printf("Digite o nome que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contC; i++) {
                if (strcmp(nome, Cliente[i].nome) == 0) {
                    printf("%dº Cliente \n", cont + 1);
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                }
            }

            printf("Total de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum cliente cadastrado. \n");
    }
}

//-------------------------------------------------------------------------------

void filClientes_CPF() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, contC = returnCont_Clientes();
    char cpf[12];

    system("clear");

    if (Cliente != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR CPF | ======\n");
            printf("Digite o CPF que deseja buscar: ");
            scanf("%[^\n]s", cpf);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR CPF | ======\n");
            for (i = 0; i < contC; i++) {
                if (strcmp(cpf, Cliente[i].cpf) == 0) {
                    printf("%dº Cliente \n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                }
            }

            printf("Total de resultados: %d \n", cont);
            cont = 0;
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum cliente cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filClientes_Sexo() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, opc, cont = 0, contC = returnCont_Clientes();

    system("clear");

    if (Cliente != NULL) {
        do {
            printf("====== | FILTRAR POR SEXO | ======\n");
            do {
                printf("\t1. Sexo masculino \n"
                        "\t2. Sexo feminino \n"
                        "Digite a opção desejada:  ");
                scanf("%d", &opc);
            } while (opc != 1 && opc != 2);

            system("clear");
            printf("====== | FILTRAR POR SEXO | ======\n");

            for (i = 0; i < contC; i++) {
                if (opc == Cliente[i].opc_sexo) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                }
            }

            printf("Total de resultados: %d \n\n", cont);
            cont = 0;
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum cliente cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void imprimeClientes(int i) {
    Strc_Clientes* Cliente = return_Clientes();

    printf("\tNome: %s \n", Cliente[i].nome);
    printf("\tData de nascimento: %s \n", Cliente[i].data_nascimento);
    printf("\tCodigo: %d \n", Cliente[i].codigo);
    printf("\tEndereço completo: %s \n", Cliente[i].endereco);
    printf("\tCPF: %s \n", Cliente[i].cpf);
    printf("\tTelefone: %s \n", Cliente[i].telefone);
    printf("\tEmail: %s \n", Cliente[i].email);

    printf("\tSexo: ");
    if (Cliente[i].opc_sexo == 1) {
        printf("Mascukino \n");
    } else if (Cliente[i].opc_sexo == 2) {
        printf("Feminino \n");
    }

    printf("\tEstado civil: ");
    if (Cliente[i].estado_civi == 1) {
        printf("Solteiro(a) \n\n");
    } else if (Cliente[i].estado_civi == 2) {
        printf("Casado(a) \n\n");
    } else if (Cliente[i].estado_civi == 3) {
        printf("Divorciado(a) \n\n");
    } else if (Cliente[i].estado_civi == 4) {
        printf("Viúvo(a) \n\n");
    } else if (Cliente[i].estado_civi == 5) {
        printf("Separado(a) \n\n");
    }
    printf("|-------------------------------------------------------------------|\n");
}