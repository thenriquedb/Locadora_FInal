#include "structs.h"
#ifndef RELATORIOS_H
#define RELATORIOS_H

//------------------------| RELATORIO CLIENTES |--------------------------------

/* Função para mostrar todos os clientes cadastrados */
void filClientes_Todos();

/* Função para filtrar pelo codigo os clientes cadastrados */
void filClientes_Codigo();

/* Função para filtrar por uma faixa de codigo os clientes cadastrados */
void filClientes_FaixaCodigo();

/*Função para filtrar pelo nome os clientes cadastrados */
void filClientes_Nome();

/* Função para filtrar pelo sexo os clientes cadastrados */
void filClientes_Sexo();

/* Função para filtrar pelo CPF os clientes cadastrados */
void filClientes_CPF();

//-------------------------| RELATORIO FILMES |---------------------------------

/* Imprimir todos os dados de um filmes cadastrado */
void filFilmes_Todos();

/* Função para filtrar pelo codigo os filmes cadastrados */
void filFilmes_Codigo();

/* Função para filtrar por uma faixa de codigo os filmes cadastrados */
void filFilmes_FaixaCodigo();

/*Função para filtrar pelo nome os filmes cadastrados */
void filFilmes_Nome();

/* Função para filtrar pelo idioma os filmes cadastrados */
void filFilmes_Idioma();

/* Função para filtrar pela quantidade de exemplares os filmes cadastrados */
void filFilmes_Exemplares();

//-------------------------| RELATORIO CATEGORIAS |---------------------------------

/* Imprimir todos os dados de um categorias cadastrado */
void filCategorias_Todos();

/* Função para filtrar pelo codigo os categorias cadastrados */
void filCategorias_Codigo();

/* Função para filtrar por uma faixa de codigo os categorias cadastrados */
void filCategorias_FaixaCodigo();

/*Função para filtrar pelo nome os categorias cadastrados */
void filCategoria_Nome();

//-------------------------| RELATORIO FUNCIONARIOS |---------------------------------

/* Imprimir todos os dados de um funcionarios cadastrado */
void filFuncionarios_Todos();

/* Função para filtrar pelo codigo os funcionarios cadastrados */
void filFuncionarios_Codigo();

/* Função para filtrar por uma faixa de codigo os funcionarios cadastrados */
void filFuncionarios_FaixaCodigo();

/*Função para filtrar pelo nome os funcionarios cadastrados */
void filFuncionarios_Nome();

/*Função para filtrar pelo nome os funcionarios cadastrados */
void filFuncionarios_Cargo();

//-------------------------| RELATORIO FORNECEDORES |---------------------------------

/* Imprimir todos os dados de um fornecedores cadastrado */
void filFornecedores_Todos();

/* Função para filtrar pelo codigo os fornecedores cadastrados */
void filFornecedores_Codigo();

/* Função para filtrar pelo codigo os fornecedores cadastrados */
void filFornecedores_FaixaCodigo();

/*Função para filtrar pelo nome fantasia os fornecedores cadastrados */
void filFornecedores_NomeFantasia();

/*Função para filtrar pela razao social fornecedores cadastrados */
void filFornecedores_RazaoSocial();

/*Função para filtrar pelo CNPJ os fornecedores cadastrados */
void filFornecedores_CNPJ();

/*Função para filtrar pela inscricao social os fornecedores cadastrados */
void filFornecedores_InscricaoSocial();

//-------------------------| RELATORIO NOTA FISCAL |---------------------------------

void filNotasFiscais_Todas();
void filNotasFiscais_Fornecedor();
void filNotasFiscais_Pagas();
void filNotasFiscais_NaoPagas();
void filNotasFiscais_codigoFornecedor();

//-------------------------| RELATORIO LOCACOES |---------------------------------
void filLocacoes_aVista();
void filLocacoes_aPrazo();
void filLocacoes_Func();
void filLocacoes_todas();
void filLocacoes_Data();

//-------------------------| RELATORIO CONTAS A RECEBER |---------------------------------
void filContaReceber_todas();
void filContaReceber_faixaCodigo();

//---------------------------------| OUTROS |-----------------------------------
int chamarMenu_Relatorio();

#endif /* RELATORIOS_H */
