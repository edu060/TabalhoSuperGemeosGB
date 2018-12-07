#include "Menu.h"



Menu::Menu()
{
	pMenu.push(MENUI);
	pCriar.push(NOME);
	pLogar.push(NOME);

	nome = "";
	senha = "";
}


Menu::~Menu()
{
}

void Menu::atualizarMenus()
{
	switch (pMenu.top())
	{
	case MENUP:
		atualizarMenuPrincipal();
		break;
	case JOGAR:
		atualizarJogar();
		break;
	case MENUI:
		atualizarConta();
		break;
	case CRIAR:
		pCriar.top();
		atualizarCriar();
		break;
	case LOGAR:
		pLogar.top();
		atualizarLogar();
		break;
	case HIGH5:
		atualizarHigh5();
		break;
	default:
		break;
	}
}

void Menu::inicializar()
{
#pragma region Instancias
	usuario = new Usuario;
	gContas = new Contas;
	input.inicializar();


#pragma endregion

#pragma region Arquivos
	arqHigh5.open("High5.txt", ios::in);
	gContas->inserirRank(arqHigh5, gContas, nome, mPonto);
	arqHigh5.close();

	dadosUsuario.open("info.bin", ios::binary | ios::in);
	gContas->inserirPorArquivo(dadosUsuario, gContas, usuario);
	dadosUsuario.close();

#pragma endregion

#pragma region Audios
	gRecursos.carregarMusica("Entrada", "Assets/Audios/Musicas/CuteCuteOverkill.mp3", 70);
	gRecursos.carregarMusica("InGame", "Assets/Audios/Musicas/SairNaMao.mp3", 100);
	gRecursos.carregarMusica("High5", "Assets/Audios/Musicas/Coral.mp3", 100);
#pragma endregion

#pragma region Sprites
	gRecursos.carregarSpriteSheet("Campo", "Assets/SpriteSheets/Outros/Fundo_Escrita.png");

	gRecursos.carregarSpriteSheet("BotCriar", "Assets/SpriteSheets/Botao/Botao_Criar_Sheet.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotJogar", "Assets/SpriteSheets/Botao/Botao_Jogar_Sheet.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotVazar", "Assets/SpriteSheets/Botao/Botao_Vazar_Sheet.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotLogar", "Assets/SpriteSheets/Botao/Botao_Logar_Sheet.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotHigh5", "Assets/SpriteSheets/Botao/Botao_High5_Sheet.png", 3, 1);
	gRecursos.carregarSpriteSheet("BotBarco", "Assets/SpriteSheets/Botao/Botao_Barco_Sheet.png", 3, 1);


	campo.setSpriteSheet("Campo");
	botCriar.setSpriteSheet("BotCriar");
	botLogar.setSpriteSheet("BotLogar");
	botJogar.setSpriteSheet("BotJogar");
	botHigh5.setSpriteSheet("BotHigh5");
	botVazar.setSpriteSheet("BotVazar");
	botBarco.setSpriteSheet("BotBarco");


	botCriar.setPos(400, 250);
	botLogar.setPos(400, 350);
	botJogar.setPos(400, 230);
	botHigh5.setPos(400, 300);
	botVazar.setPos(400, 370);

	jogando.inicializar();

	//fundo.setSpriteSheet("Fundo");


#pragma endregion

#pragma region Fontes

	gRecursos.carregarFonte("Fonte1", "Assets/Fontes/Fipps-Regular.otf", 32);
	gRecursos.carregarFonte("Fonte2", "Assets/Fontes/Fipps-Regular.otf", 16);


	input.txt.setString("Fonte1");
	high5textoTitulo.setFonte("Fonte1");
	logtexto.setFonte("Fonte1");
	//inttexto.setFonte("Fonte1");
#pragma endregion
}

void Menu::atualizarMenuPrincipal()
{
	if (!gMusica.estaTocando())
	{
		gMusica.tocar("Entrada", true);
	}

	botVazar.atualizar();
	botHigh5.atualizar();
	botJogar.atualizar();
	botVazar.desenhar();
	botHigh5.desenhar();
	botJogar.desenhar();

	if (botJogar.estaClicado())
	{
		jogando.player.resetar();
		gMusica.pausar();
		pMenu.push(JOGAR);
	}

	if (botHigh5.estaClicado())
	{
		gMusica.pausar();
		pMenu.push(HIGH5);
	}

	if (botVazar.estaClicado())
	{
		uniTerminarFrame();
		uniFinalizar();
	}
}

