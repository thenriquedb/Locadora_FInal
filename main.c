
#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/gestao.h"
#include "teste.h"

int main(int argc, char** argv) {

    // cadastrarLocadora();
    prencherDados();

    do {
        Strc_Financeiro Fin = return_Financeiro();
        printf("CAIXA: R$ %.2f \n", Fin.caixa);

        printf("====== | MENU PRINCIPAL | ======\n"
                "\t1. Cadastros \n" //Concluido
                "\t2. Locação \n" // Andamento
                "\t3. Gestão de dados \n" //Cocnluido
                "\t4. Relatórios \n" //Concluido
                "\t5. Financeiro \n" //Não iniciado
                "\t6. Administrativo \n" //Em andamento
                "\t7. Importtação e exportação de dados \n" //Nao iniciado
                "\t8. Sair \n");

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
                menuFinanceiro();
                break;

            case 6:
                menuAdministrativo();
                break;

            case 8:
                system("clear");
                printf("Programa encerrado. \n");
                exit(EXIT_SUCCESS);
        }
    } while (1);
}