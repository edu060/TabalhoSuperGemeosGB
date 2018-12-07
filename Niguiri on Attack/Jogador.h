#pragma once
#include "libUnicornio.h"
class Jogador
{
public:
	Jogador();
	~Jogador();

	void inicializar(string nome, string caminho);
	void atualizar();
	void desenhar();
	void conometro();
	void resetar();

	float conMaki2 = 10, conMaki3 = 10, x, y, pontos = 0;
	
	bool terminou = true, vivo, lado = 0;
	int vel = 1, maki2 = 1, maki3 = 1, vidas = 5;

	float pontuacao_aux = 0;

	Sprite spr;

};

