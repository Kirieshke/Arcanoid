#include"Blocks.h"

Block::Block(float startX, float startY)
{
    position.x = startX;
	position.y = startY;

	blockShape.setSize(sf::Vector2f(70, 30));
	blockShape.setFillColor(sf::Color::Yellow);
	blockShape.setPosition(position);
}

Block::Block()
{

}

FloatRect Block::getPosition()
{
	return blockShape.getGlobalBounds();
}

RectangleShape Block::getShape()
{
	return blockShape;
}

void Block::update()
{
	blockShape.getPosition();
}