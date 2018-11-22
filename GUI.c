#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Bibliotecas/structs.h"
#include "Bibliotecas/alocacao.h"
#include "Bibliotecas/menus.h"
#include "Bibliotecas/veriificacaoDeDados.h"
#include "Bibliotecas/GUI.h"

void imprimeLocadora() {
    Strc_Locadora Locadora = return_Locadora();

    printf("\tRazão social: %s \n", Locadora.razaoSocial);
    printf("\tNome fantasia: %s \n", Locadora.nomeFanatasia);
    printf("\tNome responsável: %s \n", Locadora.nomeResponsavel);
    printf("\tEndereço: %s \n", Locadora.endereco);
    printf("\tEmail: %s \n", Locadora.email);
    printf("\tTelefone: %s \n", Locadora.telefone);
    printf("\tCNPJ: %s \n", Locadora.cnpj);
    printf("\tInscrição estadual: %s \n", Locadora.InscricaoEstadual);

    for (int i = 0; i < Locadora.contFilmes_comprados; i++) {
        printf("%d \n",Locadora.filmesComprados[i]);
    }
}
//------------------------------------------------------------------------------

void imprimeCategorias(int i) {
    Strc_Categoria* Categoria = return_Categorias();

    printf("\tNome: %s \n", Categoria[i].nome);
    printf("\tDescrição: %s \n", Categoria[i].descricao);
    printf("\tCódigo: %d \n", Categoria[i].codigo);
    printf("\tValor da multa de atraso: R$ %.2f \n", Categoria[i].valor);
}
//------------------------------------------------------------------------------

void imprimeClientes(int i) {
    Strc_Clientes* Cliente = return_Clientes();

    printf("\tNome: %s \n", Cliente[i].nome);
    printf("\tData de nascimento: %s \n", Cliente[i].data_nascimento);
    printf("\tCodigo: %d \n", Cliente[i].codigo);
    printf("\tEndereço completo: %s \n", Cliente[i].endereco);
    printf("\tCPF: %s \n", Cliente[i].cpf);
    printf("\tTelefone: %s \n", Cliente[i].telefone);
    printf("\tEmail: %s \n", Cliente[i].email);

    printf("\tSexo: ");
    if (Cliente[i].opc_sexo == 1) {
        printf("Mascukino \n");
    } else if (Cliente[i].opc_sexo == 2) {
        printf("Feminino \n");
    }

    printf("\tEstado civil: ");
    if (Cliente[i].estado_civi == 1) {
        printf("Solteiro(a) \n\n");
    } else if (Cliente[i].estado_civi == 2) {
        printf("Casado(a) \n\n");
    } else if (Cliente[i].estado_civi == 3) {
        printf("Divorciado(a) \n\n");
    } else if (Cliente[i].estado_civi == 4) {
        printf("Viúvo(a) \n\n");
    } else if (Cliente[i].estado_civi == 5) {
        printf("Separado(a) \n\n");
    }
}
//-------------------------------------------------------------------------------

void imprimeFuncionarios(int i) {
    Strc_Funcionario* Funcionario = return_Funcionarios();

    printf("\tNome: %s \n", Funcionario[i].nome);
    printf("\tTelefone: %s \n", Funcionario[i].telefone);
    printf("\tEmail: %s \n", Funcionario[i].email);
    printf("\tCargo: %s \n", Funcionario[i].cargo);
    printf("\tCódigo: %d \n", Funcionario[i].codigo);
}
//-------------------------------------------------------------------------------

void imprimeFornecedores(int i) {
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Filmes* Filme = return_Filmes();

    printf("\tRazão Social: %s \n", Fornecedor[i].razaoScial);
    printf("\tNome Fantasia: %s \n", Fornecedor[i].nomeFantasia);
    printf("\tEndereço: %s \n", Fornecedor[i].endereco);
    printf("\tTelefone: %s \n", Fornecedor[i].telefone);
    printf("\tEmail: %s \n", Fornecedor[i].email);
    printf("\tCNPJ: %s \n", Fornecedor[i].cnpj);
    printf("\tInscrição social: %s \n\n", Fornecedor[i].inscricaooSocial);

    printf("Filmes disponiveis: \n");
    for (int j = 0; j < Fornecedor[i].contCatalago; j++) {
        int posFil = Fornecedor[i].catalogoFilmes[j] - 1;
        //  printf("\t %d. %s \n", Fornecedor[i].catalogoFilmes[j], Filme[posFil].nome);
        printf("\t filme forn: %d \n", j);

    }
}
//-------------------------------------------------------------------------------

void imprimeFilmes(int i) {
    Strc_Filmes* Filme = return_Filmes();
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Categoria* Categoria = return_Categorias();

    int posCategoria = Filme[i].codigoCategoria - 1;
    int posFornecedor = Filme[i].codigoFornecedor - 1;

    printf("\tTítulo: %s \n", Filme[i].nome);
    printf("\tDescrição: %s \n", Filme[i].descricao);
    printf("\tCodígo uníco: %d \n", Filme[i].codigo);
    // printf("\tFornecedor: %s (%d)\n", Fornecedor[i].razaoScial, Filme[i].codigoFornecedor);
    printf("\tCódigo do fornecedor: %d \n", Filme[i].codigoFornecedor);
    printf("\tPreço de compra: R$ %.2f \n", Filme[i].precoCompra);

    printf("\tIdioma: ");
    if (Filme[i].idioma == 1) {
        printf("Dublado \n");
    } else {
        printf("Legendado \n");
    }

    printf("\tCategoria: %s (%d) \n", Categoria[posCategoria].nome, Filme[i].codigoCategoria);
    printf("\tExemplares disponiveis: %d \n", Filme[i].exemplares);
}
//------------------------------------------------------------------------------

