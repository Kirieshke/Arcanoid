#include<SFML/Graphics.hpp>
using namespace sf;
class Block
{
private:
	Vector2f position;
public:
	bool destroyed = false;
	Block();
	Block(float startX, float startY);
	RectangleShape blockShape;

	FloatRect getPosition();
	RectangleShape getShape();
	void update();
};