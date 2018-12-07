#pragma once
#include <fstream>
#include <iostream>
#include "libUnicornio.h"
using namespace std;
class Barco
{
public:
	Barco();
	~Barco();

	void atualizar();
	void desenhar();
	void salvarDados();
	void lerDados();

	ifstream arqBarcoCarregar;
	ofstream arqBarcoEscrever;
	

	int niguiri, makiFiladelfia, uruMaki, makiVegetariano, baiacu;
};

