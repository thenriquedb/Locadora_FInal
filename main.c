
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/gestao.h"

int main(int argc, char** argv) {

  // cadastrarLocadora();
    
    do {
        printf("====== | MENU PRINCIPAL | ======\n"
                "\t1. Cadastros \n"
                "\t2. Gestão de dados \n"
                "\t3. Relatórios \n"
                "\t4. Administrativo \n"
                "\t5. Importtação e exportação de dados \n"
                "\t6. Sair \n");

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
                
            case 4:
                menuAdministrativo();
                break;

            case 6:
                system("clear");
                printf("Programa encerrado. \n");
                exit(EXIT_SUCCESS);
        }
    } while (1);
}