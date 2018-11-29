
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/menus.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/gestao.h"
#include "Bibliotecas/administracao.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/financas.h"
#include "Bibliotecas/fileTXT.h"
#include "Bibliotecas/GUI.h"
#include "Bibliotecas/fileXML.h"
#include "Bibliotecas/fileBIN.h"

void inicializacao() {
    int opc;
    static int OPC_ARMAZENAMENTO;

    do {
        printf("====== | INICIALIZALIZAÇÃO DO SOFTWARE | ======\n"
                "\t1. Apagar arquivos texto salvos \n"
                "\t2. Excluir arquivos binários salvos \n"
                "\t3. Importar informações anteriores \n"
                "\t4. Continuar \n");

        switch (opc = selecao()) {
            case 1:
                excluirArquivos_txt();
                break;

            case 2:
                break;

            case 3:
                menuImportacao();
                break;
        }
    } while (opc != 3);
    
    printf("Para continuar é necessario realizar o cadastro do estabelecimento. \n");
    cadastrarLocadora();
}

void menuImportacao() {
    int opc;

    printf("====== | IMPORTAÇÃO DE DADOS | ======\n");
    printf("\t1. Importar de arquivo texto \n"
            "\t2. Importar de arquivo binário \n"
            "\t3. Voltar ao menu anterior \n");

    switch (opc = selecao()) {
        case 1:
            menuImportacaoTXT();
            break;

        case 2:
            menuImportacaoBIN();
            break;

        case 3:
            break;
            system("clear");
    }
}

void menuImportacaoTXT() {
    int opc;
    static int verificar[9];
    do {
        printf("====== | IMPORTAÇÃO DE DADOS: ARQUIVO DE TEXTO| ======\n");
        printf("\t1. Clientes \n"
                "\t2. Filmes \n"
                "\t3. Categoria \n"
                "\t4. Funciónarios \n"
                "\t5. Fornecedores \n"
                "\t6. Locações \n"
                "\t7. Notas fiscais \n"
                "\t8. Contas a receber \n"
                "\t9. Voltar ao menu anterior \n");

        switch (opc = selecao()) {
            case 1:
                if (verificar[0] != 1) {
                    importCliente_txt();
                    verificar[0] = 1;
                } else {
                    printf("Dados dos clientes já foram importados. \n");
                }
                break;

            case 2:
                if (verificar[1] != 1) {
                    importFilmes_txt();
                    verificar[1] = 1;
                } else {
                    printf("Dados das categorias já foram importados. \n");
                }
                break;

            case 3:
                if (verificar[2] != 1) {
                    importCategoria_txt();
                } else {
                    printf("Dados dos funciónarios já foram importados. \n");
                }
                break;

            case 4:
                if (verificar[3] != 1) {
                    importFuncionarios_txt();
                } else {
                    printf("Dados dos fornecedores já foram importados. \n");
                }
                break;

            case 5:
                if (verificar[4] != 1) {
                    importFornecedores_txt();
                    verificar[4] = 1;
                } else {
                    printf("Dados dos fornecedores já foram importados. \n");
                }
                break;

            case 6:
                if (verificar[5] != 1) {
                    importLocacoes_txt();
                    verificar[5] = 1;
                } else {
                    printf("Dados dos filmes alugados já foram importados. \n");
                }
                break;

            case 7:
                if (verificar[6] != 1) {
                    importLocacoes_txt();
                    verificar[6] = 1;
                } else {
                    printf("Dados das notas fiscais já foram importados. \n");
                }
                break;

            case 8:
                if (verificar[7] != 1) {
                    importContasReceber_txt();
                    verificar[7] = 1;
                } else {
                    printf("Dados de contas a receber já foram importados. \n");
                }
                break;


            case 9:
                break;

            default:
                printf("Opção inválida");

        }
    } while (opc != 9);

    system("clear");
}

