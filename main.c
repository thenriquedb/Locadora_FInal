/*
 * Projeto de gerenciamento de todas as operações de uma locadora de filmes..
 * Todo o projeto foi feito em uma maquina rodando Linux Mint 19 e utilizando a 
 * IDE Netbeans 8.2

 * Author: Thiago Henrique Domingues Botelho
 */

#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "teste.h"
#include "Bibliotecas/GUI.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/fileBIN.h"

int main(int argc, char** argv) {
    // prencherDados();
    inicializacao();
    printf("\n");

    do {
        imprimeLogo();

        Strc_Caixa Fin = return_Caixa();
        printf("\nCaixa: R$ %.2f \n", Fin.caixa);

        printf("============= | MENU PRINCIPAL | =============\n"
                "\t\t1. Cadastros \n"
                "\t\t2. Locação \n"
                "\t\t3. Gestão de dados \n"
                "\t\t4. Relatórios \n"
                "\t\t5. Finanças \n"
                "\t\t6. Administrativo \n"
                "\t\t7. Exportar dados no formato XML \n"
                "\t\t8. Sair \n");

        switch (selecao()) {
            case 1:
                menuCadastro();
                break;

            case 2:
                menuLocacao();
                break;

            case 3:
                menuGestao();
                break;

            case 4:
                menuRelatorios();
                break;

            case 5:
                menuFinancas();
                break;

            case 6:
                menuAdministrativo();
                break;

            case 7:
                menuexportXML();
                break;

            case 8:
                system("clear");
                printf("Programa encerrado. \n");

                /* A exportação de dados binários é realizada de uma unica vez  */
                if (returnModoArmazenamento() == 2) {
                    exportTudo_bin();
                }
                exit(EXIT_SUCCESS);
                break;
        }
    } while (1);
}



