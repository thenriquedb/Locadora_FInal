#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/GUI.h"

void filCategorias_Todos() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, contCat = returnCont_Categorias();

    system("clear");
    if (Categoria != NULL) {
        printf("====== | VISUALIZAR TODAS AS CATEGORIAS CADASTRADAS | ======");

        for (i = 0; i < contCat; i++) {
            printf("\n====== | %dº CATEGORIA | ======\n", i + 1);
            imprimeCategorias(i);
        }
        printf("Total de resultados: %d \n", i);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filCategorias_FaixaCodigo() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, cont = 0, codInicio, codFim, contCat = returnCont_Categorias();

    if (Categoria != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contCat) {
                    printf("Valor maior que o número de categorias cadastrados. \n");
                }
            } while (codFim > contCat);
            system("clear");

            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                imprimeFuncionarios(i);
            }

            printf("Nenhum resultado encontrado. \n");

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filCategorias_Codigo() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, cod, cont = 0, contCat = returnCont_Categorias();

    if (Categoria != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contCat; i++) {
                if (cod == Categoria[i].codigo) {
                    printf("====== | %dº CATEGORIA | ======\n", cont + 1);
                    imprimeCategorias(i);
                    cont++;
                }
            }
            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filCategoria_Nome() {
    Strc_Categoria* Categoria = return_Categorias();
    int i, cod, cont = 0, contCat = returnCont_Categorias();
    char nome[100];

    if (Categoria != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contCat; i++) {
                if (strcmp(nome, Categoria[i].nome) == 0) {
                    printf("====== | %dº CATEGORIA | ======\n", cont + 1);
                    imprimeCategorias(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhuma categoria cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filClientes_Todos() {
    Strc_Clientes* Cliente = return_Clientes();
    int contC = returnCont_Clientes();
    int i;

    system("clear");

    if (Cliente != NULL) {
        printf("====== | VISUALIZAR TODOS CLIENTES CADASTRADOS | ======\n");

        for (i = 0; i < contC; i++) {
            printf("====== | %dº CLIENTE | ======\n", i + 1);
            imprimeClientes(i);
        }

        printf("Total de resultados: %d \n", i);
    } else {
        printf("Nenhum cliente cadastrado. \n");

    }
}
//-------------------------------------------------------------------------------

void filClientes_Codigo() {
    Strc_Clientes* Cliente = return_Clientes();
    int cont = 0, contC = returnCont_Clientes();
    int i, cod;

    system("clear");

    if (Cliente != NULL) {
        do {
            printf("====== | FILTRAR POR CODIGO | ======\n");
            printf("Digite o codigo que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CODIGO | ======\n");
            for (i = 0; i < contC; i++) {
                if (cod == Cliente[i].codigo) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                    break;
                }
            }

            printf("Nenhum resultado encontrado. \n");
            cont = 0;

        } while (chamarMenu_Relatorio() != 0);

    } else {
        printf("Nenhum cliente cadastrado. \n");

    }
}
//-------------------------------------------------------------------------------

void filClientes_FaixaCodigo() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, codInicio, codFim, contC = returnCont_Clientes();

    system("clear");
    do {
        printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n\n");

        if (Cliente != NULL) {
            do {
                printf("Digite o codigo inicial que deseja buscar: ");
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contC) {
                    printf("Valor maior que o número de clientes cadastrados. \n");
                }
            } while (codFim > contC);

            system("clear");
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n\n");
            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº CLIENTE | ======\n", cont + 1);
                imprimeClientes(i);
                cont++;
            }
        } else {
            printf("Nenhum cliente cadastrado. \n");
            break;
        }
    } while (chamarMenu_Relatorio() != 1);
}
//-------------------------------------------------------------------------------

void filClientes_Nome() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, contC = returnCont_Clientes();
    char nome[100];

    system("clear");
    if (Cliente != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME | ======\n");
            printf("Digite o nome que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contC; i++) {
                if (strcmp(nome, Cliente[i].nome) == 0) {
                    printf("%dº Cliente \n", cont + 1);
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                }
            }

            printf("Total de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum cliente cadastrado. \n");
    }
}

