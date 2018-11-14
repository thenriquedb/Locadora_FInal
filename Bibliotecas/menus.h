#ifndef MENUS_H
#define MENUS_H

/*
 * --------------------------------------| MENUS |------------------------------
 */

/* Função para imprimir o menu de opções de relatorios */
void menuRelatorios();

/* Função para imprimir o menu de opções de relatorios */
void menuCadastro();

/* Função para imprimir o menu de opções de gestão de dados */
void menuGestao();

/* Função para imprimir o menu de opções de locação de filmes */
void menuLocacao();

/* Função para imprimir o menu de opções de finanças */
void menuFinancas();

/* Função para imprimir o menu de opções de notas fiscais */
void menuNotasFiscais();

/* Função para imprimir o menu de opções de administração */
void menuAdministrativo();

/* Função para imprimir o menu de opções de contas a pagar */
void menuContas_aPagar();

/* Função para imprimir o menu de opções de entrada de filmes */
void menu_EntradaFilmes();

/**/
void menuLocacoes();

/*
 * -----------------------------| SUBMENUS RELATORIOS |-------------------------
 */

//Submenu de relatorio dos clientes
void subMenuRel_Clientes();

//Submenu de relatorio dos filmes
void subMenuRel_Filmes();

//Submenu de relatorio dos categorias
void subMenuRel_Categorias();

//Submenu de relatorio dos funcionario
void subMenuRel_Funcionarios();

//Submenu de relatorio dos fornecedores
void subMenuRel_Fornecedores();

//Submenu de contas a pagar
void subMenuContas_aPagar();

/*
 * -----------------------------| SUBMENUS GESTÃO: EDIÇÃO |-------------------------
 */
void subMenuGestao_Editar();

//Submenu para gestão: edição de dados dos clientes
void subMenu_edicaoClientes();

//Submenu para gestão: edição de dados de filmes
void subMenu_edicaoFilmes();

//Submenu para gestão: edição de dados de categorias
void subMenu_edicaoCategorias();

//Submenu para gestão: edição de dados de funcionários
void subMenu_edicaoFuncionarios();

//Submenu para gestão: edição de dados de fornecedores
void subMenu_edicaoFornecedores();

/*
 * -----------------------------| SUBMENUS GESTÃO: EXCLUSÃO |-------------------------
 */
void subMenuGestao_Excluir();


#endif /* MENUS_H */

