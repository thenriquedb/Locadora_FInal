#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/structs.h"
#include <string.h>
#include <assert.h>

//Estruturas
Strc_Locadora Locadora;
Strc_Caixa Caixa;

Strc_Clientes* Clientes = NULL;
Strc_Filmes* Filmes = NULL;
Strc_Categoria* Categorias = NULL;
Strc_Funcionario* Funcionarios = NULL;
Strc_Fornecedores* Fornecedores = NULL;
Strc_Locacoes* Locacoes = NULL;
Strc_ContasReceber* Contas_aReceber = NULL;
Strc_notaFiscal *NotasFiscais = NULL;

//Contadores para controle da alocação
int static contClientesAlocados = 0;
int static contFilmes_comprados = 0;
int static contFIlmesAlocados = 0;
int static contCategoriasAlocados = 0;
int static contFuncionariosAlocados = 0;
int static contFornecedoresAlocados = 0;
int static contNotasFiscaisAlocados = 0;
int static contLocacoesAlocados = 0;
int static contContas_aReceber = 0;

int alocarEstoque_Locadora(Strc_Locadora* loc) {
    if (Locadora.filmesComprados == NULL) {
        Locadora.filmesComprados = malloc(sizeof (int));
    } else {
        Locadora.filmesComprados = realloc(Locadora.filmesComprados, (contFilmes_comprados + 1) * sizeof (int));
    }

    Locadora.contFilmes_comprados = contFilmes_comprados;

    if (Locadora.filmesComprados == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contFilmes_comprados++;
}
//-------------------------------------------------------------------------------

int* alocar_Int(int* str, int cont) {
    if (str == NULL) {
        str = malloc(sizeof (int));
    } else {
        str = realloc(str, sizeof (int)*(cont + 1));
    }

    return str;
    free(str);
}
//-------------------------------------------------------------------------------

int* alocar_FilmesComprados(int* str, int cont) {
    if (str == NULL) {
        str = malloc(sizeof (int));
    } else {
        str = realloc(str, sizeof (int)*(cont + 1));
    }

    return str;
    free(str);
}
//-------------------------------------------------------------------------------

Strc_Caixa* alocar_Financas(Strc_Caixa* str, int cont) {
    if (str == NULL) {
        str = malloc(sizeof (Strc_Caixa));
    } else {
        str = realloc(str, sizeof (Strc_Caixa)*(cont + 1));
    }

    if (str == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    return str;
    free(str);
}
//-------------------------------------------------------------------------------

Strc_MinimalFilmes* alocar_MinimalFilmes(Strc_MinimalFilmes* str, int cont) {
    if (str == NULL) {
        str = malloc(sizeof (Strc_MinimalFilmes));
    } else {
        str = realloc(str, sizeof (Strc_MinimalFilmes)*(cont + 1));
    }

    if (str == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    return str;
    free(str);
}
//-------------------------------------------------------------------------------

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
//-------------------------------------------------------------------------------

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
//-------------------------------------------------------------------------------

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
//-------------------------------------------------------------------------------

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
//-------------------------------------------------------------------------------

int alocarFornecedores(Strc_Fornecedores* forn) {
    if (Fornecedores == NULL) {
        Fornecedores = malloc(sizeof (Strc_Fornecedores));
    } else {
        Fornecedores = realloc(Fornecedores, (contFornecedoresAlocados + 1) * sizeof (Strc_Fornecedores));
    }

    *(Fornecedores + contFornecedoresAlocados) = *forn;

    if (Fornecedores == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contFornecedoresAlocados++;

    return 1;
}
//-------------------------------------------------------------------------------

int alocarNotasFiscais(Strc_notaFiscal* nota) {
    if (NotasFiscais == NULL) {
        NotasFiscais = malloc(sizeof (Strc_notaFiscal));
    } else {
        NotasFiscais = realloc(NotasFiscais, (contNotasFiscaisAlocados + 1) * sizeof (Strc_notaFiscal));
    }

    *(NotasFiscais + contNotasFiscaisAlocados) = *nota;

    if (NotasFiscais == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contNotasFiscaisAlocados++;

    return 1;
}
//-------------------------------------------------------------------------------

int alocarLocacoes(Strc_Locacoes* str) {
    if (Locacoes == NULL) {
        Locacoes = malloc(sizeof (Strc_Locacoes));
    } else {
        Locacoes = realloc(Locacoes, (contLocacoesAlocados + 1) * sizeof (Strc_Locacoes));
    }

    *(Locacoes + contLocacoesAlocados) = *str;

    if (Locacoes == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contLocacoesAlocados++;

    return 1;
}
//-------------------------------------------------------------------------------

int alocarContas_aReceber(Strc_ContasReceber* str) {
    if (Contas_aReceber == NULL) {
        Contas_aReceber = malloc(sizeof (Strc_ContasReceber));
    } else {
        Contas_aReceber = realloc(Contas_aReceber, (contContas_aReceber + 1) * sizeof (Strc_ContasReceber));
    }

    *(Contas_aReceber + contContas_aReceber) = *str;

    if (Contas_aReceber == NULL) {
        printf("Ocorreu um erro durante a alocação, \n");
        exit(EXIT_FAILURE);
    }

    contContas_aReceber++;

    return 1;
}
//------------------------------------------------------------------------------

//-----------------------| FUNÇÕES PARA RETORNO DOS VETORES |--------------------

Strc_Locadora return_Locadora() {
    return Locadora;
}

Strc_Caixa return_Financas() {
    return Caixa;
}

Strc_Clientes* return_Clientes() {
    return Clientes;
}

Strc_Filmes* return_Filmes() {
    return Filmes;
}

Strc_Categoria* return_Categorias() {
    return Categorias;
}

Strc_Funcionario* return_Funcionarios() {
    return Funcionarios;
}

Strc_Fornecedores* return_Fornecedores() {
    return Fornecedores;
}

Strc_notaFiscal* return_NotasFiscais() {
    return NotasFiscais;
}

Strc_Locacoes* return_Locacoes() {
    return Locacoes;
}

Strc_ContasReceber* return_contasReceber() {
    return Contas_aReceber;
}

//-----------------------| FUNÇÕES PARA RETORNO DOS CONTADORES |----------------

int returnCont_Clientes() {
    return contClientesAlocados;
}

int returnCont_Filmes() {
    return contFIlmesAlocados;
}

int returnCont_Categorias() {
    return contCategoriasAlocados;
}

int returnCont_Funcionarios() {
    return contFuncionariosAlocados;
}

int returnCont_Fornecedores() {
    return contFornecedoresAlocados;
}

int returnCont_NotasFiscais() {
    return contNotasFiscaisAlocados;
}

int returnCont_Locacoes() {
    return contLocacoesAlocados;
}

int returnCont_contasReceber() {
    return contContas_aReceber;
}

//-----------------------| FUNÇÕES PARA ALTERAR DADOS ORIGINAIS |----------------

int alterarLocadora(Strc_Locadora loc) {
    Locadora = loc;
}

int alterarFinanceiro(Strc_Caixa fin) {
    Caixa = fin;
}

void alterarClientes(Strc_Clientes *cl) {
    Clientes = cl;
}

void alterar_contClientes(int cont) {
    contClientesAlocados = cont;
}

void alterarFilmes(Strc_Filmes *fil) {
    Filmes = fil;
}

void alterar_contFilmes(int cont) {
    contFIlmesAlocados = cont;
}

void alterarCategorias(Strc_Categoria *cat) {
    Categorias = cat;
}

void alterar_contCategorias(int cont) {
    contCategoriasAlocados = cont;
}

void alterarFuncionarios(Strc_Funcionario *fun) {
    Funcionarios = fun;
}

void alterar_contFuncionarios(int cont) {
    contFuncionariosAlocados = cont;
}

void alterarFornecedores(Strc_Fornecedores *forn) {
    Fornecedores = forn;
}

void alterar_contFornecedores(int cont) {
    contFornecedoresAlocados = cont;
}

void alterarNotasFiscais(Strc_notaFiscal *nota) {
    NotasFiscais = nota;
}

void alterar_contNotasFiscais(int nota) {
    contNotasFiscaisAlocados = nota;
}

void alterarLocacoes(Strc_Locacoes *locacoes) {
    Locacoes = locacoes;
}

void alterar_contLocacoes(int cont) {
    contLocacoesAlocados = cont;
}

void alterar_contasReceber(Strc_ContasReceber *str) {
    Contas_aReceber = str;
}

void alterar_contcontasReceber(int cont) {
    contContas_aReceber = cont;
}

