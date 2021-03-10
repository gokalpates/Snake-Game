#include "Game.hpp"

#include <iostream>

fw::Game::Game()
{
	initialise();
}

void fw::Game::run()
{
	while (window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
}

void fw::Game::initialise()
{
	videoMode = sf::VideoMode::getDesktopMode();
	window.create(videoMode, "SFML",sf::Style::Fullscreen);
	window.setFramerateLimit(5);

	background.setFillColor(sf::Color::Black);
	background.setSize(sf::Vector2f((float)videoMode.width, (float)videoMode.height));
}

void fw::Game::handleEvents()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
	}
}

void fw::Game::update()
{
	food.update();
	snake.update(food.getFoods());
	if (!background.getGlobalBounds().intersects(snake.getHeadOfSnake().getGlobalBounds()))
	{
		std::cout << "GAME OVER! Your score is: " << snake.getPoint() << "\n";
		std::exit(0);
	}
}

void fw::Game::render()
{
	window.clear(sf::Color::Black);

	food.draw(window);
	snake.draw(window);

	window.display();
}

