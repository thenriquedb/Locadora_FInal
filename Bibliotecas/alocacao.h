
#ifndef ALOCACAO_H
#define ALOCACAO_H

#include "structs.h"

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

//Funções para retornar os vetores dinamicos
Strc_Clientes* return_Clientes();
Strc_Filmes* return_Filmes();
Strc_Categoria* return_Categorias();
Strc_Funcionario* return_Funcionarios();
Strc_Fornecedores* return_Fornecedores();

//Funções para retornar os contadores
int returnCont_Clientes();
int returnCont_Filmes();
int returnCont_Categorias();
int returnCont_Funcionarios();
int returnCont_Fornecedores();

#endif /* ALOCACAO_H */
