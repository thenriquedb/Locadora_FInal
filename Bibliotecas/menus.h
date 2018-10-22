/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menus.h
 * Author: thiago
 *
 * Created on 18 de Outubro de 2018, 22:36
 */

#ifndef MENUS_H
#define MENUS_H


/*
 * --------------------------------------| MENUS |------------------------------
 */

//Função para imprimir o menu de opções de relatorios
void menuRelatorios();

//Função para imprimir o menu de opções de relatorios
void menuCadastro();

//Função para imprimir o menu de opções de gestão de dados
void menuGestao();


/*
 * --------------------------------------| SUBMENUS |---------------------------
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

//Submenu para gestão: edição de dados dos clientes
void subMenu_edicaoClientes();

void subMenuGestao_Editar();

#endif /* MENUS_H */

