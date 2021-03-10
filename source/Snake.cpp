#include "Snake.hpp"

#include <iostream>
#include <thread>

game::Snake::Snake():
	point(0u)
{
	generateSnake();
	
	//Running determineDirection() function concurrently to get smoother inputs.
	std::thread t1(&Snake::determineDirection,this);
	if (t1.joinable())
		t1.detach();
}

game::Snake::~Snake()
{
	snakeTiles.clear();
}

void game::Snake::update(std::vector<sf::RectangleShape>& foodLocations)
{
	/*
	* You can do jobs in single thread if you use determineDirection() function here.
	* But it will cause more coarse inputs.	
	*/
	if (isEat(foodLocations))
	{
		point++;
		addTileToTail();
	}
	updateTilePositions();
	if (isDead())
	{
		std::cout << "WHERE ARE YOU GOING? GAME OVER! Your score is: " << point << "\n";
		std::exit(0);
	}
}

void game::Snake::draw(sf::RenderWindow& target)
{
	for (size_t i = 0; i < snakeTiles.size(); i++)
	{
		target.draw(snakeTiles[i]);
	}
}

sf::RectangleShape& game::Snake::getHeadOfSnake()
{
	return snakeTiles[0];
}

size_t game::Snake::getPoint()
{
	return point;
}

void game::Snake::generateSnake()
{
	snakeDirection = Right;

	sf::RectangleShape head(sf::Vector2f(80.f, 80.f));
	head.setFillColor(sf::Color::Red);
	head.setOutlineThickness(-5.f);
	head.setOutlineColor(sf::Color::Black);

	head.setPosition(sf::Vector2f((float)sf::VideoMode::getDesktopMode().width / 2.f, (float)sf::VideoMode::getDesktopMode().height / 2.f));
	
	snakeTiles.push_back(head);
}

void game::Snake::determineDirection()
{
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (snakeDirection != Down))
		{
			snakeDirection = Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (snakeDirection != Left))
		{
			snakeDirection = Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (snakeDirection != Up))
		{
			snakeDirection = Down;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (snakeDirection != Right))
		{
			snakeDirection = Left;
		}
	}
}

void game::Snake::updateTilePositions()
{
	for (int i = (snakeTiles.size() - 1); i >= 0; i--)
	{
		if (i == 0)
		{
			if (snakeDirection == Up)
			{
				snakeTiles[0].move(0.f, -80.f);
			}
			else if (snakeDirection == Right)
			{
				snakeTiles[0].move(80.f, 0.f);
			}
			else if (snakeDirection == Down)
			{
				snakeTiles[0].move(0.f, 80.f);
			}
			else
			{
				snakeTiles[0].move(-80.f, 0.f);
			}
		}
		else
		{
			snakeTiles[i].setPosition(snakeTiles[i - 1].getPosition());
		}
	}
}

bool game::Snake::isEat(std::vector<sf::RectangleShape>& foodLocations)
{
	for (size_t i = 0; i < foodLocations.size(); i++)
	{
		if (snakeTiles[0].getGlobalBounds().intersects(foodLocations[i].getGlobalBounds()))
		{
			foodLocations.erase(foodLocations.begin() + i);
			return true;
		}
	}
	return false;
}

bool game::Snake::isDead()
{
	for (size_t i = 1; i < snakeTiles.size(); i++)
	{
		if (snakeTiles[0].getGlobalBounds().intersects(snakeTiles[i].getGlobalBounds()))
		{
			return true;
		}
	}
	return false;
}

void game::Snake::addTileToTail()
{
	sf::RectangleShape tail(sf::Vector2f(80.f, 80.f));
	tail.setFillColor(sf::Color::Red);
	tail.setOutlineThickness(-5.f);
	tail.setOutlineColor(sf::Color::Black);

	int index = snakeTiles.size() - 1;
	tail.setPosition(snakeTiles[index].getPosition());

	snakeTiles.push_back(tail);
}
