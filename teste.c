
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/fileTXT.h"

void prencherDados() {
    Strc_Clientes cl;
    for (int i = 0; i < 5; i++) {
        strcpy(cl.nome, "Fulaninho");
        strcpy(cl.cpf, "111600");
        strcpy(cl.email, "email@email");
        strcpy(cl.endereco, "endereco");
        strcpy(cl.data_nascimento, "10/10/1999");
        cl.opc_sexo = 1;
        cl.estado_civi = 2;
        cl.codigo = gerarCodigoCliente();
        strcpy(cl.telefone, "5555555");

        exportCliente_txt(cl);
        alocarClientes(&cl);
    }

    Strc_Funcionario fun;
    strcpy(fun.nome, "klebin");
    strcpy(fun.cargo, "peao");
    strcpy(fun.email, "email@gmail.com");
    strcpy(fun.telefone, "555555");
    fun.codigo = gerarCodigoFuncionario();

    exportFunc_txt(fun);
    alocarFuncionarios(&fun);

    Strc_Locadora loc;
    strcpy(loc.endereco, "Endereco");
    strcpy(loc.razaoSocial, "razao social");
    strcpy(loc.nomeFanatasia, "Nome Fantasia");
    strcpy(loc.nomeResponsavel, "Nome Responsavel");
    strcpy(loc.InscricaoEstadual, "Inscricao estadual");
    strcpy(loc.cnpj, "CNPJ");
    strcpy(loc.telefone, "telefone");
    strcpy(loc.razaoSocial, "razao social");
    strcpy(loc.email, "email");
    loc.filmesComprados = NULL;
    loc.valorMulta = 10;
    loc.contFilmes_comprados = 3;

    for (int i = 0; i < loc.contFilmes_comprados; i++) {
        loc.filmesComprados = alocar_Int(loc.filmesComprados, i);
        loc.filmesComprados[i] = i + 1;
    }

     exportLocadora_txt(loc);
    alterarLocadora(loc);

    Strc_Categoria cat;
    strcpy(cat.nome, "categoria A");
    strcpy(cat.descricao, "descricao categoria A");
    cat.codigo = gerarCodigoCategoria();
    cat.valor = 10.98;

    exportCategoria_txt(cat);
    alocarCategoria(&cat);


    for (int i = 0; i < 2; i++) {

        Strc_Fornecedores forn;
        strcpy(forn.nomeFantasia, "fornecedor A");
        strcpy(forn.cnpj, "CNPJ");
        strcpy(forn.inscricaooSocial, "INSCRICAO SOCIAL");
        strcpy(forn.email, "email@gmail.com");
        strcpy(forn.telefone, "33513351");
        strcpy(forn.endereco, "rua aaaaaaaaa");
        strcpy(forn.razaoScial, "razao social");

        forn.codigo = gerarCodigoFornecedores();
        forn.contCatalago = 10;

        for (int j = 0; j < forn.contCatalago; j++) {
            forn.catalogoFilmes = alocar_Int(forn.catalogoFilmes, forn.contCatalago);
            forn.catalogoFilmes[j] = j + 1;
          //printf("%d j: %d\n", forn.catalogoFilmes[j],j);
        }

        exportFornecedor_txt(forn);
        alocarFornecedores(&forn);
    }


    Strc_Filmes fil;
    for (int i = 0; i < 5; i++) {
        fil.codigo = gerarCodigoFilme();
        fil.codigoCategoria = 1;
        strcpy(fil.nome, "titulo filme");
        strcpy(fil.descricao, "descricao filme");
        fil.idioma = 1;
        fil.precoAluguel = 10;
        fil.precoCompra = 1000;
        fil.exemplares = 1000;
        fil.codigoFornecedor = 1;

        exportFilmes_txt(fil);
        alocarFilmes(&fil);
    }
}
