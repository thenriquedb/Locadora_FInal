
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/fileBIN.h"

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

        alocarClientes(&cl);
    }

     exportCliente_bin();

    Strc_Funcionario fun;
    strcpy(fun.nome, "klebin");
    strcpy(fun.cargo, "peao");
    strcpy(fun.email, "email@gmail.com");
    strcpy(fun.telefone, "555555");
    fun.codigo = gerarCodigoFuncionario();

    // exportFunc_bin(fun);
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

    exportLocadora_bin(loc);
    alterarLocadora(loc);

    Strc_Categoria cat;
    strcpy(cat.nome, "categoria A");
    strcpy(cat.descricao, "descricao categoria A");
    cat.codigo = gerarCodigoCategoria();
    cat.valor = 10.98;

    alocarCategoria(&cat);
    exportCategoria_bin(cat);


    Strc_Fornecedores forn;
    for (int i = 0; i < 2; i++) {
        forn.catalogoFilmes = NULL;

        strcpy(forn.nomeFantasia, "fornecedor A");
        strcpy(forn.cnpj, "CNPJ");
        strcpy(forn.inscricaooSocial, "INSCRICAO SOCIAL");
        strcpy(forn.email, "email@gmail.com");
        strcpy(forn.telefone, "33513351");
        strcpy(forn.endereco, "rua aaaaaaaaa");
        strcpy(forn.razaoScial, "razao social");

        forn.codigo = gerarCodigoFornecedores();
        forn.contCatalago = 3;

        for (int j = 0; j < forn.contCatalago; j++) {
            forn.catalogoFilmes = alocar_Int(forn.catalogoFilmes, forn.contCatalago);
            forn.catalogoFilmes[j] = j + 1;
            //printf("%d j: %d\n", forn.catalogoFilmes[j], j);
        }

        alocarFornecedores(&forn);
    }
    
    exportFornecedor_bin(forn);


    
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

        alocarFilmes(&fil);
    }
    
    exportFilmes_bin(fil);


    /*
        Strc_Locacoes locacoes;
        for (int i = 0; i < 1; i++) {
            locacoes.codCliente = i + 1;
            locacoes.codFunc = 1;
            locacoes.pagamento = 'V';
            locacoes.contItens = 2;
            locacoes.Itens = NULL;

            if (locacoes.contItens != 0) {
                for (int j = 0; j < locacoes.contItens; j++) {
                    locacoes.Itens = alocar_MinimalFilmes(locacoes.Itens, locacoes.contItens);
                    locacoes.Itens[j].codFilme = j + 1;
                    locacoes.Itens[j].quant = (j + 1)*100;
                    locacoes.Itens[j].preco = 10;
                    locacoes.Itens[j].total = locacoes.Itens[j].quant * locacoes.Itens[j].preco;

                    exportLocacoes_bin(locacoes);
                    alocarLocacoes(&locacoes);
                }
            }
        }
     */
    
    /*
    Strc_ContasReceber contasReceber;
    for (int i = 0; i < 3; i++) {
        contasReceber.codCl = i + 1;
        contasReceber.situacao[0] = 'P';
        contasReceber.quantParcelas = 2;
        contasReceber.entrada[0] = 'S';
        contasReceber.valorEntrada = 177;
        contasReceber.vlrParcela = 50;

        alocarContas_aReceber(&contasReceber);
    }
        exportContasReceber_bin(contasReceber);


    Strc_notaFiscal nf;
    for (int i = 0; i < 3; i++) {
        nf.Itens = NULL;
        nf.codForn = 3 * (i + 2);
        nf.codigo = i + 1;
        nf.contItens = 3;
        nf.paga = 1;
        nf.precoImposto = 300;
        nf.freteUnidade = 150;
        nf.impostoUnidade = 300;
        nf.totalNF = 5555;

        for (int j = 0; j < 3; j++) {
            nf.Itens = alocar_MinimalFilmes(nf.Itens, nf.contItens);
            nf.Itens[j].codFilme = j + 1;
            nf.Itens[j].quant = (j + 1)*100;
            nf.Itens[j].preco = 10;
            nf.Itens[j].total = 9999;
        }

        alocarNotasFiscais(&nf);
    }
            exportNotasFiscais_bin(nf);
*/
}