void menuexportXML() {
    int opc;

    do {
        printf("====== | EXPORTAÇÃO DE DADOS: XML | ======\n");
        printf("\t1. Locadora \n"
                "\t2. Clientes \n"
                "\t3. Filmes \n"
                "\t4. Categoria \n"
                "\t5. Funciónarios \n"
                "\t6. Fornecedores \n"
                "\t7. Locações \n"
                "\t8. Notas fiscais \n"
                "\t9. Contas a receber \n"
                "\t10. Todos \n"
                "\t11. Voltar ao menu anterior \n");

        switch (opc = selecao()) {
            case 1:
                exportLocadora_XML();
                printf("Dados do estabelecimento exportados com sucesso para um arquivo XML. \n");
                break;

            case 2:
                if (return_Clientes() != NULL) {
                    exportCliente_XML();
                    printf("Dados dos clientes exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhum cliente foi cadastrado. \n");
                }
                break;

            case 3:
                if (return_Filmes() != NULL) {
                    exportFilmes_XML();
                    printf("Dados dos filmes exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhum filme foi cadastrado. \n");
                }
                break;

            case 4:
                if (return_Categorias() != NULL) {
                    exportCategoria_XML();
                    printf("Dados das categorias exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhuma categoria foi cadastrado. \n");
                }
                break;

            case 5:
                if (return_Funcionarios() != NULL) {
                    exportFunc_XML();
                    printf("Dados dos funcionários exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhum funcionário foi cadastrado. \n");
                }
                break;

            case 6:
                if (return_Fornecedores() != NULL) {
                    exportFornecedores_XML();
                    printf("Dados dos fornecedores exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhum fornecedor foi cadastrado. \n");
                }
                break;

            case 7:
                if (return_Locacoes() != NULL) {
                    exportLocacoes_XML();
                    printf("Dados dos filmes alugados exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhum filme foi alugado. \n");
                }

                break;

            case 8:
                if (return_NotasFiscais() != NULL) {
                    exportNotaFiscal_XML();
                    printf("Dados das notas fiscais exportados com sucesso para um arquivo XML. \n");
                } else {
                    printf("Nenhuma nota fiscal foi cadastrada. \n");
                }
                break;

            case 9:
                if (return_contasReceber() != NULL) {
                    exportContasReceber_XML();
                    printf("Dados das contas a receber exportados com sucesso para um arquivo XML. ");
                } else {
                    printf("Nenhuma conta a receber foi cadastrada. \n");
                }
                break;

            case 10:
                if (return_Clientes() != NULL && return_Categorias() != NULL &&
                        return_Funcionarios() != NULL && return_Locacoes() != NULL
                        && return_Filmes() != NULL && return_Fornecedores() != NULL
                        && return_NotasFiscais() != NULL) {


                    exportLocadora_XML();
                    exportCliente_XML();
                    exportFilmes_XML();
                    exportCategoria_XML();
                    exportFunc_XML();
                    exportFornecedores_XML();
                    exportLocacoes_XML();
                    printf("Todos os dados foram exportados com sucesso para o formato XML. \n");
                } else {
                    printf("Nem todos os dados foram cadastrados. \n");
                }
                break;

            case 11:
                break;

            default:
                printf("Opção inválida");

        }
    } while (opc != 11);

    system("clear");
}

void menuImportacaoBIN() {
    int opc, verificar[9];

    do {
        printf("====== | IMPORTAÇÃO DE DADOS: ARQUIVO DE BINARIO | ======\n");
        printf("\t1. Clientes \n"
                "\t2. Filmes \n"
                "\t3. Categoria \n"
                "\t4. Funciónarios \n"
                "\t5. Fornecedores \n"
                "\t6. Locações \n"
                "\t7. Notas fiscais \n"
                "\t8. Contas a receber \n"
                "\t9. Voltar ao menu anterior \n");

        switch (opc = selecao()) {
            case 1:
                if (verificar[0] != 1) {
                    importCliente_bin();
                    verificar[0] = 1;
                } else {
                    printf("Dados dos clientes já foram importados. \n");
                }
                break;

            case 2:
                if (verificar[1] != 1) {
                      importFilmes_bin();
                    verificar[1] = 1;
                } else {
                    printf("Dados das categorias já foram importados. \n");
                }
                break;

            case 3:
                if (verificar[2] != 1) {
                        importCategoria_bin();
                } else {
                    printf("Dados dos funciónarios já foram importados. \n");
                }
                break;

            case 4:
                if (verificar[3] != 1) {
                        importFuncionarios_bin();
                } else {
                    printf("Dados dos fornecedores já foram importados. \n");
                }
                break;

            case 5:
                if (verificar[4] != 1) {
                        importFornecedores_bin();
                    verificar[4] = 1;
                } else {
                    printf("Dados dos fornecedores já foram importados. \n");
                }
                break;

            case 6:
                if (verificar[5] != 1) {
                        importLocacoes_bin();
                    verificar[5] = 1;
                } else {
                    printf("Dados dos filmes alugados já foram importados. \n");
                }
                break;

            case 7:
                if (verificar[6] != 1) {
                        importLocacoes_bin();
                    verificar[6] = 1;
                } else {
                    printf("Dados das notas fiscais já foram importados. \n");
                }
                break;

            case 8:
                if (verificar[7] != 1) {
                    importContasReceber_bin();
                    verificar[7] = 1;
                } else {
                    printf("Dados de contas a receber já foram importados. \n");
                }
                break;


            case 9:
                inicializacao();
                break;

            default:
                printf("Opção inválida");

        }
    } while (opc != 9);

    system("clear");
}

