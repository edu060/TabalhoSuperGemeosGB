#include "Inimigo.h"



Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}

void Inimigo::individualidade()
{
	if (player.terminou == true)
	{
		player.vidas--;
	}
}
