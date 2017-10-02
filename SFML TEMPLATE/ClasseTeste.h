#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class ClasseTeste
{
private:
	//Janela
	sf::RenderWindow *window = nullptr;

	//Eventos
	sf::Event event;
	
	//Mouse
	sf::Vector2i MousePos; //Mouse position
	bool clic = false; //Click :V


	

public:
	ClasseTeste();
	virtual ~ClasseTeste();

	

	void LoopCentral();

	//Create all the stuff you need
	void Create();

	//IN Apply you do all de basic configuration
	void Apply();

	void Update();


	void Input();
	void InputKeyboard();
	void InputMouse();


	void Render();
};

