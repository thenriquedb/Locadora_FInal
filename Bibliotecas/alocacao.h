
#ifndef ALOCACAO_H
#define ALOCACAO_H

#include "structs.h"

/*
 * -----------------------| FUNÇÕES DE ALOCAÇÃO |----------------
 */

/* Função responsavel por fazer a aloção de memoria para armazenar os clientes*/
int armazenarLocadora(Strc_Locadora loc);

/* Função responsavel por fazer a aloção de memoria para armazenar os clientes*/
int alocarClientes(Strc_Clientes* cl);

/* Função responsavel por fazer a aloção de memoria para armazenar os filmes*/
int alocarFilmes(Strc_Filmes* fil);

/* Função responsavel por fazer a aloção de memoria para armazenar os categoria*/
int alocarCategoria(Strc_Categoria* cat);

/* Função responsavel por fazer a aloção de memoria para armazenar os funcionarios*/
int alocarFuncionarios(Strc_Funcionario* func);

/* Função responsavel por fazer a aloção de memoria para armazenar os funcionarios*/
int alocarFornecedores(Strc_Fornecedores* forn);

/* Funçao usada durante o cadastro de filmes para verificar se a categoria no qual
 o usuario quer realizar o cadastro de um novo filme é valida.*/
int verificarCategoria();


/*
 * -----------------------| FUNÇÕES PARA RETORNAR OS VETORES |----------------
 */

/* Função que retorna o vetor de clientes */
Strc_Clientes* return_Clientes();

/* Função que retorna o vetor de filmes */
Strc_Filmes* return_Filmes();

/* Função que retorna o vetor de categoria */
Strc_Categoria* return_Categorias();

/* Função que retorna o vetor de funcionario */
Strc_Funcionario* return_Funcionarios();

/* Função que retorna o vetor de fornecedores */
Strc_Fornecedores* return_Fornecedores();

/*
 * -----------------------| FUNÇÕES PARA RETORNAR CONTADORES |----------------
 */

/* Funções para retornar a quantidade de clientes alocados */
int returnCont_Clientes();

/* Funções para retornar a quantidade de  filmes alocados */
int returnCont_Filmes();

/* Funções para retornar a quantidade de  categorias alocados */
int returnCont_Categorias();

/* Funções para retornar a quantidade de funcionarios alocados */
int returnCont_Funcionarios();

/* Funções para retornar a quantidade de fornecedores alocados */
int returnCont_Fornecedores();

/*
 * -----------------------| FUNÇÕES PARA ALTERAR DADOS ORIGINAIS |----------------
 */
void alterarClientes(Strc_Clientes *cl);
void alterarFilmes(Strc_Filmes *fil);
void alterarCategorias(Strc_Categoria *cat);
void alterarFuncionarios(Strc_Funcionario *fun);
void alterarFornecedores(Strc_Fornecedores *forn);


void alterar_contClientes(int cont);
void alterar_contFilmes(int cont);
void alterar_contCategorias(int cont);
void alterar_contFuncionarios(int cont);
void alterar_contFornecedores(int cont);

#endif /* ALOCACAO_H */