#include "Jogador.h"



Jogador::Jogador()
{
}


Jogador::~Jogador()
{
}

void Jogador::inicializar(string nome, string caminho)
{
	if (!gRecursos.carregouSpriteSheet(nome))
	{
		gRecursos.carregarSpriteSheet(nome, caminho, 1, 4); // carrega a sprite do personagem (nro de animacoes, nro de frames da maior animacao)
	}

	spr.setSpriteSheet(nome); // posiciona o personagem na tela

	x = 200;
	y = 300;

	vivo = true;
}

void Jogador::atualizar()
{
	if (gTeclado.segurando[TECLA_W])
	{
		if (y >= 40)
		{
			y = y - 3 * vel;
		}
		//y = y - 3 * vel;
	}
	if (gTeclado.segurando[TECLA_S])
	{
		if (y <= 555)
		{
			y = y + 3 * vel;;
		}
	}
	if (gTeclado.segurando[TECLA_A])
	{
		if (x >= 40)
		{
			x = x - 4 * vel;;
			lado = true;
		}
	}
	if (gTeclado.segurando[TECLA_D])
	{
		if (x <= 765)
		{
			x = x + 2 * vel;;
			lado = false;
		}
	}

	spr.avancarAnimacao();

	if (conMaki3 < 2)
	{
		vel = 3;
		conMaki3 = conMaki3 + 0.002f;
	}
	else
	{
		vel = 1;
	}
	if (maki3 > 0)
	{
		maki3--;
		conMaki3 = 0;
	}

	if (conMaki2 < 2)
	{
		conometro();
	}
	else
	{
		terminou = true;

		if (maki2 > 0)
		{
			if (gTeclado.pressionou[TECLA_I])
			{
				terminou = false;
				conMaki2 = 0;
				conometro();
				maki2--;
			}
		}
	}

	desenhar();
}

void Jogador::desenhar()
{
	spr.desenhar(x, y);
	spr.setEscala(2, 2);
}

void Jogador::conometro()
{
	conMaki2 = conMaki2 + 0.002f;
}

void Jogador::resetar()
{
	x = 200;
	y = 300;
	vidas = 5;
	maki2 = 0;
	maki3 = 0;
	pontos = 0;
}
