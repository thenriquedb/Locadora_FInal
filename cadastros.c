#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"

void cadastrarLocadora() {
    
}

//---------------------------| INICIO CADASTRO CLIENTES |-----------------------

void cadastrarClientes() {
    int opcao;

    Strc_Clientes Cliente;
    do {
        printf("=== | CADASTRO DE CLIENTES | ===\n");

        setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", Cliente.nome);
        setbuf(stdin, NULL);

        Cliente.codigo = gerarCodigoCliente();

        printf("Endereço completo: ");
        scanf("%[^\n]s", Cliente.endereco);
        setbuf(stdin, NULL);

        printf("CPF: ");
        scanf("%[^\n]s", Cliente.cpf);
        setbuf(stdin, NULL);

        printf("Telefone: ");
        scanf("%[^\n]s", Cliente.telefone);
        setbuf(stdin, NULL);

        printf("E-mail: ");
        scanf("%[^\n]s", Cliente.email);
        setbuf(stdin, NULL);

        do {
            printf("\nSexo: \n"
                    "\t1. Masculino \n"
                    "\t2. Feminino \n"
                    "Digite a opção desejada:");
            scanf("%d", &Cliente.opc_sexo);

        } while (Cliente.opc_sexo != 1 && Cliente.opc_sexo != 2);

        do {
            printf("\nEstado civil: \n"
                    "\t1. Solteiro \n"
                    "\t2. Casado \n"
                    "\t3. Divorciado(a) \n"
                    "\t4. Viúvo(a) \n"
                    "\t5. Separado(a) \n"
                    "Digite a opção desejada: ");
            scanf("%d", &Cliente.estado_civi);

            if (Cliente.estado_civi < 0 && Cliente.estado_civi > 5) {
                printf("Opção inválida. \n");
            }

        } while (
                Cliente.estado_civi != 1 && Cliente.estado_civi != 2 &&
                Cliente.estado_civi != 3 && Cliente.estado_civi != 4 &&
                Cliente.estado_civi != 5);


        setbuf(stdin, NULL);
        printf("Data de nascimento (No formato dd/mm/aaaa): ");
        scanf("%[^\n]s", Cliente.data_nascimento);
        setbuf(stdin, NULL);

        system("clear");

        alocarClientes(&Cliente);

        do {
            opcao = parar_ou_ContinuarCadastro();
        } while (opcao != 1 && opcao != 2);

        if (opcao == 2) {
            break;
        }

    } while (1);
}

int gerarCodigoCliente() {
    int static codigo = 0;

    codigo++;
    return codigo;
}
//---------------------------| FIM CADASTRO CLIENTES |--------------------------

//---------------------------| INICIO CADASTRO FILMES |-------------------------

void cadastrarFilmes() {
    int opcao, cat;
    Strc_Filmes Filme;

    do {
        printf("=== | CADASTRO DE FILMES | ===\n");
        Filme.codigo = gerarCodigoFilme();

        setbuf(stdin, NULL);
        printf("Titulo: ");
        scanf("%[^\n]s", Filme.nome);
        setbuf(stdin, NULL);

        printf("Descrição: ");
        scanf("%[^\n]s", Filme.descricao);
        setbuf(stdin, NULL);

        printf("Exemplares: ");
        scanf("%d", &Filme.exemplares);

        Filme.codigoCategoria = verificarCategoria();         

        do {
            printf("\nIdioma: \n"
                    "\t1. Dublado \n"
                    "\t2. Legendado \n"
                    "Digite a opção desejada: ");
            scanf("%d", &Filme.idioma);
        } while (Filme.idioma != 1 && Filme.idioma != 2);

        alocarFilmes(&Filme);

        do {
            opcao = parar_ou_ContinuarCadastro();
        } while (opcao != 1 && opcao != 2);

        if (opcao == 2) {
            break;
        }
    } while (1);
}

int gerarCodigoFilme() {
    int static codigo = 0;

    codigo++;
    return codigo;
}
//---------------------------| FIM CADASTRO FILMES |----------------------------

//---------------------------| INICIO CADASTRO CATEGORIAS |---------------------

void cadastrarCategorias() {
    Strc_Categoria categoria;
    int opcao;

    printf("=== | CADASTRO DE CATEGORIAS | ===\n");

    setbuf(stdin, NULL);
    printf("Nome: ");
    scanf("%[^\n]s", categoria.nome);
    setbuf(stdin, NULL);

    printf("Descrição: ");
    scanf("%[^\n]s", categoria.descricao);
    setbuf(stdin, NULL);

    printf("Valor da multa de atraso: ");
    scanf("%f", &categoria.valor);

    categoria.codigo = gerarCodigoCategoria();
    alocarCategoria(&categoria);
}

