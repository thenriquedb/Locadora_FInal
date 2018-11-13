
#ifndef ADMINISTRACAO_H
#define ADMINISTRACAO_H
#include "structs.h"

/* Funçao para efetuar a compra de novos filmes para o estoque */
void entradaFilmes();

/* Função responsavel por realizar a locação de filmes para clientes */
void locacaoFilmes();

/* Imprime os tiulos comprados pela locadora. (Nome, código e quantidade de exemplares) */
void visualizarEstoque();

/* Função para gerar um código uníco para cada nota fiscal emitida */
int gerarCodigoNF();

#endif /* ADMINISTRACAO_H */
