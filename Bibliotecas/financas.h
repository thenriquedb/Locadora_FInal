
#ifndef FINANCAS_H
#define FINANCAS_H
#include "structs.h"

void contasPagar_Todas();

/* Pagar uma unica conta por vez, filtrada pelo código da nota */
void contasPagar_Unica();

/* Filtrar contas a pagar pelo fornecedor */
void contasPagar_Fornecedor();

void PagamentoLocacao(int codCl, int codFun, int contAluguel, int posCl, 
        float totalPagamento, Strc_MinimalFilmes* FilmesLocados);

void receber_ContasCl();

#endif /* FINANCAS_H */

