//#include<SFML/Graphics.hpp>
//#include"Animation.h"
//using namespace std;
//using namespace sf;
//
//
//class Character : public Animation
//{
//public:
//	float dx, dy;
//	FloatRect rect;
//	bool onGround;
//
//
//	Character(Texture& image)
//	{
//		sprite.setTexture(image);
//		rect = FloatRect(0, 0, 10, 50);
//
//		dx = dy = 0;
//		currentFrame = 0;
//	}
//
//	void update(float time)
//	{
//		currentFrame += 0.03;
//		rect.left += dx * time;
//
//		if (!onGround)
//		{
//			dy = dy + 0.00123 * time;
//			rect.top += dy * time;
//			onGround = false;
//		}
//
//		if (rect.top > ground)
//		{
//			rect.top = ground; dy = 0; onGround = true;
//		}
//
//		currentFrame += 0.005*time;
//		if (currentFrame > 5) {
//			currentFrame -= 2.5;
//		}
//		if (dx < 0)	sprite.setTextureRect(IntRect(108 * int(currentFrame), 135, 105, 135));
//		if (dx > 0) sprite.setTextureRect(IntRect(108 * int(currentFrame) + 108, 135, -105, 119)); {
//			sprite.setPosition(100, 500);
//			dx = 0;
//		}
//	}
//
//};
