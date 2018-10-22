
#ifndef CADASTROS_H
#define CADASTROS_H

//Funções de input de dados de clientes
void cadastrarClientes();

//Funções de input de dados de filmes
void cadastrarFilmes();

//Funções de input de dados de categoria
void cadastrarCategorias();

//Funções de input de dados de funcionarios
void cadastrarFuncionarios();

//Funções de input de dados de fornecedores
void cadastrarFornecedores();

//-----------------------------------------------------------------------------

//Função para gerar um codigo unico para cada cliente cadastrado
int gerarCodigoCliente();

//Função para gerar um codigo unico para cada filme cadastrado
int gerarCodigoFilme();

//Função para gerar um codigo unico para cada categoria cadastrado
int gerarCodigoCategoria();

//Função para gerar um codigo unico para cada funcionario cadastrado
int gerarCodigoFuncionario();

//Função para gerar um codigo unico para cada fornecedor cadastrado
int gerarCodigoFornecedores();

#endif /* CADASTROS_H */