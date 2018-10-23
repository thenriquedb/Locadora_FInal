#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"

int edicaoFornecedor() {
    int cod, i;

    printf("====== | ATUALIZAÇÃO DE DADOS: FORNECEDOR | ======\n");
    printf("Digite o codigo do fornecedor que deseja editar: ");
    scanf("%d", &cod);

    if (verificarCod_Fornecedores(cod) >= 0) {
        i = verificarCod_Fornecedores(cod);

        system("clear");
        printf("====== | ATUALIZAÇÃO DE DADOS: FORNECEDOR | ======\n");
        printf("Código %d \n", i);
        imprimeFornecedores(i);

        printf("\nO que deseja editar: \n"
                "\t1. Razão social \n"
                "\t2. Nome fantasia \n"
                "\t3. Endereço \n"
                "\t4. Telefone \n"
                "\t5. Email \n"
                "\t6. CNPJ \n"
                "\t7. Inscrição social \n"
                "\t8. Tudo \n"
                "\t9. Voltar ao menu anterior \n");

        switch (selecao()) {
            case 1:
                edicaoFornecedor_razaoSocial(i);
                break;

            case 2:
                edicaoFornecedor_nomeFantasia(i);
                break;

            case 3:
                edicaoFornecedor_endereco(i);
                break;

            case 4:
                edicaoFornecedor_telefone(i);
                break;

            case 5:
                edicaoFornecedor_email(i);
                break;

            case 6:
                edicaoFornecedor_cnpj(i);
                break;

            case 7:
                edicaoFornecedor_inscricaoSocial(i);
                break;

            case 8:
                edicaoFornecedor_tudo(i);
                break;

            case 9:
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

void edicaoFornecedor_nomeFantasia(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char nomeFantasia[100];

    do {
        printf("Nome fantasia atual: %s \n", Fornecedor[i].nomeFantasia);
        printf("Novo nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nomeFantasia);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].nomeFantasia, nomeFantasia);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_razaoSocial(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char razaoSocial[100];

    do {
        printf("Nome fantasia atual: %s \n", Fornecedor[i].razaoScial);
        printf("Novo nome fantasia: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", razaoSocial);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].razaoScial, razaoSocial);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_inscricaoSocial(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char inscricaoSocial[16];

    do {
        printf("Inscrição social atual: %s \n", Fornecedor[i].inscricaooSocial);
        printf("Novo numero de inscrição social: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", inscricaoSocial);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].inscricaooSocial, inscricaoSocial);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_email(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char email[150];

    do {
        printf("Email atual: %s \n", Fornecedor[i].email);
        printf("Novo email: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", email);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].email, email);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_endereco(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char endereco[150];

    do {
        printf("Endereço atual: %s \n", Fornecedor[i].endereco);
        printf("Novo endereço: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", endereco);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].endereco, endereco);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_telefone(int i) {
Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char telefone[12];

    do {
        printf("Telefone atual: %s \n", Fornecedor[i].telefone);
        printf("Novo telefone: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", telefone);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].telefone, telefone);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_cnpj(int i) {
Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int opc;
    char cnpj[14];

    do {
        printf("CNPJ atual: %s \n", Fornecedor[i].cnpj);
        printf("Novo CNPJ: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", cnpj);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].cnpj, cnpj);

            alterarFornecedores(Fornecedor);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFornecedor_tudo(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    char nomeFantasia[100], razaoSocial[100], endereco[150], telefone[12], cnpj[14], inscricaooSocial[16], email[150];
    int opc;

    do {
        setbuf(stdin, NULL);
        printf("Razão Social: ");
        scanf("%[^\n]s", razaoSocial);
        setbuf(stdin, NULL);

        printf("Nome Fantasia: ");
        scanf("%[^\n]s", nomeFantasia);
        setbuf(stdin, NULL);

        printf("Endereço: ");
        scanf("%[^\n]s", endereco);
        setbuf(stdin, NULL);

        printf("Telefone: ");
        scanf("%[^\n]s", telefone);
        setbuf(stdin, NULL);

        printf("Email: ");
        scanf("%[^\n]s", email);
        setbuf(stdin, NULL);

        printf("CNPJ (Somente números): ");
        scanf("%[^\n]s", cnpj);
        setbuf(stdin, NULL);

        printf("Inscrição social (Somente números): ");
        scanf("%[^\n]s", inscricaooSocial);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Fornecedor[i].razaoScial, razaoSocial);
            strcpy(Fornecedor[i].nomeFantasia, nomeFantasia);

            strcpy(Fornecedor[i].endereco, endereco);
            strcpy(Fornecedor[i].telefone, telefone);
            strcpy(Fornecedor[i].email, email);
            strcpy(Fornecedor[i].cnpj, cnpj);
            strcpy(Fornecedor[i].inscricaooSocial, inscricaooSocial);

            alterarFornecedores(Fornecedor);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}