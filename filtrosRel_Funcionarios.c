#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"

void filFuncionarios_Todos() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, contFun = returnCont_Funcionarios();

    system("clear");
    if (Funcionario != NULL) {
        printf("====== | VISUALIZAR TODOS FUNCIONÁRIOS CADASTRADOS | ======");

        for (i = 0; i < contFun; i++) {
            printf("\n====== | %dº FUNCIONÁRIO | ======\n", i + 1);
            imprimeFuncionarios(i);
        }
        printf("Total de resultados: %d \n\n", i);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_FaixaCodigo() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, codInicio, codFim, contFun = returnCont_Funcionarios();

    if (Funcionario != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");


            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contFun) {
                    printf("Valor maior que o número de funcionários cadastrados. \n");
                }
            } while (codFim > contFun);
            system("clear");

            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                imprimeFuncionarios(i);
            }

            printf("Nenhum resultado encontrado. \n");

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_Codigo() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, cod, contFun = returnCont_Funcionarios();

    if (Funcionario != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contFun; i++) {
                if (cod == Funcionario[i].codigo) {
                    printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                    imprimeFuncionarios(i);
                    cont++;
                }
            }
            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_Nome() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, cod, contFun = returnCont_Funcionarios();
   char nome[100];

    if (Funcionario != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contFun; i++) {
                if (strcmp(nome, Funcionario[i].nome) == 0) {
                    printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                    imprimeFuncionarios(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_Cargo() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, cod, contFun = returnCont_Funcionarios();
   char cargo[100];

    if (Funcionario != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR CARGO | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", cargo);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contFun; i++) {
                if (strcmp(cargo, Funcionario[i].cargo) == 0) {
                    printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                    imprimeFuncionarios(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void imprimeFuncionarios(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();

    printf("\tNome: %s \n", Funcionario[i].nome);
    printf("\tEndereço: %s \n", Funcionario[i].endereco);
    printf("\tTelefone: %s \n", Funcionario[i].telefone);
    printf("\tEmail: %s \n", Funcionario[i].email);
    printf("\tCargo: %s \n", Funcionario[i].cargo);
    printf("\tCódigo: %d \n", Funcionario[i].codigo);
}