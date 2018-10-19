
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/menus.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"

void menuCadastro() {
    printf("====== | CADASTROS | ======\n");
    printf("\t1. Cadastrar clientes \n"
            "\t2. Cadastrar filmes \n"
            "\t3. Cadastrar categoria \n"
            "\t4. Cadastrar funcionarios \n"
            "\t5. Cadastrar fonecedores \n"
            "\t6. Retornar ao menu principal");

    switch (selecao()) {
        case 1:
            cadastrarClientes();
            break;

        case 2:
            cadastrarFilmes();
            break;

        case 3:
            cadastrarCategorias();
            break;

        case 4:
            cadastrarFuncionarios();
            break;

        case 5:
            cadastrarFornecedores();
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void menuRelatorios() {

    printf("====== | RELATORIO | ======\n"
            "\t1. Relatorio de clientes \n"
            "\t2. Relatorio de filmes \n"
            "\t3. Relatorio de categoria \n"
            "\t4. Relatorio de funcionarios \n"
            "\t5. Relatorio de fonecedores \n"
            "\t6. Retornar ao menu principal \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Clientes();
            break;

        case 2:
            // relatorioFilmes();
            break;

        case 3:
            // relatorioCategorias();
            break;

        case 4:
            //  relatorioFuncionarios();
            break;

        case 5:
            //relatorioFornecedores();
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuRel_Clientes() {
    printf("====== | RELATÓRIO: CLIENTES | ======\n"
            "Filtrar por: \n"
            "\t1. Visualizar todos \n"
            "\t2. Codigo \n"
            "\t3. Nome \n"
            "\t4. CPF \n"
            "\t5. Sexo\n"
            "\t6. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 6:
            menuRelatorios();
            break;
    }

}
