
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/alocacao.h"

/********************************************************************************
 *Exporta os dados da locadora em formato XML
 ********************************************************************************/
void exportLocadora_XML() {
    Strc_Locadora Loc = return_Locadora();
    FILE* file = fopen("arquivos/xml/Locadora.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = locadora> \n");

    fprintf(file, "\t\t<registro> \n");

    fprintf(file, "\t\t\t<razao_social> %s <\\razao_social> \n", Loc.razaoSocial);
    fprintf(file, "\t\t\t<nome_fantasia> %s <\\nome_fantasia> \n", Loc.nomeFanatasia);
    fprintf(file, "\t\t\t<nome_responsavel> %s <\\nome_responsavel> \n", Loc.nomeResponsavel);
    fprintf(file, "\t\t\t<endereço> %s <\\endereço> \n", Loc.endereco);
    fprintf(file, "\t\t\t<email> %s <\\email> \n", Loc.email);
    fprintf(file, "\t\t\t<telefone> %s <\\telefone> \n", Loc.telefone);
    fprintf(file, "\t\t\t<cnpj> %s <\\cnpj> \n", Loc.cnpj);
    fprintf(file, "\t\t\t<inscricao_estadual> %s <\\inscricao_estadual> \n", Loc.InscricaoEstadual);

    for (int i = 0; i < Loc.contFilmes_comprados; i++) {
        fprintf(file, "\t\t\t\t<filmes_comprados> %d <\\filmes_comprados> \n", Loc.filmesComprados[i]);
    }

    fprintf(file, "\t\t<\\registro> \n");
}

/********************************************************************************
 *Exporta os dados das categorias em formato XML
 ********************************************************************************/
void exportCategoria_XML() {
    Strc_Categoria* Cat = return_Categorias();
    FILE* file = fopen("arquivos/xml/Categoria.txt", "w");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = categoria> \n");

    for (int i = 0; i < returnCont_Categorias(); i++) {
        fprintf(file, "\t\t<registro> \n");
        fprintf(file, "\t\t\t<nome> %s <\\nome> \n", Cat[i].nome);
        fprintf(file, "\t\t\t<descricao> %s <\\descricao> \n", Cat[i].descricao);
        fprintf(file, "\t\t\t<codigo> %d <\\codigo> \n", Cat[i].codigo);
        fprintf(file, "\t\t\t<vlr_multa> %.2f <\\vlr_multa> \n", Cat[i].valor);
        fprintf(file, "\t\t<\\registro> \n");
    }
}

/********************************************************************************
 *Exporta os dados dos clientes em formato XML
 ********************************************************************************/
