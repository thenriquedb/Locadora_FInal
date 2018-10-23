#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"

void filFornecedores_Todos() {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, contFor = returnCont_Fornecedores();

    system("clear");
    if (Fornecedor != NULL) {
        printf("====== | VISUALIZAR TODOS OS FORNECEDORES CADASTRADOS | ======");

        for (i = 0; i < contFor; i++) {
            printf("\n====== | %dº FORNECEDOR | ======\n", i + 1);
            imprimeFornecedores(i);
        }
        printf("Total de resultados: %d \n\n", i);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}

//-------------------------------------------------------------------------------

void filFornecedores_Codigo() {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, cod, cont = 0, contFor = returnCont_Fornecedores();

    if (Fornecedor != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contFor; i++) {
                if (cod == Fornecedor[i].codigo) {
                    printf("\n====== | %dº FORNECEDOR | ======\n", i + 1);
                    imprimeFornecedores(i);
                    cont++;
                }
            }

            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}

//-------------------------------------------------------------------------------

void filFornecedores_FaixaCodigo() {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, cont = 0, codInicio, codFim, contFor = returnCont_Fornecedores();

    if (Fornecedor != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");


            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contFor) {
                    printf("Valor maior que o número de fornecedores cadastrados. \n");
                }
            } while (codFim > contFor);
            system("clear");


            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FORNECEDOR | ======\n", cont + 1);
                imprimeFornecedores(i);
            }
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFornecedores_NomeFantasia() {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, cont = 0, contFor = returnCont_Fornecedores();
    char nome[100];

    if (Fornecedor != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME FANTASIA | ======\n");
            printf("Digite o nome fantasia que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME FANTASIA | ======\n");
            for (i = 0; i < contFor; i++) {
                if (strcmp(nome, Fornecedor[i].nomeFantasia) == 0) {
                    printf("====== | %dº FORNECEDOR | ======\n", cont + 1);
                    imprimeFornecedores(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}


//-------------------------------------------------------------------------------

void filFornecedores_RazaoSocial() {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, cont = 0, contFor = returnCont_Fornecedores();
    char razaoSocial[100];

    if (Fornecedor != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR RAZÃO SOCIAL | ======\n");
            printf("Digite a razão social que deseja buscar: ");
            scanf("%[^\n]s", razaoSocial);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR RAZÃO SOCIAL | ======\n");
            for (i = 0; i < contFor; i++) {
                if (strcmp(razaoSocial, Fornecedor[i].razaoScial) == 0) {
                    printf("====== | %dº FORNECEDOR | ======\n", cont + 1);
                    imprimeFornecedores(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFornecedores_CNPJ() {
Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, cont = 0, contFor = returnCont_Fornecedores();
    char cnpj[14];

    if (Fornecedor != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR CNPJ | ======\n");
            printf("Digite o CNPJ que deseja buscar: ");
            scanf("%[^\n]s", cnpj);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR CNPJ | ======\n");
            for (i = 0; i < contFor; i++) {
                if (strcmp(cnpj, Fornecedor[i].cnpj) == 0) {
                    printf("====== | %dº FORNECEDOR | ======\n", cont + 1);
                    imprimeFornecedores(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFornecedores_InscricaoSocial() {
Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int i, cont = 0, contFor = returnCont_Fornecedores();
    char inscricaoSocial[14];

    if (Fornecedor != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR INSCRIÇÃO SOCIAL | ======\n");
            printf("Digite o número de inscrição social que deseja buscar: ");
            scanf("%[^\n]s", inscricaoSocial);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR INSCRIÇÃO SOCIAL | ======\n");
            for (i = 0; i < contFor; i++) {
                if (strcmp(inscricaoSocial, Fornecedor[i].inscricaooSocial) == 0) {
                    printf("====== | %dº FORNECEDOR | ======\n", cont + 1);
                    imprimeFornecedores(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum fornecedor cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void imprimeFornecedores(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();

    printf("\tRazão Social: %s \n", Fornecedor[i].razaoScial);
    printf("\tNome Fantasia: %s \n", Fornecedor[i].nomeFantasia);
    printf("\tEndereço: %s \n", Fornecedor[i].endereco);
    printf("\tTelefone: %s \n", Fornecedor[i].telefone);
    printf("\tEmail: %s \n", Fornecedor[i].email);
    printf("\tCNPJ: %s \n", Fornecedor[i].cnpj);
    printf("\tInscrição social: %s \n", Fornecedor[i].inscricaooSocial);
}
