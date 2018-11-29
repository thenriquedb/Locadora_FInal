#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/structs.h"
#include <string.h>
#include <assert.h>

/*******************************************************************************
 *  Estruturas unicas 
 ********************************************************************************/
Strc_Locadora Locadora;
Strc_Caixa Caixa;

/********************************************************************************
 * Variaveis dinâmicas globais  
 ********************************************************************************/
Strc_Clientes* Clientes = NULL;
Strc_Filmes* Filmes = NULL;
Strc_Categoria* Categorias = NULL;
Strc_Funcionario* Funcionarios = NULL;
Strc_Fornecedores* Fornecedores = NULL;
Strc_Locacoes* Locacoes = NULL;
Strc_ContasReceber* Contas_aReceber = NULL;
Strc_notaFiscal *NotasFiscais = NULL;

/********************************************************************************
 * Contadores para controle da alocação
 * Contadores estaticos utilizado para armazenar a quantidade de dados cadastrados
 * de determinado tipo.
 * ******************************************************************************/
int static contClientesAlocados = 0;
int static contFilmes_comprados = 0;
int static contFIlmesAlocados = 0;
int static contCategoriasAlocados = 0;
int static contFuncionariosAlocados = 0;
int static contFornecedoresAlocados = 0;
int static contNotasFiscaisAlocados = 0;
int static contLocacoesAlocados = 0;
int static contContas_aReceber = 0;
int static verificaoLocadora = 0;

/********************************************************************************
 * Alcoar memoria para o estoque de filmes  da locadora
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para a numeros inteiros
 * ******************************************************************************/
int* alocar_Int(int* str, int cont) {
    if (str == NULL) {
        str = malloc(sizeof (int));
    } else {
        str = realloc(str, sizeof (int)*(cont + 1));
    }

    return str;
    free(str);
}

/********************************************************************************
 * Alcoar memoria para a filmes comprados pelo estabelecimento
 * ******************************************************************************/
int* alocar_FilmesComprados(int* str, int cont) {
    if (str == NULL) {
        str = malloc(sizeof (int));
    } else {
        str = realloc(str, sizeof (int)*(cont + 1));
    }

    return str;
    free(str);
}


/********************************************************************************
 * Alocoar memoria para as operações relacionadas a finanças
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para a versão minimalista de filmes 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para cliente cadastrados 
 * ******************************************************************************/
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


/********************************************************************************
 * Alcoar memoria para os filmes cadastrados 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para as categorias cadastrados 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para os funcionários cadastrados 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para os fornecedores cadastrados 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para as notas fiscais cadastrados 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para os filmes alugados cadastrados 
 * ******************************************************************************/
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

/********************************************************************************
 * Alcoar memoria para contas a receber 
 * ******************************************************************************/
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

/********************************************************************************
 * Retornar a variavel que contem os dados da locadora 
 * ******************************************************************************/
Strc_Locadora return_Locadora() {
    return Locadora;
}

/********************************************************************************
 * Retornar a variavel que contem os dados do caixa 
 * ******************************************************************************/
Strc_Caixa return_Caixa() {
    return Caixa;
}

/********************************************************************************
 * Retornar o vetor dinâmico de clientes 
 * ******************************************************************************/
Strc_Clientes* return_Clientes() {
    return Clientes;
}

/********************************************************************************
 * Retornar o vetor dinâmico de filmes 
 * ******************************************************************************/
Strc_Filmes* return_Filmes() {
    return Filmes;
}

/********************************************************************************
 * Retornar o vetor dinâmico de categoria 
 * ******************************************************************************/
Strc_Categoria* return_Categorias() {
    return Categorias;
}

/********************************************************************************
 * Retornar o vetor de funcionarios 
 * ******************************************************************************/
Strc_Funcionario* return_Funcionarios() {
    return Funcionarios;
}

/********************************************************************************
 * Retornar o vetor dinâmicos de fornecedores 
 * ******************************************************************************/
Strc_Fornecedores* return_Fornecedores() {
    return Fornecedores;
}

/********************************************************************************
 * Retornar o vetor dinâmicos de notas fiscais 
 * ******************************************************************************/
Strc_notaFiscal* return_NotasFiscais() {
    return NotasFiscais;
}

/********************************************************************************
 * Retornar o vetor dinâmicos de filmes alugados 
 * ******************************************************************************/
Strc_Locacoes* return_Locacoes() {
    return Locacoes;
}

/********************************************************************************
 * Retornar o vetor dinâmicos de contas a receber 
 * ******************************************************************************/
Strc_ContasReceber* return_contasReceber() {
    return Contas_aReceber;
}

/********************************************************************************
 * Retornar a quantidade de clientes cadastrados 
 * ******************************************************************************/
int returnCont_Clientes() {
    return contClientesAlocados;
}

