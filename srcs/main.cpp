#include <SFML/Graphics.hpp>
#include "Grid.hpp"

void draw_in_window(sf::RenderWindow &window) {
	// Draw your graphics here
	Grid mainGrid(window, 40, 21);
	mainGrid.display();
}

int main() {

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(); // Clear the window
		draw_in_window(window);
		window.display(); // Display the contents of the window
	}
	return 0;
}
