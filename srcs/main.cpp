#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "KeyHandler.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	Grid mainGrid(window, GRID_HEIGHT, GRID_WIDTH);
	KeyHandler handler(window);
	while (window.isOpen()) {
		handler.processEvents();
		if (Config::isPaused() == false) {
			window.clear(); // Clear the window
			mainGrid.display();
			window.display(); // Display the contents of the window
			usleep(TICK_TIME);
		}
	}
	return 0;
}
