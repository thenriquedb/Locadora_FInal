#ifndef MENUS_H
#define MENUS_H

/*
 * --------------------------------------| MENUS |------------------------------
 */

void inicializacao();

void menuRelatorios();

void menuCadastro();

void menuGestao();

void menuLocacao();

void menuFinancas();

void menuNotasFiscais();

void menuAdministrativo();

void menuContas_aPagar();

void menu_EntradaFilmes();

void menu_filmesAlugados();

void menuContas_aReceber();

void menuImportacao();

void menuImportacaoTXT();

void menuImportacaoBIN();

void menuLocacoes_FilmeSePagar();

void menuexportXML();


/*
 * -----------------------------| SUBMENUS RELATORIOS (FEEDBACK) |-------------------------
 */

void subMenuRel_Clientes();

void subMenuRel_Filmes();

void subMenuRel_Categorias();

void subMenuRel_Funcionarios();

void subMenuRel_Fornecedores();

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

