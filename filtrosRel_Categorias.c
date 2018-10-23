#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"

void filCategorias_Todos() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, contCat = returnCont_Categorias();

    system("clear");
    if (Categoria != NULL) {
        printf("====== | VISUALIZAR TODOS FILMES CADASTRADOS | ======");

        for (i = 0; i < contCat; i++) {
            printf("\n====== | %dº CATEGORIA | ======\n", i + 1);
            imprimeCategorias(i);
        }
        printf("Total de resultados: %d \n", i);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filCategorias_FaixaCodigo() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, cont = 0, codInicio, codFim, contCat = returnCont_Categorias();

    if (Categoria != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contCat) {
                    printf("Valor maior que o número de categorias cadastrados. \n");
                }
            } while (codFim > contCat);
            system("clear");

            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                imprimeFuncionarios(i);
            }

            printf("Nenhum resultado encontrado. \n");

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filCategorias_Codigo() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, cod, cont = 0, contCat = returnCont_Categorias();

    if (Categoria != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contCat; i++) {
                if (cod == Categoria[i].codigo) {
                    printf("====== | %dº CATEGORIA | ======\n", cont + 1);
                    imprimeCategorias(i);
                    cont++;
                }
            }
            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filCategoria_Nome() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, cod, cont = 0, contCat = returnCont_Categorias();
    char nome[100];

    if (Categoria != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contCat; i++) {
                if (strcmp(nome, Categoria[i].nome) == 0) {
                    printf("====== | %dº CATEGORIA | ======\n", cont + 1);
                    imprimeCategorias(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void imprimeCategorias(int i) {
    Strc_Categoria* Categoria = return_Categorias();

    printf("\tNome: %s \n", Categoria[i].nome);
    printf("\tDescrição: %s \n", Categoria[i].descricao);
    printf("\tCódigo: %d \n", Categoria[i].codigo);
    printf("\tValor da multa de atraso: R$ %.2f \n", Categoria[i].valor);
}