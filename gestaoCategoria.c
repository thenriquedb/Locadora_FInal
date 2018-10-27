#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"

int edicaoCategoria() {
    int cod, i;

    printf("====== | ATUALIZAÇÃO DE DADOS: CATEGORIAS | ======\n");
    printf("Digite o codigo do cliente que deseja editar: ");
    scanf("%d", &cod);

    if (verificarCod_Categoria(cod) >= 0) {
        i = verificarCod_Categoria(cod);

        system("clear");
        printf("====== | ATUALIZAÇÃO DE DADOS: CATEGORIAS | ======\n");
        printf("Código %d \n", i);
        imprimeCategorias(i);

        printf("\nO que deseja editar: \n"
                "\t1. Nome \n"
                "\t2. Descrição \n"
                "\t3. Valor da multa \n"
                "\t4. Tudo \n"
                "\t5. Voltar ao menu anterior \n");

        switch (selecao()) {
            case 1:
                edicaoCategoria_nome(i);
                break;

            case 2:
                edicaoCategoria_descricao(i);
                break;

            case 3:
                edicaoCategoria_valor(i);
                break;

            case 4:
                edicaoCategoria_tudo(i);
                break;

            case 5:
                menuGestao(i);
                break;

            default:
                printf("Opção inválida. \n");

        }
    } else {
        printf("Código inválido. \n");
    }
}
//-------------------------------------------------------------------------------

void edicaoCategoria_nome(int i) {
    Strc_Categoria* Categoria = return_Categorias();
    char nome[100];
    int opc;

    do {
        printf("Nome atual: %s \n", Categoria[i].nome);
        setbuf(stdin, NULL);
        printf("Novo nome: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Categoria[i].nome, nome);
            alterarCategorias(Categoria);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCategoria_descricao(int i) {
    Strc_Categoria* Categoria = return_Categorias();
    char descricao[400];
    int opc;

    do {
        printf("Descrição atual: %s \n", Categoria[i].descricao);
        setbuf(stdin, NULL);
        printf("Nova descrição: ");
        scanf("%[^\n]s", descricao);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Categoria[i].descricao, descricao);
            alterarCategorias(Categoria);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCategoria_valor(int i) {
    Strc_Categoria* Categoria = return_Categorias();
    float vlr;
    int opc;

    do {
        printf("Valor da multa atual: R$ %.2f \n", Categoria[i].valor);

        printf("Novo valor: ");
        do {
            scanf("%f", &vlr);
        } while (verificarNumeroPositivoFLOAT(vlr) != 1);


        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Categoria[i].valor = vlr;
            alterarCategorias(Categoria);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCategoria_tudo(int i) {
    Strc_Categoria* Categoria = return_Categorias();
    float vlr;
    int opc;
    char nome[100], descricao[400];

    do {
        setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Descrição: ");
        scanf("%[^\n]s", descricao);
        setbuf(stdin, NULL);

        printf("Valor da multa de atraso: ");
        scanf("%f", &vlr);
        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Categoria[i].descricao, descricao);
            strcpy(Categoria[i].nome, nome);
            Categoria[i].valor = vlr;

            alterarCategorias(Categoria);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void excluirCategoria() {
    Strc_Categoria* Categoria = return_Categorias();
    int cod, verifica = 0, contCat = returnCont_Categorias();

    printf("====== | EXCLUIR CATEGORIA CADASTRADA | ======\n");
    printf("Digite o codigo da categoria que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contCat; i++) {
        if (cod == Categoria[i].codigo) {
            verifica++;
            do {
                Categoria[i] = Categoria[i + 1];
                i++;
            } while (i < contCat);
            break;
        }
    }
    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Categoria excluída com sucesso. \n");
        contCat = contCat - 1;
        alterarCategorias(Categoria);
        alterar_contCategorias(contCat);
    }
}