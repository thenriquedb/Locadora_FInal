#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"

void filClientes_Todos() {
    Strc_Clientes* Cliente = return_Clientes();
    int contC = returnCont_Clientes();
    int i;

    system("clear");
    printf("====== | VISUALIZAR TODOS CLIENTES CADASTRADOS | ======\n");

    for (i = 0; i < contC; i++) {
        printf("====== | %dº CLIENTES | ======\n", i + 1);
        imprimeClientes(i);
    }

    printf("Total de resultados: %d \n", i);
}

void filClientes_Codigo() {
    Strc_Clientes* Cliente = return_Clientes();
    int contC = returnCont_Clientes();
    int i, cod;

    system("clear");

    do {
        printf("====== | FILTRAR POR CODIGO | ======\n");
        printf("Digite o codigo que deseja buscar: ");
        scanf("%d", &cod);

        for (i = 0; i < contC; i++) {
            if (cod == Cliente[i].codigo) {
                imprimeClientes(i);
                break;
            }
        }

        do {
        } while (continuarBusca() != 1);

    } while (1);
}

void filClientes_Nome() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, contC = returnCont_Clientes();
    char nome[100];

    system("clear");

    do {
        setbuf(stdin, NULL);
        printf("====== | FILTRAR POR NOME | ======\n");
        printf("Digite o nome que deseja buscar: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        for (i = 0; i < contC; i++) {
            if (strcmp(nome, Cliente[i].nome) == 0) {
                printf("%d Cliente", cont + 1);
                imprimeClientes(i);
                cont++;
            }
        }

        do {
        } while (continuarBusca() != 1);

    } while (1);

    printf("Total de resultados: %d \n", cont);
}

void filClientes_CPF() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, contC = returnCont_Clientes();
    char cpf[12];

    system("clear");

    do {
        setbuf(stdin, NULL);
        printf("====== | FILTRAR POR CPF | ======\n");
        printf("Digite o CPF que deseja buscar: ");
        scanf("%[^\n]s", cpf);
        setbuf(stdin, NULL);

        for (i = 0; i < contC; i++) {
            if (strcmp(cpf, Cliente[i].nome) == 0) {
                printf("%d Cliente", cont + 1);
                imprimeClientes(i);
                cont++;
            }
        }

        do {
        } while (continuarBusca() != 1);
    } while (1);

    printf("Total de resultados: %d \n", cont);
}

void filClientes_sexo() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, opc, cont = 0, contC = returnCont_Clientes();

    system("clear");

    do {
        printf("====== | FILTRAR POR SEXO | ======\n");
        do {
            printf("1. Sexo feminino \n"
                    "2. Sexo Masculino \n");
            scanf("%d", &opc);
        } while (opc != 1 && opc != 2);

        for (i = 0; i < contC; i++) {
            if (opc == Cliente[i].opc_sexo) {
                printf("%d Cliente", cont + 1);
                imprimeClientes(i);
                cont++;
            }
        }

        do {
        } while (continuarBusca() != 1);
    } while (1);

    printf("Total de resultados: %d \n", cont);
}

void imprimeClientes(int i) {
    Strc_Clientes* Cliente = return_Clientes();

    printf("Nome: %s \n", Cliente[i].nome);
    printf("Codigo: %d \n", Cliente[i].codigo);
    printf("Endereço completo: %s \n", Cliente[i].endereco);
    printf("CPF: %s \n", Cliente[i].cpf);
    printf("Telefone: %s \n", Cliente[i].telefone);
    printf("Telefone: %s \n", Cliente[i].email);

    printf("Sexo: ");
    if (Cliente[i].opc_sexo == 1) {
        printf("Mascukino \n");
    } else if (Cliente[i].opc_sexo == 2) {
        printf("Feminino \n");
    }

    printf("Estado civil: ");
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
}

int continuarBusca() {
    printf("Não foi encontrado nenhum resultado para sua pesquisa. Digite 1 para "
            "continuar sua pesquisa ou qualquer tecla para sair. \n \n ");

    if (selecao() == 1) {
        return 1;
    } else {
        subMenuRel_Clientes();
    }
}