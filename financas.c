
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

//------------------------------------------------------------------------------

void contasPagar_Unica() {
    int codNF, i, opc, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Financas Financeiro = return_Financas();

    do {
        system("clear");
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

                system("clear");
                printf("Nota paga com sucesso!. \n");
            } else {
                menuFinancas();
            }
        } else {
            system("clear");
            printf("A nota de código %d já esta paga. \n", codNF);
        }


        printf("Opções: \n"
                "\t1. Pagar outra conta \n"
                "\t2. Voltar para o menu anterior \n");
    } while (selecao() != 2);
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
//------------------------------------------------------------------------------

void PagamentoLocacao(int codCl, int codFun, int contAluguel, int posCl, float totalPagamento, Strc_MinimalFilmes* FilmesLocados) {
    int i, codFilme, codCliente, opc, opc2, quant, quantParcela;
    float entrada;
    Strc_Clientes* Clientes = return_Clientes();
    Strc_Financas Financeiro = return_Financas();
    Strc_Locacoes Locacoes;

    Locacoes.codFunc = codFun;
    Locacoes.Itens = FilmesLocados;
    Locacoes.contItens = contAluguel;
    Locacoes.codCliente = codCl;

    printf("Total: R$ %.2f \n", totalPagamento);
    printf("Forma de pagamento: \n"
            "\t1. A vista \n"
            "\t2, A prazo \n");

    if (selecao() == 1) {
        Financeiro.caixa += totalPagamento;
        Locacoes.pagamento = 'V';
    } else {
        printf("PAGAMENTO A PRAZO \n"
                "\t1. Com entrada \n"
                "\t2. Sem entrada \n");

        Locacoes.pagamento = 'P';
        if (selecao() == 1) {
            printf("Digite o valor da entrada: ");
            scanf("%f", &entrada);

            do {
                printf("Digite a quantidade de parcelas que deseja, uma, ou três parcelas: ");
                scanf("%d", &quantParcela);
            } while (quantParcela < 1 && quantParcela > 3);

            Clientes[posCl].quantParcela = quantParcela;
            Clientes[posCl].devendo = 1;
            Clientes[posCl].vlr_devendo = (totalPagamento - entrada) / quantParcela;
            Financeiro.caixa += entrada;

            printf("\nForma de pagamento escolhida foi %d parcelas de R$ %.2f cada. \n", quantParcela, Clientes[posCl].vlr_devendo);
        }
    }

    system("clear");
    printf("DATA \n");
    printf("\tDia: ");
    scanf("%d",&Locacoes.dia);
    printf("\tMês: ");
    scanf("%d",&Locacoes.mes);

    alterarClientes(Clientes);
    alocarLocacoes(&Locacoes);
    alterarFinanceiro(Financeiro);
}