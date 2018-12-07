#include "Contas.h"
Contas::Contas()
{
}
Contas::~Contas()
{
}

void Contas::inserirPorArquivo(fstream & arquivo, Contas * hash, Usuario * conta)
{
	if (arquivo.is_open())
	{
		while (!arquivo.eof())
		{
			arquivo.read(reinterpret_cast<char *>(conta), sizeof(Usuario));
			hash->pContas.first = conta->getNome();
			hash->pContas.second = *conta;
			hash->cont.insert(hash->pContas);
		}
	}
}

void Contas::inserirRank(fstream & arquivo, Contas * hash, std::string use, float pontos)
{
	if (arquivo.is_open())
	{
		while (!arquivo.eof())
		{
			arquivo >> use >> pontos;
			hash->pRank.first = use;
			hash->pRank.second = pontos;
			gDebug.depurar("Usuario: ", hash->pRank.first);
			gDebug.depurar("Pontos: ", hash->pRank.second);
			hash->rank.insert(hash->pRank);
		}
	}
}