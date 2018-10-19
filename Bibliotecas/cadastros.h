
#ifndef CADASTROS_H
#define CADASTROS_H

//Funções para a coleta de informações
void cadastrarClientes();
void cadastrarFilmes();
void cadastrarCategorias();
void cadastrarFuncionarios();
void cadastrarFornecedores();

//Geradores de codigos unicos
int gerarCodigoCliente();
int gerarCodigoFilme();
int gerarCodigoCategoria();
int gerarCodigoFuncionario();
int gerarCodigoFornecedores();

#endif /* CADASTROS_H */