int verificarCategoria() {
    int i, cont, cat, contCategoriasAlocados = returnCont_Categorias();
    Strc_Categoria* Categoria = return_Categorias();
    
    do {
        printf("Digite o codigo da categoria: ");
        scanf("%d", &cat);

        if (contCategoriasAlocados == 0) {
            system("clear");

            printf("Nenhuma categoria cadastrada. Para continuar é necessario realizar"
                    "o cadastro de pelo menos uma. \n");
            cadastrarCategorias();
            
            return 1;
            
            system("clear");
            printf("=== | CADASTRO DE FILMES | ===\n");
            printf("Continuação do cadastro do filme... ");

            break;
        }

        for (i = 0; i < contCategoriasAlocados; i++) {
            if (cat == Categoria[i].codigo) {
                return i;
                break;
            }
        }

        return -1;
        printf("Nenhuma categoria com este codigo encontrada. \n");
    } while (1);
}

int gerarCodigoCategoria() {
    int static codigo = 0;
    codigo++;
    return codigo;
}
//--------------------------- FIM CADASTRO CATEGORIA ---------------------------

//--------------------------- INICIO CADASTRO FUNCIONARIOS ---------------------

void cadastrarFuncionarios() {
    int opcao;
    Strc_Funcionario Funcionario;
    do {
        printf("=== | CADASTRO DE FUNCIONARIOS | ===\n");

        setbuf(stdin, NULL);
        printf("Nome: ");
        scanf("%[^\n]s", Funcionario.nome);
        setbuf(stdin, NULL);

        printf("Endereço: ");
        scanf("%[^\n]s", Funcionario.endereco);
        setbuf(stdin, NULL);

        printf("Telefone: ");
        scanf("%[^\n]s", Funcionario.telefone);
        setbuf(stdin, NULL);

        printf("Email: ");
        scanf("%[^\n]s", Funcionario.email);
        setbuf(stdin, NULL);

        printf("Cargo: ");
        scanf("%[^\n]s", Funcionario.cargo);
        setbuf(stdin, NULL);

        Funcionario.codigo = gerarCodigoFuncionario();

        system("clear");
        alocarFuncionarios(&Funcionario);

        do {
            opcao = parar_ou_ContinuarCadastro();
        } while (opcao != 1 && opcao != 2);

        if (opcao == 2) {
            break;
        }
    } while (1);
}

int gerarCodigoFuncionario() {
    int static codigo = 0;

    codigo++;
    return codigo;
}
//---------------------------| FIM CADASTRO FUNCIONARIOS |----------------------

//---------------------------| INICIO CADASTRO FORNECEDORES |-------------------

void cadastrarFornecedores() {
    int opcao;
    Strc_Fornecedores Fornecedor;

    do {
        printf("=== | CADASTRO DE FORNECEDORES | ===\n");

        setbuf(stdin, NULL);
        printf("Razão Social: ");
        scanf("%[^\n]s", Fornecedor.razaoScial);
        setbuf(stdin, NULL);

        printf("Nome Fantasia: ");
        scanf("%[^\n]s", Fornecedor.nomeFantasia);
        setbuf(stdin, NULL);

        printf("Endereço: ");
        scanf("%[^\n]s", Fornecedor.endereco);
        setbuf(stdin, NULL);

        printf("Telefone: ");
        scanf("%[^\n]s", Fornecedor.telefone);
        setbuf(stdin, NULL);

        printf("Email: ");
        scanf("%[^\n]s", Fornecedor.email);
        setbuf(stdin, NULL);

        printf("CNPJ (Somente números): ");
        scanf("%[^\n]s", Fornecedor.cnpj);
        setbuf(stdin, NULL);

        printf("Inscrição social (Somente números): ");
        scanf("%[^\n]s", Fornecedor.inscricaooSocial);
        setbuf(stdin, NULL);

        Fornecedor.codigo = gerarCodigoFornecedores();

        system("clear");
        alocarFornecedores(&Fornecedor);

        do {
            opcao = parar_ou_ContinuarCadastro();
        } while (opcao != 1 && opcao != 2);

        if (opcao == 2) {
            break;
        }
    } while (1);
}

int gerarCodigoFornecedores() {
    int static codigo = 0;

    codigo++;
    return codigo;
}
//---------------------------| FIM CADASTRO FORNECEDORES |----------------------