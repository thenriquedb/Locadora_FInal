
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/menus.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"

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
//-------------------------------------------------------------------------------

void menuRelatorios() {

    printf("====== | RELATORIOS | ======\n"
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
            subMenuRel_Filmes();
            break;

        case 3:
            subMenuRel_Categorias();
            break;

        case 4:
            subMenuRel_Funcionarios();
            break;

        case 5:
            subMenuRel_Fornecedores();
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

//------------------------------------------------------------------------------

void menuGestao() {
    int cod;
    /*
        printf("====== | GESTÃO DE DADOS: EDIÇÃO | ======\n");
        printf("Edições de dados so podem ser realizados por funcionarios já cadastrados no sistema. \n");
        printf("Digite o seu codigo de cadastro: ");
        scanf("%d", &cod);

        system("clear");
        if (verificarFuncionario(cod) == 1) {
     */
    printf("====== | GESTÃO DE DADOS | ======\n"
            "\t1. Editar dados \n"
            "\t2. Excluir dadas \n"
            "\t3. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            subMenuGestao_Editar();
            break;

        case 2:
            break;

        case 3:
            break;

        default:
            printf("Opção inválida. \n");
    }
    /*   
    } else {
            printf("Código inválido. \n");
        }
     * */
}

void subMenuGestao_Editar() {

    printf("====== | GESTÃO DE DADOS: EDIÇÃO | ======\n"
            "Deseja editar: \n"
            "\t1. Cliente \n"
            "\t2. Filme \n"
            "\t3. Categoria \n"
            "\t4. Funcionário \n"
            "\t5. Fornecedor \n"
            "\t6. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            subMenu_edicaoClientes();
            break;

        case 2:
            subMenu_edicaoFilmes();
            break;

        case 3:
            subMenu_edicaoCategorias();
            break;

        case 4:
            subMenu_edicaoFuncionarios();
            break;

        case 5:
            subMenu_edicaoFornecedores();
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//-------------------------------------------------------------------------------

void subMenu_edicaoClientes() {
    printf("====== | EDIÇÃO DE CLIENTES | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar clientes cadastrados \n"
            "\t2. Buscar cliente pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Clientes();
            break;

        case 2:
            edicaoCliente();
            break;
    }
}
//-------------------------------------------------------------------------------

void subMenu_edicaoFilmes() {
    printf("====== | EDIÇÃO DE FILMES | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar filmes cadastrados \n"
            "\t2. Buscar filme pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Filmes();
            break;

        case 2:
            edicaoFilme();
            break;
    }
}
//-------------------------------------------------------------------------------

void subMenu_edicaoCategorias() {
    printf("====== | EDIÇÃO DE CATEGORIAS | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar categorias cadastrados \n"
            "\t2. Buscar categoria pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Categorias();
            break;

        case 2:
            edicaoCategoria();
            break;
    }
}
//-------------------------------------------------------------------------------

void subMenu_edicaoFuncionarios() {
    printf("====== | EDIÇÃO DE FUNCIONÁRIOS | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar funcionários cadastrados \n"
            "\t2. Buscar funcionário pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Funcionarios();
            break;

        case 2:
            edicaoFuncionario();
            break;
    }
}
//-------------------------------------------------------------------------------

void subMenu_edicaoFornecedores() {
    printf("====== | EDIÇÃO DE FORNECEDORES | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar fornecedores cadastrados \n"
            "\t2. Buscar fornecedor pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Fornecedores();
            break;

        case 2:
            edicaoFornecedor();
            break;
    }
}
//-------------------------------------------------------------------------------

void subMenuRel_Clientes() {
    printf("====== | RELATÓRIO: CLIENTES | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. CPF \n"
            "\t4. Sexo \n"
            "\t5. Visualizar todos \n"
            "\t6. Faixa de códigos \n"
            "\t7. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filClientes_Nome();
            break;

        case 2:
            filClientes_Codigo();
            break;

        case 3:
            filClientes_CPF();
            break;

        case 4:
            filClientes_Sexo();
            break;

        case 5:
            filClientes_Todos();
            break;

        case 6:
            filClientes_FaixaCodigo();
            break;

        case 7:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//-------------------------------------------------------------------------------

void subMenuRel_Filmes() {
    printf("====== | RELATÓRIO: FILMES | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. Idioma \n"
            "\t4. Exemplares \n"
            "\t5. Visualizar todos \n"
            "\t6. Faixa de códigos \n"
            "\t7. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFilmes_Nome();
            break;

        case 2:
            filFilmes_Codigo();
            break;

        case 3:
            filFilmes_Idioma();
            break;

        case 4:
            filFilmes_Exemplares();
            break;

        case 5:
            filFilmes_Todos();
            break;

        case 6:
            filFilmes_FaixaCodigo();
            break;

        case 7:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//-------------------------------------------------------------------------------

void subMenuRel_Categorias() {
    printf("====== | RELATÓRIO: CATEGORIAS | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. Visualizar todos \n"
            "\t4. Faixa de códigos \n"
            "\t5. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filCategoria_Nome();
            break;

        case 2:
            filCategorias_Codigo();
            break;

        case 3:
            filCategorias_Todos();
            break;

        case 4:
            filCategorias_FaixaCodigo();
            break;

        case 5:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//-------------------------------------------------------------------------------

void subMenuRel_Funcionarios() {
    printf("====== | RELATÓRIO: FUNCIONÁRIOS | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. Cargo \n"
            "\t4. Visualizar todos \n"
            "\t5. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFuncionarios_Nome();
            break;

        case 2:
            filCategorias_Codigo();
            break;

        case 3:
            filFuncionarios_Cargo();
            break;

        case 4:
            filFuncionarios_Todos();
            break;

        case 5:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//-------------------------------------------------------------------------------

void subMenuRel_Fornecedores() {
    printf("====== | RELATÓRIO: FORNECEDORES | ======\n"
            "Filtrar por: \n"
            "\t1. Razão social \n"
            "\t2. Nome fantasia \n"
            "\t3. Codigo \n"
            "\t4. CNPJ \n"
            "\t5. Inscrição social \n"
            "\t6. Visualizar todos \n"
            "\t7. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFornecedores_RazaoSocial();
            break;

        case 2:
            filFornecedores_NomeFantasia();
            break;

        case 3:
            filFornecedores_Codigo();
            break;

        case 4:
            filFornecedores_CNPJ();
            break;

        case 5:
            filFornecedores_InscricaoSocial();
            break;

        case 6:
            filFornecedores_Todos();
            break;

        case 7:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}