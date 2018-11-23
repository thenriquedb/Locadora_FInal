#include "structs.h"
#ifndef RELATORIOS_H
#define RELATORIOS_H
/*
 * --------------------------| EDIÇÃO DE DADOS |---------------------
 * Funções que realizam a filtragem dos dados cadastradps no qual cada tipo posssui
 * seus filtros proprios.
 */




//------------------------| RELATORIO CLIENTES |--------------------------------
void filClientes_Todos();

void filClientes_Codigo();

void filClientes_FaixaCodigo();

void filClientes_Nome();

void filClientes_Sexo();

void filClientes_CPF();



//-------------------------| RELATORIO FILMES |---------------------------------
void filFilmes_Todos();

void filFilmes_Codigo();

void filFilmes_FaixaCodigo();

void filFilmes_Nome();

void filFilmes_Idioma();

void filFilmes_Exemplares();



//-------------------------| RELATORIO CATEGORIAS |---------------------------------
void filCategorias_Todos();

void filCategorias_Codigo();

void filCategorias_FaixaCodigo();

void filCategoria_Nome();



//-------------------------| RELATORIO FUNCIONARIOS |---------------------------------
void filFuncionarios_Todos();

void filFuncionarios_Codigo();

void filFuncionarios_FaixaCodigo();

void filFuncionarios_Nome();

void filFuncionarios_Cargo();



//-------------------------| RELATORIO FORNECEDORES |---------------------------------

void filFornecedores_Todos();

void filFornecedores_Codigo();

void filFornecedores_FaixaCodigo();

void filFornecedores_NomeFantasia();

void filFornecedores_RazaoSocial();

void filFornecedores_CNPJ();

void filFornecedores_InscricaoSocial();



//-------------------------| RELATORIO NOTA FISCAL |---------------------------------

void filNotasFiscais_Todas();

void filNotasFiscais_Fornecedor();

void filNotasFiscais_Pagas();

void filNotasFiscais_NaoPagas();

void filNotasFiscais_codigoFornecedor();



//-------------------------| RELATORIO LOCACOES |---------------------------------
void filFilmesAlugados_aVista();

void filFilmesAlugados_aPrazo();

void filFilmesAlugados_Func();

void filFilmesAlugados_todos();

void filLocacoes_Data();



//-------------------------| RELATORIO CONTAS A RECEBER |---------------------------------
void filContaReceber_todas();

void filContaReceber_faixaCodigo();



//---------------------------------| OUTROS |-----------------------------------
int chamarMenu_Relatorio();

#endif /* RELATORIOS_H */
