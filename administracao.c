
#include <stdio.h>
#include <stdlib.h>
#include "Bibliotecas/administracao.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/GUI.h"

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
    int i, codFilme, codCliente, opc, opc2, quant, contAluguel = 0, posCat = 0, posFilme, posCliente;
    float totalPagamento = 0;

    Strc_Filmes* Filmes = return_Filmes();
    Strc_Clientes* Clientes = return_Clientes();
    Strc_Categoria* Categoria = return_Categorias();
    Strc_Locadora Locadora = return_Locadora();
    Strc_Financas Financeiro = return_Financas();
    Strc_MinimalFilmes* FilmesLocados = NULL;

    /*
    do {
        printf("Digite o código do cliente para continuar: ");
        scanf("%d", &codCliente);
    } while (verificarCod_Cliente(codCliente) < 0);
     */
    
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

        if (opc == 1) {
            system("clear");
            printf("Filme adcionado com sucesso! \n");

            Filmes[posFilme].exemplares -= quant;
            totalPagamento += Categoria[posCat].valor * quant;
        } else {
            printf("Títulos selecionados: \n");

            for (i = 0; i < contAluguel; i++) {
                printf("\tTitulo: %s \n", Filmes[FilmesLocados[i].codFilme - 1].nome);
                printf("\tQuantidade: %d \n\n", FilmesLocados[i].quant);
            }

            printf("\nDigite 1 para confirmar ou 2 para selecionar novamente. \n");
            opc2 = selecao();

            if (opc2 == 2) {
                contAluguel = 0;
            }
        }
    } while (opc2 != 1);

    system("clear");
    printf("Total: R$ %.2f \n", totalPagamento);

    int quantParcela;
    float entrada;

    printf("Forma de pagamento: \n"
            "\t1. A vista \n"
            "\t2, A prazo \n");

    if (selecao() == 1) {
        Clientes[posCliente].devendo = 0;
        Financeiro.caixa = totalPagamento;

        //     alterarLocadora(Locadora);
        alterarFinanceiro(Financeiro);
    } else {
        printf("PAGAMENTO A PRAZO \n"
                "\t1. Com entrada \n"
                "\t2. Sem entrada \n");

        if (selecao() == 1) {
            printf("Digite o valor da entrada: ");
            scanf("%f", &entrada);

            do {
                printf("Digite a quantidade de parcelas que deseja: ");
                scanf("%d", &quantParcela);
            } while (quantParcela < 1 && quantParcela > 3);

            Clientes[posCliente].quantParcela = quantParcela;
            Clientes[posCliente].devendo = 1;
            Clientes[posCliente].vlr_devendo = (totalPagamento - entrada) / quantParcela;

            printf("\nForma de pagamento escolhida foi %d parcelas de R$ %.2f cada. \n", quantParcela, Clientes[posCliente].vlr_devendo);
        }
        alterarClientes(Clientes);

    }
}
//------------------------------------------------------------------------------

void contasPagar_Unica() {
    int codNF, i, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Financas Financeiro = return_Financas();

    printf("====== | PAGAR NF PELO SEU CÓDIGO | ======\n");
    do {
        printf("Digite o código da nota fisca que deseja pagar: ");
        scanf("%d", &codNF);
    } while (verificarCod_NotaFiscal(codNF) > 0);

    if (Nota[codNF - 1].paga == 0) {
        imprimeNotaFiscal(Nota[codNF - 1].codForn - 1, Nota[codNF - 1].contItens);

        printf("Opções: \n"
                "\t1. Pagar agora \n"
                "\t2. Pagar em outro momento \n");

        if (selecao() == 1) {
            Financeiro.caixa -= Nota[codNF - 1].totalNF;
            Nota[codNF - 1].paga = 1;

            alterarFinanceiro(Financeiro);
            alterarNotasFiscais(Nota);
        } else {
            menuFinancas();
        }
    } else {
        printf("A nota de código %d já esta paga. \n", codNF);
    }
}
//------------------------------------------------------------------------------

void contasPagar_Fornecedor() {
    int codFor, codNF, i, cont = 0, opc, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Financas Financeiro = return_Financas();

    printf("====== | PAGAR NF DE DETERMINADO FORNECEDOR | ======\n");
    do {
        printf("Digite o código da nota fiscal que deseja pagar: ");
        scanf("%d", &codFor);
    } while (verificarCod_Fornecedores(codFor) > 0);

    for (i = 0; i < contNF; i++) {
        if (Nota[i].codForn == codFor && Nota[i].paga == 0) {
            imprimeNotaFiscal(Nota[i].codForn - 1, Nota[i].contItens);
            cont++;
        }
    }
    if (cont != 0) {
        printf("Opções: \n"
                "\t1. Pagar todas de uma vez \n"
                "\t2. Pagar pelo código \n");

        if (selecao() == 1) {
            for (i = 0; i < contNF; i++) {
                if (Nota[i].codForn == codFor && Nota[i].paga == 0) {
                    Financeiro.caixa -= Nota[i].totalNF;
                    Nota[i].paga = 1;
                    cont++;
                }
            }
            printf("Todas as notas deste fornecedor foram quitadas. \n");
        } else {

            do {
                do {
                    printf("Digite o código da nota: \n");
                    scanf("%d", &codNF);
                } while (verificarCod_NotaFiscal(codNF) < 0);

                Nota[codFor - 1].paga = 1;
                Financeiro.caixa -= Nota[codFor - 1].totalNF;
                printf("Nota de código %d paga com sucesso. \n", codNF);

                alterarFinanceiro(Financeiro);
                alterarNotasFiscais(Nota);

                system("clear");
                printf("Opções: \n"
                        "\t1. Pagar outra nota fiscal \n"
                        "\t2. Sair \n");
                opc = selecao();
            } while (opc != 2);
        }
    } else {
        printf("Todas as contas deste fornecedor já foram pagas. \n");
    }
}

//------------------------------------------------------------------------------

void contasPagar_Todas() {
    int codFor, codNF, i, cont = 0, opc, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Financas Financeiro = return_Financas();

    printf("====== | PAGAR TODAS NOTAS FISCAIS | ======\n");

    for (i = 0; i < contNF; i++) {
        if (Nota[i].paga == 0) {
            imprimeNotaFiscal(Nota[i].codForn - 1, Nota[i].contItens);
            cont++;
        }
    }

    printf("Opções: \n"
            "\t1. Pagar todas de uma vez \n"
            "\t2. Pagar em outro moemento \n");

    if (selecao() == 1) {
        for (i = 0; i < contNF; i++) {
            if (Nota[i].paga == 0) {
                Financeiro.caixa -= Nota[i].totalNF;
                Nota[i].paga = 1;
                cont++;
            }
        }
    } else {
        menuFinancas();
    }
}