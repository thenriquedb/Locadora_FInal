
#ifndef ALOCACAO_H
#define ALOCACAO_H

#include "structs.h"

/* Funçao usada durante o cadastro de filmes para verificar se a categoria no qual
 o usuario quer realizar o cadastro de um novo filme é valida.*/
int verificarCategoria();




/*
 * -----------------------------| FUNÇÕES DE ALOCAÇÃO |-------------------------
 * Funções para alocar de novos dados.
 */
int alterarLocadora(Strc_Locadora loc);

int alocarClientes(Strc_Clientes* cl);

int alocarFilmes(Strc_Filmes* fil);

int alocarCategoria(Strc_Categoria* cat);

int alocarFuncionarios(Strc_Funcionario* func);

int alocarFornecedores(Strc_Fornecedores* forn);

int alocarNotasFiscais(Strc_notaFiscal* nota);

int* alocar_Int(int* str, int cont);

int* alocar_FilmesComprados(int* str, int cont);

int alocarLocacoes(Strc_Locacoes* str);

Strc_Caixa* alocar_Financas(Strc_Caixa* str, int cont);

Strc_MinimalFilmes* alocar_MinimalFilmes(Strc_MinimalFilmes* str, int cont);

int alocarContas_aReceber(Strc_ContasReceber* str);





/*
 * -----------------------| FUNÇÕES PARA RETORNAR OS VETORES |------------------
 * Funções para retornar os vetores originais de dados. 
 */

Strc_Locadora return_Locadora();

Strc_Clientes* return_Clientes();

Strc_Filmes* return_Filmes();

Strc_Categoria* return_Categorias();

Strc_Funcionario* return_Funcionarios();

Strc_Fornecedores* return_Fornecedores();

Strc_notaFiscal* return_NotasFiscais();

Strc_Caixa return_Financas();

Strc_Locacoes* return_Locacoes();

Strc_ContasReceber* return_contasReceber();




/*
 * -----------------------| FUNÇÕES PARA RETORNAR CONTADORES |------------------
 * Funções retornam a quantidade de dados de determinado tipo ja foram alocados.
 * São utilizadas para controle de laços de repetição em outros funções
 */
int returnCont_Clientes();

int returnCont_Filmes();

int returnCont_Categorias();

int returnCont_Funcionarios();

int returnCont_Fornecedores();

int returnCont_NotasFiscais();

int returnCont_Locacoes();

int returnCont_contasReceber();




/*
 * -----------------------| FUNÇÕES PARA ALTERAR DADOS ORIGINAIS |--------------
 * Funções  usadas quando alguma modificação é feita em uma variavel local e 
 * deseja-se aplicar as variaveis globais 
 */
void alterarCategorias(Strc_Categoria *cat);

void alterarClientes(Strc_Clientes *cl);

void alterarFilmes(Strc_Filmes *fil);

int alterarFinanceiro(Strc_Caixa fin);

void alterarFornecedores(Strc_Fornecedores *forn);

void alterarFuncionarios(Strc_Funcionario *fun);

int alterarLocadora(Strc_Locadora loc);

void alterarNotasFiscais(Strc_notaFiscal *nota);

void alterar_contasReceber(Strc_ContasReceber *str);

void alterarLocacoes(Strc_Locacoes *locacoes);




/*
 * --------------------| FUNÇÕES PARA ALTERAR CONTADORES ORIGINAIS |------------
 * Funções usadas para fazerem alterações nos contadores de dados alocados. 
 */
void alterar_contClientes(int cont);

void alterar_contFilmes(int cont);

void alterar_contCategorias(int cont);

void alterar_contFuncionarios(int cont);

void alterar_contFornecedores(int cont);

void alterar_contcontasReceber(int cont);

#endif /* ALOCACAO_H */