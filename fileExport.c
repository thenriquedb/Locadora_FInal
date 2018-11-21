/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fileCliente.c
 * Author: thiago
 *
 * Created on 19 de Novembro de 2018, 21:57
 */

#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/fileTXT.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"

void excluirArquivos_txt() {

    printf("Deseja apagar todos os dados salvos anteriormente? Lembrando que esta "
            "ação não poderá ser desfeita depois. \n"
            "\t1. Sim \n"
            "\t2. Não \n");
    if (selecao() == 1) {
        remove("arquivos/fileClientes.txt");
        remove("arquivos/fileCategorias.txt");
        remove("arquivos/fileCategorias.txt");
        remove("arquivos/fileFornecedores.txt");
        remove("arquivos/fileFuncionarios.txt");
        remove("arquivos/fileLocacoes.txt");
    } else {
        menuInicial();
    }
}
//------------------------------------------------------------------------------

void exportCliente_txt(Strc_Clientes Cl) {
    FILE * file = fopen("arquivos/fileClientes.txt", "a");

    fprintf(file, "#, %s,", Cl.nome);
    fprintf(file, "%s,", Cl.data_nascimento);
    fprintf(file, "%d,", Cl.codigo);
    fprintf(file, "%s,", Cl.endereco);
    fprintf(file, "%s,", Cl.cpf);
    fprintf(file, "%s,", Cl.telefone);
    fprintf(file, "%s,", Cl.email);
    fprintf(file, "%d,", Cl.opc_sexo);
    fprintf(file, "%d\n", Cl.estado_civi);
}

void exportFunc_txt(Strc_Funcionario Func) {
    FILE * file = fopen("arquivos/fileFuncionarios.txt", "a");

    fprintf(file, "#, %s,", Func.nome);
    fprintf(file, "%d,", Func.codigo);
    fprintf(file, "%s,", Func.telefone);
    fprintf(file, "%s,", Func.email);
    fprintf(file, "%s\n", Func.cargo);
}
//------------------------------------------------------------------------------

void exportCategoria_txt(Strc_Categoria Cat) {
    FILE * file = fopen("arquivos/fileCategorias.txt", "a");

    fprintf(file, "#, %s,", Cat.nome);
    fprintf(file, "%s,", Cat.descricao);
    fprintf(file, "%d,", Cat.codigo);
    fprintf(file, "%.2f \n", Cat.valor);
}
//------------------------------------------------------------------------------

void exportFornecedor_txt(Strc_Fornecedores Forn) {
    FILE * file = fopen("arquivos/fileFornecedores.txt", "a");

    fprintf(file, "# %s,", Forn.razaoScial);
    fprintf(file, "%s,", Forn.nomeFantasia);
    fprintf(file, "%d", Forn.codigo);
    fprintf(file, "%s,", Forn.endereco);
    fprintf(file, "%s,", Forn.telefone);
    fprintf(file, "%s,", Forn.email);
    fprintf(file, "%s,", Forn.cnpj);
    fprintf(file, "%s,", Forn.inscricaooSocial);

    /* Struct filmes disponiveis pelo fornecedor */
    if (Forn.contCatalago == 0) {
        fprintf(file, "0\n");
    } else {
        fprintf(file, "%d,", Forn.contCatalago);
        fprintf(file, "(");
        for (int i = 0; i < Forn.contCatalago; i++) {
            fprintf(file, "%d;", Forn.catalogoFilmes[i]);
        }
        fprintf(file, ")\n");
    }

}
//------------------------------------------------------------------------------

void exportFilmes_txt(Strc_Filmes Fil) {
    FILE * file = fopen("arquivos/fileFilmes.txt", "a");

    fprintf(file, "#, %s,", Fil.nome);
    fprintf(file, "%s,", Fil.descricao);
    fprintf(file, "%d,", Fil.codigo);
    fprintf(file, "%d,", Fil.codigoFornecedor);
    fprintf(file, "%f,", Fil.precoCompra);
    fprintf(file, "%d,", Fil.idioma);
    fprintf(file, "%d,", Fil.codigoCategoria);
    fprintf(file, "%d \n", Fil.exemplares);
}
//------------------------------------------------------------------------------

void exportLocacoes_txt(Strc_Locacoes Loc) {
    FILE * file = fopen("arquivos/fileLocacoes.txt", "a");

    fprintf(file, "# %d,", Loc.codFunc);
    fprintf(file, "%d,", Loc.codCliente);
    fprintf(file, "%c,", Loc.pagamento);


    fprintf(file, "(");
    for (int i = 0; i < Loc.contItens; i++) {
        fprintf(file, "%d-%d", Loc.Itens[i].codFilme, Loc.Itens[i].quant);
    }
    fprintf(file, ")\n");
}