/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Thiago Henrique Domingues Botelho
 */
#include <stdio.h>
#include <stdlib.h>

/* ####################### BIBLIOTECAS PROPRIAS #######################*/
#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "teste.h"
#include "Bibliotecas/GUI.h"
#include "Bibliotecas/veriificacaoDeDados.h"


int main(int argc, char** argv) {
     prencherDados();
    //  inicializacao();
      
    do {
        Strc_Caixa Fin = return_Caixa();
        printf("\n");
        imprimeLogo();  
        printf("\nCaixa: R$ %.2f \n",Fin.caixa);
        
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
                exit(EXIT_SUCCESS);
        }
    } while (1);
    

}