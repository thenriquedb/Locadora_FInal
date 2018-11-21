
#ifndef FILETXT_H
#define FILETXT_H

#include "./../Bibliotecas/structs.h"

/*
 *Armazena as informações dos clientes cadastrados em um arquivo TXT 
 */
void exportCliente_txt(Strc_Clientes Cl);

/*
 *Armazena as informações dos funcionários cadastrados em um arquivo TXT 
 */
void exportFunc_txt(Strc_Funcionario Func);

/*
 *Armazena as informações das categorias cadastrados em um arquivo TXT 
 */
void exportCategoria_txt(Strc_Categoria Cat);

/*
 *Armazena as informações dos fornecedores cadastrados em um arquivo TXT 
 */
void exportFornecedor_txt(Strc_Fornecedores Forn);

/*
 *Armazena as informações das locações realizadas um arquivo TXT 
 */
void exportLocacoes_txt(Strc_Locacoes Loc);

//------------------------------------------------------------------------------
/*
 *Realiza a leitura de um arquivo em formato texto onde estão armazendo os dados 
 * das categorias e os armazena em mémoria 
 */
void importCategoria_txt();

/*
 *Realiza a leitura de um arquivo em formato texto onde estão armazendo os dados 
 * dados e os armazena em mémoria 
 */
void importCliente_txt();

void excluirArquivos_txt();
void importFuncionarios_txt();

void importFilmes_txt();
void exportFilmes_txt(Strc_Filmes Fil);

#endif /* FILETXT_H */

