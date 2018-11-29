
#ifndef CADASTROS_H
#define CADASTROS_H

/*********************************************************************************
 * -----------------------------| FUNÇÕES DE ALOCAÇÃO |-------------------------
 * Funções para receber entradas de dados pelo usuário e fazer o seu armazenamento
 * em mémoria.
 *********************************************************************************/

void cadastrarLocadora();

void cadastrarClientes();

void cadastrarFilmes();

void cadastrarCategorias();

void cadastrarFuncionarios();

void cadastrarFornecedores();




/*********************************************************************************
 * -----------------------------| FUNÇÕES DE ALOCAÇÃO |-------------------------
 * Funções geradoras de códigos unicos para cada nova entrada
 *********************************************************************************/

int gerarCodigoCliente();

int gerarCodigoFilme();

int gerarCodigoCategoria();

int gerarCodigoFuncionario();

int gerarCodigoFornecedores();

#endif /* CADASTROS_H */