//-------------------------------------------------------------------------------

void filClientes_CPF() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, cont = 0, contC = returnCont_Clientes();
    char cpf[12];

    system("clear");

    if (Cliente != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR CPF | ======\n");
            printf("Digite o CPF que deseja buscar: ");
            scanf("%[^\n]s", cpf);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR CPF | ======\n");
            for (i = 0; i < contC; i++) {
                if (strcmp(cpf, Cliente[i].cpf) == 0) {
                    printf("%dº Cliente \n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                }
            }

            printf("Total de resultados: %d \n", cont);
            cont = 0;
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum cliente cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filClientes_Sexo() {
    Strc_Clientes* Cliente = return_Clientes();
    int i, opc, cont = 0, contC = returnCont_Clientes();

    system("clear");

    if (Cliente != NULL) {
        do {
            printf("====== | FILTRAR POR SEXO | ======\n");
            do {
                printf("\t1. Sexo masculino \n"
                        "\t2. Sexo feminino \n"
                        "Digite a opção desejada:  ");
                scanf("%d", &opc);
            } while (opc != 1 && opc != 2);

            system("clear");
            printf("====== | FILTRAR POR SEXO | ======\n");

            for (i = 0; i < contC; i++) {
                if (opc == Cliente[i].opc_sexo) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeClientes(i);
                    cont++;
                }
            }

            printf("Total de resultados: %d \n\n", cont);
            cont = 0;
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum cliente cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

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
        printf("\nTotal de resultados: %d \n\n", i);
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

void filFilmes_Todos() {
    Strc_Filmes* Filme = return_Filmes();
    int i, contF = returnCont_Filmes();

    system("clear");
    if (Filme != NULL) {
        printf("====== | VISUALIZAR TODOS FILMES CADASTRADOS | ======");

        for (i = 0; i < contF; i++) {
            printf("\n====== | %dº FILME | ======\n", i + 1);
            imprimeFilmes(i);
        }
        printf("Total de resultados: %d \n\n", i);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Codigo() {
    Strc_Filmes* Filme = return_Filmes();
    int i, cod, cont = 0, contF = returnCont_Filmes();

    system("clear");
    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contF; i++) {
                if (cod == Filme[i].codigo) {
                    printf("====== | %dº FILME | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_FaixaCodigo() {
    Strc_Filmes* Filme = return_Filmes();
    int i, cont = 0, codInicio, codFim, contF = returnCont_Filmes();

    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");


            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contF) {
                    printf("Valor maior que o número de filmes cadastrados. \n");
                }
            } while (codFim > contF);
            system("clear");


            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FILME | ======\n", cont + 1);
                imprimeFilmes(i);
            }
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Nome() {
    Strc_Filmes* Filme = return_Filmes();
    int i, cont = 0, contF = returnCont_Filmes();
    char titulo[100];

    if (Filme != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR TÍTULO | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", titulo);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR TÍTULO | ======\n");
            for (i = 0; i < contF; i++) {
                if (strcmp(titulo, Filme[i].nome) == 0) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Exemplares() {
    Strc_Filmes* Filme = return_Filmes();
    int i, exemplares, cont = 0, contF = returnCont_Filmes();

    system("clear");
    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR EXEMPLARES | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%d", &exemplares);

            system("clear");
            printf("====== | FILTRAR POR EXEMPLARES | ======\n");

            for (i = 0; i < contF; i++) {
                if (exemplares == Filme[i].exemplares) {
                    printf("====== | %dº CLIENTE | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFilmes_Idioma() {
    Strc_Filmes* Filme = return_Filmes();
    int i, opc, cont = 0, contF = returnCont_Filmes();

    system("clear");
    if (Filme != NULL) {
        do {
            printf("====== | FILTRAR POR IDIOMA | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%d", &opc);

            system("clear");
            printf("====== | FILTRAR POR IDIOMA | ======\n");

            for (i = 0; i < contF; i++) {
                if (opc == Filme[i].idioma) {
                    printf("====== | %dº FILME | ======\n", cont + 1);
                    imprimeFilmes(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;
        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum filme cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filNotasFiscais_Todas() {
    int i, cont = 0, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();

    system("clear");
    if (Nota != NULL) {
        system("clear");
        printf("====== | TODAS NOTAS FISCAIS | ======\n");

        for (i = 0; i < contNF; i++) {
            printf("%dº NOTA \n", i + 1);
            imprimeNotaFiscal(i, Nota[i].contItens);
        }
    } else {
        printf("Nenhum nota fiscal gerada. \n");
    }
}
//-------------------------------------------------------------------------------

void filNotasFiscais_Pagas() {
    int i, cont = 0, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();

    system("clear");
    if (Nota != NULL) {
        system("clear");
        printf("====== | NOTAS FISCAIS PAGAS | ======\n");

        for (i = 0; i < contNF; i++) {
            if (Nota[i].paga == 1) {
                printf("%dº NOTA \n", i + 1);
                imprimeNotaFiscal(i, Nota[i].contItens);
                cont++;
            }
        }

        if (cont == 0) {
            printf("Nenhuma nota foi paga. \n");
        } else {
            printf("Total de resultados: %d \n", cont);
        }

    } else {
        printf("Nenhum nota fiscal gerada. \n");
    }
}
//-------------------------------------------------------------------------------

void filNotasFiscais_NaoPagas() {
    int i, cont = 0, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();

    system("clear");
    if (Nota != NULL) {
        printf("====== | NOTAS FISCAIS: EM ABERTO | ======\n");

        for (i = 0; i < contNF; i++) {
            if (Nota[i].paga == 0) {
                printf("%dº NOTA \n", cont + 1);
                imprimeNotaFiscal(i, Nota[i].contItens);
                cont++;
            }
        }
    } else {
        printf("Nenhum nota fiscal gerada. \n");
    }
}
//-------------------------------------------------------------------------------

void filNotasFiscais_Fornecedor() {
    int codForn, i, cont = 0, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();

    system("clear");
    if (Nota != NULL) {
        do {
            system("clear");
            printf("====== | NOTAS FISCAIS: FILTRAR POR FORNECEDOR | ======\n");
            do {
                printf("Digite o código do fornecedor: ");
                scanf("%d", &codForn);
            } while (verificarCod_Fornecedores(codForn));

            system("clear");
            printf("====== | NOTAS FISCAIS: FILTRAR POR FORNECEDOR | ======\n");
            for (i = 0; i < contNF; i++) {
                if (Nota[i].codForn == codForn) {
                    printf("%dº NOTA \n", cont + 1);
                    imprimeNotaFiscal(i, Nota[i].contItens);
                    cont++;
                }
            }

            printf("\nTotal de resultados: %d \n\n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum nota fiscal gerada. \n");
    }
}
//-------------------------------------------------------------------------------

void filNotasFiscais_codigoFornecedor() {
    int codInicio, codFinal, i, cont = 0, contNF = returnCont_NotasFiscais();
    Strc_notaFiscal* Nota = return_NotasFiscais();

    system("clear");
    if (Nota != NULL) {
        system("clear");
        printf("====== | NOTAS FISCAIS: FILTRAR POR FORNECEDOR | ======\n");
        printf("Digite o código de início: ");
        scanf("%d", &codInicio);

        printf("Digite o código do fim: ");
        scanf("%d", &codFinal);

        system("clear");
        printf("====== | NOTAS FISCAIS: FILTRAR POR FORNECEDOR | ======\n");
        for (i = codInicio; i < codFinal; i++) {
            if (Nota[i].codForn == i) {
                printf("%dº NOTA \n", cont + 1);
                imprimeNotaFiscal(i, Nota[i].contItens);
                cont++;
            }
        }

        if (cont > 0) {
            printf("\nTotal de resultados: %d \n\n", cont);

        } else {
            printf("\nNenhuma nota do forncedor de código %d foi encontrada. \n", cont);
        }
    }
}
//-------------------------------------------------------------------------------

void filLocacoes_aVista() {
    Strc_Locacoes* Locacoes = return_Locacoes();
    int cont = 0;

    printf("====== | LOCAÇÕES A VISTA | ======\n");
    for (int i = 0; i < cont; i++) {
        if (Locacoes[i].pagamento == 'V') {
            imprimeLocacoes(i);
            cont++;
        }
    }

    if (cont == 0) {
        printf("Nenhuma locação a vista foi realizada. \n");
    }
}
//-------------------------------------------------------------------------------

void filLocacoes_aPrazo() {
    Strc_Locacoes* Locacoes = return_Locacoes();
    int cont;

    printf("====== | LOCAÇÕES A PRAZO | ======\n");
    for (int i = 0; i < cont; i++) {
        if (Locacoes[i].pagamento == 'P') {
            imprimeLocacoes(i);
            cont++;
        }
    }

    if (cont == 0) {
        printf("Nenhuma locação a vista foi realizada. \n");
    }
}
//-------------------------------------------------------------------------------

void filLocacoes_Func() {
    Strc_Locacoes* Locacoes = return_Locacoes();
    int cont, codF, contLocacoes = returnCont_Locacoes();

    printf("====== | LOCAÇÕES POR FUNCIONÁRIO | ======\n");
    do {
        printf("Digite o codígo do funcionário: ");
        scanf("%d", &codF);
    } while (verificarCod_Funcionario(codF) < 0);

    printf("\n");
    for (int i = 0; i < contLocacoes; i++) {
        if (Locacoes[i].codFunc == codF) {
            imprimeLocacoes(i);
            cont++;
        }
    }

    if (cont == 0) {
        printf("O funcionário de codígo %d ainda não realizou nenhuma venda. \n", codF);
    }
}
//-------------------------------------------------------------------------------

void filLocacoes_Data() {
    Strc_Locacoes* Locacoes = return_Locacoes();
    int diaInicial, diaFinal, mesInicial, mesFinal, contLocacoes = returnCont_Locacoes();

    printf("====== | LOCAÇÕES POT DATA | ======\n");

    printf("Digite o dia inicial: ");
    scanf("%d", &diaInicial);
    printf("Digite o mês inicial: ");
    scanf("%d", &mesInicial);


    printf("Digite o dia final: ");
    scanf("%d", &diaFinal);
    printf("Digite o mês final: ");
    scanf("%d", &mesFinal);

    /*
    for (int i = 0; i < contLocacoes; i++) {
        if (Locacoes[i].codFunc == codF) {
            imprimeLocacoes(i);
            cont++;
        }
    }
     */
}
//-------------------------------------------------------------------------------

void filLocacoes_todas() {
    int cont = returnCont_Locacoes();

    system("clear");
    printf("====== | TODAS LOCAÇÕES REALIZADAS | ======\n");
    for (int i = 0; i < cont; i++) {
        imprimeLocacoes(i);
    }
}
//-------------------------------------------------------------------------------

void filContaReceber_todas() {
    int cont = returnCont_contasReceber();

    system("clear");
    printf("====== | TODAS AS CONTAS A RECEBER | ======\n");
    for (int i = 0; i < cont; i++) {
        imprimeContaReceber(i);
    }
}
//-------------------------------------------------------------------------------

void filContaReceber_faixaCodigo() {
    int codInicio, codFinal, verificar = 0;
    Strc_ContasReceber* Conta = return_contasReceber();

    printf("Digite o código inicial: ");
    scanf("%d", &codInicio);

    printf("Digite o código final: ");
    scanf("%d", &codFinal);

    printf("====== | TODAS AS CONTAS A RECEBER | ======\n");
    for (int i = codInicio; i < codFinal; i++) {
        //Verificar se existe informação na posição i
        if (Conta[i].codCl == i) {
            imprimeContaReceber(i);
            verificar++;
        }
    }

    if (verificar == 0) {
        printf("Não foi encontrado nenhuma conta a receber entre %d e %d, \n", codInicio, codFinal);
    }
}
//-------------------------------------------------------------------------------