#include <iostream>
#include <SFML\Main.hpp>
#include <SFML\Graphics.hpp>
#include "ClasseTeste.h"

using namespace std;

int main()
{
	/*Manager *manager = new Manager();
	manager->Programa();
	delete manager;*/

	/*ClasseTeste *Teste = new ClasseTeste();
	Teste->LoopCentral();
	delete Teste;*/

	//Janela
	sf::RenderWindow window(sf::VideoMode(800, 600), "YES THE WINDOW");

	//Events de Input
	sf::Event event;

	//Mouse
	sf::Vector2i MousePos; //Posição do Mouse
	bool clic = false; //Se teve click :V

	//Posição do Quadrado criado abaixo
	float PlayerX = 0.1, PlayerY = 0.1;

	//Quadrado
	sf::RectangleShape Rectan(sf::Vector2f(50, 50));
	Rectan.setFillColor(sf::Color(255, 0, 0, 255));
	Rectan.setPosition(sf::Vector2f(100, 100));
	
	//Fonte
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "Erro ao carregar a Fonte" << endl;
	}

	//Texto
	sf::Text text;
	text.setFont(font);
	text.setString("");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);			//setStyle é usado para deixar o texto como Negrito, Italico e etc
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//text.setPosition(PlayerX, PlayerY);



	//Texto da velocidade do quadrado
	//SpeedX
	sf::Text speedX;
	speedX.setFont(font);
	speedX.setCharacterSize(30);
	speedX.setFillColor(sf::Color::Yellow);
	speedX.setStyle(sf::Text::Bold);
	speedX.setPosition(0, 30);
	std::string playerSX;

	//SpeedY
	sf::Text speedY;
	speedY.setFont(font);
	speedY.setCharacterSize(30);
	speedY.setFillColor(sf::Color::Yellow);
	speedY.setStyle(sf::Text::Bold);
	speedY.setPosition(0, 60);
	std::string playerSY;

	//Texto de Zuera
	sf::Text HUEText;
	HUEText.setFont(font);
	HUEText.setCharacterSize(90);
	HUEText.setFillColor(sf::Color(148, 0, 211));
	HUEText.setPosition(0, 90);


	//----------------------
	//Textura
	sf::Texture texture;
	if (!texture.loadFromFile("canttouch.jpg"))
		cout << "Erro ao Carregar a textura" << endl;
	
	//Sprite pra Textura
	sf::Sprite canTouch;
	canTouch.setTexture(texture);
	canTouch.setScale(0.2, 0.2);
	canTouch.setPosition(200, 150);

	//Collisions Box
	sf::FloatRect CantBox;
	sf::FloatRect RectBox;
	
	

	
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		while (window.pollEvent(event))
		{	




			//Pegando a posição do Mouse dentro da janela.........caso não tenha o (window) ele ira pegar com relação a tela
			MousePos = sf::Mouse::getPosition(window);




			switch (event.type)
			{

			case sf::Event::Closed:
					window.close();
					break;





			//Input para as teclas pressionadas do teclado
			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Space)
				{
					Rectan.setFillColor(sf::Color::Green);
				}				
				
				break;




			//Input para as teclas soltasdo teclado
			case sf::Event::KeyReleased:

				if (event.key.code == sf::Keyboard::Space)
				{
					Rectan.setFillColor(sf::Color::Red);
				}
				
				break;





			//Input para os botões do mouse pressionados
			case sf::Event::MouseButtonPressed:

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//Cor muda com o click e não com clicar nela, em colições aparecerá como clicar nela
					canTouch.setColor(sf::Color::Cyan);
					clic = true;
				}
				break;



			//Quando o botão do mouse for solto
			case sf::Event::MouseButtonReleased:
				clic = false;

				if (event.mouseButton.button == sf::Mouse::Left)
				{
					canTouch.setColor(sf::Color(255,225,225,255));
				}
				break;

			default:
				break;
			}
		}
		
	
		
	


		


	





		//Código :V
		//----------------------------------------------------------------------------------------------

		//Aqui os valores estão sendo convertidos para String para poderem serem impressões		
		playerSX = std::to_string(PlayerX);
		speedX.setString(playerSX);

		playerSY = std::to_string(PlayerY);
		speedY.setString(playerSY);




		//Move o Quadrado
		Rectan.move(sf::Vector2f(PlayerX, PlayerY));
		if (Rectan.getPosition().x < 0)
			PlayerX = (PlayerX - 0.005) * -1;

		if (Rectan.getPosition().x > 760)
			PlayerX = (PlayerX + 0.005) * -1;

		if (Rectan.getPosition().y < 0)
			PlayerY = (PlayerY - 0.005) * -1;

		if (Rectan.getPosition().y > 560)
			PlayerY = (PlayerY + 0.005) * -1;





		//Colições
		//-----------------------------------------------------------------
		//Pega as posições dos objetos 
		CantBox = canTouch.getGlobalBounds();
		RectBox = Rectan.getGlobalBounds();

		//Quando o Quadrado acerta a imagem
		if (RectBox.intersects(CantBox))
			text.setString("ACERTOOOOOOOO!!!!!!!!!!!!!!!");
		else
			text.setString("Ainda não");

		//Quando a imagem é clicada
		if (CantBox.contains((sf::Vector2f)MousePos) && clic == true)
		{
			text.setString("CLICO :O");
		}
		
		
		
		if (PlayerX >= 1 && PlayerY >= 3 || PlayerX <= -1 && PlayerY <= -3)
			HUEText.setString("POWEERRRRRR!!!");




		




		//Tela sendo limpa 
		window.clear(sf::Color::Black);
		
		
		//Todas as coisas são desenhadas
		//A ordem que é coloca para desenhar influencia em quem aparece por cima
		//As primeiras ficam atrás
		window.draw(speedX);	
		window.draw(speedY);
		window.draw(HUEText);

		window.draw(Rectan);
		window.draw(text);
		window.draw(canTouch);
		//Coisas mais pra baixo aparecem na frente 


		// draw everything here...
		// window.draw(...);
		
		window.display();
	}
	return 0;
}