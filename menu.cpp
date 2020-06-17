#include<iostream>
#include<SFML/Graphics.hpp>
#include"menu.h"

using namespace sf;
using namespace std;

Menu::Menu()
{

}

Menu::Menu(sf::RenderWindow& window1)
{

}

Menu::~Menu()
{

}

void Menu::menu(sf::RenderWindow& window1, sf::RenderWindow& window)
{
	while (window1.isOpen())
	{
		Texture menuTexture1, menuTexture3, aboutTexture, gameAuthor, menuBackground;
		menuTexture1.loadFromFile("D:/images/SpriteMenu1.png");
		menuTexture3.loadFromFile("D:/images/SpriteMenu3.png");
		menuBackground.loadFromFile("D:/images/dio.png");


		Sprite menu1(menuTexture1), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
		bool isMenu = 1;
		int MenuNum = 0;

		menu1.setPosition(100, 200);
		menu3.setPosition(100, 300);
		/*	menuBg.setTextureRect(IntRect(1360));*/
		while (isMenu)
		{
			menu1.setColor(Color::White);
			menu3.setColor(Color::White);
			MenuNum = 0;
			window1.clear(Color(129, 181, 221));

			if (IntRect(100, 200, 300, 50).contains(Mouse::getPosition(window1))) { menu1.setColor(Color::White); MenuNum = 1; }
			if (IntRect(100, 300, 300, 50).contains(Mouse::getPosition(window1))) { menu3.setColor(Color::White); MenuNum = 3; }

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (MenuNum == 1)
				{
					window1.close();
					isMenu = false;
			
					
				}
				if (MenuNum == 2)
				{
					window1.draw(about);
					window1.display();
					while (!Keyboard::isKeyPressed(Keyboard::Escape));
				}
				else if (MenuNum == 3)
				{
					window1.close();
					isMenu = false;
					window.close();
				}
		
			}
		    
			window1.draw(menuBg);
			window1.draw(menu1);
			window1.draw(menu3);

			window1.display();
		}
		////////////////////////////////////////////////////
	}
}
