#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	//Inicializando o Carregador de Assets
	this->mapa_assets.open("..\\mapa_assets.txt", ios::in);
	if (!mapa_assets) {
		gDebug.erro("n�o abriu o arquivo", this);
	}
	CarregadorDeAssets * cda_carregador_assets = new CarregadorDeAssets;
	if (!cda_carregador_assets->CarregarAssets(mapa_assets)) {
		gDebug.erro("Falha no carregamento de recursos");
	}



	menu->inicializar();
}

void Jogo::finalizar()
{
	//	O resto da finaliza��o vem aqui (provavelmente, em ordem inversa a inicializa��o)!
	//	...

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//	Seu c�digo vem aqui!
		//	...
		menu->atualizarMenus();
		uniTerminarFrame();
	}
}