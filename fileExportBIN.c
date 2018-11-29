/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fileExportBIN.c
 * Author: thiago
 *
 * Created on 23 de Novembro de 2018, 13:34
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/fileTXT.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/fileXML.h"
#include "Bibliotecas/fileBIN.h"

/*
 *Exporta as informaçoes da locadora em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileLocadora.bin
 */
void exportLocadora_bin(Strc_Locadora Loc) {
    FILE * file = fopen("arquivos/bin/fileLocadora.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados da locadora."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fwrite(&Loc, sizeof (Strc_Locadora), 1, file);

    fclose(file);
    free(file);
}

/*
 *Exporta todas as contas de clientes a receber cadastrados em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileContasReceber.bin
 */
void exportContasReceber_bin() {
    FILE * file = fopen("arquivos/bin/fileContasReceber.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de contas a receber."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_ContasReceber* contasReceber = return_contasReceber();
    fwrite(&contasReceber, sizeof (Strc_ContasReceber), returnCont_contasReceber(), file);

    fclose(file);
    free(file);
}

/*
 *Exporta todos os filmes cadastrados em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileFilmes.bin
 */
void exportFilmes_bin() {
    FILE * file = fopen("arquivos/bin/fileFilmes.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento de filmes alcoados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_Filmes* filmes = return_Filmes();
    fwrite(&filmes, sizeof (Strc_Filmes), returnCont_Filmes(), file);

    fclose(file);
    free(file);
}

/*
 *Exporta todos os clientes cadastrados em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileClientes    .bin
 */
void exportCliente_bin() {
    FILE * file = fopen("arquivos/bin/fileClientes.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de clientes alocados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_Clientes* clientes = return_Clientes();
    for (int i = 0; i < returnCont_Clientes(); i++) {
        fwrite(&clientes[i], sizeof (Strc_Clientes), 1, file);
    }

    fclose(file);
    free(file);
}

/*
 *Exporta todos os funcionários cadastrados formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileFuncionario.bin
 */
void exportFunc_bin() {
    FILE * file = fopen("arquivos/bin/fileFuncionario.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de funcionários alocados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_Funcionario* funcionarios = return_Funcionarios();
    for (int i = 0; i < returnCont_Funcionarios(); i++) {
        fwrite(&funcionarios[i], sizeof (Strc_Funcionario), 1, file);
    }

    fclose(file);
    free(file);
}

/*
 *Exporta todas as categorias cadastradas em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileCategoria.bin
 */
void exportCategoria_bin() {
    FILE * file = fopen("arquivos/bin/fileCategoria.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de categorias alocados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_Categoria* categoria = return_Categorias();
    for (int i = 0; i < returnCont_Categorias(); i++) {
        fwrite(&categoria[i], sizeof (Strc_Categoria), 1, file);
    }

    fclose(file);
    free(file);
}

/*
 *Exporta todas os fornecedores cadastrados em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileFornecedor.bin
 */
void exportFornecedor_bin() {
    FILE * file = fopen("arquivos/bin/fileFornecedor.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados dos fornecedores alocados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_Fornecedores* fornecedor = return_Fornecedores();
    for (int i = 0; i < returnCont_Fornecedores(); i++) {
        fwrite(&fornecedor[i], sizeof (Strc_Fornecedores), 1, file);
    }

    fclose(file);
    free(file);
}

/*
 *Exporta todas as locações realizadas  em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileNotasFiscais.bin
 */
void exportLocacoes_bin() {
    FILE * file = fopen("arquivos/bin/fileLocacoes.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de filmes alugados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_Locacoes* Loc = return_Locacoes();
    for (int i = 0; i < returnCont_Locacoes(); i++) {
        fwrite(&Loc[i], sizeof (Strc_Locacoes), 1, file);
    }

    fclose(file);
    free(file);




}

/*
 *Exporta todas as notas fiscais cadastradas em formato de arquivo binário
 * O arquivo exportado esta no seguinte diretorio: arquivos/bin/fileNotasFiscais.bin
 */
void exportNotasFiscais_bin() {
    FILE * file = fopen("arquivos/bin/fileNotasFiscais.bin", "wb");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de notas fiscais."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_notaFiscal* nf = return_NotasFiscais();
    for (int i = 0; i < returnCont_NotasFiscais(); i++) {
        fwrite(&nf[i], sizeof (Strc_notaFiscal), 1, file);
    }

    fclose(file);
    free(file);
}

/*  Exporta todas as informações para arquivos binarios separadamente 
 * os arquivos podem ser encontrados no seguinte diretorio: arquivos/bin
 */
void exportTudo_bin() {
    if (returnverificaoLocadora() == 2) {
        exportNotasFiscais_bin();
        exportLocacoes_bin();
        exportFornecedor_bin();
        exportFilmes_bin();
        exportCliente_bin();
    }
}
