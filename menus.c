
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/menus.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"
#include "Bibliotecas/administracao.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/financas.h"
#include "Bibliotecas/fileTXT.h"

void menuInicial() {

    printf("====== | INICIALIZALIZAÇÃO DO SOFTWARE | ======\n"
            "\t1. Iniciar do zero \n"
            "\t2. Importar  informações anteriores \n");

    switch (selecao()) {
        case 1:
            excluirArquivos_txt();
            cadastrarLocadora();
            break;

        case 2:
            menuImportacao();
    }
}
//------------------------------------------------------------------------------

void menuImportacao() {
    printf("====== | IMPORTAÇÃO DE DADOS | ======\n");
    printf("\t1. Clientes \n"
            "\t2. Filmes \n"
            "\t3. Categoria \n"
            "\t4. Funciónarios \n"
            "\t5. Fornecedores \n"
            "\t6. Locações \n"
            "\t7. Notas fiscais \n"
            "\t8. Contas a pagar \n"
            "\t9. Contas a receber \n"
            "\t10. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            importCliente_txt();
            break;

        case 2:
            importFilmes_txt();
            break;

        case 3:
            importCategoria_txt();
            break;

        case 4:
            importFuncionarios_txt();
            break;

        case 5:
            importFornecedores_txt();
            break;

        case 10:
            menuInicial();
            break;

        default:
            printf("Opção inválida");

    }
    system("clear");
}

