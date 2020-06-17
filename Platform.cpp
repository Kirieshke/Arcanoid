#include"Platform.h"
Platform::Platform(){}
Platform::Platform(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
		
	platformShape.setSize(sf::Vector2f(70, 30));
	platformShape.setFillColor(sf::Color::Yellow);
	platformShape.setPosition(position);
}

FloatRect Platform::getPosition()
{
	return platformShape.getGlobalBounds();
}

RectangleShape Platform::getShape()
{
	return platformShape;
}

void Platform::moveLeft()
{
	position.x -= platformSpeed;
}

void Platform::moveRight()
{
	position.x += platformSpeed;
}

void Platform::update()
{
	platformShape.setPosition(position);
}
void Platform::setX(int x_) {
	position.x = x_;
}
void Platform::setWidth(int w) {

	platformShape.setSize(sf::Vector2f(2100, 5));
}



