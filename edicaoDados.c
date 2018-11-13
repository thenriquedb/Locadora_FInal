#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"
#include "Bibliotecas/GUI.h"
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
/*
  ==============================================================================
*/
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
//------------------------------------------------------------------------------
int edicaoFilme() {
    int cod, i;

    printf("====== | ATUALIZAÇÃO DE DADOS: FILMES | ======\n");
    printf("DIgite o codigo do filme que deseja editar: ");
    scanf("%d", &cod);

    if (verificarCod_Filme(cod) >= 0) {
        i = verificarCod_Filme(cod);

        system("clear");
        printf("====== | ATUALIZAÇÃO DE DADOS: FILMES | ======\n");
        printf("Código %d \n", i);
        imprimeFilmes(i);

        printf("\nO que deseja editar: \n"
                "\t1. Título \n"
                "\t2. Descrição \n"
                "\t3. Codigo da categoria \n"
                "\t4. Exemplares \n"
                "\t5. Idioma \n"
                "\t6. Tudo \n"
                "\t7. Voltar ao menu anterior \n");

        switch (selecao()) {
            case 1:
                edicaoFilme_nome(i);
                break;

            case 2:
                edicaoFilme_descricao(i);
                break;

            case 3:
                edicaoFilme_codigoCategoria(i);
                break;

            case 4:
                edicaoFilme_exemplares(i);
                break;

            case 5:
                edicaoFilme_idioma(i);
                break;

            case 6:
                edicaoFilme_tudo(i);
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

//-------------------------------------------------------------------------------

void edicaoFilme_nome(int i) {
    Strc_Filmes* Filme = return_Filmes();
    char nome[100];
    int opc;

    do {
        printf("Título atual: %s \n", Filme[i].nome);
        setbuf(stdin, NULL);
        printf("Novo título: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Filme[i].nome, nome);
            alterarFilmes(Filme);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}

//-------------------------------------------------------------------------------

void edicaoFilme_descricao(int i) {
    Strc_Filmes* Filme = return_Filmes();
    char descricao[400];
    int opc;

    do {
        printf("Descrição atual: %s \n", Filme[i].descricao);
        setbuf(stdin, NULL);
        printf("Nova descrição: ");
        scanf("%[^\n]s", descricao);
        setbuf(stdin, NULL);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Filme[i].descricao, descricao);
            alterarFilmes(Filme);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}

//-------------------------------------------------------------------------------

void edicaoFilme_exemplares(int i) {
    Strc_Filmes* Filme = return_Filmes();
    int opc, exemplares;

    do {
        printf("Quantidade de exemplares disponiveis atualmente: %d \n", Filme[i].exemplares);
        printf("Nova quantidade: ");
        scanf("%d", &exemplares);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Filme[i].exemplares = exemplares;
            alterarFilmes(Filme);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}

//-------------------------------------------------------------------------------

void edicaoFilme_idioma(int i) {
    Strc_Filmes* Filme = return_Filmes();
    int opc, idioma;

    do {
        printf("\tIdioma atual: ");
        if (Filme[i].idioma == 1) {
            printf("Dublado \n");
        } else {
            printf("Legendado \n");
        }

        printf("Novo idioma: \n"
                "\t1. Dublado \n"
                "\t2. Legendado \n"
                "Digite a opção desejada: ");
        scanf("%d", &idioma);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Filme[i].idioma = idioma;
            alterarFilmes(Filme);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFilme_codigoCategoria(int i) {
    Strc_Filmes* Filme = return_Filmes();
    int opc, codCategoria;

    do {
        printf("\tCodigo atual: %d \n", Filme[i].codigo);

        do {
            printf("\tNovo código: ");
            scanf("%d", &codCategoria);
            if (verificarCod_Categoria(codCategoria) >= 0) {
                break;
            }
        } while (1);

        printf("\tNovo código: %d \n\n", codCategoria);

        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);
        if (opc == 1) {
            Filme[i].codigoCategoria = codCategoria;
            alterarFilmes(Filme);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}
//-------------------------------------------------------------------------------

void edicaoFilme_tudo(int i) {
    char nome[100], descricao[400];
    int codCategoria, exemplares, idioma, opc;
    Strc_Filmes* Filme = return_Filmes();

    printf("Dados atuais \n");
    imprimeFilmes(i);

    do {
        printf("\nNovos dados \n");

        setbuf(stdin, NULL);
        printf("\tTítulo: ");
        scanf("%[^\n]s", nome);
        setbuf(stdin, NULL);

        printf("\tDescrição: ");
        scanf("%[^\n]s", descricao);
        setbuf(stdin, NULL);

        printf("\tExemplares: ");
        scanf("%d", &exemplares);

        do {
            printf("\tCódigo categoria: ");
            scanf("%d", &codCategoria);

            if (verificarCod_Categoria(codCategoria) >= 0) {
                break;
            }

        } while (1);

        do {
            printf("Idioma: \n"
                    "\t1. Dublado \n"
                    "\t2. Legendado \n"
                    "Digite a opção desejada: ");
            scanf("%d", &idioma);
        } while (idioma != 1 && idioma != 2);

        printf("\nDigite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);

        if (opc == 1) {
            strcpy(Filme[i].nome, nome);
            strcpy(Filme[i].descricao, descricao);
            Filme[i].idioma = idioma;
            Filme[i].exemplares = exemplares;
            Filme[i].codigoCategoria = codCategoria;

            alterarFilmes(Filme);

            system("clear");
            printf("Dados alterados com sucesso! \n");
        } else {
            system("clear");
        }
    } while (opc != 1);
}