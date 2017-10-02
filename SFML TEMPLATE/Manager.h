#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

#define MENU 0
#define JOGO 1
#define GAMEOVER 2

class Manager
{
private: //AQUI VOC� CRIA AS VARI�VEIS
	sf::RenderWindow *janela = nullptr;
	sf::Vector2i posicaoMouse;
	sf::Event eventos;

	
	


	short estadoTela = MENU;
	bool quit = false;
public:
	Manager();
	~Manager();

	void Programa();

	void Inputs();
	void Update();
	void Render();

	void UpdateMenu();
	void UpdateJogo();
	void UpdateGameOver();

	void RenderMenu();
	void RenderJogo();
	void RenderGameOver();

	void InputTeclado();
	void MouseClicado();
	void MouseMovido();
};

