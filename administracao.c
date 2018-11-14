
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/administracao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/GUI.h"
#include "Bibliotecas/financas.h"

void entradaFilmes() {
    int i, opc, opc2, codFor, CodFil, PosForn, PosFil, contCompras = 0, quantCopias, totalCopias = 0;
    float total = 0, somatorio = 0, totalFrete, totalImposto, vlrEntrada;

    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Filmes* Filme = return_Filmes();
    Strc_Locadora Locadora = return_Locadora();
    Strc_Financas Financeiro = return_Financas();
    Strc_notaFiscal Notas;

    Notas.Itens = NULL;

    printf("====== | ENTRADA DE FILMES |======\n");
    do {
        printf("Digite o código do fornecedor: ");
        scanf("%d", &codFor);
    } while (verificarCod_Fornecedores(codFor) < 0);
    PosForn = codFor - 1;

    system("clear");
    //Inicio bloco selecão dos titulos
    do {
        printf("====== | ENTRADA DE FILMES |======\n");
        printf("%dº PRODUTO \n", contCompras + 1);

        do {
            printf("Digite o código do filme desejado: ");
            scanf("%d", &CodFil);
        } while (verificarFilme_Fornecedor(PosForn, CodFil, Fornecedor[PosForn].contCatalago) != 1);
        PosFil = CodFil - 1;

        printf("====== | ENTRADA DE FILMES |======\n");
        system("clear");
        do {
            printf("Total de cópias: ");
            scanf("%d", &quantCopias);
        } while (verificarNumeroPositivoINT(quantCopias) != 1);

        printf("Opções: \n"
                "\t1. Confirmar \n"
                "\t2. Corrigir \n");
        opc = selecao();

        if (opc == 1) {
            Notas.Itens = alocar_MinimalFilmes(Notas.Itens, contCompras);
            Locadora.filmesComprados = alocar_FilmesComprados(Locadora.filmesComprados, Locadora.contFilmes_comprados);

            Locadora.filmesComprados[PosFil] = CodFil;
            Filme[PosFil].exemplares += quantCopias;

            total = Filme[PosFil].precoCompra*quantCopias; // Valor total da compra de cada produto
            somatorio += total; //Soma de todas as compras
            totalCopias += quantCopias;

            Notas.Itens[contCompras].codFilme = CodFil;
            Notas.Itens[contCompras].preco = Filme[CodFil - 1].precoCompra;
            Notas.Itens[contCompras].quant = quantCopias;
            Notas.Itens[contCompras].total = total;

            contCompras++;
            Notas.contItens = contCompras;
            Locadora.contFilmes_comprados++;
        }

        printf("Opções \n"
                "\t1. Comprar mais filmes \n"
                "\t2. Encerrar \n");
        opc = selecao();

    } while (opc != 2);
    //Fim bloco de seleção de tiulos

    alterarFilmes(Filme);
    system("clear");

    printf("Finalizando... \n");

    printf("\tFrete: ");
    scanf("%f", &totalFrete);

    printf("\tImposto: ");
    scanf("%f", &totalImposto);

    do {
        system("clear");
        printf("Total: R$ %.2f \n\n", somatorio + totalFrete + totalImposto);
        printf("Forma de pagamento: \n"
                "\t1. A vista \n"
                "\t2. A prazo \n");
        opc2 = selecao();

        if (opc2 != 1 && opc2 != 2) {
            printf("Opção inválida. \n");
        }
    } while (opc2 != 1 && opc2 != 2);

    if (opc2 == 1) {
        Notas.paga = 1;
        Notas.totalNF = somatorio + totalFrete + totalImposto;
        Financeiro.caixa -= Notas.totalNF;

    } else {
        printf("PAGAMENTO A PRAZO \n"
                "\t1. Com entrada \n"
                "\t2. Sem entrada \n");
        opc = selecao();

        if (opc == 1) {
            printf("Digite o valor da entrada: ");
            scanf("%f", &vlrEntrada);

            Notas.totalNF = (somatorio + totalFrete + totalImposto) - vlrEntrada;
            Financeiro.caixa = Financeiro.caixa - vlrEntrada;
            Notas.paga = 0;
        } else {
            Notas.totalNF = (somatorio + totalFrete + totalImposto);
        }
        printf("Nota fiscal disponível no menu \"Contas a pagar.\" \n");
    }

    Notas.codForn = codFor;
    Notas.freteUnidade = totalFrete / totalCopias;
    Notas.impostoUnidade = totalImposto / totalCopias;
    Notas.precoFrete = totalFrete;
    Notas.precoImposto = totalImposto;

    alterarLocadora(Locadora);
    alterarFinanceiro(Financeiro);
    alocarNotasFiscais(&Notas);
}
//------------------------------------------------------------------------------

