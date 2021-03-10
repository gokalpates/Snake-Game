#pragma once

#include <SFMLModules.hpp>
#include <Snake.hpp>
#include <Food.hpp>

namespace fw
{
	class Game
	{
	public:

		//Constructor.
		Game();

		//Game loop.
		void run();

	private:
		//Initialising member variables, setting some window flags, etc. in the Game Class constructor.
		void initialise();

		//Utility functions that used in game loop.
		void handleEvents();
		void update();
		void render();

		//Fundamental variables to create window and handle events.
		sf::RenderWindow window;
		sf::VideoMode videoMode;
		sf::Event event;

		//Game assets.
		sf::RectangleShape background;
		game::Snake snake;
		game::Food food;
	};
}

