
#ifndef GUI_H
#define GUI_H

/********************************************************************************
 *  Imprimir todos os dados de um cliente cadastrado 
 *******************************************************************************/
void imprimeClientes(int i);

/********************************************************************************
 *  Função para mostrar todos os filmes cadastrados 
 *******************************************************************************/
void imprimeFilmes(int i);

/********************************************************************************
 *  Função para mostrar todos os categorias cadastrados 
 ********************************************************************************/
void imprimeCategorias(int i);

/******************************************************************************** 
 * Função para mostrar todos os funcionarios cadastrados 
 ********************************************************************************/
void imprimeFuncionarios(int i);

/********************************************************************************
 *  Função para mostrar todos os funcionarios cadastrados 
 ********************************************************************************/
void imprimeFornecedores(int i);

/********************************************************************************
 *  Função para  imprimir informações da nota fiscal 
 ********************************************************************************/
void imprimeNotaFiscal(int codForn, int contItens);

/********************************************************************************
 *  Imprime informoções sobre filmes alugados 
 ********************************************************************************/
void imprimeLocacoes(int i);

/********************************************************************************
 * Imprime informoções sobre contas a receber de clientes 
 ********************************************************************************/
void imprimeContaReceber();

/*********************************************************************************
 * Imprime informoções sobre filmes alugados 
 *********************************************************************************/
void imprimeLocadora();

/********************************************************************************
 * Imprime informoções sobre quantas locações restantes para que determinado filme 
 * se pega 
 ********************************************************************************/
void ImprimeContLocacoes_FilmesePaga(int i, float totalVenda) ;

/********************************************************************************
 * Imprime mensagem se a importação for realziada com sucesso 
 ********************************************************************************/
void imprimeMsgm_importSucesso();

/********************************************************************************
 *Imrpime logo da locadora
 ********************************************************************************/
void imprimeLogo();

#endif /* GUI_H */

