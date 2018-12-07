#include "libUnicornio.h"
#include <unordered_map>
#include "Usuario.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
class Contas
{
public:
	Contas();
	~Contas();

	unordered_multimap<string, Usuario> cont;
	unordered_multimap<string, int> rank;

	unordered_multimap <string, Usuario>::iterator itCont;
	unordered_multimap <string, int>::iterator itRank;


	pair<string, Usuario> pContas;
	pair<string, int> pRank;

	//pContas pHContas;
	//pRank pRankPontos;

	void inserirPorArquivo(fstream & arquivo, Contas * hash, Usuario * conta);
	void inserirRank(fstream & arquivo, Contas * hash, string use, float pontos);
};