void menuCadastro() {
    printf("====== | CADASTROS | ======\n");
    printf("\t1. Cadastrar clientes \n"
            "\t2. Cadastrar filmes \n"
            "\t3. Cadastrar categoria \n"
            "\t4. Cadastrar funcionarios \n"
            "\t5. Cadastrar fonecedores \n"
            "\t6. Retornar ao menu principal \n");

    switch (selecao()) {
        case 1:
            cadastrarClientes();
            break;

        case 2:
            if (return_Fornecedores() != NULL && return_Categorias() != NULL) {
                cadastrarFilmes();
            } else {
                printf("Antes de cadastrar algum filme é necessario cadastrar um fornecedor primeiro. \n ");
            }
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
            if (return_Clientes() != NULL) {
                subMenuRel_Clientes();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum cliente cadastrado. \n");
            }
            break;

        case 2:
            if (return_Filmes() != NULL) {
                subMenuRel_Filmes();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            if (return_Categorias() != NULL) {
                subMenuRel_Categorias();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhuma categoria cadastrado. \n");
            }
            break;

        case 4:
            if (return_Funcionarios() != NULL) {
                subMenuRel_Funcionarios();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum funcionário cadastrado. \n");
            }
            break;

        case 5:
            if (return_Fornecedores() != NULL) {
                subMenuRel_Fornecedores();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum fornecedor cadastrado. \n");
            }
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

//------------------------------------------------------------------------------

void menu_EntradaFilmes() {
    printf("====== | COMPRAS DE NOVOS FILMES | ======\n"
            "\t1. Visualizar fornecedores cadastrados \n"
            "\t2. Cadastrar novo fornecedor \n"
            "\t3. Escolher fornecedor através do codigo \n"
            "\t4. Voltar ao menu anterior \n");
    do {
        switch (selecao()) {
            case 1:
                subMenuRel_Fornecedores();
                break;

            case 2:
                cadastrarFornecedores();
                break;

            case 3:
                entradaFilmes();

            case 4:
                menuAdministrativo();
                break;

            default:
                printf("Opção inválida. \n");
        }
        break;
    } while (1);
}
//------------------------------------------------------------------------------

void menuGestao() {
    int cod;

    printf("====== | GESTÃO DE DADOS | ======\n");
    printf("Edições ou exclusões de dados so podem ser realizados por funcionarios já cadastrados no sistema. \n");
    printf("Digite o seu codigo de cadastro: ");
    scanf("%d", &cod);

    system("clear");
    if (verificarCod_Funcionario(cod) == 1) {

        printf("====== | GESTÃO DE DADOS | ======\n"
                "\t1. Editar dados \n"
                "\t2. Excluir dadas \n"
                "\t3. Voltar para o menu principal \n");

        switch (selecao()) {
            case 1:
                subMenuGestao_Editar();
                break;

            case 2:
                subMenuGestao_Excluir();
                break;

            case 3:
                break;

            default:
                printf("Opção inválida. \n");
        }

    } else {
        printf("Código inválido. \n");
    }
}
//------------------------------------------------------------------------------

void menuLocacao() {
    printf("====== | LOCAÇÃO | ======\n"
            "\t1. Locação de filmes \n"
            "\t2. Devolução de filmes \n"
            "\t3. Locações realizadas \n"
            "\t4. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_Funcionarios() != NULL && return_Clientes() != NULL) {
                locacaoFilmes();
            } else {
                printf("Para efetuar uma locação é necessario ter pelo um cliente "
                        "e um funcionário ja cadastrado no sistema. \n ");
            }
            break;

        case 2:
            if (return_Locacoes() != NULL) {
                DevolucaoFilmes();
            } else {
                printf("Nenhuma locação realizada. \n ");
            }
            break;

        case 3:
            if (return_Locacoes() != NULL) {
                menuLocacoes();
            } else {
                printf("Nenhuma locação realizada. \n");
            }
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

void menuFinancas() {
    printf("====== | FINANCEIRO | ======\n"
            "\t1. Contas a receber \n"
            "\t2. Contas a pagar \n"
            "\t3. Notas fiscais \n"
            "\t4. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_contasReceber() != NULL) {
                menuContas_aReceber();
            } else {
                printf("Nenhuma conta a receber. \n");
            }
            break;

        case 2:
            if (return_NotasFiscais() != NULL) {
                menuContas_aPagar();
            } else {
                printf("Nenhuma nota fiscal foi cadastrada. \n");
            }
            break;

        case 3:
            if (return_NotasFiscais() != NULL) {
                menuNotasFiscais();
            } else {
                printf("Nenhuma nota fiscal foi cadastrada. \n");
            }
            break;

        case 4:
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

void menuAdministrativo() {
    printf("====== | ADMINISTRATIVO | ======\n"
            "\t1. Dados do estabelecimento \n"
            "\t2. Compra de filmes \n"
            "\t3. Quantidade de locações para que um filme se pague \n"
            "\t4. Visualizar estoque da locadora \n"
            "\t5. Voltar para o menu principal \n");

    Strc_Locadora Locadora = return_Locadora();

    switch (selecao()) {
        case 1:
            imprimeLocadora();
            digiteAlguma_teclaContinuar();
            break;

        case 2:
            if (return_Filmes() != NULL) {
                menu_EntradaFilmes();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            menuLocacoes_FilmeSePagar();
            break;

        case 4:
            if (Locadora.filmesComprados != NULL) {
                visualizarEstoque();
            }
            printf("Nenhum filme comprado. \n");
            break;

        case 5:
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

void menuNotasFiscais() {
    printf("====== | NOTAS FISCAIS | ======\n"
            "\t1. Visualizar todas \n"
            "\t2. Filtrar por fornecedor \n"
            "\t3, Faixa de codígo dos fornecedores \n"
            "\t4. Visualazir as que já pagas \n"
            "\t5. Visualizar as que ainda não foram pagas \n"
            "\t6. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            filNotasFiscais_Todas();
            break;

        case 2:
            filNotasFiscais_Fornecedor();
            break;

        case 3:
            filNotasFiscais_codigoFornecedor();
            break;

        case 4:
            filNotasFiscais_Pagas();
            break;

        case 5:
            filNotasFiscais_NaoPagas();
            break;

        case 6:
            menuAdministrativo();

        default:
            printf("Opção inválida. \n");
    }
}

void menuLocacoes_FilmeSePagar() {
    printf("====== | LOCAÇÕES RESTANTE PARA QUE UM FILME SE PAGUE | ======\n"
            "\t1. Situação de todos os filmes \n"
            "\t2. Filmes pagos \n"
            "\t3, Filmes com déficit \n"
            "\t4. Código do filme \n"
            "\t5. Faixa de códigos \n"
            "\t6. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            contLocacoes_FilmesePaga_Todos();
            break;

        case 2:
            contLocacoes_FilmesePaga_Pagos();
            break;

        case 3:
            contLocacoes_FilmesePaga_Deficit();
            break;

        case 4:
            contLocacoes_FilmesePaga_codFilme();
            break;

        case 5:
            contLocacoes_FilmesePaga_faixaCodigo();
            break;

        case 6:
            menuAdministrativo();

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

void menuContas_aPagar() {
    printf("====== | CONTAS A PAGAR | ======\n"
            "\t1. Visualizar notas fiscais \n"
            "\t2. Pagar nota fiscal \n"
            "\t3. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            menuNotasFiscais();
            break;

        case 2:
            system("clear");
            subMenuContas_aPagar();
            break;

        case 3:
            menuFinancas();

        default:
            printf("Opção inválida. \n");
    }
}

void menuContas_aReceber() {
    printf("====== | CONTAS A RECEBER | ======\n"
            "\t1. Receber pagamento cliente \n"
            "\t2. Visualizar todas contas a receber \n"
            "\t3. Pesquisar contas a receber por faixa de código \n"
            "\t4. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            receber_ContasCl();
            break;

        case 2:
            filContaReceber_todas();
            break;

        case 3:
            filContaReceber_faixaCodigo();
            break;

        case 4:
            menuFinancas();
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

void menuLocacoes() {
    printf("====== | LOCAÇÕES | ======\n"
            "\t1. Todas as locações \n"
            "\t2. Locações a vista \n"
            "\t3. Locações a prazo \n"
            "\t4. Por funcionárior \n"
            "\t5. Data \n"
            "\t6. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filLocacoes_todas();
            digiteAlguma_teclaContinuar();
            break;

        case 2:
            system("clear");
            filLocacoes_aVista();
            digiteAlguma_teclaContinuar();
            break;

        case 3:
            filLocacoes_aPrazo();
            digiteAlguma_teclaContinuar();
            break;

        case 4:
            filLocacoes_Func();
            digiteAlguma_teclaContinuar();
            break;

        case 5:
            filLocacoes_Data();
            digiteAlguma_teclaContinuar();
            break;

        case 6:
            menuLocacao();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

/*------------------------------------------------------------------------------ 
 *
 ------------------------------------------------------------------------------*/
void subMenuContas_aPagar() {
    printf("====== | OPÇÕES DE PAGAMENTO | ======\n"
            "\t1. Pagar uma uníca nota fiscal \n"
            "\t2. Pagar todas notas  fiscal \n"
            "\t3. Pagar todas notas de determinado fornecedor \n"
            "\t4. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            contasPagar_Unica();
            break;

        case 2:
            contasPagar_Todas();
            break;

        case 3:
            break;

        case 4:
            menuAdministrativo();

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

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
            if (return_Clientes() != NULL) {
                subMenu_edicaoClientes();
            } else {
                printf("Nenhum cliente cadastrado. \n");
            }
            break;

        case 2:
            if (return_Filmes() != NULL) {
                subMenu_edicaoFilmes();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            if (return_Categorias() != NULL) {
                subMenu_edicaoCategorias();
            } else {
                printf("Nenhuma cetgoria cadastrado. \n");
            }
            break;

        case 4:
            if (return_Funcionarios() != NULL) {
                subMenu_edicaoFuncionarios();
            } else {
                printf("Nenhum funcionário cadastrado. \n");
            }
            break;

        case 5:
            if (return_Fornecedores() != NULL) {
                subMenu_edicaoFornecedores();
            } else {
                printf("Nenhum fornecedor cadastrado. \n");
            }
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}
//------------------------------------------------------------------------------

void subMenuGestao_Excluir() {

    printf("====== | GESTÃO DE DADOS: EXCLUSÃO | ======\n"
            "Deseja excluir: \n"
            "\t1. Cliente \n"
            "\t2. Filme \n"
            "\t3. Categoria \n"
            "\t4. Funcionário \n"
            "\t5. Fornecedor \n"
            "\t6. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_Clientes() != NULL) {
                excluirCliente();
            } else {
                printf("Nenhum cliente cadastrado. \n");
            }
            break;

        case 2:
            if (return_Filmes() != NULL) {
                excluirFilme();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            if (return_Categorias() != NULL) {
                excluirCategoria();
            } else {
                printf("Nenhuma categoria cadastrado. \n");
            }
            break;

        case 4:
            if (return_Funcionarios() != NULL) {
                excluirFuncionario();
            } else {
                printf("Nenhum funcionário cadastrado. \n");
            }
            break;

        case 5:
            if (return_Fornecedores() != NULL) {
                excluirFornecedor();
            } else {
                printf("Nenhum forncedor cadastrado. \n");
            }
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