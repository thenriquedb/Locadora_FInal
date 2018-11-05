#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/alocacao.h"
//#include "verificacaoDeDados.h"

int verificarNumeroPositivoINT(int x) {

    if (x >= 0) {
        return 1;
    } else {
        printf("Valor inválido! \n");
        return 0;
    }
}
//-------------------------------------------------------------------------------

int verificarNumeroPositivoFLOAT(float x) {

    if (x > 0.0) {
        return 1;
    } else {
        printf("Valor inválido! Digite um valor maior que zero para poder proseguir. \n");
        return 0;
    }
}
//-------------------------------------------------------------------------------

int selecao() {
    int opc;

    printf("Digite a opção desejada: ");
    scanf("%d", &opc);
    system("clear");
    return opc;
}
//-------------------------------------------------------------------------------

int parar_ou_ContinuarCadastro() {
 int opcao;

    do {
        printf("\nDigte 1 para continuar cadastrando ou 2 para voltar para o menu principal: ");
        scanf("%d", &opcao);

        if (opcao != 1 && opcao != 2) {
            printf("Opção invalida. \n");
        }
    } while (opcao != 1 && opcao != 2);

    system("clear");

    return opcao;
}
//-------------------------------------------------------------------------------

int chamarMenu_Relatorio() {
    printf("\nDigite 1 para retornar ao menu principal ou qualquer tecla para buscar por novos resultados.");
    if (selecao() != 1) {
        return 0;
    } else {
        return 1;
    }
}

//-------------------------------------------------------------------------------

int verificarCod_Funcionario(int cod) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int cont = returnCont_Funcionarios();

    for (int i = 0; i < cont; i++) {
        if (Funcionario[i].codigo == cod) {
            return i;
            break;
        }
    }

    return -1;
}

//-------------------------------------------------------------------------------

int verificarCod_Cliente(int cod) {
    Strc_Clientes* Cliente = return_Clientes();
    int cont = returnCont_Clientes();

    for (int i = 0; i < cont; i++) {
        if (Cliente[i].codigo == cod) {
            return i;
            break;
        }
    }
    return -1;
}
//-------------------------------------------------------------------------------

int verificarCod_Filme(int cod) {
    Strc_Filmes* Filme = return_Filmes();
    int cont = returnCont_Filmes();

    for (int i = 0; i < cont; i++) {
        if (Filme[i].codigo == cod) {
            return i;
            break;
        }
    }
    return -1;
}
//-------------------------------------------------------------------------------

int verificarCod_Fornecedores(int cod) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    int cont = returnCont_Fornecedores();

    for (int i = 0; i < cont; i++) {
        if (Fornecedor[i].codigo == cod) {
            return i;
            break;
        }
    }
    return -1;
}
//-------------------------------------------------------------------------------

int verificarCod_Categoria(int cod) {
    Strc_Categoria* Categoria = return_Categorias();
    int cont = returnCont_Categorias();
    int verificar = 0;

    for (int i = 0; i < cont; i++) {
        if (Categoria[i].codigo == cod) {
            return i;
            verificar++;
            break;
        }
    }
    if (verificar == 0) {
        system("clear");
        printf("Categoria inválida! \n");
        return -1;
    }
}

//------------------------------------------------------------------------------

int verificarExemplares_Filmes(int id, int quant) {
    Strc_Filmes* Filme = return_Filmes();
    int cont = returnCont_Filmes();

    if (Filme[id - 1].exemplares >= quant) {
        return 1;
    } else {
        if (Filme[id - 1].exemplares == 0) {
            printf("Esgotado. \n");
            return 3;
        } else {
            printf("Estoque insuficiente. Ainda resta %d exemplares no estoque. \n", Filme[id - 1].exemplares);
            return 0;
        }
    }
}
