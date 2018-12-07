#pragma once
#include "libUnicornio.h"
#include "Jogador.h"

#include <ctime>

class GameObject
{
public:
	GameObject();
	~GameObject();

	void inicializar(string nome, string caminho, float Vel, int c, int l, float t_respawn, float B);
	void atualizar();
	void morrer();

	virtual void individualidade();

	bool ondas = false;
	bool fundo = false;
	float t_Respawn;

	Sprite spr;

	Jogador player;

	float x, y;
	float vel;
};