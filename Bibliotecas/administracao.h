
#ifndef ADMINISTRACAO_H
#define ADMINISTRACAO_H
#include "structs.h"

/* Funçao para efetuar a compra de novos filmes para o estoque */
void entradaFilmes();

/* Função responsavel por realizar a locação de filmes para clientes */
void locacaoFilmes();

void DevolucaoFilmes();

/* Imprime os tiulos comprados pela locadora. (Nome, código e quantidade de exemplares) */
void visualizarEstoque();

/* Função para gerar um código uníco para cada nota fiscal emitida */
int gerarCodigoNF();

/*
 * --------| FILTROS DE FEEDBACK DE QUANTAS LOCAÇÕES RESTANTES PARA QUE | ------
 * -----------------------| DETERMINADO FILME SE PAGUE |------------------------
 */
void contLocacoes_FilmesePaga_Todos();
void contLocacoes_FilmesePaga_Pagos();
void contLocacoes_FilmesePaga_Deficit();
void contLocacoes_FilmesePaga_codFilme();
void contLocacoes_FilmesePaga_faixaCodigo();

#endif /* ADMINISTRACAO_H */
