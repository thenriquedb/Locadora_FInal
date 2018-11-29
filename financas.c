
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
#include "Bibliotecas/fileTXT.h"



void contasPagar_Unica() {
    int codNF, i, opc, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Caixa Financeiro = return_Caixa();

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

                alterarCaixa(Financeiro);
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

    digiteAlguma_teclaContinuar();
}





void contasPagar_Fornecedor() {
    int codFor, codNF, i, cont = 0, opc, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Caixa Financeiro = return_Caixa();

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

                alterarCaixa(Financeiro);
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

    digiteAlguma_teclaContinuar();
}





void contasPagar_Todas() {
    int codFor, codNF, i, cont = 0, opc, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Caixa Financeiro = return_Caixa();

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

    digiteAlguma_teclaContinuar();
}






void PagamentoLocacao(int codCl, int codFun, int contAluguel, int posCl, float totalPagamento, Strc_MinimalFilmes* FilmesLocados) {
    int i, codFilme, codCliente, opc, opc2, quant, quantParcela;
    float entrada;

    Strc_Clientes* Clientes = return_Clientes();
    Strc_Caixa Financeiro = return_Caixa();
    Strc_Locacoes Locacoes;
    Strc_ContasReceber conta_aReceber;

    Locacoes.codFunc = codFun;
    Locacoes.Itens = FilmesLocados;
    Locacoes.contItens = contAluguel;
    Locacoes.codCliente = codCl;

    printf("Total: R$ %.2f \n", totalPagamento);
    printf("Forma de pagamento: \n"
            "\t1. A vista \n"
            "\t2, A prazo \n");
    conta_aReceber.total = totalPagamento;

    if (selecao() == 1) {
        Financeiro.caixa += totalPagamento;
        Locacoes.pagamento = 'V';
    } else {
        printf("====== | FORMA DE PAGAMENTO: A PRAZO | ======\n");
        do {
            printf("Digite a quantidade de parcelas que deseja, uma, ou três parcelas: ");
            scanf("%d", &quantParcela);
        } while (quantParcela < 1 && quantParcela > 3);

        Locacoes.pagamento = 'D';
        conta_aReceber.codCl = codCl;
        conta_aReceber.quantParcelas = quantParcela;
        conta_aReceber.situacao[0] = 'D';

        printf("Deseja dar algum valor de entrada: \n"
                "\t1. Com entrada \n"
                "\t2. Sem entrada \n");
        if (selecao() == 1) {
            do {
                printf("Digite o valor da entrada: ");
                scanf("%f", &entrada);

                if (entrada >= conta_aReceber.total) {
                    printf("Valor de entrada precisa ser menor que o valor total da comrpa. \n");
                }

                conta_aReceber.entrada[0] = 'S';
                conta_aReceber.valorEntrada = entrada;
            } while (entrada >= conta_aReceber.total);

            conta_aReceber.vlrParcela = (totalPagamento - entrada) / quantParcela;
            Financeiro.caixa += entrada;
        } else {
            conta_aReceber.entrada[0] = 'N';
            conta_aReceber.vlrParcela = totalPagamento / quantParcela;
        }
        printf("\nForma de pagamento escolhida foi %d parcelas de R$ %.2f cada. \n",
                quantParcela, conta_aReceber.vlrParcela);
    }

    alocarContas_aReceber(&conta_aReceber);
    exportLocacoes_txt(Locacoes);
    alocarLocacoes(&Locacoes);

    alterarClientes(Clientes);
    alterarCaixa(Financeiro);

    digiteAlguma_teclaContinuar();
}






void receber_ContasCl() {
    int codCl, verificar = 0;
    int contContas = returnCont_contasReceber();
    Strc_ContasReceber* Conta = return_contasReceber();
    Strc_Caixa Financas = return_Caixa();

    printf("====== | RECEBIMENTO DE CONTAS | ======\n");
    do {
        printf("Digite o código do cliente: ");
        scanf("%d", &codCl);
    } while (verificarCod_Cliente(codCl) < 0);

    for (int i = 0; i < contContas; i++) {
        if (Conta[i].codCl == codCl) {
            if (Conta[i].situacao[0] == 'D') {
                Conta[i].quantParcelas--;
                Financas.caixa += Conta[i].vlrParcela;

                verificar++;
                printf("Parcela paga com sucesso. Parcelas restantes: %d \n", Conta[i].quantParcelas);

                if (Conta[i].quantParcelas == 0) {
                    Conta[i].situacao[0] = 'P';
                    printf("Todas as parcelas foram pagas. \n");
                }
            } else {
                printf("Este cliente não possui nenhuma conta em aberto. \n");
                verificar++;
            }
        }
    }

    if (verificar > 0) {
        alterarCaixa(Financas);
        alterar_contasReceber(Conta);
    } else {
        printf("Nenhum cliente com este código encontrado. \n");
    }

    digiteAlguma_teclaContinuar();
}