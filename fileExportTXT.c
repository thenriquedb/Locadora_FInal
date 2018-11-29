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
    remove("arquivos/fileClientes.txt");
    remove("arquivos/fileCategorias.txt");
    remove("arquivos/fileCategorias.txt");
    remove("arquivos/fileFornecedores.txt");
    remove("arquivos/fileFuncionarios.txt");
    remove("arquivos/fileLocacoes.txt");
    remove("arquivos/fileLocadora.txt");
   // remove("arquivos/bin/fileContasReceber.txt");
  //  remove("arquivos/bin/fileFilmes.txt");
   // remove("arquivos/bin/fileLocadora.txt");
   // remove("arquivos/bin/fileNotasFiscais.txt");

    printf("Arquivos de texto excluidos com sucesso! \n");
}


//------------------------------------------------------------------------------

void exportLocadora_txt(Strc_Locadora Loc) {
    FILE * file = fopen("arquivos/fileLocadora.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados da locadora."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#, %s,", Loc.razaoSocial);
    fprintf(file, "%s,", Loc.nomeFanatasia);
    fprintf(file, "%s,", Loc.nomeResponsavel);
    fprintf(file, "%s,", Loc.endereco);
    fprintf(file, "%s,", Loc.email);
    fprintf(file, "%s,", Loc.telefone);
    fprintf(file, "%s,", Loc.cnpj);
    fprintf(file, "%s,", Loc.InscricaoEstadual);
    fprintf(file, "%.2f,", Loc.valorMulta);

    /* leitura da struct filmes disponiveis pelo fornecedor */
    if (Loc.contFilmes_comprados == 0) {
        fprintf(file, "0\n");
    } else {
        fprintf(file, "%d\n", Loc.contFilmes_comprados);
        fprintf(file, "$,");

        for (int i = 0; i < Loc.contFilmes_comprados; i++) {
            Loc.filmesComprados = alocar_Int(Loc.filmesComprados, Loc.contFilmes_comprados);
            fprintf(file, "%d", Loc.filmesComprados[i]);

            if (i < Loc.contFilmes_comprados - 1)
                fprintf(file, ",");
        }
        fprintf(file, "\n");
    }
}
//------------------------------------------------------------------------------

void exportCliente_txt(Strc_Clientes Cl) {
    FILE * file = fopen("arquivos/fileClientes.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados dos clientes."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

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
//------------------------------------------------------------------------------

void exportFunc_txt(Strc_Funcionario Func) {
    FILE * file = fopen("arquivos/fileFuncionarios.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados dos funcionários."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#, %s,", Func.nome);
    fprintf(file, "%d,", Func.codigo);
    fprintf(file, "%s,", Func.telefone);
    fprintf(file, "%s,", Func.email);
    fprintf(file, "%s\n", Func.cargo);
}
//------------------------------------------------------------------------------

void exportCategoria_txt(Strc_Categoria Cat) {
    FILE * file = fopen("arquivos/fileCategorias.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados das categorias."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#, %s,", Cat.nome);
    fprintf(file, "%s,", Cat.descricao);
    fprintf(file, "%d,", Cat.codigo);
    fprintf(file, "%.2f \n", Cat.valor);
}
//------------------------------------------------------------------------------

void exportFornecedor_txt(Strc_Fornecedores Forn) {
    FILE * file = fopen("arquivos/fileFornecedores.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de fornecedores."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#, %s,", Forn.razaoScial);
    fprintf(file, "%s,", Forn.nomeFantasia);
    fprintf(file, "%d,", Forn.codigo);
    fprintf(file, "%s,", Forn.endereco);
    fprintf(file, "%s,", Forn.telefone);
    fprintf(file, "%s,", Forn.email);
    fprintf(file, "%s,", Forn.cnpj);
    fprintf(file, "%s,", Forn.inscricaooSocial);

    /* leitura da struct filmes disponiveis pelo fornecedor */
    if (Forn.contCatalago == 0) {
        fprintf(file, "0\n");
    } else {
        fprintf(file, "%d\n", Forn.contCatalago);
        fprintf(file, "$,");

        int i = 0;
        for (i = 0; i < Forn.contCatalago; i++) {
            fprintf(file, "%d", Forn.catalogoFilmes[i]);

            if (i < Forn.contCatalago - 1)
                fprintf(file, ",");
        }
        fprintf(file, "\n");
    }
}
//------------------------------------------------------------------------------

void exportFilmes_txt(Strc_Filmes Fil) {
    FILE * file = fopen("arquivos/fileFilmes.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados de filmes."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

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
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados dos filmes alugados."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#,%d,", Loc.codFunc);
    fprintf(file, "%d,", Loc.codCliente);
    fprintf(file, "%c,", Loc.pagamento);

    if (Loc.contItens == 0) {
        fprintf(file, "0\n");
    }/* leitura da struct filmes disponiveis pelo fornecedor */
    else {
        fprintf(file, "%d,", Loc.contItens);

        for (int i = 0; i < Loc.contItens; i++) {
            fprintf(file, "$,");
            fprintf(file, "%d,", Loc.Itens[i].codFilme);
            fprintf(file, "%d,", Loc.Itens[i].quant);
            fprintf(file, "%.2f,", Loc.Itens[i].preco);
            fprintf(file, "%.2f\n", Loc.Itens[i].total);
        }
    }
}
//------------------------------------------------------------------------------

void exportContasReceber_txt(Strc_ContasReceber contasReceber) {
    FILE * file = fopen("arquivos/fileContasReceber.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados da locadora."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#,%d,", contasReceber.codCl);
    fprintf(file, "%.2f,", contasReceber.total);
    fprintf(file, "%c,", contasReceber.situacao[0]);
    fprintf(file, "%c,", contasReceber.entrada[0]);

    if (contasReceber.entrada[0] == 'S') {
        fprintf(file, "%.2f,", contasReceber.valorEntrada);
    }

    fprintf(file, "%d,", contasReceber.quantParcelas);
    fprintf(file, "%.2f\n", contasReceber.vlrParcela);
}
//------------------------------------------------------------------------------

void exportNotasFiscais_txt() {
    FILE * file = fopen("arquivos/fileNotasFiscais.txt", "a");
    if (file == NULL) {
        printf("Não foi possível criar o arquivo para armazenamento dos dados das notas fiscais."
                "O programa será fechado. \n");
        exit(EXIT_FAILURE);
    }

    Strc_notaFiscal notaFiscal;

    fprintf(file, "#,%d,", notaFiscal.codForn);
    fprintf(file, "%d,", notaFiscal.codigo);
    fprintf(file, "%d,", notaFiscal.paga);
    fprintf(file, "%.2f,", notaFiscal.precoFrete);
    fprintf(file, "%.2f,", notaFiscal.precoImposto);
    fprintf(file, "%.2f,", notaFiscal.freteUnidade);
    fprintf(file, "%.2f,", notaFiscal.impostoUnidade);
    fprintf(file, "%.2f,", notaFiscal.totalNF);
    fprintf(file, "%d\n", notaFiscal.contItens);

    for (int i = 0; i < notaFiscal.contItens; i++) {
        fprintf(file, "$,");
        fprintf(file, "%d,", notaFiscal.Itens[i].codFilme);
        fprintf(file, "%d,", notaFiscal.Itens[i].quant);
        fprintf(file, "%.2f,", notaFiscal.Itens[i].preco);
        fprintf(file, "%.2f\n", notaFiscal.Itens[i].total);
    }
}
