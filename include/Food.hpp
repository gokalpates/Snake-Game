#pragma once

#include <SFMLModules.hpp>
#include <vector>
#include <cstdlib>

namespace game
{
	class Food
	{
	public:

		~Food();

		void update();
		void draw(sf::RenderWindow& target);

		std::vector<sf::RectangleShape>& getFoods();

	private:

		void generateFood();

		std::vector <sf::RectangleShape> foods;

	};
}


