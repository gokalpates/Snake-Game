#include <Game.hpp>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(time(0));

	fw::Game application;
	application.run();

}