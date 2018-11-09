#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "GUI.h"

void imprimeCategorias(int i) {
    Strc_Categoria* Categoria = return_Categorias();

    printf("\tNome: %s \n", Categoria[i].nome);
    printf("\tDescrição: %s \n", Categoria[i].descricao);
    printf("\tCódigo: %d \n", Categoria[i].codigo);
    printf("\tValor da multa de atraso: R$ %.2f \n", Categoria[i].valor);
}

void imprimeClientes(int i) {
    Strc_Clientes* Cliente = return_Clientes();

    printf("\tNome: %s \n", Cliente[i].nome);
    printf("\tData de nascimento: %s \n", Cliente[i].data_nascimento);
    printf("\tCodigo: %d \n", Cliente[i].codigo);
    printf("\tEndereço completo: %s \n", Cliente[i].endereco);
    printf("\tCPF: %s \n", Cliente[i].cpf);
    printf("\tTelefone: %s \n", Cliente[i].telefone);
    printf("\tEmail: %s \n", Cliente[i].email);

    printf("\tSexo: ");
    if (Cliente[i].opc_sexo == 1) {
        printf("Mascukino \n");
    } else if (Cliente[i].opc_sexo == 2) {
        printf("Feminino \n");
    }

    printf("\tEstado civil: ");
    if (Cliente[i].estado_civi == 1) {
        printf("Solteiro(a) \n\n");
    } else if (Cliente[i].estado_civi == 2) {
        printf("Casado(a) \n\n");
    } else if (Cliente[i].estado_civi == 3) {
        printf("Divorciado(a) \n\n");
    } else if (Cliente[i].estado_civi == 4) {
        printf("Viúvo(a) \n\n");
    } else if (Cliente[i].estado_civi == 5) {
        printf("Separado(a) \n\n");
    }
    printf("|-------------------------------------------------------------------|\n");
}
//-------------------------------------------------------------------------------

