
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
    int i, cod;

    printf("====== | COMPRAS DE NOVOS FILMES | ======\n"
            "\t1. Visualizar fornecedores cadastrados \n"
            "\t2. Cadastrar novo fornecedor \n"
            "\t3. Escolher fornecedor através do codigo \n"
            "\t4. Voltar ao menu principal \n");
    do {
        switch (selecao()) {
            case 1:
                subMenuRel_Fornecedores();
                break;

            case 2:
                cadastrarFornecedores();
                break;

            case 3:
                printf("Digite o codigo do fornecedor que deseja comprar: ");
                scanf("%d", &cod);

                if (verificarCod_Fornecedores(cod) >= 0) {
                    i = verificarCod_Fornecedores(cod);
                } else {
                    printf("Codigo inválido. \n");
                }
                break;

            case 4:
                break;

            default:
                printf("Opção inválida. \n");
        }
        break;
    } while (1);
}

void locacaoFilmes() {
    int filme[50];
    int i = 0, codFilme, codCliente, opc, opc2, quant, contAluguel = 0, posCat, posFilme, posCliente;
    float totalPagamento = 0;

    Strc_Filmes* Filmes = return_Filmes();
    Strc_Clientes* Clientes = return_Clientes();
    Strc_Categoria* Categoria = return_Categorias();
    Strc_Locadora Locadora = return_Locadora();

    /*
    do {
        printf("Digite o código do cliente para continuar: ");
        scanf("%d", &codCliente);
    } while (verificarCod_Cliente(codCliente) < 0);
     */
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
        Locadora.caixa = totalPagamento;

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