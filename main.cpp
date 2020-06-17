#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"menu.h"
#include"Ball.h"
#include"Platform.h"
#include"Blocks.h"
#include<vector>
#include<sstream>
using namespace std;
using namespace sf;

int count_blocksX = 13;
int count_blocksY = 10;

int main()
{
	int windowWidth = 1024; //1024
	int windowHeight = 768; //768
		// Make a window that is 1024 by 768 pixels
	RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Arcanoid");
	RenderWindow window1(sf::VideoMode(windowWidth, windowHeight), "Menu");

	int score = 0;
	int lives = 3;

	Platform platform(windowWidth / 2, windowHeight - 20);

	// create a ballb 

	Menu menu;

	Ball ball(windowWidth / 2, windowHeight - 20); // where appear ball

	sf::SoundBuffer buffer;
	buffer.loadFromFile("D:/GameSound/DirtyRick.ogg");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	vector<Block>block;

	for (int i = 0; i < count_blocksX; ++i)
	{
		for (int j = 0; j < count_blocksY; ++j)
		{
			block.emplace_back((i + 0.1) * (70.f + 3) + 22, (j + 2)* (30.f + 3));
		}
	}

	// Handle ball hitting sides
	if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
	{
		ball.reboundSides();
	}

	// Has the ball hit the bat?
	if (ball.getPosition().intersects(platform.getPosition()))
	{
		// Hit detected so reverse the ball and score a point
		ball.reboundBatOrTop();
	}
	Clock clock;
	// This "while" loop goes round and round- perhaps forever
	while (window.isOpen())
	{
		Text text, text1, textLose;
		// We need to choose a font
		Font font, font1, font2;
		font.loadFromFile("D:/Bootstrap/arial.otf");
		text.setCharacterSize(24);
		text.setFont(font);
		text.setPosition(100, 25);
		text.setFillColor(Color::Red);
		std::string scStr = std::to_string(score);
		std::string res = "Your score: " + scStr;
		text.setString(res);

		font1.loadFromFile("D:/Bootstrap/arial.otf");
		text1.setCharacterSize(24);
		text1.setFont(font1);
		text1.setFillColor(Color::Red);
		std::string scStr1 = to_string(lives);
		std::string res1 = "Lives: " + scStr1;
		text1.setPosition(400, 25);
		text1.setString(res1);


		float time = clock.getElapsedTime().asMicroseconds();
		//Handle the player input

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Someone closed the window- bye
				window.close();
		}


		if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// quit...
			// Someone closed the window- bye
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			// move left...
			platform.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			// move right...
			platform.moveRight();
		}
		
		if (ball.getPosition().top > windowHeight)
		{
			// reverse the ball direction
			ball.reboundBatOrTop();
			// Remove a life
			lives--;
			if (lives == 0)
			{
				window.close();
				while (window.isOpen())
					score++;
				cout << "You lose :(" << endl;
				cout << "Your score: " << score << endl;
				
			}
			if (score == (windowHeight*windowWidth))
			{
				window.close();
				cout << "You won, congratulation" << endl;
			}
		}

		// Handle ball hitting the bottom

		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();

			// Add a point to the players score

		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
		{
			ball.reboundSides();
		}

		// Has the ball hit the bat?
		if (ball.getPosition().intersects(platform.getPosition()))
		{
			ball.reboundBatOrTop();
		}

		for (int i = 0; i < block.size(); ++i)
		{
			if (ball.getPosition().intersects(block[i].getPosition()))
			{
				vector<Block>count;
				ball.reboundBatOrTop();
				block.erase(block.begin() + i);
				score++;
			}
		}
		
		///////////////////

		menu.menu(window1, window);
		ball.update();
		platform.update();

		// Update the HUD text

		window.clear(Color::Black);

		window.draw(platform.getShape());

		window.draw((ball.getShape()));

		window.draw(text);

		window.draw(text1);



		for (int i = 0; i < block.size(); ++i)
		{
			window.draw(block[i].getShape());
		}

		// Show everything we just drew
		window.display();
		window1.display();

	}// This is the end of the "while" loop

	system("pause");
	return 0;
}
