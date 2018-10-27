#ifndef GESTAO_H
#define GESTAO_H

/*
 * --------------------------| EXCLUSÃO DE DADOS |---------------------
 */
void excluirCliente();
void excluirFilme();
void excluirCategoria();
void excluirFornecedor();
void excluirFuncionario();

/*
 * --------------------------| EDIÇÃO DE DADOS DOS CLIENTES |---------------------
 */
int edicaoCliente();

void edicaoCliente_nome(int i);
void edicaoCliente_CPF(int i);
void edicaoCliente_telefone(int i);
void edicaoCliente_dataNascimento(int i);
void edicaoCliente_email(int i);
void edicaoCliente_endereco(int i);
void edicaoCliente_tudo(int i);
void edicaoCliente_estadoCivil(int i);

/*
 * --------------------------| EDIÇÃO DE DADOS DOS FILMES |---------------------
 */
int edicaoFilme();

void edicaoFilme_nome(int i);
void edicaoFilme_codigoCategoria(int i);
void edicaoFilme_descricao(int i);
void edicaoFilme_exemplares(int i);
void edicaoFilme_idioma(int i);
void edicaoFilme_tudo(int i);

/*
 * --------------------------| EDIÇÃO DE DADOS DAS CATEGORIAS |---------------------
 */
int edicaoCategoria();

void edicaoCategoria_nome(int i);
void edicaoCategoria_valor(int i);
void edicaoCategoria_descricao(int i);
void edicaoCategoria_tudo(int i);

/*
 * --------------------------| EDIÇÃO DE DADOS DOS FUNCIONARIOS |---------------------
 */
int edicaoFuncionario();

void edicaoFuncionario_nome(int i);
void edicaoFuncionario_cargo(int i);
void edicaoFuncionario_email(int i);
void edicaoFuncionario_endereco(int i);
void edicaoFuncionario_telefone(int i);
void edicaoFuncionario_tudo(int i);

/*
 * --------------------------| EDIÇÃO DE DADOS DOS FORNECEDORES |---------------------
 */
int edicaoFornecedor();

void edicaoFornecedor_nomeFantasia(int i);
void edicaoFornecedor_razaoSocial(int i);
void edicaoFornecedor_inscricaoSocial(int i);
void edicaoFornecedor_email(int i);
void edicaoFornecedor_endereco(int i);
void edicaoFornecedor_telefone(int i);
void edicaoFornecedor_cnpj(int i);
void edicaoFornecedor_tudo(int i);

#endif /* GESTAO_H */