void filFuncionarios_Todos() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, contFun = returnCont_Funcionarios();

    system("clear");
    if (Funcionario != NULL) {
        printf("====== | VISUALIZAR TODOS FUNCIONÁRIOS CADASTRADOS | ======");

        for (i = 0; i < contFun; i++) {
            printf("\n====== | %dº FUNCIONÁRIO | ======\n", i + 1);
            imprimeFuncionarios(i);
        }
        printf("Total de resultados: %d \n\n", i);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_FaixaCodigo() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, codInicio, codFim, contFun = returnCont_Funcionarios();

    if (Funcionario != NULL) {
        do {
            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");


            printf("Digite o codigo inicial que deseja buscar: ");
            do {
                scanf("%d", &codInicio);
            } while (verificarNumeroPositivoINT(codInicio) != 1);


            printf("Digite o codigo final que deseja buscar: ");
            do {
                scanf("%d", &codFim);

                if (codFim > contFun) {
                    printf("Valor maior que o número de funcionários cadastrados. \n");
                }
            } while (codFim > contFun);
            system("clear");

            printf("====== | FILTRAR POR FAIXA DE CODIGO | ======\n");

            for (i = codInicio; i < codFim; i++) {
                printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                imprimeFuncionarios(i);
            }

            printf("Nenhum resultado encontrado. \n");

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_Codigo() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, cod, contFun = returnCont_Funcionarios();

    if (Funcionario != NULL) {
        do {
            printf("====== | FILTRAR POR CÓDIGO | ======\n");
            printf("Digite o código que deseja buscar: ");
            scanf("%d", &cod);

            system("clear");
            printf("====== | FILTRAR POR CÓDIGO | ======\n");

            for (i = 0; i < contFun; i++) {
                if (cod == Funcionario[i].codigo) {
                    printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                    imprimeFuncionarios(i);
                    cont++;
                }
            }
            if (cont == 0) {
                printf("Nenhum resultado encontrado. \n");
            }
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_Nome() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, cod, contFun = returnCont_Funcionarios();
    char nome[100];

    if (Funcionario != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR NOME | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contFun; i++) {
                if (strcmp(nome, Funcionario[i].nome) == 0) {
                    printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                    imprimeFuncionarios(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void filFuncionarios_Cargo() {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int i, cont = 0, cod, contFun = returnCont_Funcionarios();
    char cargo[100];

    if (Funcionario != NULL) {
        do {
            setbuf(stdin, NULL);
            printf("====== | FILTRAR POR CARGO | ======\n");
            printf("Digite o titulo que deseja buscar: ");
            scanf("%[^\n]s", cargo);
            setbuf(stdin, NULL);

            system("clear");
            printf("====== | FILTRAR POR NOME | ======\n");
            for (i = 0; i < contFun; i++) {
                if (strcmp(cargo, Funcionario[i].cargo) == 0) {
                    printf("====== | %dº FUNCIONÁRIO | ======\n", cont + 1);
                    imprimeFuncionarios(i);
                    cont++;
                }
            }
            printf("\nTotal de resultados: %d \n", cont);
            cont = 0;

        } while (chamarMenu_Relatorio() != 1);
    } else {
        printf("Nenhum funcionário cadastrado. \n");
    }
}
//-------------------------------------------------------------------------------

void imprimeFuncionarios(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();

    printf("\tNome: %s \n", Funcionario[i].nome);
    printf("\tEndereço: %s \n", Funcionario[i].endereco);
    printf("\tTelefone: %s \n", Funcionario[i].telefone);
    printf("\tEmail: %s \n", Funcionario[i].email);
    printf("\tCargo: %s \n", Funcionario[i].cargo);
    printf("\tCódigo: %d \n", Funcionario[i].codigo);
}
//-------------------------------------------------------------------------------

void imprimeFornecedores(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Filmes* Filme = return_Filmes();

    printf("\tRazão Social: %s \n", Fornecedor[i].razaoScial);
    printf("\tNome Fantasia: %s \n", Fornecedor[i].nomeFantasia);
    printf("\tEndereço: %s \n", Fornecedor[i].endereco);
    printf("\tTelefone: %s \n", Fornecedor[i].telefone);
    printf("\tEmail: %s \n", Fornecedor[i].email);
    printf("\tCNPJ: %s \n", Fornecedor[i].cnpj);
    printf("\tInscrição social: %s \n\n", Fornecedor[i].inscricaooSocial);

    printf("Filmes disponiveis: \n");
    for (int j = 0; j < Fornecedor[i].contCatalago; j++) {
        int posFil = Fornecedor[i].catalogoFilmes[j] - 1;
        printf("\t %d. %s \n", Fornecedor[i].catalogoFilmes[j], Filme[posFil].nome);

    }
}
//-------------------------------------------------------------------------------

void imprimeFilmes(int i) {
    Strc_Filmes* Filme = return_Filmes();
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Categoria* Categoria = return_Categorias();

    int posCategoria = Filme[i].codigoCategoria - 1;
    int posFornecedor = Filme[i].codigoFornecedor - 1;

    printf("\tTítulo: %s \n", Filme[i].nome);
    printf("\tDescrição: %s \n", Filme[i].descricao);
    printf("\tCodígo uníco: %d \n", Filme[i].codigo);
    printf("\tFornecedor: %s (%d)\n", Fornecedor[i].razaoScial, Filme[i].codigoFornecedor);
    printf("\tFornecedor: %d \n", Filme[i].codigoFornecedor);

    printf("\tIdioma: ");
    if (Filme[i].idioma == 1) {
        printf("Dublado \n");
    } else {
        printf("Legendado \n");
    }

    printf("\tCategoria: %s (%d) \n", Categoria[posCategoria].nome, Filme[i].codigoCategoria);
    printf("\tExemplares disponiveis: %d \n", Filme[i].exemplares);
}
//------------------------------------------------------------------------------

void imprimeNotaFiscal(int codForn, int contItens) {
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Filmes* Filme = return_Filmes();

    printf("Fornecedor: %s \t\t", Fornecedor[codForn].razaoScial);
    printf("CNPJ: %s \n", Fornecedor[codForn].cnpj);
    printf("Frete: R$ %.2f \t\t", Nota[codForn].precoFrete);
    printf("Frete (Por unidade): R$ %.2f \n", Nota[codForn].freteUnidade);
    printf("Imposto: R$ %.2f \t", Nota[codForn].precoImposto);
    printf("Imposto (Por unidade): R$ %.2f \n", Nota[codForn].impostoUnidade);
    printf("Código da nota: %d \n\n", Nota[codForn].codigo);

    printf("PRODUTOS ");
    for (int j = 0; j < contItens; j++) {
        printf("\n\tTítulo: %s \n", Filme[Nota[codForn].Itens[j].codFilme - 1].nome);
        printf("\tUnidades: %d unidades \n", Nota[codForn].Itens[j].quant);
        printf("\tValor de custo: R$ %.2f \n", Nota[codForn].Itens[j].preco);
        printf("\tTotal: R$ %.2f \n", (Nota[codForn].Itens[j].quant * Nota[codForn].Itens[j].preco) + Nota[codForn].impostoUnidade + Nota[codForn].freteUnidade);
    }
    printf("_________________________________________________________\n");
    printf("TOTAL ARRENDONDADO: R$ %.2f \n", Nota[codForn].totalNF);
    printf("SITUAÇÃO: ");

    if (Nota[codForn].paga == 0) {
        printf("Em aberto. \n");
    } else {
        printf("Paga. \n");
    }
    printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
}

