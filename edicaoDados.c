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