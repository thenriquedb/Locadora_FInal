#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"

void filFilmes_Todos() {
    Strc_Filmes* Filme = return_Filmes();
    int i, contF = returnCont_Filmes();

    system("clear");
    if (Filme != NULL) {
        printf("====== | VISUALIZAR TODOS FILMES CADASTRADOS | ======");

        for (i = 0; i < contF; i++) {
            printf("\n====== | %dº FILME | ======\n", i + 1);
            imprimeFilmes(i);
        }
        printf("Total de resultados: %d \n\n", i);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Codigo() {
    Strc_Filmes* Filme = return_Filmes();
    int i, cod, cont = 0, contF = returnCont_Filmes();

    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contF; i++) {
                if (cod == Filme[i].codigo) {
                    printf("====== | %dº FILME | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_FaixaCodigo() {
    Strc_Filmes* Filme = return_Filmes();
    int i, cont = 0, codInicio, codFim, contF = returnCont_Filmes();

    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");


            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contF) {
                    printf("Valor maior que o número de filmes cadastrados. \n");
                }
            } while (codFim > contF);
            system("clear");


            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FILME | ======\n", cont + 1);
                imprimeFilmes(i);
            }
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Nome() {
    Strc_Filmes* Filme = return_Filmes();
    int i, cont = 0, contF = returnCont_Filmes();
    char titulo[100];

    if (Filme != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR TÍTULO | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", titulo);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR TÍTULO | ======\n");
            for (i = 0; i < contF; i++) {
                if (strcmp(titulo, Filme[i].nome) == 0) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Exemplares() {
    Strc_Filmes* Filme = return_Filmes();
    int i, exemplares, cont = 0, contF = returnCont_Filmes();

    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR EXEMPLARES | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%d", &exemplares);

            system("clear");
            printf("====== | FILTRAR POR EXEMPLARES | ======\n");

            for (i = 0; i < contF; i++) {
                if (exemplares == Filme[i].exemplares) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Idioma() {
    Strc_Filmes* Filme = return_Filmes();
    int i, opc, cont = 0, contF = returnCont_Filmes();

    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR IDIOMA | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%d", &opc);

            system("clear");
            printf("====== | FILTRAR POR IDIOMA | ======\n");

            for (i = 0; i < contF; i++) {
                if (opc == Filme[i].idioma) {
                    printf("====== | %dº FILME | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void imprimeFilmes(int i) {
    Strc_Filmes* Filme = return_Filmes();
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Categoria* Categoria = return_Categorias();

    int posCategoria = Filme[i].codigoCategoria - 1;
    int posFornecedor = Filme[i].codigoFornecedor - 1;

    printf("\tTítulo: %s \n", Filme[i].nome);
    printf("\tDescrição: %s \n", Filme[i].descricao);
    printf("\tCodígo uníco: %d \n", Filme[i].codigo);
    printf("\tFornecedor: %s (%d)\n", Fornecedor[0].razaoScial, Filme[i].codigoFornecedor);
    printf("\tIdioma: ");
    if (Filme[i].idioma == 1) {
        printf("Dublado \n");
    } else {
        printf("Legendado \n");
    }

    printf("\tCategoria: %s (%d) \n", Categoria[posCategoria].nome, Filme[i].codigoCategoria);
    printf("\tExemplares disponiveis: %d \n", Filme[i].exemplares);
}
//-------------------------------------------------------------------------------

