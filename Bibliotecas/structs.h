
#ifndef STRUCTS_H
#define STRUCTS_H

//Struct CLientes

typedef struct {
    char nomeFanatasia[100];
    char razaoSocial[100];
    char InscricaoEstadual[12];
    char cnpj[14];
    char endereco[150];
    char telefone[12];
    char email[150];
    char nomeResponsavel[100];
    
    float Caixa;
    float valorMulta;
} Strc_Locadora;

//Struct CLientes

typedef struct {
    char nome[100];
    char endereco[150];
    char telefone[12];
    char email[150];
    char cpf[11];
    char data_nascimento[10];

    int codigo;
    int opc_sexo;
    int estado_civi;
} Strc_Clientes;

//Struct Filmes

typedef struct {
    char nome[100];
    char descricao[400];

    int codigo;
    int codigoCategoria;
    int exemplares;
    int idioma;
} Strc_Filmes;

//Struct Categorias

typedef struct {
    char nome[100];
    char descricao[300];

    int codigo;
    float valor;
} Strc_Categoria;

//Struct Funcionarios

typedef struct {
    char nome[100];
    char endereco[150];
    char telefone[12];
    char email[150];
    char cargo[50];

    int codigo;
} Strc_Funcionario;

//Struct Fornecedores

typedef struct {
    char nomeFantasia[100];
    char razaoScial[100];
    char endereco[150];
    char telefone[12];
    char inscricaooSocial[16];
    char cnpj[14];
    char email[150];

    int codigo;
} Strc_Fornecedores;

#endif /* STRUCTS_H */

