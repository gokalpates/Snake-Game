#include "Food.hpp"

game::Food::~Food()
{
	foods.clear();
}

void game::Food::update()
{
	generateFood();
}

void game::Food::draw(sf::RenderWindow& target)
{
	for (size_t i = 0; i < foods.size(); i++)
	{
		target.draw(foods[i]);
	}
}

std::vector<sf::RectangleShape>& game::Food::getFoods()
{
	return foods;
}

void game::Food::generateFood()
{
	if (foods.size() < 5u)
	{
		sf::RectangleShape food(sf::Vector2f(20.f, 20.f));
		food.setFillColor(sf::Color::Green);

		float posX = 0, posY = 0;
		posX = (float)(std::rand() % sf::VideoMode::getDesktopMode().width);
		posY = (float)(std::rand() % sf::VideoMode::getDesktopMode().height);
		food.setPosition(posX, posY);

		foods.push_back(food);
	}
}
