/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest.c
 * Author: thiago
 *
 * Created on 3 de Novembro de 2018, 10:50
 */

#include <stdio.h>
#include <stdlib.h>
#include "Bibliotecas/administracao.h"

/*
 * Simple C Test Suite
 */

void testEntradaFilmes() {
    entradaFilmes();
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testEntradaFilmes (newsimpletest) message=error message sample\n");
    }
}

void testLocacaoFilmes() {
    locacaoFilmes();
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testLocacaoFilmes (newsimpletest) message=error message sample\n");
    }
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%%  testEntradaFilmes (newsimpletest)\n");
    testEntradaFilmes();
    printf("%%TEST_FINISHED%% time=0 testEntradaFilmes (newsimpletest)\n");

    printf("%%TEST_STARTED%%  testLocacaoFilmes (newsimpletest)\n");
    testLocacaoFilmes();
    printf("%%TEST_FINISHED%% time=0 testLocacaoFilmes (newsimpletest)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
