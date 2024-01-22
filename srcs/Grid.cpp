/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:35:28 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/22 22:42:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"

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
			// updateCell(cell, i, j);
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
			Cell cell(i, j);
			cell.setScreenPosition(posX, posY);
			row.push_back(cell);
		}
		grid.push_back(row);
	}
}

// void Grid::updateCell(Cell &cell, const size_t i, const size_t j) {

// }
