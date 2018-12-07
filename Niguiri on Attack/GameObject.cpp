#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::inicializar(string nome, string caminho, float Vel, int c, int l, float t_respawn, float B)
{
	if (!gRecursos.carregouSpriteSheet(nome))
	{
		gRecursos.carregarSpriteSheet(nome, caminho, c, l); // carrega a sprite do personagem (nro de animacoes, nro de frames da maior animacao)
	}

	spr.setSpriteSheet(nome); // posiciona o personagem na tela

	t_Respawn = t_respawn;

	x = 600 + t_Respawn + B;
	y = rand() % 600;

	vel = Vel;

	if (ondas == true)
	{
		y = 565;
		x = x - 200;
	}
	if (fundo)
	{
		y = 370;
		x = x;
	}
}

void GameObject::atualizar()
{
	x = x - vel;

	vel = vel;

	spr.desenhar(x, y);
	spr.setEscala(2, 2);

	if (x < 0 - spr.getLargura())
	{
		morrer();
	}

	if (ondas == true)
	{
		spr.setAnimacao(0);
		spr.avancarAnimacao();
	}
}

void GameObject::morrer()
{
	individualidade();

	if (ondas == true)
	{
		y = 565;
		x = 800 + t_Respawn;
	}
	else
	{
		y = rand() % 600;
		x = 800 + t_Respawn;
	}
}

void GameObject::individualidade()
{
}
