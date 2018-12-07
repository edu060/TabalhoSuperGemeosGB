#include "Jogando.h"



Jogando::Jogando()
{
}


Jogando::~Jogando()
{
}

void Jogando::inicializar()
{
	player.inicializar("Niguiri", "assets/spritesheets/Objetos/Niguiri_Sheet.png");

	gameObject[0] = new Inimigo;
	gameObject[0]->inicializar("Baiacu_spr", "Assets/SpriteSheets/Objetos/Baiacu.png",6, 1, 1, 0, 300);
	gameObject[0]->spr.setEscala(2, 2);

	gameObject[1] = new Inimigo;
	gameObject[1]->inicializar("Baiacu_spr", "Assets/SpriteSheets/Objetos/Baiacu.png", 5, 1, 1, 0, 300);
	gameObject[1]->spr.setEscala(2, 2);

	gameObject[2] = new Inimigo;
	gameObject[2]->inicializar("Baiacu_spr", "Assets/SpriteSheets/Objetos/Baiacu.png", 7, 1, 1, 20, 300);
	gameObject[2]->spr.setEscala(2, 2);

	gameObject[3] = new Maki_1;
	gameObject[3]->inicializar("Maki_1", "Assets/SpriteSheets/Objetos/Maki_1_Sheet.png", 5.5f, 1, 4, 10000, 300);
	gameObject[3]->spr.avancarAnimacao();
	gameObject[3]->spr.setEscala(2, 2);

	gameObject[4] = new Maki_2;
	gameObject[4]->inicializar("Maki_2_Sheet", "Assets/SpriteSheets/Objetos/Maki_2_Sheet.png", 5.5f, 1, 4, 20000, 300);
	gameObject[4]->spr.setEscala(2, 2);

	gameObject[5] = new Maki_3;
	gameObject[5]->inicializar("Maki_3_Sheet", "Assets/SpriteSheets/Objetos/Maki_3_Sheet.png", 5.5f, 1, 4, 30000, 300);
	gameObject[5]->spr.setEscala(2, 2);

	gameObject[6] = new GameObject;
	gameObject[6]->ondas = true;
	gameObject[6]->spr.setEscala(1, 1);
	gameObject[6]->inicializar("Ondas_Sheet", "Assets/SpriteSheets/Fundo/Ondas_Sheet2.png", 0, 1, 8, 0, 0);
	gameObject[6]->spr.avancarAnimacao();
	gameObject[6]->spr.setEscala(1,1);


	gameObject[7] = new GameObject;
	gameObject[7]->fundo = true;
	gameObject[7]->inicializar("fundoInGame", "Assets/SpriteSheets/Fundo/FundoInGame.jpg", 0, 1, 1, 0, 0);

}

void Jogando::executar()
{
	gDebug.limpar();

	gameObject[7]->atualizar();

	gameObject[6]->atualizar();

	if (player.pontos > 2.5f)
	{
		aux = player.pontos;
		for (int i = 0; 6 > i; i++)
		{
			gameObject[i]->atualizar();
		}
		
		for (int i = 0; i < 3; i++)
		{
			gameObject[i]->vel = gameObject[i]->vel + (aux / 7000);
		}
			
	}

	if (player.vidas >= 1)
	{
		player.atualizar();

		player.pontos = player.pontos + 0.002f;
		
		player.pontuacao_aux = player.pontuacao_aux + 0.002f;
		colisoes();
	}

	if (player.vidas < 1 && Morreu == false)
	{
		Morreu = true;
		salvarPlacar();
	}



	Inimigo inimigo;
	inimigo.vel += player.pontos;


	gDebug.erro("Pontuação: " + to_string(player.pontos));
	gDebug.erro("Vidas: " + to_string(player.vidas));
	gDebug.erro("X: " + to_string(player.x));
	gDebug.erro("Y: " + to_string(player.y));
	gDebug.erro("Makis 1: " + to_string(player.maki2));
	gDebug.erro("Makis 2: " + to_string(player.maki3));
	gDebug.erro("Power Up: " + to_string(player.conMaki2));
}

void Jogando::colisoes()
{
	for (int i = 0; 6 > i; i++)
	{
		if (uniTestarColisao(gameObject[i]->spr, gameObject[i]->x, gameObject[i]->y, 0, player.spr, player.x, player.y, 0))
		{
			gameObject[i]->morrer();
			gameObject[i]->individualidade();

			if (player.terminou == true)
			{
				if (i < 3)
				{
					player.vidas--;
				}
			}
			if (i == 3)
			{
				ma1++;
				player.vidas++;
			}
			if (i == 4)
			{
				ma2++;
				player.maki2++;
			}
			if (i == 5)
			{
				ma3++;
				player.maki3++;
			}
			
		}
	}
}

void Jogando::salvarPlacar()
{
	float Placar[5];

	ifstream arqPlacarCarregar;

	arqPlacarCarregar.open("Placar.txt");

	for (int i = 0; i < 5; i++)
	{
		arqPlacarCarregar >> Placar[i];
	}

	ofstream arqPlacarImprimir;

	arqPlacarImprimir.open("Placar.txt");

	float Aux = 0;

	for (int l = 0; l < 5; l++)
	{
		if (Placar[l] < player.pontos)
		{
			Aux = Placar[l];

			Placar[l] = player.pontos;

			player.pontos = Aux;
		} /////
	}

	for (int i = 0; i < 5; i++)
	{
		arqPlacarImprimir << Placar[i];
		arqPlacarImprimir << endl;
	}


	arqPlacarCarregar.close();
	arqPlacarImprimir.close();
}
