#include<SFML/Graphics.hpp>
using namespace sf;
class Platform
{
private:
	Vector2f position;
private:
	float platformSpeed = 9.9;	
	RectangleShape platformShape;

public:
	Platform();

	Platform(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void update();

	void setX(int x_);
	void setWidth(int w);
};