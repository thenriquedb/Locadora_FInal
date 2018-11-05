#include <stdio.h>
#include <stdlib.h>

#include "Bibliotecas/cadastros.h"
#include "Bibliotecas/structs.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/relatorios.h"
#include "GUI.h"

void cadastrarLocadora() {
    Strc_Locadora Locadora;
    int opc;

    printf("=== | CADASTRO DA LOCADORA | ===\n");

    do {
        setbuf(stdin, NULL);
        printf("\tRazão social: ");
        scanf("%[^\n]s", Locadora.razaoSocial);
        setbuf(stdin, NULL);

        printf("\tNome fantasia: ");
        scanf("%[^\n]s", Locadora.nomeFanatasia);
        setbuf(stdin, NULL);

        printf("\tNome do responsavel: ");
        scanf("%[^\n]s", Locadora.nomeResponsavel);
        setbuf(stdin, NULL);

        printf("\tEndereço: ");
        scanf("%[^\n]s", Locadora.endereco);
        setbuf(stdin, NULL);

        printf("\tEmail: ");
        scanf("%[^\n]s", Locadora.email);
        setbuf(stdin, NULL);

        printf("\tTelefone: ");
        scanf("%[^\n]s", Locadora.telefone);
        setbuf(stdin, NULL);

        printf("\tCNPJ: ");
        scanf("%[^\n]s", Locadora.cnpj);
        setbuf(stdin, NULL);

        printf("\tInscrição estadual: ");
        scanf("%[^\n]s", Locadora.InscricaoEstadual);
        setbuf(stdin, NULL);

        printf("\tValor da multa de atraso: ");
        scanf("%f", &Locadora.valorMulta);


        printf("Digite 1 para confirmar ou 2 para corrigir: ");
        scanf("%d", &opc);
        system("clear");

        if (opc == 1) {
            printf("Cadastro concluído com sucesso! \n");
            alterarLocadora(Locadora);
        }
    } while (opc != 1);
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
    int opcao, codForn, codCat, sair = 0, posCatalago, PosForn;
    Strc_Filmes Filme;
    Strc_Fornecedores* Fornecedor = return_Fornecedores();

    do {
        printf("=== | CADASTRO DE FILMES | ===\n");

        setbuf(stdin, NULL);
        printf("Titulo: ");
        scanf("%[^\n]s", Filme.nome);
        setbuf(stdin, NULL);

        printf("Descrição: ");
        scanf("%[^\n]s", Filme.descricao);
        setbuf(stdin, NULL);

        printf("Exemplares: ");
        scanf("%d", &Filme.exemplares);


        do {
            printf("Código da categoria: ");
            scanf("%d", &codCat);
        } while (verificarCod_Categoria(codCat) < 0);
        Filme.codigoCategoria = codCat;


        do {
            printf("Código do fornecedor: ");
            scanf("%d", &codForn);
        } while (verificarCod_Fornecedores(codForn) < 0);
        Filme.codigoFornecedor = codForn;

        PosForn = codForn - 1;
        posCatalago = Fornecedor[PosForn].contCatalago;


        do {
            printf("\nIdioma: \n"
                    "\t1. Dublado \n"
                    "\t2. Legendado \n"
                    "Digite a opção desejada: ");
            scanf("%d", &Filme.idioma);
        } while (Filme.idioma != 1 && Filme.idioma != 2);

        Filme.codigo = gerarCodigoFilme();
        Filme.codigoCategoria = codCat;

        Fornecedor[PosForn].catalogoFilmes = alocar_CatalagoFornecedor(Fornecedor[PosForn].catalogoFilmes, Fornecedor[PosForn].contCatalago);
        Fornecedor[PosForn].catalogoFilmes[posCatalago] = Filme.codigo;
        Fornecedor[PosForn].contCatalago++;

        alterarFornecedores(Fornecedor);
        alocarFilmes(&Filme);

        system("clear");
        printf("DADOS CADASTRADOS \n");
        imprimeFilmes(returnCont_Filmes() - 1);

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
    do {
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

        do {
            opcao = parar_ou_ContinuarCadastro();
        } while (opcao != 1 && opcao != 2);

        if (opcao == 2) {
            break;
        }
    } while (1);
}

int verificarCategoria(int cat) {
    int i, contCategoriasAlocados = returnCont_Categorias();
    Strc_Categoria* Categoria = return_Categorias();

    for (i = 0; i < contCategoriasAlocados; i++) {
        if (cat == Categoria[i].codigo) {
            return i;
            break;
        }
    }

    return -1;
    printf("Nenhuma categoria com este codigo encontrada. \n");
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
    int codFil, opcao, cod, contCatalago = 0;

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
        Fornecedor.catalogoFilmes = NULL;
        Fornecedor.contCatalago = 0;

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