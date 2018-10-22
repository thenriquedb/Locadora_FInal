#include "structs.h"
#ifndef RELATORIOS_H
#define RELATORIOS_H

//------------------------| RELATORIO CLIENTES |--------------------------------

/* Função para mostrar todos os clientes cadastrados */
void filClientes_Todos();

/* Função para filtrar pelo codigo os clientes cadastrados */
void filClientes_Codigo();

/* Função para filtrar pelo codigo os clientes cadastrados */
void filClientes_FaixaCodigo();

/*Função para filtrar pelo nome os clientes cadastrados */
void filClientes_Nome();

/* Função para filtrar pelo sexo os clientes cadastrados */
void filClientes_Sexo();

/* Função para filtrar pelo CPF os clientes cadastrados */
void filClientes_CPF();

/* Imprimir todos os dados de um cliente cadastrado */
void imprimeClientes(int i);

//-------------------------| RELATORIO FILMES |---------------------------------

/* Imprimir todos os dados de um filmes cadastrado */
void filFilmes_Todos();

/* Função para filtrar pelo codigo os filmes cadastrados */
void filFilmes_Codigo();

/* Função para filtrar pelo codigo os filmes cadastrados */
void filFilmes_FaixaCodigo();

/*Função para filtrar pelo nome os filmes cadastrados */
void filFilmes_Nome();

/* Função para filtrar pelo idioma os filmes cadastrados */
void filFilmes_Idioma();

/* Função para filtrar pela quantidade de exemplares os filmes cadastrados */
void filFilmes_Exemplares();

/* Função para mostrar todos os filmes cadastrados */
void imprimeFilmes(int i);

//---------------------------------| OUTROS |-----------------------------------
int chamarMenu_Relatorio();

#endif /* RELATORIOS_H */

