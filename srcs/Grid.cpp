#include "Grid.hpp"

Grid::Grid(sf::RenderWindow &window): window(window), height(DEFAULT_SIZE), width(DEFAULT_SIZE) {}

Grid::Grid(sf::RenderWindow &window, const size_t height, const size_t width): window(window), height(height), width(width) {}

void Grid::display() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
			cell.setPosition(i * cellSize + xOffset, j * cellSize + yOffset);
			window.draw(cell);
		}
	}
}

Grid::~Grid() {}
