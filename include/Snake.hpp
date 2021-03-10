#pragma once

#include <SFMLModules.hpp>
#include <vector>

namespace game
{
	class Snake
	{
	public:

		Snake();
		~Snake();

		void update(std::vector<sf::RectangleShape>& foodLocations);
		void draw(sf::RenderWindow& target);

		sf::RectangleShape& getHeadOfSnake();
		size_t getPoint();

	private:

		enum Direction
		{
			Up = 0,
			Right = 1,
			Down = 2,
			Left = 3
		};

		int snakeDirection;
		size_t point;

		void generateSnake();

		void determineDirection();
		void updateTilePositions();

		bool isEat(std::vector<sf::RectangleShape>& foodLocations);
		bool isDead();

		void addTileToTail();

		std::vector<sf::RectangleShape> snakeTiles;

	};
}

