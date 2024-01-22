#include <SFML/Graphics.hpp>
#include "Grid.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	Grid mainGrid(window, GRID_HEIGHT, GRID_WIDTH);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Black); // Clear the window
		mainGrid.display();
		window.display(); // Display the contents of the window
		usleep(TICK_TIME);
	}
	return 0;
}
