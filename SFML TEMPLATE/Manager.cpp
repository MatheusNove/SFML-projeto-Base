#include "Manager.h"



Manager::Manager()
{
	janela = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Jogo");


	/*sf::RectangleShape Rectan(sf::Vector2f(150, 50));
	Rectan.setFillColor(sf::Color(255, 0, 0, 255));
	Rectan.setPosition(sf::Vector2f(100, 100));*/
	
	
}

Manager::~Manager()
{
	delete janela;
}

void Manager::Programa()
{
	while (quit == false)
	{
		Inputs();
		Update();
		Render();
	}
}

void Manager::Inputs()
{
	while (janela->pollEvent(eventos))
	{
		posicaoMouse = sf::Mouse::getPosition(*janela);
		switch (eventos.type)
		{
		case sf::Event::Closed:
			quit = true;
			break;
		case sf::Event::KeyPressed:
			InputTeclado();
			break;
		case sf::Event::MouseButtonPressed:
			MouseClicado();
			break;
		case sf::Event::MouseMoved:
			MouseMovido();
			break;
		}
	}
}

void Manager::Update()
{
	switch (estadoTela)
	{
	case MENU:
		UpdateMenu();
		break;
		
	case JOGO:
		UpdateJogo();
		break;

	case GAMEOVER:
		UpdateGameOver();
		break;
	}
}

void Manager::Render()
{
	janela->clear();
	switch (estadoTela)
	{
	case MENU:
		RenderMenu();
		break;

	case JOGO:
		RenderJogo();
		break;

	case GAMEOVER:
		RenderGameOver();
		break;
	}
	janela->display();
}

void Manager::UpdateMenu()
{
}

void Manager::UpdateJogo()
{
}

void Manager::UpdateGameOver()
{
}

void Manager::RenderMenu()
{
}

void Manager::RenderJogo()
{
	
}

void Manager::RenderGameOver()
{
}

void Manager::InputTeclado()
{
	switch (eventos.key.code)
	{
	case sf::Keyboard::Escape:
		quit = true;
		break;
	case sf::Keyboard::A:
		break;
	}
}

void Manager::MouseClicado()
{
	switch (eventos.mouseButton.button)
	{
	case sf::Mouse::Left: //Mouse Botao Esquerdo Pressionado
		break;

	case sf::Mouse::Right: //Mouse Botao Direito Pressionado
		break;
	}
}

void Manager::MouseMovido()
{
}