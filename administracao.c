
#include <stdio.h>
#include <stdlib.h>
#include "Bibliotecas/administracao.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/alocacao.h"

void entradaFilmes() {
    int i, opc, codFor, CodFil, PosForn, PosFil, contCompras = 0, quantCopias, totalCopias = 0;
    float total = 0, somatorio = 0, totalFrete, totalImposto, freteUnidade, impostoUnidade;

    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Filmes* Filme = return_Filmes();
    Strc_Locadora Locadora = return_Locadora();

    Strc_notaFiscal Notas;
    Notas.Itens = NULL;

    printf("====== | ENTRADA DE FILMES |======\n");
    do {
        printf("Digite o código do fornecedor: ");
        scanf("%d", &codFor);
    } while (verificarCod_Fornecedores(codFor) < 0);
    PosForn = codFor - 1;
    system("clear");

    do {
        printf("====== | ENTRADA DE FILMES |======\n");
        printf("%dº PRODUTO \n", contCompras + 1);
        
        do {
            printf("Digite o código do filme desejado: ");
            scanf("%d", &CodFil);
        } while (verificarFilme_Fornecedor(PosForn, CodFil, Fornecedor[PosForn].contCatalago) != 1);
        PosFil = CodFil - 1;

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
        
        printf("Oppções \n"
                "\t1. Comprar mais filmes \n"
                "\t2. Encerrar \n");
        opc = selecao();

    } while (opc != 2);

    system("clear");
    printf("Finalizando... \n");
    
    printf("\tFrete: ");
    scanf("%f", &totalFrete);

    printf("\tImposto: ");
    scanf("%f", &totalImposto);

    Notas.codForn = codFor;
    Notas.freteUnidade = totalFrete / totalCopias;
    Notas.impostoUnidade = totalImposto / totalCopias;
    Notas.precoFrete = totalFrete;
    Notas.precoImposto = totalImposto;
    Notas.totalNF = somatorio + totalFrete + totalImposto;

    alocarNotasFiscais(&Notas);
    alterarLocadora(Locadora);
    alterarFilmes(Filme);
}

void visualizarEstoque() {
    Strc_Locadora Locadora = return_Locadora();

    for (int i = 0; i < Locadora.contFilmes_comprados; i++) {
        printf("%dº Filme \n", i + 1);
        printf("\tTítulo:  \n");
        printf("\tCódigo: %d \n", Locadora.filmesComprados[i]);
    }
}

void locacaoFilmes() {
    int filme[50];
    int i = 0, codFilme, codCliente, opc, opc2, quant, contAluguel = 0, posCat, posFilme, posCliente;
    float totalPagamento = 0;

    Strc_Filmes* Filmes = return_Filmes();
    Strc_Clientes* Clientes = return_Clientes();
    Strc_Categoria* Categoria = return_Categorias();
    Strc_Locadora Locadora = return_Locadora();

    do {
        printf("Digite o código do cliente para continuar: ");
        scanf("%d", &codCliente);
    } while (verificarCod_Cliente(codCliente) < 0);
    posCliente = codCliente - 1;

    do {
        printf("====== | LOCAÇÃO DE FILMES | ======\n");
        printf("%dº FILME \n", i + 1);

        do {
            printf("\tDigite o codígo do filme desejado: ");
            scanf("%d", &codFilme);
        } while (verificarCod_Filme(codFilme) < 0);

        filme[i] = codFilme;

        do {
            printf("\tDigite o número de exemplares: ");
            scanf("%d", &quant);
        } while (verificarExemplares_Filmes(codFilme, quant) != 1 && verificarExemplares_Filmes(codFilme, quant) != 3);

        printf("\tDeseja selecionar mais filmes: \n"
                "\t\t1. Sim \n"
                "\t\t2. Não \n");
        opc = selecao();

        if (opc == 1) {
            system("clear");
            printf("Filme adcionado com sucesso! \n");

            contAluguel++;
            i++;

            posCat = Filmes[codFilme - 1].codigoCategoria - 1;
            posFilme = codFilme - 1;

            Filmes[posFilme].exemplares -= quant;
            totalPagamento += Categoria[posCat].valor * quant;
        } else {
            printf("Títulos selecionados: \n");

            for (i = 0; i < contAluguel; i++) {
                printf("%d; ", filme[i]);
            }

            printf("\nDigite 1 para confirmar ou 2 para selecionar novamente. \n");
            opc2 = selecao();

            if (opc2 == 2) {
                i = 0;
                contAluguel = 0;
            }
        }
    } while (opc != 2 || opc2 != 1);

    system("clear");
    printf("Total: R$ %.2f \n", totalPagamento);

    int quantParcela;
    float entrada;

    printf("Forma de pagamento: \n"
            "\t1. A vista \n"
            "\t2, A prazo \n");

    if (selecao() == 1) {
        Clientes[posCliente].devendo = 0;
        Locadora.caixa += totalPagamento;

        alterarLocadora(Locadora);
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

            alterarClientes(Clientes);
        }
    }
}