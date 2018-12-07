#include "Usuario.h"



Usuario::Usuario()
{
}


Usuario::~Usuario()
{
}

string Usuario::getNome()
{
	return nome;
}

string Usuario::getSenha()
{
	return senha;
}

void Usuario::setNome(string no)
{
	nome = no;
}

void Usuario::setSenha(string se)
{
	senha = se;
}