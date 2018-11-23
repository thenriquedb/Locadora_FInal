
#ifndef FILETXT_H
#define FILETXT_H

#include "./../Bibliotecas/structs.h"

/* Exclui todos os arquivos do programa salvos no computador*/
void excluirArquivos_txt();



/*
 * -----------------| FUNÇÕES DE EXPORTAÇÃO PARA ARQUIVOS TXT |-----------------
 * Funções que leem informações e os armazenam em mémoria. Os parámetros recebidos
 * é a struct a ser lida.
 */
void exportLocadora_txt(Strc_Locadora Loc);

void exportContasReceber_txt(Strc_ContasReceber contasReceber);

void exportFilmes_txt(Strc_Filmes Fil);

void exportCliente_txt(Strc_Clientes Cl);

void exportFunc_txt(Strc_Funcionario Func);

void exportCategoria_txt(Strc_Categoria Cat);

void exportFornecedor_txt(Strc_Fornecedores Forn);

void exportLocacoes_txt(Strc_Locacoes Loc);

void exportNotasFiscais_txt();



/*
 * --------| FUNÇÕES DE IMPORTAÇÃO DE DADOS DE ARQUIVO TXT PARA MÉMORIA --------
 * Funções que leem um arquivo TXT e os salva em mémoriados
 */
void importCategoria_txt();

void importCliente_txt();

void importFuncionarios_txt();

void importFilmes_txt();

void importFornecedores_txt();

void importLocadora_txt();

void importLocacoes_txt();

void importContasReceber_txt();

void importNotasFiscais_txt();
#endif /* FILETXT_H */