void Menu::atualizarJogar()
{
	if (!gMusica.estaTocando())
	{
		gMusica.tocar("InGame", true);
	}

	jogando.salvarPlacar();
	jogando.executar();
	jogando.colisoes();

	if (gTeclado.segurando[TECLA_F3])
	{
		//Adicionar pontos
		jogando.player.pontos++;
	}

	if (gTeclado.pressionou[TECLA_VOLTAR])
	{
		


		player.pontos = 0;
		player.vidas = 5;
		gMusica.pausar();
		pMenu.pop();
	}
}

void Menu::atualizarHigh5()
{
	float pontos[5];

	if (!gMusica.estaTocando())
	{
		gMusica.tocar("High5", true);
	}
	// --------------------------------------- EXECUCAO -------------------------------------------------- //
	high5textoTitulo.setString("!1! THE HIGH 5 !1!");
	high5textoTitulo.desenhar(400, 100, 1.5f);
	high5textoTitulo.setCor(0, 0, 0);

	arqPlacarCarregar.open("Placar.txt");

	for (int i = 0; i < 5; i++)
	{
		arqPlacarCarregar >> pontos[i];

		placar[i].setFonte("Fonte2");
		placar[i].desenhar(400, 400 - i * 50);
		placar[i].setString("A" + to_string(pontos[i]));
	}

	





	if (gTeclado.pressionou[TECLA_VOLTAR])
	{
		gMusica.pausar();
		pMenu.pop();
	}
}

void Menu::atualizarLogar()
{
	campo.setEscala(6, 2);
	campo.desenhar(400, 310);
	input.atualizar();
	input.desenhar();

	logtexto.desenhar(400, 250);
	if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {

		input.atualizar();
		input.desenhar();
		campo.desenhar(400, 300);


		switch (pLogar.top())
		{
		case NOME:
			logtexto.setString("Digite a Senha");
			nome = input.txt.getString();
			input.apagar_texto();
			pLogar.push(SENHA);
			break;

		case SENHA:
			senha = input.txt.getString();
			input.apagar_texto();
			gContas-> itCont = gContas->cont.find(nome);
			if (nome == gContas->itCont->second.getNome())
			{
				if (senha == gContas->itCont->second.getSenha())
					pMenu.push(MENUP);
			}
			else
			{
				logtexto.setString("Senha Incorreta, Digite Seu Nome");
				pLogar.push(NOME);
			}
			break;
		}
	}
}

void Menu::atualizarCriar()
{
	campo.setEscala(6, 2);
	campo.desenhar(400, 310);
	input.atualizar();
	input.desenhar();

	logtexto.desenhar(400, 250);
	if (gTeclado.pressionou[TECLA_ENTER] || gTeclado.pressionou[TECLA_ENTER2]) {

		input.atualizar();
		input.desenhar();
		campo.desenhar(400, 300);


		switch (pCriar.top())
		{
		case NOME:
			logtexto.setString("Digite a Senha");
			nome = input.txt.getString();
			input.apagar_texto();
			pCriar.push(SENHA);
			break;

		case SENHA:
			logtexto.setString("Confirme Sua Senha");
			senha = input.txt.getString();
			input.apagar_texto();
			pCriar.push(CONFIRMACAO);
			break;
		case CONFIRMACAO:
			senhaAux = input.txt.getString();
			input.apagar_texto();
			if (senhaAux == senha)
			{
				dadosUsuario.open("info.bin", std::ios::binary | ios::out | ios::app);
				usuario->setNome(nome);
				usuario->setSenha(senha);
				dadosUsuario.write(reinterpret_cast<char *>(usuario), sizeof(Usuario));
				dadosUsuario.close();
				pMenu.push(MENUP);
			}
			else
			{
				logtexto.setString("Não Confere, Digite Seu Nome");
				nome = "";
				senha = "";
				senhaAux = "";
				pCriar.push(NOME);
			}
			break;
		}
	}
}

void Menu::atualizarConta()
{

	gJanela.setCorDeFundo(200, 200, 255);

	logtexto.setCor(0, 0, 0);

	botCriar.desenhar();
	botCriar.atualizar();
	botLogar.desenhar();
	botLogar.atualizar();

	if (botCriar.estaClicado())
	{
		fundo.desenhar(400, 230);
		pMenu.push(CRIAR);
		logtexto.setString("Digite Seu Nome");
	}
	if (botLogar.estaClicado())
	{
		fundo.desenhar(400, 230);
		pMenu.push(LOGAR);
		logtexto.setString("Digite Seu Nome");
	}
}

void Menu::atualizarBarco()
{

}


