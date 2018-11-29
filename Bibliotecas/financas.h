
#ifndef FINANCAS_H
#define FINANCAS_H
#include "structs.h"

 /*********************************************************************************
 * Funções para pagamento de notas fiscais armazenadas 
 *********************************************************************************/
void contasPagar_Todas();

void contasPagar_Unica();

void contasPagar_Fornecedor();


 /*********************************************************************************
 * Funções para controle do pagamento quando o cliente ira realizar alguma locacao
 * de filmes 
 *********************************************************************************/
void PagamentoLocacao(int codCl, int codFun, int contAluguel, int posCl, 
        float totalPagamento, Strc_MinimalFilmes* FilmesLocados);


 /*********************************************************************************
 * Recebe o pagamento do cliente e da baixa na parcela paga. 
 *********************************************************************************/
void receber_ContasCl();

#endif /* FINANCAS_H */