void imprimeNotaFiscal(int codForn, int contItens) {
    Strc_notaFiscal* Nota = return_NotasFiscais();
    Strc_Fornecedores* Fornecedor = return_Fornecedores();
    Strc_Filmes* Filme = return_Filmes();

    printf("Fornecedor: %s \t\t", Fornecedor[codForn].razaoScial);
    printf("CNPJ: %s \n", Fornecedor[codForn].cnpj);
    printf("Frete: R$ %.2f \t\t", Nota[codForn].precoFrete);
    printf("Frete (Por unidade): R$ %.2f \n", Nota[codForn].freteUnidade);
    printf("Imposto: R$ %.2f \t", Nota[codForn].precoImposto);
    printf("Imposto (Por unidade): R$ %.2f \n", Nota[codForn].impostoUnidade);
    printf("Código da nota: %d \n\n", Nota[codForn].codigo);

    printf("PRODUTOS ");
    for (int j = 0; j < contItens; j++) {
        printf("\n\tTítulo: %s \n", Filme[Nota[codForn].Itens[j].codFilme - 1].nome);
        printf("\tUnidades: %d unidades \n", Nota[codForn].Itens[j].quant);
        printf("\tValor de custo: R$ %.2f \n", Nota[codForn].Itens[j].preco);
        printf("\tTotal: R$ %.2f \n", (Nota[codForn].Itens[j].quant * Nota[codForn].Itens[j].preco) + Nota[codForn].impostoUnidade + Nota[codForn].freteUnidade);
    }
    printf("_________________________________________________________\n");
    printf("TOTAL ARRENDONDADO: R$ %.2f \n", Nota[codForn].totalNF);
    printf("SITUAÇÃO: ");

    if (Nota[codForn].paga == 0) {
        printf("Em aberto. \n");
    } else {
        printf("Paga. \n");
    }
    printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
}

//------------------------------------------------------------------------------

void imprimeLocacoes(int i) {
    Strc_Locacoes* Locacoes = return_Locacoes();
    Strc_Clientes* Clientes = return_Clientes();
    int contItens = Locacoes[i].contItens;

    printf("Compra realizada pelo funcionário de codígo %d. \n", Locacoes[i].codFunc);
    printf("Nome do clientes: %s \n", Clientes[Locacoes[i].codCliente - 1].nome);
    printf("Codígo clientes: %d \n", Locacoes[i].codCliente);

    printf("Forma de pagamento: ");
    if (Locacoes[i].pagamento == 'V') {
        printf("A vista \n\n");
    } else {
        printf("A prazo \n\n");
    }

    printf("PRODUTOS \n");
    for (int j = 0; j < Locacoes[i].contItens; j++) {
        printf("\tCódigo do filme: %d \n", Locacoes[i].Itens[j].codFilme);
        printf("\tExemplares: %d \n\n", Locacoes[i].Itens[j].quant);
    }
    printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
}
//------------------------------------------------------------------------------

void imprimeContaReceber(int i) {
    Strc_ContasReceber* ContaReceber = return_contasReceber();
    Strc_Clientes* Clientes = return_Clientes();

    printf("Nome do clientes: %s \n", Clientes[ContaReceber[i].codCl - 1].nome);
    printf("Codígo clientes: %d \n", ContaReceber[i].codCl);
    printf("Total: R$ %.2f \n", ContaReceber[i].total);

    if (ContaReceber[i].entrada == 'S') {
        printf("Entrada: R$ %.2f \n", ContaReceber[i].valorEntrada);
        printf("Restante: R$ %.2f \n", (ContaReceber[i].total - ContaReceber[i].valorEntrada));
    }

    printf("Número de parcelas: %d \n", ContaReceber[i].quantParcelas);
    printf("Valor da parcela: R$ %.2f \n", ContaReceber[i].vlrParcela);

    printf("Situação: ");
    if (ContaReceber[i].situacao == 'D') {
        printf("Em aberto. \n");
    } else {
        printf("Paga. \n");
    }
    printf("¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n");
}
//------------------------------------------------------------------------------

void ImprimeContLocacoes_FilmesePaga(int i, float totalVenda) {
    Strc_Filmes* Filmes = return_Filmes();

    printf("Título: %s \n", Filmes[i].nome);
    printf("\tPreço de compra: R$ %.2f \n", Filmes[i].precoCompra);
    printf("\tPreço do aluguel: R$ %.2f \n", Filmes[i].precoAluguel);
    printf("\tQuantidade de vezes que foi locado: %d \n", Filmes[i].contAluguel);
    printf("\tSituação: ");

    if (totalVenda >= Filmes[i].precoCompra) {
        printf("Superávit. \n\n");
    } else {
        printf("Déficit \n");
        printf("\tTotal de locações para que o filme se pague: %.0f.  \n\n", (round(Filmes[i].precoCompra / Filmes[i].precoAluguel)) - Filmes[i].contAluguel);
    }
}
