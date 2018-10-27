#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"

int edicaoFuncionario() {
    int cod, i;

    printf("====== | ATUALIZAÇÃO DE DADOS: FUNCIONÁRIO | ======\n");
    printf("Digite o codigo do funcionário que deseja editar: ");
    scanf("%d", &cod);

    if (verificarCod_Funcionario(cod) >= 0) {
        i = verificarCod_Funcionario(cod);

        printf("Código %d \n", i);
        system("clear");
        printf("====== | ATUALIZAÇÃO DE DADOS: FUNCIONÁRIO | ======\n");
        imprimeFuncionarios(i);

        printf("\nO que deseja editar: \n"
                "\t1. Nome \n"
                "\t2. Endereço \n"
                "\t3. Telefone \n"
                "\t4. Email \n"
                "\t5, Cargo \n"
                "\t6. Tudo \n"
                "\t7. Voltar ao menu anterior \n");

        switch (selecao()) {
            case 1:
                edicaoFuncionario_nome(i);
                break;

            case 2:
                edicaoFuncionario_endereco(i);
                break;

            case 3:
                edicaoFuncionario_telefone(i);
                break;

            case 4:
                edicaoFuncionario_email(i);
                break;

            case 5:
                edicaoFuncionario_cargo(i);
                break;

            case 6:
                edicaoFuncionario_tudo(i);
                break;

            case 7:
                menuGestao(i);
                break;

            default:
                printf("Opção inválida. \n");

        }
    } else {
        printf("Código inválido. \n");
    }
}

void edicaoFuncionario_nome(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    char nome[100];
    int opc;

    do {
        printf("Nome atual: %s \n", Funcionario[i].nome);
        printf("Novo nome: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Funcionario[i].nome, nome);

            alterarFuncionarios(Funcionario);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFuncionario_cargo(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    char cargo[50];
    int opc;

    do {
        printf("Cargo atual: %s \n", Funcionario[i].cargo);
        printf("Novo cargo: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", cargo);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Funcionario[i].cargo, cargo);

            alterarFuncionarios(Funcionario);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFuncionario_email(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    char email[150];
    int opc;

    do {
        printf("Email atual: %s \n", Funcionario[i].email);
        printf("Novo email: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", email);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Funcionario[i].email, email);

            alterarFuncionarios(Funcionario);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFuncionario_endereco(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    char endereco[150];
    int opc;

    do {
        printf("Endereço atual: %s \n", Funcionario[i].endereco);
        printf("Novo endereço: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", endereco);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Funcionario[i].endereco, endereco);

            alterarFuncionarios(Funcionario);
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFuncionario_telefone(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    char telefone[12];
    int opc;

    do {
        printf("Endereço atual: %s \n", Funcionario[i].telefone);
        printf("Novo endereço: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", telefone);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Funcionario[i].telefone, telefone);

            alterarFuncionarios(Funcionario);
        }
    } while (opc != 1);
}

//-------------------------------------------------------------------------------

void edicaoFuncionario_tudo(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    char nome[100], endereco[150], telefone[12], email[150], cargo[50];
    int opc;

    do {
        setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", nome);
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

        printf("Cargo: ");
        scanf("%[^\n]s", cargo);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Funcionario[i].nome, nome);
            strcpy(Funcionario[i].endereco, endereco);
            strcpy(Funcionario[i].telefone, telefone);
            strcpy(Funcionario[i].email, email);
            strcpy(Funcionario[i].cargo, cargo);

            alterarFuncionarios(Funcionario);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void excluirFuncionario() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int cod, verifica = 0, contFunc = returnCont_Fornecedores();

    printf("====== | EXCLUIR FUNCIONÁRIO CADASTRADO | ======\n");
    printf("Digite o codigo do funcionário que deseja editar: ");
    scanf("%d", &cod);

    for (int i = 0; i < contFunc; i++) {
        if (cod == Funcionario[i].codigo) {
            verifica++;
            do {
                Funcionario[i] = Funcionario[i + 1];
                i++;
            } while (i < contFunc);
            break;
        }
    }

    if (verifica == 0) {
        printf("Código inválido. \n");
    } else {
        printf("Funcionário excluído com sucesso. \n");
        contFunc = contFunc - 1;

        if (contFunc == 0) {
            Funcionario = NULL;
        }

        alterarFuncionarios(Funcionario);
        alterar_contFuncionarios(contFunc);
    }
}