void exportCliente_XML() {
    Strc_Clientes* Cl = return_Clientes();
    FILE* file = fopen("arquivos/xml/Cliente.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = cliente> \n");

    for (int i = 0; i < returnCont_Clientes(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<codigo> %d <\\codigo> \n", Cl[i].codigo);
        fprintf(file, "\t\t\t<nome> %s <\\nome> \n", Cl[i].nome);
        fprintf(file, "\t\t\t<endereço> %s <\\endereço> \n", Cl[i].endereco);
        fprintf(file, "\t\t\t<cpf> %s <\\cpf> \n", Cl[i].cpf);
        fprintf(file, "\t\t\t<telefone> %s <\\telefone> \n", Cl[i].telefone);
        fprintf(file, "\t\t\t<email> %s <\\email> \n", Cl[i].cpf);
        fprintf(file, "\t\t\t<sexo> %d <\\sexo> \n", Cl[i].opc_sexo);
        fprintf(file, "\t\t\t<est_civil> %d <\\est_civil> \n", Cl[i].estado_civi);
        fprintf(file, "\t\t\t<data_nascimento> %s <\\data_nascimento> \n", Cl[i].data_nascimento);

        fprintf(file, "\t\t<\\registro> \n");
    }
    fprintf(file, "\t<\\tabela> \n");

}

/********************************************************************************
 *Exporta os dados de funcionarios em formato XML
 ********************************************************************************/
void exportFunc_XML() {
    Strc_Funcionario* Fun = return_Funcionarios();
    FILE* file = fopen("arquivos/xml/Funcionario.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = funcionarios> \n");

    for (int i = 0; i < returnCont_Funcionarios(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<nome> %s <\\nome> \n", Fun[i].nome);
        fprintf(file, "\t\t\t<telefone> %s <\\telefone> \n", Fun[i].telefone);
        fprintf(file, "\t\t\t<email> %s <\\email> \n", Fun[i].email);
        fprintf(file, "\t\t\t<cargo> %s <\\cargo> \n", Fun[i].cargo);
        fprintf(file, "\t\t\t<sexo> %d <\\sexo> \n", Fun[i].codigo);

        fprintf(file, "\t\t<\\registro> \n");
    }
    fprintf(file, "\t<\\tabela> \n");
}

/********************************************************************************
 *Exporta os dados de fornecedores em formato XML
 ********************************************************************************/
void exportFornecedores_XML() {
    Strc_Fornecedores* Forn = return_Fornecedores();
    FILE* file = fopen("arquivos/xml/Fornecedores.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = fornecedores> \n");

    for (int i = 0; i < returnCont_Fornecedores(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<razao_social> %s <\\razao_social> \n", Forn[i].razaoScial);
        fprintf(file, "\t\t\t<nome_fantasia> %s <\\nome_fantasia> \n", Forn[i].nomeFantasia);
        fprintf(file, "\t\t\t<endereco> %s <\\endereco> \n", Forn[i].endereco);
        fprintf(file, "\t\t\t<telefone> %s <\\telefone> \n", Forn[i].telefone);
        fprintf(file, "\t\t\t<email> %s <\\email> \n", Forn[i].email);
        fprintf(file, "\t\t\t<cnpj> %s <\\cnpj> \n", Forn[i].cnpj);
        fprintf(file, "\t\t\t<inscricao_social> %s <\\inscricao_social> \n", Forn[i].inscricaooSocial);

        fprintf(file, "\t\t\t<filme_disponiveis>");
        for (int j = 0; j < Forn[i].contCatalago; j++) {
            fprintf(file, "\t\t\t\t<filme_disponiveis> %d <\\filme_disponiveis> \n", Forn[i].catalogoFilmes[j]);

        }
        fprintf(file, "\t\t\t<\\filme_disponiveis> \n");

        fprintf(file, "\t\t<\\registro> \n");
    }
    fprintf(file, "\t<\\tabela> \n");
}

/********************************************************************************
 *Exporta os dados de filmes em formato XML
 ********************************************************************************/
void exportFilmes_XML() {
    Strc_Filmes* Film = return_Filmes();
    FILE* file = fopen("arquivos/xml/Filmes.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = filmes> \n");

    for (int i = 0; i < returnCont_Fornecedores(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<titulo> %s <\\titulo> \n", Film[i].nome);
        fprintf(file, "\t\t\t<descricao> %s <\\descricao> \n", Film[i].descricao);
        fprintf(file, "\t\t\t<codigo_unico> %d <\\codigo_unico> \n", Film[i].codigo);
        fprintf(file, "\t\t\t<fornecedor> %d <\\fornecedor> \n", Film[i].codigoFornecedor);
        fprintf(file, "\t\t\t<preco_compra> %.2f <\\preco_compra> \n", Film[i].precoCompra);
        fprintf(file, "\t\t\t<idioma> %d <\\idioma> \n", Film[i].idioma);
        fprintf(file, "\t\t\t<categoria> %d <\\categoria> \n", Film[i].codigoCategoria);
        fprintf(file, "\t\t\t<exemplares> %d <\\exemplares> \n", Film[i].exemplares);

        fprintf(file, "\t\t<\\registro> \n");
    }

    fprintf(file, "\t<\\tabela> \n");
}

/********************************************************************************
 *Exporta os dados de notas fiscais em formato XML
 ********************************************************************************/
void exportNotaFiscal_XML() {
    Strc_notaFiscal* notasF = return_NotasFiscais();

    FILE* file = fopen("arquivos/xml/NotasFiscais.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = nota_fiscal> \n");

    for (int i = 0; i < returnCont_NotasFiscais(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<fornecedor> %d <\\fornecedor> \n", notasF[i].codForn);
        fprintf(file, "\t\t\t<frete> %.2f <\\frete> \n", notasF[i].precoFrete);
        fprintf(file, "\t\t\t<frete_unidade> %.2f <\\frete_unidade> \n", notasF[i].freteUnidade);
        fprintf(file, "\t\t\t<imposto> %.2f <\\imposto> \n", notasF[i].precoImposto);
        fprintf(file, "\t\t\t<imposto_unidade> %.2f <\\imposto_unidade> \n", notasF[i].impostoUnidade);
        fprintf(file, "\t\t\t<codigo_nota> %d <\\codigo_nota> \n", notasF[i].codigo);


        fprintf(file, "\t\t\t<produtos>\n");
        for (int j = 0; j < notasF[i].contItens; j++) {
            fprintf(file, "\t\t\t\t<codigo> %d <\\codigo> \n", notasF[i].Itens[j].codFilme);
            fprintf(file, "\t\t\t\t<exemplares> %d <\\exemplares> \n", notasF[i].Itens[j].quant);
            fprintf(file, "\t\t\t\t<exemplares> %d <\\exemplares> \n", notasF[i].Itens[j].quant);
            fprintf(file, "\t\t\t\t<preco> %.2f <\\preco> \n", notasF[i].Itens[j].preco);
            fprintf(file, "\t\t\t\t<total> %.2f <\\total> \n", notasF[i].Itens[j].total);
        }

        fprintf(file, "\t\t\t<\\produtos>\n");
        fprintf(file, "\t\t\t<situacao> %d <\\situacao> \n", notasF[i].paga);
        fprintf(file, "\t<\\tabela> \n");
    }
}

/********************************************************************************
 *Exporta os dados dos filmes alugados em formato XML
 ********************************************************************************/
void exportLocacoes_XML() {
    Strc_Locacoes* Locacoes = return_Locacoes();

    FILE* file = fopen("arquivos/xml/Locacoes.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = filmes_alugados> \n");

    for (int i = 0; i < returnCont_NotasFiscais(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<cod_func> %d <\\cod_func> \n", Locacoes[i].codFunc);
        fprintf(file, "\t\t\t<cod_cliente> %d <\\cod_cliente> \n", Locacoes[i].codCliente);
        fprintf(file, "\t\t\t<forma_pagamento> %d <\\forma_pagamento> \n", Locacoes[i].pagamento);


        fprintf(file, "\t\t\t<produtos>\n");
        for (int j = 0; j < Locacoes[i].contItens; j++) {
            fprintf(file, "\t\t\t\t<codigo_filme> %d <\\codigo_filme> \n", Locacoes[i].Itens[j].codFilme);
            fprintf(file, "\t\t\t\t<exemplares> %d <\\exemplares> \n", Locacoes[i].Itens[j].quant);
        }
        fprintf(file, "\t\t\t<\\produtos>\n");
        fprintf(file, "\t<\\tabela> \n");
    }
}

/********************************************************************************
 *Exporta os dados de contas a receber em formato XML
 ********************************************************************************/
void exportContasReceber_XML() {
    Strc_ContasReceber* contas = return_contasReceber();

    FILE* file = fopen("arquivos/xml/ContasReceber.txt", "a");
    if (file == NULL) {
        printf("Não foi possivel criar o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "<dados> \n");
    fprintf(file, "\t<tabela = contas_receber> \n");

    for (int i = 0; i < returnCont_contasReceber(); i++) {
        fprintf(file, "\t\t<registro> \n");

        fprintf(file, "\t\t\t<cod_cliente> %d <\\cod_cliente> \n", contas[i].codCl);
        fprintf(file, "\t\t\t<total> %.2f <\\total> \n", contas[i].total);
        fprintf(file, "\t\t\t<entrada> %c <\\entrada> \n", contas[i].entrada[0]);
        fprintf(file, "\t\t\t<vlr_entrada> %.2f <\\vlr_entrada> \n", contas[i].valorEntrada);
        fprintf(file, "\t\t\t<num_parcela> %.2f <\\num_parcela> \n", contas[i].vlrParcela);
        fprintf(file, "\t\t\t<situacao> %c <\\situacao> \n", contas[i].situacao[0]);

        fprintf(file, "\t<\\tabela> \n");
    }
}
