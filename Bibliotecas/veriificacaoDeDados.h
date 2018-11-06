
#ifndef VERIIFICACAODEDADOS_H
#define VERIIFICACAODEDADOS_H

/* Verificar se um número inteiro é positivo */
int verificarNumeroPositivoINT(int x);

/* Verificar se um número real é positivo */
int verificarNumeroPositivoFLOAT(float x);

/* Verificar se o codigo do cliente existe */
int verificarCod_Cliente(int cod);

/* Verificar se o codigo do categoria existe */
int verificarCod_Categoria(int cod);

/* Verificar se o codigo do filme existe */
int verificarCod_Filme(int cod);

/* Verificar se o codigo do funcionário existe */
int verificarCod_Funcionario(int cod);

/* Verificar se o codigo do fornecedor existe */
int verificarCod_Fornecedores(int cod);

int verificarExemplares_Filmes(int id, int quant);

int verificarFilme_Fornecedor(int posFor, int idFil, int cont);

/*Retorna a opÃ§Ã£o digitada pelo usuario*/
int selecao();

// Função para finalizar o cadastro ou se deseja cadastrar mais
int parar_ou_ContinuarCadastro();

int chamarMenu_Relatorio();

#endif /* VERIIFICACAODEDADOS_H */