void menuCadastro() {
    printf("====== | CADASTROS | ======\n");
    printf("\t1. Cadastrar clientes \n"
            "\t2. Cadastrar filmes \n"
            "\t3. Cadastrar categoria \n"
            "\t4. Cadastrar funcionarios \n"
            "\t5. Cadastrar fonecedores \n"
            "\t6. Retornar ao menu principal \n");

    switch (selecao()) {
        case 1:
            cadastrarClientes();
            break;

        case 2:
            if (return_Fornecedores() != NULL && return_Categorias() != NULL) {
                cadastrarFilmes();
            } else {
                printf("Antes de cadastrar algum filme é necessario cadastrar um fornecedor primeiro. \n ");
            }
            break;

        case 3:
            cadastrarCategorias();
            break;

        case 4:
            cadastrarFuncionarios();
            break;

        case 5:
            cadastrarFornecedores();
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void menuRelatorios() {

    printf("====== | RELATORIOS | ======\n"
            "\t1. Relatorio de clientes \n"
            "\t2. Relatorio de filmes \n"
            "\t3. Relatorio de categoria \n"
            "\t4. Relatorio de funcionarios \n"
            "\t5. Relatorio de fonecedores \n"
            "\t6. Retornar ao menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_Clientes() != NULL) {
                subMenuRel_Clientes();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum cliente cadastrado. \n");
            }
            break;

        case 2:
            if (return_Filmes() != NULL) {
                subMenuRel_Filmes();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            if (return_Categorias() != NULL) {
                subMenuRel_Categorias();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhuma categoria cadastrado. \n");
            }
            break;

        case 4:
            if (return_Funcionarios() != NULL) {
                subMenuRel_Funcionarios();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum funcionário cadastrado. \n");
            }
            break;

        case 5:
            if (return_Fornecedores() != NULL) {
                subMenuRel_Fornecedores();
                digiteAlguma_teclaContinuar();
            } else {
                printf("Nenhum fornecedor cadastrado. \n");
            }
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

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

void menu_EntradaFilmes() {
    printf("====== | COMPRAS DE NOVOS FILMES | ======\n"
            "\t1. Visualizar fornecedores cadastrados \n"
            "\t2. Cadastrar novo fornecedor \n"
            "\t3. Escolher fornecedor através do codigo \n"
            "\t4. Voltar ao menu anterior \n");
    do {
        switch (selecao()) {
            case 1:
                subMenuRel_Fornecedores();
                break;

            case 2:
                cadastrarFornecedores();
                break;

            case 3:
                entradaFilmes();

            case 4:
                menuAdministrativo();
                break;

            default:
                printf("Opção inválida. \n");
        }
        break;
    } while (1);
}

void menuGestao() {
    int cod;

    printf("====== | GESTÃO DE DADOS | ======\n");
    printf("Edições ou exclusões de dados so podem ser realizados por funcionarios já cadastrados no sistema. \n");
    printf("Digite o seu codigo de cadastro: ");
    scanf("%d", &cod);

    system("clear");
    if (verificarCod_Funcionario(cod) >= 0) {

        printf("====== | GESTÃO DE DADOS | ======\n"
                "\t1. Editar dados \n"
                "\t2. Excluir dadas \n"
                "\t3. Voltar para o menu principal \n");

        switch (selecao()) {
            case 1:
                subMenuGestao_Editar();
                break;

            case 2:
                subMenuGestao_Excluir();
                break;

            case 3:
                break;

            default:
                printf("Opção inválida. \n");
        }

    } else {
        printf("Código inválido. \n");
    }
}

void menuLocacao() {
    printf("====== | LOCAÇÃO | ======\n"
            "\t1. Locação de filmes \n"
            "\t2. Devolução de filmes \n"
            "\t3. Locações realizadas \n"
            "\t4. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_Funcionarios() != NULL && return_Clientes() != NULL && 
                    return_Filmes() != NULL) {
                locacaoFilmes();
            } else {
                printf("Para efetuar uma locação é necessario ter pelo um cliente "
                        "e um funcionário ja cadastrado no sistema. \n ");
            }
            break;

        case 2:
            if (return_Locacoes() != NULL) {
                DevolucaoFilmes();
            } else {
                printf("Nenhuma locação realizada. \n ");
            }
            break;

        case 3:
            if (return_Locacoes() != NULL) {
                menu_filmesAlugados();
            } else {
                printf("Nenhuma locação realizada. \n");
            }
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void menuFinancas() {
    printf("====== | FINANCEIRO | ======\n"
            "\t1. Contas a receber \n"
            "\t2. Contas a pagar \n"
            "\t3. Notas fiscais \n"
            "\t4. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_contasReceber() != NULL) {
                menuContas_aReceber();
            } else {
                printf("Nenhuma conta a receber. \n");
            }
            break;

        case 2:
            if (return_NotasFiscais() != NULL) {
                menuContas_aPagar();
            } else {
                printf("Nenhuma nota fiscal foi cadastrada. \n");
            }
            break;

        case 3:
            if (return_NotasFiscais() != NULL) {
                menuNotasFiscais();
            } else {
                printf("Nenhuma nota fiscal foi cadastrada. \n");
            }
            break;

        case 4:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void menuAdministrativo() {
    printf("====== | ADMINISTRATIVO | ======\n"
            "\t1. Dados do estabelecimento \n"
            "\t2. Compra de filmes \n"
            "\t3. Quantidade de locações para que um filme se pague \n"
            "\t4. Visualizar estoque da locadora \n"
            "\t5. Voltar para o menu principal \n");

    Strc_Locadora Locadora = return_Locadora();

    switch (selecao()) {
        case 1:
            imprimeLocadora();
            digiteAlguma_teclaContinuar();
            break;

        case 2:
            if (return_Filmes() != NULL) {
                menu_EntradaFilmes();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            menuLocacoes_FilmeSePagar();
            break;

        case 4:
            if (Locadora.filmesComprados != NULL) {
                visualizarEstoque();
            }
            printf("Nenhum filme comprado. \n");
            break;

        case 5:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void menuNotasFiscais() {
    printf("====== | NOTAS FISCAIS | ======\n"
            "\t1. Visualizar todas \n"
            "\t2. Filtrar por fornecedor \n"
            "\t3, Faixa de codígo dos fornecedores \n"
            "\t4. Visualazir as que já pagas \n"
            "\t5. Visualizar as que ainda não foram pagas \n"
            "\t6. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            filNotasFiscais_Todas();
            break;

        case 2:
            filNotasFiscais_Fornecedor();
            break;

        case 3:
            filNotasFiscais_codigoFornecedor();
            break;

        case 4:
            filNotasFiscais_Pagas();
            break;

        case 5:
            filNotasFiscais_NaoPagas();
            break;

        case 6:
            menuAdministrativo();

        default:
            printf("Opção inválida. \n");
    }
}

void menuLocacoes_FilmeSePagar() {
    printf("====== | LOCAÇÕES RESTANTE PARA QUE UM FILME SE PAGUE | ======\n"
            "\t1. Situação de todos os filmes \n"
            "\t2. Filmes pagos \n"
            "\t3, Filmes com déficit \n"
            "\t4. Código do filme \n"
            "\t5. Faixa de códigos \n"
            "\t6. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            contLocacoes_FilmesePaga_Todos();
            break;

        case 2:
            contLocacoes_FilmesePaga_Pagos();
            break;

        case 3:
            contLocacoes_FilmesePaga_Deficit();
            break;

        case 4:
            contLocacoes_FilmesePaga_codFilme();
            break;

        case 5:
            contLocacoes_FilmesePaga_faixaCodigo();
            break;

        case 6:
            menuAdministrativo();

        default:
            printf("Opção inválida. \n");
    }
}

void menuContas_aPagar() {
    printf("====== | CONTAS A PAGAR | ======\n"
            "\t1. Visualizar notas fiscais \n"
            "\t2. Pagar nota fiscal \n"
            "\t3. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            menuNotasFiscais();
            break;

        case 2:
            system("clear");
            subMenuContas_aPagar();
            break;

        case 3:
            menuFinancas();

        default:
            printf("Opção inválida. \n");
    }
}

void menuContas_aReceber() {
    printf("====== | CONTAS A RECEBER | ======\n"
            "\t1. Receber pagamento cliente \n"
            "\t2. Visualizar todas contas a receber \n"
            "\t3. Pesquisar contas a receber por faixa de código \n"
            "\t4. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            receber_ContasCl();
            break;

        case 2:
            filContaReceber_todas();
            break;

        case 3:
            filContaReceber_faixaCodigo();
            break;

        case 4:
            menuFinancas();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void menu_filmesAlugados() {
    printf("====== | LOCAÇÕES | ======\n"
            "\t1. Todas as locações \n"
            "\t2. Locações a vista \n"
            "\t3. Locações a prazo \n"
            "\t4. Por funcionárior \n"
            "\t5. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFilmesAlugados_todos();
            digiteAlguma_teclaContinuar();
            break;

        case 2:
            system("clear");
            filFilmesAlugados_aVista();
            digiteAlguma_teclaContinuar();
            break;

        case 3:
            filFilmesAlugados_aPrazo();
            digiteAlguma_teclaContinuar();
            break;

        case 4:
            filFilmesAlugados_Func();
            digiteAlguma_teclaContinuar();
            break;

        case 6:
            menuLocacao();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuContas_aPagar() {
    printf("====== | OPÇÕES DE PAGAMENTO | ======\n"
            "\t1. Pagar uma uníca nota fiscal \n"
            "\t2. Pagar todas notas  fiscal \n"
            "\t3. Pagar todas notas de determinado fornecedor \n"
            "\t4. Voltar para o menu anterior \n");

    switch (selecao()) {
        case 1:
            contasPagar_Unica();
            break;

        case 2:
            contasPagar_Todas();
            break;

        case 3:
            break;

        case 4:
            menuAdministrativo();

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuGestao_Editar() {

    printf("====== | GESTÃO DE DADOS: EDIÇÃO | ======\n"
            "Deseja editar: \n"
            "\t1. Cliente \n"
            "\t2. Filme \n"
            "\t3. Categoria \n"
            "\t4. Funcionário \n"
            "\t5. Fornecedor \n"
            "\t6. Voltar para o menu principal \n");

    switch (selecao()) {

        case 1:
            if (return_Clientes() != NULL) {
                subMenu_edicaoClientes();
            } else {
                printf("Nenhum cliente cadastrado. \n");
            }
            break;

        case 2:
            if (return_Filmes() != NULL) {
                subMenu_edicaoFilmes();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            if (return_Categorias() != NULL) {
                subMenu_edicaoCategorias();
            } else {
                printf("Nenhuma cetgoria cadastrado. \n");
            }
            break;

        case 4:
            if (return_Funcionarios() != NULL) {
                subMenu_edicaoFuncionarios();
            } else {
                printf("Nenhum funcionário cadastrado. \n");
            }
            break;

        case 5:
            if (return_Fornecedores() != NULL) {
                subMenu_edicaoFornecedores();
            } else {
                printf("Nenhum fornecedor cadastrado. \n");
            }
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuGestao_Excluir() {

    printf("====== | GESTÃO DE DADOS: EXCLUSÃO | ======\n"
            "Deseja excluir: \n"
            "\t1. Cliente \n"
            "\t2. Filme \n"
            "\t3. Categoria \n"
            "\t4. Funcionário \n"
            "\t5. Fornecedor \n"
            "\t6. Voltar para o menu principal \n");

    switch (selecao()) {
        case 1:
            if (return_Clientes() != NULL) {
                excluirCliente();
            } else {
                printf("Nenhum cliente cadastrado. \n");
            }
            break;

        case 2:
            if (return_Filmes() != NULL) {
                excluirFilme();
            } else {
                printf("Nenhum filme cadastrado. \n");
            }
            break;

        case 3:
            if (return_Categorias() != NULL) {
                excluirCategoria();
            } else {
                printf("Nenhuma categoria cadastrado. \n");
            }
            break;

        case 4:
            if (return_Funcionarios() != NULL) {
                excluirFuncionario();
            } else {
                printf("Nenhum funcionário cadastrado. \n");
            }
            break;

        case 5:
            if (return_Fornecedores() != NULL) {
                excluirFornecedor();
            } else {
                printf("Nenhum forncedor cadastrado. \n");
            }
            break;

        case 6:
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenu_edicaoClientes() {
    printf("====== | EDIÇÃO DE CLIENTES | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar clientes cadastrados \n"
            "\t2. Buscar cliente pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Clientes();
            break;

        case 2:
            edicaoCliente();
            break;
    }
}

void subMenu_edicaoFilmes() {
    printf("====== | EDIÇÃO DE FILMES | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar filmes cadastrados \n"
            "\t2. Buscar filme pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Filmes();
            break;

        case 2:
            edicaoFilme();
            break;
    }
}

void subMenu_edicaoCategorias() {
    printf("====== | EDIÇÃO DE CATEGORIAS | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar categorias cadastrados \n"
            "\t2. Buscar categoria pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Categorias();
            break;

        case 2:
            edicaoCategoria();
            break;
    }
}

void subMenu_edicaoFuncionarios() {
    printf("====== | EDIÇÃO DE FUNCIONÁRIOS | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar funcionários cadastrados \n"
            "\t2. Buscar funcionário pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Funcionarios();
            break;

        case 2:
            edicaoFuncionario();
            break;
    }
}

void subMenu_edicaoFornecedores() {
    printf("====== | EDIÇÃO DE FORNECEDORES | ======\n"
            "Você deseja: \n"
            "\t1. VIsualizar fornecedores cadastrados \n"
            "\t2. Buscar fornecedor pelo codigo \n");

    switch (selecao()) {
        case 1:
            subMenuRel_Fornecedores();
            break;

        case 2:
            edicaoFornecedor();
            break;
    }
}

void subMenuRel_Clientes() {
    printf("====== | RELATÓRIO: CLIENTES | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. CPF \n"
            "\t4. Sexo \n"
            "\t5. Visualizar todos \n"
            "\t6. Faixa de códigos \n"
            "\t7. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filClientes_Nome();
            break;

        case 2:
            filClientes_Codigo();
            break;

        case 3:
            filClientes_CPF();
            break;

        case 4:
            filClientes_Sexo();
            break;

        case 5:
            filClientes_Todos();
            break;

        case 6:
            filClientes_FaixaCodigo();
            break;

        case 7:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuRel_Filmes() {
    printf("====== | RELATÓRIO: FILMES | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. Idioma \n"
            "\t4. Exemplares \n"
            "\t5. Visualizar todos \n"
            "\t6. Faixa de códigos \n"
            "\t7. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFilmes_Nome();
            break;

        case 2:
            filFilmes_Codigo();
            break;

        case 3:
            filFilmes_Idioma();
            break;

        case 4:
            filFilmes_Exemplares();
            break;

        case 5:
            filFilmes_Todos();
            break;

        case 6:
            filFilmes_FaixaCodigo();
            break;

        case 7:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuRel_Categorias() {
    printf("====== | RELATÓRIO: CATEGORIAS | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. Visualizar todos \n"
            "\t4. Faixa de códigos \n"
            "\t5. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filCategoria_Nome();
            break;

        case 2:
            filCategorias_Codigo();
            break;

        case 3:
            filCategorias_Todos();
            break;

        case 4:
            filCategorias_FaixaCodigo();
            break;

        case 5:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuRel_Funcionarios() {
    printf("====== | RELATÓRIO: FUNCIONÁRIOS | ======\n"
            "Filtrar por: \n"
            "\t1. Nome \n"
            "\t2. Codigo \n"
            "\t3. Cargo \n"
            "\t4. Visualizar todos \n"
            "\t5. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFuncionarios_Nome();
            break;

        case 2:
            filCategorias_Codigo();
            break;

        case 3:
            filFuncionarios_Cargo();
            break;

        case 4:
            filFuncionarios_Todos();
            break;

        case 5:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}

void subMenuRel_Fornecedores() {
    printf("====== | RELATÓRIO: FORNECEDORES | ======\n"
            "Filtrar por: \n"
            "\t1. Razão social \n"
            "\t2. Nome fantasia \n"
            "\t3. Codigo \n"
            "\t4. CNPJ \n"
            "\t5. Inscrição social \n"
            "\t6. Visualizar todos \n"
            "\t7. Voltar ao menu anterior \n");

    switch (selecao()) {
        case 1:
            filFornecedores_RazaoSocial();
            break;

        case 2:
            filFornecedores_NomeFantasia();
            break;

        case 3:
            filFornecedores_Codigo();
            break;

        case 4:
            filFornecedores_CNPJ();
            break;

        case 5:
            filFornecedores_InscricaoSocial();
            break;

        case 6:
            filFornecedores_Todos();
            break;

        case 7:
            menuRelatorios();
            break;

        default:
            printf("Opção inválida. \n");
    }
}