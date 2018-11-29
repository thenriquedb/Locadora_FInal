
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


/* Verificar se o codigo da nota fiscal existe */
int verificarCod_NotaFiscal();


/* Verificar se o codigo do fornecedor existe */
int verificarCod_Fornecedores(int cod);


/* Verificar se quantidade de filmes solicitada esta disponivel */
int verificarExemplares_Filmes(int id, int quant);

/* Verifica o fornecedor possui determinado filme 
 * cont: utilizado para controlar o limite do for dentro da função */
int verificarFilme_Fornecedor(int posFor, int idFil, int cont);


/*Retorna a opÃ§Ã£o digitada pelo usuario*/
int selecao();


// Função para finalizar o cadastro ou se deseja cadastrar mais
int parar_ou_ContinuarCadastro();

/*
 * Utilizada nas funcos de filtros do relatorio. Pergunta ao usuario se deseja 
 * ralizar uma nova busca ou voltar ao menu principal 
 */
int chamarMenu_Relatorio();


/* Limpa a tela apos uma entrada do usuario*/
void digiteAlguma_teclaContinuar();

int returnModoArmazenamento();

void modoArmazenamento() ;

#endif /* VERIIFICACAODEDADOS_H */
