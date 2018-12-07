#pragma once
#include "libUnicornio.h"
#include "InputTexto.h"
#include "Jogando.h"
#include "Usuario.h"
#include "Contas.h"
#include <iostream>
#include <fstream>
#include <deque>
#include <stack>

using namespace std;

enum MENU
{
	MENUP,
	JOGAR,
	MENUI,
	CRIAR,
	LOGAR,
	HIGH5,
	BARCO
};

enum STATUS
{
	NOME,
	SENHA,
	CONFIRMACAO
};

class Menu
{
public:
	stack <MENU> pMenu;
	stack <STATUS> pCriar;
	stack <STATUS> pLogar;
	Menu();
	~Menu();

	Sprite fundo, logo, campo;

	void atualizarMenus();				// Atuliza Menus - Organiza a troca de menus
	void inicializar();					// Inicializacao - Inicializa tudo que for nessessario;
	void atualizarMenuPrincipal();		// Menu Principal - Onde tem as opcoes jogar,sair e rank
	void atualizarJogar();				// Jogar - O "InGame", execussao do jogo
	void atualizarHigh5();				// Rank - mostra os "HighFive"
	void atualizarLogar();				// Menu de Logar - Para logar um usuario
	void atualizarCriar();				// Menu de Criar - Para cirar um usuario
	void atualizarConta();				// Menu de Abertura (login) - Onde possui as escolha logar e criar
	void atualizarBarco();				// Inventario Acumulativo - Um barco de Sushis, mostra quantos consegui ate agora (Inventario LocalGlobal), (Colhecionaveis)


	//void finalizarMenu();

	//void testeRanking(string usuario, int pontos, fstream & arquivo);


	fstream arqHigh5;
	fstream dadosUsuario;
	ifstream arqPlacarCarregar; //-----------------------------------------

	Usuario * usuario = new Usuario;
	Contas * gContas = new Contas;
	

	BotaoSprite botJogar, botHigh5, botVazar, botLogar, botCriar, botBarco;

	int mPonto;

	/*float pontos[5] = { 0,0,0,0,0 };*/


	Texto logtexto, high5textoTitulo;
	InputTexto input;
	Texto texto_creditos;

	Texto placar[5];

	string nome, senha, senhaAux;

	Jogando jogando;
	Jogador player;

};

