#pragma once
#include "libUnicornio.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Maki_1.h"
#include "Maki_2.h"
#include "Maki_3.h"
#include <iostream>
#include <fstream>
#include <string>

class Jogando
{
public:
	Jogando();
	~Jogando();

	void inicializar();
	void executar();
	void colisoes();
	void salvarPlacar();

	bool Ja_Imp = false;
	bool Morreu = false;

	float aux;

	GameObject * gameObject[15];
	Jogador player;
	
	int nig, ma1, ma2, ma3, bai;
};

