#include <SFML/Graphics.hpp>
using namespace sf;
class Ball
{
private:
	Vector2f position;
	RectangleShape  ballShape;
	float xVelocity = 7;
	float yVelocity = 7;

public:

	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();
	
	void reboundBlock();

	void hitBottom();

	void update();

	void setVel(float x_, float y_, float time);

};