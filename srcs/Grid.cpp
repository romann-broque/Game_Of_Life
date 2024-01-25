/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:35:28 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 11:26:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"

// Public methods

Grid::Grid(sf::RenderWindow &window):
	window(window), width(DEFAULT_SIZE),
	height(DEFAULT_SIZE) { initCellGrids(); }

Grid::Grid(sf::RenderWindow &window, const size_t width, const size_t height):
	window(window), width(width),
	height(height) { initCellGrids(); }

void Grid::update() {

	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			updateCell(grid_temp[i][j], j, i);
		}
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			grid[i][j] = grid_temp[i][j];
		}
	}
}

void Grid::display_background() {
	sf::RectangleShape background(sf::Vector2f(width * CELL_SIZE, height * CELL_SIZE));
	background.setPosition(topLeftX, topLeftY);
	background.setFillColor(sf::Color::Blue);
	window.draw(background);
}

void Grid::display_grid() {

	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			grid[i][j].draw(window);
		}
	}
}

void Grid::display() {
	display_background();
	display_grid();
}

Grid::~Grid() {}

// Private methods

void Grid::initCellGrids() {

	for (size_t i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for (size_t j = 0; j < width; ++j) {
			const float posX = j * CELL_SIZE + topLeftX;
			const float posY = i * CELL_SIZE + topLeftY;
			Cell cell;
			cell.setScreenPosition(posX, posY);
			cell.setState();
			row.push_back(cell);
		}
		grid.push_back(row);
		grid_temp.push_back(row);
	}
}

std::vector<Cell> Grid::getSurroundingLivingCells(const size_t x, const size_t y) {

	const std::vector<std::pair<int, int>> directions
		= {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	std::vector<Cell> surroundingCells;

	for (std::vector<std::pair<int, int>>::const_iterator it = directions.begin();
		it != directions.end(); ++it) {
		const int newX = x + it->first;
		const int newY = y + it->second;
		const size_t finalX = (newX + width) % width;
		const size_t finalY = (newY + height) % height;
		if (grid[finalY][finalX].isAlive())
			surroundingCells.push_back(grid[finalY][finalX]);
	}
	return surroundingCells;
}

void Grid::updateCell(Cell &cell, const size_t x, const size_t y) {
	const std::vector<Cell> livingCells = getSurroundingLivingCells(x, y);
	const size_t livingCellCount = livingCells.size();

	if (livingCellCount < 2 || livingCellCount > 3) {
		cell.setState(DEAD);
	}
	else if (cell.isAlive() == false && livingCellCount == 3)
		cell.setState(ALIVE);
}

