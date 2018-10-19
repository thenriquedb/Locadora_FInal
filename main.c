
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"

int main(int argc, char** argv) {

    do {
        printf("====== | MENU PRINCIPAL | ======\n"
                "1. Cadastros \n"
                "2. Relatórios \n"
                "3. Importtação e exportação de dados \n"
                "4. Sair \n");

        switch (selecao()) {
            case 1:
                menuCadastro();
                break;

            case 2:
                menuRelatorios();
                break;

            case 4:
                system("clear");
                printf("Programa encerrado. \n");
                exit(EXIT_SUCCESS);
        }
    } while (1);
}