
#ifndef FILEBIN_H
#define FILEBIN_H

#include "./../Bibliotecas/structs.h"

/*********************************************************************************
 *  Exclui todos os arquivos do programa salvos no computador
 *********************************************************************************/
void excluirArquivos_bin();


/*********************************************************************************
 * Funções que leem informações e os armazenam em mémoria. Os parámetros recebidos
 * é a struct a ser lida.
 *********************************************************************************/
void exportLocadora_bin(Strc_Locadora Loc);

void exportContasReceber_bin();

void exportFilmes_bin();

void exportCliente_bin();

void exportFunc_bin();

void exportCategoria_bin();

void exportFornecedor_bin();

void exportLocacoes_bin();

void exportNotasFiscais_bin();

void exportTudo_bin();

/*********************************************************************************
 * Funções que leem um arquivo bin e os salva em mémoriados
 *********************************************************************************/
void importCategoria_bin();

void importCliente_bin();

void importFuncionarios_bin();

void importFilmes_bin();

void importFornecedores_bin();

void importLocadora_bin();

void importLocacoes_bin();

void importContasReceber_bin();

void importNotasFiscais_bin();

#endif /* FILEbin_H */

