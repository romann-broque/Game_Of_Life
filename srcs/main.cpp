#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "EventLoop.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	Grid mainGrid(window, GRID_HEIGHT, GRID_WIDTH);
	EventLoop checker(window);
	while (window.isOpen()) {
		checker.checkEvent();
		if (Config::isPaused() == false) {
			window.clear(sf::Color::Black); // Clear the window
			mainGrid.display();
			window.display(); // Display the contents of the window
			usleep(TICK_TIME);
		}
	}
	return 0;
}