/********************************************************************************
 * Retornar a quantidade de filmes cadastrados 
 * ******************************************************************************/
int returnCont_Filmes() {
    return contFIlmesAlocados;
}

/********************************************************************************
 * Retornar a quantidade de categorias cadastradas 
 * ******************************************************************************/
int returnCont_Categorias() {
    return contCategoriasAlocados;
}

/********************************************************************************
 * Retornar a quantidade de funcionarios cadastrados 
 * ******************************************************************************/
int returnCont_Funcionarios() {
    return contFuncionariosAlocados;
}

/********************************************************************************
 * Retornar a quantidade de fornecedores cadastrados 
 * ******************************************************************************/
int returnCont_Fornecedores() {
    return contFornecedoresAlocados;
}

/********************************************************************************
 * Retornar a quantidade de notas fiscais cadastrados 
 * ******************************************************************************/
int returnCont_NotasFiscais() {
    return contNotasFiscaisAlocados;
}

/********************************************************************************
 * Retornar a quantidade de filmes alugados cadastrados 
 * ******************************************************************************/
int returnCont_Locacoes() {
    return contLocacoesAlocados;
}

/********************************************************************************
 * Retornar a quantidade de contas a receber cadastrados 
 * ******************************************************************************/
int returnCont_contasReceber() {
    return contContas_aReceber;
}



/********************************************************************************
 * Altera o dado da locadora ja cadastrado 
 * ******************************************************************************/
int alterarLocadora(Strc_Locadora loc) {
    Locadora = loc;
    verificaoLocadora = 1;
}

/********************************************************************************
 * Altera o dado do caixa
 * ******************************************************************************/
int alterarCaixa(Strc_Caixa fin) {
    Caixa = fin;
}

/********************************************************************************
 * Altera os dados dos clientes cadastrado 
 * ******************************************************************************/
void alterarClientes(Strc_Clientes *cl) {
    Clientes = cl;
}



/********************************************************************************
 * Altera os dados da locadora ja cadastrado 
 * ******************************************************************************/
void alterarFilmes(Strc_Filmes *fil) {
    Filmes = fil;
}



/********************************************************************************
 * Altera os dados da locadora ja cadastrado 
 * ******************************************************************************/
void alterarCategorias(Strc_Categoria *cat) {
    Categorias = cat;
}

/********************************************************************************
 * Altera os dados da locadora ja cadastrado 
 * ******************************************************************************/
void alterarFuncionarios(Strc_Funcionario *fun) {
    Funcionarios = fun;
}

/********************************************************************************
 * Altera os dados da locadora ja cadastrado 
 * ******************************************************************************/
void alterarFornecedores(Strc_Fornecedores *forn) {
    Fornecedores = forn;
}

/********************************************************************************
 * Altera os dados da locadora ja cadastrado 
 * ******************************************************************************/
void alterarNotasFiscais(Strc_notaFiscal *nota) {
    NotasFiscais = nota;
}

/********************************************************************************
 * Altera os dados da locadora ja cadastrado 
 * ******************************************************************************/
void alterarLocacoes(Strc_Locacoes *locacoes) {
    Locacoes = locacoes;
}

/********************************************************************************
 * Altera a quantidade de filmes filmes alugados cadastrado 
 * ******************************************************************************/
void alterar_contLocacoes(int cont) {
    contLocacoesAlocados = cont;
}

/********************************************************************************
 * Altera os dados de contas a receber a ja cadastrado 
 * ******************************************************************************/
void alterar_contasReceber(Strc_ContasReceber *str) {
    Contas_aReceber = str;
}

/********************************************************************************
 * Altera a quantidade de contas a receber 
 * ******************************************************************************/
void alterar_contcontasReceber(int cont) {
    contContas_aReceber = cont;
}

/********************************************************************************
 * Altera a quantidade de notas fiscais 
 * ******************************************************************************/
void alterar_contNotasFiscais(int nota) {
    contNotasFiscaisAlocados = nota;
}

/********************************************************************************
 * Altera a quantidade de fornecedores  
 * ******************************************************************************/
void alterar_contFornecedores(int cont) {
    contFornecedoresAlocados = cont;
}

/********************************************************************************
 * Altera a quantidade de funcionarios  
 * ******************************************************************************/
void alterar_contFuncionarios(int cont) {
    contFuncionariosAlocados = cont;
}

/********************************************************************************
 * Altera a quantidade de categorias  
 * ******************************************************************************/
void alterar_contCategorias(int cont) {
    contCategoriasAlocados = cont;
}

/********************************************************************************
 * Altera a quantidade de filmes  
 * ******************************************************************************/
void alterar_contFilmes(int cont) {
    contFIlmesAlocados = cont;
}

/********************************************************************************
 * Altera a quantidade de clientes  
 * ******************************************************************************/
void alterar_contClientes(int cont) {
    contClientesAlocados = cont;
}