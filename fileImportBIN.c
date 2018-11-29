#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/alocacao.h"

void importLocadora_bin() {
    Strc_Locadora Loc;
    FILE * file = fopen("arquivos/bin/fileLocadora.bin", "rb");

    fread(&Loc, sizeof (Strc_Locadora), 1, file);
    alterarLocadora(Loc);

    fclose(file);
    free(file);
}

void importCliente_bin() {
    Strc_Clientes Cl;
    FILE* file = fopen("arquivos/bin/fileClientes.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&Cl, sizeof (Strc_Clientes), 1, file);
        alocarClientes(&Cl);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importFuncionarios_bin() {
    Strc_Funcionario Fun;
    FILE* file = fopen("arquivos/bin/fileFuncionario.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&Fun, sizeof (Strc_Funcionario), 1, file);
        alocarFuncionarios(&Fun);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importCategoria_bin() {
    Strc_Categoria cat;
    FILE* file = fopen("arquivos/bin/fileCategoria.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&cat, sizeof (Strc_Categoria), 1, file);
        alocarCategoria(&cat);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importFilmes_bin() {
    Strc_Filmes Fil;
    FILE* file = fopen("arquivos/bin/fileFilmes.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&Fil, sizeof (Strc_Filmes), 1, file);
        alocarFilmes(&Fil);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importFornecedores_bin() {
    Strc_Fornecedores Forn;
    FILE* file = fopen("arquivos/bin/fileFornecedor.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&Forn, sizeof (Strc_Fornecedores), 1, file);
        alocarFornecedores(&Forn);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importLocacoes_bin() {
    Strc_Locacoes Loc;
    FILE* file = fopen("arquivos/bin/fileLocacoes.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&Loc, sizeof (Strc_Locacoes), 1, file);
        alocarLocacoes(&Loc);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importContasReceber_bin() {
    Strc_ContasReceber Contas;
    FILE* file = fopen("arquivos/bin/fileContasReceber.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&Contas, sizeof (Strc_ContasReceber), 1, file);
        alocarContas_aReceber(&Contas);
    } while (!feof(file));

    fclose(file);
    free(file);
}

void importNotasFiscais_bin() {
    Strc_notaFiscal NF;
    FILE* file = fopen("arquivos/bin/fileNotasFiscais.bin", "rb");

    if (file == NULL) {
        printf("Erro ao ler o arquivo. \n");
        exit(EXIT_FAILURE);
    }

    do {
        fread(&NF, sizeof (Strc_notaFiscal), 1, file);
        alocarNotasFiscais(&NF);
    } while (!feof(file));

    fclose(file);
    free(file);
}
