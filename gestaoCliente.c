#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"

int edicaoCliente() {
    int cod, i;

    printf("====== | ATUALIZAÇÃO DE DADOS: CLIENTES | ======\n");
    printf("Digite o codigo do cliente que deseja editar: ");
    scanf("%d", &cod);

    if (verificarCod_Cliente(cod) >= 0) {
        i = verificarCod_Cliente(cod);

        system("clear");
        printf("====== | ATUALIZAÇÃO DE DADOS: CLIENTES | ======\n");
        printf("Código %d \n", i);
        imprimeClientes(i);

        printf("\nO que deseja editar: \n"
                "\t1. Nome \n"
                "\t2. Data de nascimento \n"
                "\t3. Endereço \n"
                "\t4. CPF \n"
                "\t5. Telefone \n"
                "\t6. Email \n"
                "\t7. Tudo \n"
                "\t8. Voltar ao menu anterior \n");

        switch (selecao()) {
            case 1:
                edicaoCliente_nome(i);
                break;

            case 2:
                edicaoCliente_dataNascimento(i);
                break;

            case 3:
                edicaoCliente_endereco(i);
                break;

            case 4:
                edicaoCliente_CPF(i);
                break;

            case 5:
                edicaoCliente_telefone(i);
                break;

            case 6:
                edicaoCliente_email(i);
                break;

            case 7:
                edicaoCliente_tudo(i);
                break;


            case 8:
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

void edicaoCliente_nome(int i) {
    Strc_Clientes* Cliente = return_Clientes();
    char nome[100];
    int opc;

    do {
        printf("Nome atual: %s \n", Cliente[i].nome);
        setbuf(stdin, NULL);
        printf("Novo nome: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Cliente[i].nome, nome);
            alterarClientes(Cliente);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCliente_endereco(int i) {
    Strc_Clientes* Cliente = return_Clientes();
    char endereco[150];
    int opc;

    do {
        printf("Endereço atual: %s \n", Cliente[i].endereco);
        setbuf(stdin, NULL);
        printf("Novo endereço: ");
        scanf("%[^\n]s", endereco);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Cliente[i].endereco, endereco);
            alterarClientes(Cliente);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCliente_CPF(int i) {
    Strc_Clientes* Cliente = return_Clientes();
    char cpf[11];
    int opc;

    do {
        printf("CPF atual: %s \n", Cliente[i].cpf);
        setbuf(stdin, NULL);
        printf("Novo CPF: ");
        scanf("%[^\n]s", cpf);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Cliente[i].cpf, cpf);
            alterarClientes(Cliente);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCliente_telefone(int i) {
    Strc_Clientes* Cliente = return_Clientes();
    char telefone[12];
    int opc;

    do {
        printf("Telefone atual: %s \n", Cliente[i].telefone);
        setbuf(stdin, NULL);
        printf("Novo telefone: ");
        scanf("%[^\n]s", telefone);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Cliente[i].telefone, telefone);
            alterarClientes(Cliente);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCliente_email(int i) {
    Strc_Clientes* Cliente = return_Clientes();
    char email[150];
    int opc;

    do {
        printf("Email atual: %s \n", Cliente[i].email);
        setbuf(stdin, NULL);
        printf("Novo email: ");
        scanf("%[^\n]s", email);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Cliente[i].email, email);
            alterarClientes(Cliente);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoCliente_dataNascimento(int i) {
    Strc_Clientes* Cliente = return_Clientes();
    char dataNascimento[10];
    int opc;

    do {
        printf("Data de nascimento atual: %s \n", Cliente[i].data_nascimento);
        setbuf(stdin, NULL);
        printf("Nova data de nascimento: ");
        scanf("%[^\n]s", dataNascimento);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Cliente[i].data_nascimento, dataNascimento);
            alterarClientes(Cliente);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}

//-------------------------------------------------------------------------------

void edicaoCliente_tudo(int i) {
    char nome[100], endereco[150], telefone[12], email[150], cpf[11], data_nascimento[10];
    int opc, opc_sexo, estado_civil;
    Strc_Clientes* Cliente = return_Clientes();

    printf("Dados Atuais \n");
    imprimeClientes(i);

    do {
        printf("Novos dados \n");

        setbuf(stdin, NULL);
        printf("\tNome: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("\tEndereço completo: ");
        scanf("%[^\n]s", endereco);
        setbuf(stdin, NULL);

        printf("\tCPF: ");
        scanf("%[^\n]s", cpf);
        setbuf(stdin, NULL);

        printf("\tTelefone: ");
        scanf("%[^\n]s", telefone);
        setbuf(stdin, NULL);

        printf("\tE-mail: ");
        scanf("%[^\n]s", email);
        setbuf(stdin, NULL);

        do {
            printf("\n\tSexo: \n"
                    "\t1. Masculino \n"
                    "\t2. Feminino \n"
                    "Digite a opção desejada:");
            scanf("%d", &opc_sexo);

        } while (opc_sexo != 1 && opc_sexo != 2);

        do {
            printf("\n\tEstado civil: \n"
                    "\t1. Solteiro \n"
                    "\t2. Casado \n"
                    "\t3. Divorciado(a) \n"
                    "\t4. Viúvo(a) \n"
                    "\t5. Separado(a) \n"
                    "Digite a opção desejada: ");
            scanf("%d", &estado_civil);

            if (estado_civil < 0 && estado_civil > 5) {
                printf("Opção inválida. \n");
            }

        } while (
                estado_civil != 1 && estado_civil != 2 &&
                estado_civil != 3 && estado_civil != 4 &&
                estado_civil != 5);


        setbuf(stdin, NULL);
        printf("\tData de nascimento (No formato dd/mm/aaaa): ");
        scanf("%[^\n]s", data_nascimento);
        setbuf(stdin, NULL);

        printf("\nDigite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        system("clear");
        if (opc == 1) {
            strcpy(Cliente[i].nome, nome);
            strcpy(Cliente[i].endereco, endereco);
            strcpy(Cliente[i].cpf, cpf);
            strcpy(Cliente[i].telefone, telefone);
            strcpy(Cliente[i].email, email);
            strcpy(Cliente[i].data_nascimento, data_nascimento);

            Cliente[i].opc_sexo = opc_sexo;
            Cliente[i].estado_civi = estado_civil;

            alterarClientes(Cliente);

            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}