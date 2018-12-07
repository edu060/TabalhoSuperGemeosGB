#pragma once
#include"CarregadordeAssets.h"
#include "libUnicornio.h"
#include "Menu.h"
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

	fstream mapa_assets;
	Menu * menu = new Menu;
};

