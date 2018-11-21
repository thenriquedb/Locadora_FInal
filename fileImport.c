/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   importFile.c
 * Author: thiago
 *
 * Created on 20 de Novembro de 2018, 13:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/fileTXT.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/menus.h"

void importCategoria_txt() {
    FILE * file = fopen("arquivos/fileCategorias.txt", "r");
    if (file == NULL) {
        printf("Impossivel ler o arquivo. \n");
        menuInicial();
    }

    char line[256];
    char* token;
    Strc_Categoria cat;

    while (!feof(file)) {
        /* O primeiro caracter da string deve ser alterando manualmente para
         * evitar problemas durante a proxima leitura de dados  */
        line[0] = '\0';
        fgets(line, 256, file);

        if (line[0] == '#') {
            token = strtok(line, ",");

            while (token != NULL) {
                token = strtok(NULL, ",");
                strcpy(cat.nome, token);

                token = strtok(NULL, ",");
                strcpy(cat.descricao, token);

                token = strtok(NULL, ",");
                cat.codigo = atoi(token);

                token = strtok(NULL, ",");
                cat.valor = atof(token);

                alocarCategoria(&cat);
                token = strtok(NULL, ",");
            }
        }

    }

    fclose(file);
    free(file);
}

//------------------------------------------------------------------------------

void importCliente_txt() {
    FILE * file = fopen("arquivos/fileClientes.txt", "r");
    if (file == NULL) {
        printf("Impossivel ler o arquivo. \n");
        menuInicial();
    }

    char line[256];
    char* token;
    Strc_Clientes Cl;

    while (!feof(file)) {
        line[0] = '\0';
        fgets(line, 256, file);

        if (line[0] == '#') {
            token = strtok(line, ",");

            while (token != NULL) {
                token = strtok(NULL, ",");
                strcpy(Cl.nome, token);

                token = strtok(NULL, ",");
                strcpy(Cl.data_nascimento, token);

                token = strtok(NULL, ",");
                Cl.codigo = atoi(token);

                token = strtok(NULL, ",");
                strcpy(Cl.endereco, token);

                token = strtok(NULL, ",");
                strcpy(Cl.cpf, token);

                token = strtok(NULL, ",");
                strcpy(Cl.telefone, token);

                token = strtok(NULL, ",");
                strcpy(Cl.email, token);

                token = strtok(NULL, ",");
                Cl.opc_sexo = atoi(token);

                token = strtok(NULL, ",");
                Cl.estado_civi = atoi(token);

                alocarClientes(&Cl);
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    free(file);
}
//------------------------------------------------------------------------------

void importFuncionarios_txt() {
    FILE * file = fopen("arquivos/fileFuncionarios.txt", "r");
    if (file == NULL) {
        printf("Impossivel ler o arquivo. \n");
        menuInicial();
    }

    char line[256];
    char* token;
    Strc_Funcionario func;

    while (!feof(file)) {
        line[0] = '\0';
        fgets(line, 256, file);

        if (line[0] == '#') {
            token = strtok(line, ",");

            while (token != NULL) {
                token = strtok(NULL, ",");
                strcpy(func.nome, token);

                token = strtok(NULL, ",");
                func.codigo = atoi(token);

                token = strtok(NULL, ",");
                strcpy(func.telefone, token);

                token = strtok(NULL, ",");
                strcpy(func.email, token);

                token = strtok(NULL, ",");
                strcpy(func.cargo, token);

                alocarFuncionarios(&func);
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    free(file);
}

//------------------------------------------------------------------------------

void importFilmes_txt() {
    FILE * file = fopen("arquivos/fileFilmes.txt", "r");
    if (file == NULL) {
        printf("Impossivel ler o arquivo. \n");
        menuInicial();
    }

    char line[256];
    char* token;
    Strc_Filmes Fil;

    while (!feof(file)) {
        line[0] = '\0';
        fgets(line, 256, file);

        if (line[0] == '#') {
            token = strtok(line, ",");

            while (token != NULL) {
                token = strtok(NULL, ",");
                strcpy(Fil.nome, token);

                token = strtok(NULL, ",");
                strcpy(Fil.descricao, token);

                token = strtok(NULL, ",");
                Fil.codigo = atoi(token);

                token = strtok(NULL, ",");
                Fil.codigoFornecedor = atoi(token);

                token = strtok(NULL, ",");
                Fil.precoCompra = atof(token);

                token = strtok(NULL, ",");
                Fil.idioma = atoi(token);

                token = strtok(NULL, ",");
                Fil.codigoCategoria = atoi(token);

                token = strtok(NULL, ",");
                Fil.exemplares = atoi(token);

                alocarFilmes(&Fil);
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    free(file);
}
//------------------------------------------------------------------------------

void importFornecedores_txt() {
    FILE * file = fopen("arquivos/fileFilmes.txt", "r");
    if (file == NULL) {
        printf("Impossivel ler o arquivo. \n");
        menuInicial();
    }

    char line[256];
    char* token;
    Strc_Fornecedores Forn;

    while (!feof(file)) {
        line[0] = '\0';
        fgets(line, 256, file);

        if (line[0] == '#') {
            token = strtok(line, ",");

            while (token != NULL) {
                token = strtok(NULL, ",");
                strcpy(Forn.razaoScial, token);

                token = strtok(NULL, ",");
                strcpy(Forn.nomeFantasia, token);

                token = strtok(NULL, ",");
                Forn.codigo = atoi(token);

                token = strtok(NULL, ",");
                strcpy(Forn.endereco, token);

                token = strtok(NULL, ",");
                strcpy(Forn.telefone, token);

                token = strtok(NULL, ",");
                strcpy(Forn.email, token);

                token = strtok(NULL, ",");
                strcpy(Forn.cnpj, token);

                token = strtok(NULL, ",");
                strcpy(Forn.inscricaooSocial, token);

                token = strtok(NULL, ",");
                Forn.contCatalago = atoi(token);

                /* Leitura dos filmes disponiveis pelo fornecedor */
                if (Forn.contCatalago != 0) {
                    for (int i = 0; i < Forn.contCatalago; i++) {

                    }
                }

                alocarFilmes(&Forn);
                token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
    free(file);
}