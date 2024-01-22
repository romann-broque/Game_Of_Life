#include "Grid.hpp"

// Public methods

Grid::Grid(sf::RenderWindow &window): window(window), width (DEFAULT_SIZE), height(DEFAULT_SIZE) {}

Grid::Grid(sf::RenderWindow &window, const size_t width, const size_t height): window(window), width(width), height(height) {}

void Grid::display() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			Cell cell(i, j);
			const float posX = j * CELL_SIZE + centerX;
			const float posY = i * CELL_SIZE + centerY;
			cell.setScreenPosition(posX, posY);
			if (i % 2)
				cell.setCellColor(sf::Color::Red);
			else if (j % 2)
				cell.setCellColor(sf::Color::Blue);
			cell.draw(window);
		}
	}
}

Grid::~Grid() {}
