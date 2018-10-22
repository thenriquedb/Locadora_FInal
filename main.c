
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
                "2. Gestão de dados \n"
                "3. Relatórios \n"
                "4. Importtação e exportação de dados \n"
                "5. Sair \n");

        switch (selecao()) {
            case 1:
                menuCadastro();
                break;

            case 2:
                menuGestao();
                break;

            case 3:
                menuRelatorios();
                break;

            case 5:
                system("clear");
                printf("Programa encerrado. \n");
                exit(EXIT_SUCCESS);
        }
    } while (1);
}