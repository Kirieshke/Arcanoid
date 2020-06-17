#include<iostream>
#include<SFML/Graphics.hpp>

#define MenuString 3
using namespace sf;
class Menu
{
public: 
	Menu();
	Menu(sf::RenderWindow& window1);
	~Menu();
	void menu(sf::RenderWindow& window1, sf::RenderWindow& window);
};