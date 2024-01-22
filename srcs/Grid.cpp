/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:35:28 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 00:17:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"

// Static methods

size_t countLivingCells(const std::vector<Cell *> cells) {
	size_t count = 0;
	for (std::vector<Cell *>::const_iterator it = cells.begin();
		it != cells.end(); ++it)
			count += (*it)->isAlive();
	return count;
}

// Public methods

Grid::Grid(sf::RenderWindow &window):
	window(window), width(DEFAULT_SIZE),
	height(DEFAULT_SIZE) { initCellGrid(); }

Grid::Grid(sf::RenderWindow &window, const size_t width, const size_t height):
	window(window), width(width),
	height(height) { initCellGrid(); }

void Grid::display() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			updateCell(grid[i][j], i, j);
			grid[i][j].draw(window);
		}
	}
}

Grid::~Grid() {}

// Private methods

void Grid::initCellGrid() {

	for (size_t i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for (size_t j = 0; j < width; ++j) {
			const float posX = j * CELL_SIZE + centerX;
			const float posY = i * CELL_SIZE + centerY;
			Cell cell(j, i);
			cell.setScreenPosition(posX, posY);
			cell.setState();
			row.push_back(cell);
		}
		grid.push_back(row);
	}
}

std::vector<Cell *> Grid::getSurroundingCells(const size_t x, const size_t y) {

	std::vector<Cell *> surroundingCells;

	// Define the directions to check (up, down, left, right, and the four diagonals)
	std::vector<std::pair<int, int>> directions
		= {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

	for (std::vector<std::pair<int, int>>::const_iterator it = directions.begin();
		it != directions.end(); ++it) {
		int newX = x + it->first;
		int newY = y + it->second;

		// Check if the new indices are within the grid
		if (newY >= 0 && (size_t)newY < height && newX >= 0 && (size_t)newX < width) {
			surroundingCells.push_back(&(grid[newY][newX]));
		}
	}
	return surroundingCells;
}

void Grid::updateCell(Cell &cell, const size_t x, const size_t y) {
	const std::vector<Cell *> surroundingCells = getSurroundingCells(x, y);
	const size_t livingCellCount = countLivingCells(surroundingCells);
	if ((cell.isAlive() && livingCellCount == 2) || livingCellCount == 3)
		cell.setState(ALIVE);
	else
		cell.setState(DEAD);
}
