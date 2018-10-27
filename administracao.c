
#include <stdio.h>
#include <stdlib.h>
#include "Bibliotecas/administracao.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/relatorios.h"
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/menus.h"

void entradaFilmes() {
    int i, cod;

    printf("====== | COMPRAS DE NOVOS FILMES | ======\n"
            "\t1. Visualizar fornecedores cadastrados \n"
            "\t2. Cadastrar novo fornecedor \n"
            "\t3. Escolher fornecedor através do codigo \n");
    do {
        switch (selecao()) {
            case 1:
                subMenuRel_Fornecedores();
                break;

            case 2:
                cadastrarFornecedores();
                break;

            case 3:
                printf("Digite o codigo do fornecedor que deseja editar: ");
                scanf("%d", &cod);

                if (verificarCod_Fornecedores(cod) >= 0) {
                    i = verificarCod_Fornecedores(cod);
                    comprarFilme(i);
                } else {
                    printf("Codigo inválido. \n");
                }
                break;

            case 4:
                break;

            default:
                printf("Opção inválida. \n");
        }
        break;
    } while (1);
}

void comprarFilme(int i) {
    
}