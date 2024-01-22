#include <SFML/Graphics.hpp>
#include <unistd.h>

#define DEFAULT_SIZE 4
#define CELL_SIZE	 20.0f

class Grid {
	public:
		Grid(sf::RenderWindow &window);
		Grid(sf::RenderWindow &window, const size_t height, const size_t width);
		void display();
		~Grid();

	private:
		sf::RenderWindow &window;
		const size_t height;
		const size_t width;
		const float cellSize = CELL_SIZE;
		const size_t xOffset = 100;
		const size_t yOffset = 100;
};
