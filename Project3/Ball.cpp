#include"Ball.h"
Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;
	int playerScore = 0;
	ballShape.setSize(sf::Vector2f(20, 20));	
	ballShape.setFillColor(sf::Color::Red);
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 5);
	// при отбивании м€чик перемещаетс€ чуток назад,

	yVelocity = -yVelocity;
	//yVelocity *= -1;

}

void Ball::reboundBlock()
{
	position.y -= (yVelocity * 5);

	yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::update()
{
	// Update the ball position variables
	position.y += (yVelocity);
	position.x += (xVelocity);

	// Move the ball and the bat
	ballShape.setPosition(position);
}

void Ball::setVel(float x_, float y_, float time) {
	xVelocity = x_*time;
	yVelocity = y_*time;
}
