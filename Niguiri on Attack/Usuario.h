#pragma once
#include <iostream>
#include <string>
using namespace std;

class Usuario
{
public:
	Usuario();
	~Usuario();

	string getNome();
	string getSenha();

	void setNome(string no);
	void setSenha(string se);

protected:

	string nome, senha;
};