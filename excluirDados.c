#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"

void excluirCliente() {
    Strc_Clientes* Cliente = return_Clientes();
    int cod, verifica = 0, contCliente = returnCont_Clientes();

    printf("====== | EXCLUIR CLIENTE CADASTRADO | ======\n");
    printf("Digite o codigo do cliente que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contCliente; i++) {
        if (cod == Cliente[i].codigo) {
            verifica++;
            do {
                Cliente[i] = Cliente[i + 1];
                i++;
            } while (i < contCliente);
            break;
        }
    }
    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Cliente excluído com sucesso. \n");
        contCliente = contCliente - 1;

        if (contCliente == 0) {
            Cliente = NULL;
        }
        alterarClientes(Cliente);
        alterar_contClientes(contCliente);
    }
}






void excluirFuncionario() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int cod, verifica = 0, contFunc = returnCont_Fornecedores();

    printf("====== | EXCLUIR FUNCIONÁRIO CADASTRADO | ======\n");
    printf("Digite o codigo do funcionário que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contFunc; i++) {
        if (cod == Funcionario[i].codigo) {
            verifica++;
            do {
                Funcionario[i] = Funcionario[i + 1];
                i++;
            } while (i < contFunc);
            break;
        }
    }

    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Funcionário excluído com sucesso. \n");
        contFunc = contFunc - 1;

        if (contFunc == 0) {
            Funcionario = NULL;
        }

        alterarFuncionarios(Funcionario);
        alterar_contFuncionarios(contFunc);
    }
}






void excluirCategoria() {
    Strc_Categoria* Categoria = return_Categorias();
    int cod, verifica = 0, contCat = returnCont_Categorias();

    printf("====== | EXCLUIR CATEGORIA CADASTRADA | ======\n");
    printf("Digite o codigo da categoria que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contCat; i++) {
        if (cod == Categoria[i].codigo) {
            verifica++;
            do {
                Categoria[i] = Categoria[i + 1];
                i++;
            } while (i < contCat);
            break;
        }
    }
    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Categoria excluída com sucesso. \n");
        contCat = contCat - 1;
        alterarCategorias(Categoria);
        alterar_contCategorias(contCat);
    }
}






void excluirFilme() {
    Strc_Filmes* Filme = return_Filmes();
    int cod, verifica = 0, contFilmes = returnCont_Filmes();

    printf("====== | EXCLUIR FILME CADASTRADO | ======\n");
    printf("Digite o codigo do filme que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contFilmes; i++) {
        if (cod == Filme[i].codigo) {
            verifica++;
            do {
                Filme[i] = Filme[i + 1];
                i++;
            } while (i < contFilmes);
            break;
        }
    }
    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Filme excluído com sucesso. \n");
        contFilmes -= contFilmes;

        if (contFilmes == 0) {
            Filme = NULL;
        }

        alterarFilmes(Filme);
        alterar_contFilmes(contFilmes);
    }
}






void excluirFornecedor() {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int cod, verifica = 0, contForn = returnCont_Fornecedores();

    printf("====== | EXCLUIR FORNECEDOR CADASTRADO | ======\n");
    printf("Digite o codigo do fornecedor que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contForn; i++) {
        if (cod == Fornecedor[i].codigo) {
            verifica++;
            do {
                Fornecedor[i] = Fornecedor[i + 1];
                i++;
            } while (i < contForn);
            break;
        }
    }

    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Fornecedor excluído com sucesso. \n");
        contForn = contForn - 1;

        if (contForn == 0) {
            Fornecedor = NULL;
        }

        alterarFornecedores(Fornecedor);
        alterar_contFornecedores(contForn);
    }
}