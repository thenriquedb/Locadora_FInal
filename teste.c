
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
    strcpy(loc.endereco, "teste14");
    strcpy(loc.razaoSocial, "teste14");
    strcpy(loc.nomeFanatasia, "teste14");
    strcpy(loc.nomeResponsavel, "teste14");
    strcpy(loc.telefone, "teste14");
    strcpy(loc.razaoSocial, "teste14");
    strcpy(loc.cnpj, "teste14");
    strcpy(loc.email, "teste14");
    loc.valorMulta = 10;
    alterarLocadora(loc);

    Strc_Categoria cat;
    strcpy(cat.nome, "categoria A");
    strcpy(cat.descricao, "descricao categoria A");
    cat.codigo = gerarCodigoCategoria();
    cat.valor = 10.98;

    exportCategoria_txt(cat);
    alocarCategoria(&cat);


    for (int i = 0; i < 5; i++) {
        Strc_Fornecedores forn;
        strcpy(forn.nomeFantasia, "fornecedor A");
        strcpy(forn.cnpj, "111111");
        strcpy(forn.inscricaooSocial, "2222222");
        strcpy(forn.email, "email@gmail.com");
        strcpy(forn.telefone, "33513351");
        strcpy(forn.endereco, "rua aaaaaaaaa");
        strcpy(forn.razaoScial, "razao social");
        forn.codigo = gerarCodigoFornecedores();
        forn.contCatalago = 0;
        
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