int gerarCodigoNF() {
    int static codigo = 0;

    codigo++;
    return codigo;
}
//------------------------------------------------------------------------------

void visualizarEstoque() {
    Strc_Locadora Locadora = return_Locadora();
    Strc_Filmes* Filme = return_Filmes();

    if (Locadora.contFilmes_comprados != 0) {
        for (int i = 0; i < Locadora.contFilmes_comprados; i++) {
            printf("%dº Filme \n", i + 1);
            printf("\tTítulo: %s \n", Filme[Locadora.filmesComprados[i]].nome);
            printf("\tCódigo: %d \n", Locadora.filmesComprados[i]);
            printf("\tExempalres: %d \n", Filme[Locadora.filmesComprados[i]].exemplares);
        }
    } else {
        printf("Nenhum filme comprado. \n");
    }
}
//-------------------------------------------------------------------------------

void locacaoFilmes() {
    int i, codFilme, codFunc, codCliente, opc, opc2, quant, quantParcela, contAluguel = 0, posCat = 0, posFilme, posCliente;
    float totalPagamento = 0, entrada;

    Strc_Filmes* Filmes = return_Filmes();
    Strc_Clientes* Clientes = return_Clientes();
    Strc_Categoria* Categoria = return_Categorias();
    Strc_Financas Financeiro = return_Financas();
    Strc_MinimalFilmes* FilmesLocados = NULL;

    do {
        printf("Locações são realizadas apenas por funcionários. Digite seu código de registro: \n ");
        scanf("%d", &codFunc);
    } while (verificarCod_Funcionario(codFunc) < 0);

    do {
        printf("Digite o código do cliente para continuar: ");
        scanf("%d", &codCliente);
    } while (verificarCod_Cliente(codCliente) < 0);
    posCliente = codCliente - 1;

    do {
        printf("====== | LOCAÇÃO DE FILMES | ======\n");
        FilmesLocados = alocar_MinimalFilmes(FilmesLocados, contAluguel);
        printf("%dº FILME \n", contAluguel + 1);

        do {
            do {
                printf("\tDigite o codígo do filme desejado: ");
                scanf("%d", &codFilme);
            } while (verificarCod_Filme(codFilme) < 0);

            posFilme = codFilme - 1;
            posCat = Filmes[posFilme].codigoCategoria - 1;

            if (Filmes[posFilme].exemplares != 0) {
                do {
                    printf("\tDigite o número de exemplares: ");
                    scanf("%d", &quant);
                } while (verificarExemplares_Filmes(codFilme, quant) != 1);

                FilmesLocados[contAluguel].codFilme = codFilme;
                FilmesLocados[contAluguel].quant = quant;
            } else {
                printf("Filme esgotado. Favor selecionar outro título. \n");
            }
        } while (Filmes[posFilme].exemplares == 0);

        printf("\tDeseja selecionar mais filmes: \n"
                "\t\t1. Sim \n"
                "\t\t2. Não \n");
        opc = selecao();

        contAluguel++;
        totalPagamento += Categoria[posCat].valor * quant;
        Filmes[posFilme].exemplares -= quant;

        if (opc == 1) {
            system("clear");
            printf("Filme adcionado com sucesso! \n");

        } else {
            printf("Títulos selecionados: \n");

            for (i = 0; i < contAluguel; i++) {
                printf("\tTitulo: %s \n", Filmes[FilmesLocados[i].codFilme - 1].nome);
                printf("\tQuantidade: %d \n\n", FilmesLocados[i].quant);
            }

            printf("Opções: \n"
                    "\t1; Confirmar \n "
                    "\t2. Corrigir \n");
            opc2 = selecao();
            if (opc2 == 2) {
                contAluguel = 0;
            }
            system("clear");
        }
    } while (opc2 != 1);

    PagamentoLocacao(codCliente, codFunc, contAluguel, posCliente, totalPagamento, FilmesLocados);
}