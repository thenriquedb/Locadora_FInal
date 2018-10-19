#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"

//Estruturas
Strc_Clientes* Clientes = NULL;
Strc_Filmes* Filmes = NULL;
Strc_Categoria* Categorias = NULL;
Strc_Funcionario* Funcionarios = NULL;
Strc_Fornecedores* Fornecedores = NULL;

//Contadores para controle da alocação
int static contClientesAlocados = 0;
int static contFIlmesAlocados = 0;
int static contCategoriasAlocados = 0;
int static contFuncionariosAlocados = 0;
int static contFornecedoresAlocados = 0;

int alocarClientes(Strc_Clientes* cl) {

    if (Clientes == NULL) {
        Clientes = malloc(sizeof (Strc_Clientes));
    } else {
        Clientes = realloc(Clientes, (contClientesAlocados + 1) * sizeof (Strc_Clientes));
    }

    *(Clientes + contClientesAlocados) = *cl;

    if (Clientes == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contClientesAlocados++;

    return 1;
}

int alocarFilmes(Strc_Filmes* fil) {
    if (Filmes == NULL) {
        Filmes = malloc(sizeof (Strc_Filmes));
    } else {
        Filmes = realloc(Filmes, (contFIlmesAlocados + 1) * sizeof (Strc_Filmes));
    }

    *(Filmes + contFIlmesAlocados) = *fil;

    if (Filmes == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contFIlmesAlocados++;

    return 1;
}

int alocarCategoria(Strc_Categoria* cat) {
    if (Categorias == NULL) {
        Categorias = malloc(sizeof (Strc_Categoria));
    } else {
        Categorias = realloc(Categorias, (contCategoriasAlocados + 1) * sizeof (Strc_Categoria));
    }

    *(Categorias + contCategoriasAlocados) = *cat;

    if (Categorias == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contCategoriasAlocados++;

    return 1;
}

int alocarFuncionarios(Strc_Funcionario* func) {
    if (Categorias == NULL) {
        Funcionarios = malloc(sizeof (Strc_Funcionario));
    } else {
        Funcionarios = realloc(Funcionarios, (contFuncionariosAlocados + 1) * sizeof (Strc_Funcionario));
    }

    *(Funcionarios + contFuncionariosAlocados) = *func;

    if (Funcionarios == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contFuncionariosAlocados++;

    return 1;
}

int alocarFornecedores(Strc_Fornecedores* forn) {
    if (Fornecedores == NULL) {
        Fornecedores = malloc(sizeof (Strc_Fornecedores));
    } else {
        Fornecedores = realloc(Fornecedores, (contFornecedoresAlocados + 1) * sizeof (Strc_Fornecedores));
    }

    *(Fornecedores + contFornecedoresAlocados) = *forn;

    if (Funcionarios == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contFornecedoresAlocados++;

    return 1;
}
//------------------------------------------------------------------------------

int verificarCategoria() {
    int i, cont, cat;


    do {
        printf("Digite o codigo da categoria: ");
        scanf("%d", &cat);

        if (contCategoriasAlocados == 0) {
            system("clear");

            printf("Nenhuma categoria cadastrada. Para continuar é necessario realizar"
                    "o cadastro de pelo menos uma. \n");
            cadastrarCategorias();

            system("clear");
            printf("=== | CADASTRO DE FILMES | ===\n");
            printf("Continuação do cadastro do filme... \n\n");

            return 1;
            break;
        }

        for (i = 0; i < contCategoriasAlocados; i++) {
            if (cat == Categorias[i].codigo) {
                return 1;
                break;
            }
        }

        printf("Nenhuma categoria com este codigo encotrada. \n");
    } while (1);
}