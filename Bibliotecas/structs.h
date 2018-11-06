
#ifndef STRUCTS_H
#define STRUCTS_H

//Struct locadora

typedef struct {
    char nomeFanatasia[100];
    char razaoSocial[100];
    char InscricaoEstadual[12];
    char cnpj[14];
    char endereco[150];
    char telefone[12];
    char email[150];
    char nomeResponsavel[100];

    //Administração
    float caixa;
    float contas_receber;

    int *filmesComprados;
    int contFilmes_comprados;

    float valorMulta;
} Strc_Locadora;

//Struct Clientes

typedef struct {
    char nome[100];
    char endereco[150];
    char telefone[12];
    char email[150];
    char cpf[11];
    char data_nascimento[10];

    float vlr_devendo;
    int quantParcela;

    int devendo;
    int codigo;
    int opc_sexo;
    int estado_civi;
} Strc_Clientes;

typedef struct {
} Strc_Catalago;

//Struct Filmes

typedef struct {
    char nome[100];
    char descricao[400];

    float precoCompra;
    float precoAluguel;

    int codigo;
    int codigoCategoria;
    int codigoFornecedor;
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

    int *catalogoFilmes;
    int contCatalago;
    int codigo;
} Strc_Fornecedores;


//Struct para gerenciamento financeiro
typedef struct {
    float caixa;
    float contasPagar;
} Strc_Financeiro;

//Versao simples da struct de filmes contendo somente dados relevantes para nota fiscal
typedef struct {
    int codFilme;
    int quant;
    float preco;
    float total;
} Strc_MinimalFilmes;

typedef struct {
    int codForn;
    float precoFrete;
    float precoImposto;
    
    Strc_MinimalFilmes* Itens;
    int contItens;
    float freteUnidade;
    float impostoUnidade;
    float totalNF;
} Strc_notaFiscal;

#endif /* STRUCTS_H */

