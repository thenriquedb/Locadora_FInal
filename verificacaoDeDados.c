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

int verificarFuncionario(int cod) {
    Strc_Funcionario* Funcionario = return_Funcionarios();
    int cont = returnCont_Funcionarios();

    for (int i = 0; i < cont; i++) {
        if (Funcionario[i].codigo == cod) {
            return 1;
            break;
        }
    }

    return 0;
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

