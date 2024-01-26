/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:35:28 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 11:28:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"

static sf::Color hexToRgb(const unsigned int num) {
	const unsigned char r = num >> 16 & 0xFF;
	const unsigned char g = num >> 8 & 0xFF;
	const unsigned char b = num & 0xFF;
	return sf::Color(r, g, b);
}

// Public methods

Grid::Grid(sf::RenderWindow &window):
	window(window), width(DEFAULT_SIZE),
	height(DEFAULT_SIZE) {

	initColors();
	initCellGrids();
}

Grid::Grid(sf::RenderWindow &window, const size_t width, const size_t height):
	window(window), width(width),
	height(height) {

	initColors();
	initCellGrids();
}

void Grid::update() {

	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			updateCell(grid[i][j], j, i);
		}
	}
	refresh();
}

void Grid::refresh() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j)
			grid[i][j].refresh();
	}
}

void Grid::reset() {

	grid.clear();
	resetCellGrid();
}

void Grid::display_background() {

	sf::RectangleShape background(sf::Vector2f(width * cellSize, height * cellSize));
	background.setPosition(topLeftX, topLeftY);
	background.setOutlineColor(borderColor); // Set the outline color
	background.setOutlineThickness(borderThick); // Set the outline thickness
	background.setFillColor(backgroundColor);
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

void Grid::toggleCells() {
	const std::vector<sf::Vector2i> mousePos = Config::getMousePos();

	for (std::vector<sf::Vector2i>::const_iterator it = mousePos.begin();
	it != mousePos.end(); ++it) {
		const sf::Vector2f worldPos = window.mapPixelToCoords(*it);
		if (isInGridScreen(worldPos.x, worldPos.y)) {
			const float gridX = (worldPos.x - topLeftX) / (float)cellSize;
			const float gridY = (worldPos.y - topLeftY) / (float)cellSize;
			grid[gridY][gridX].toggleState();
			grid[gridY][gridX].draw(window);
		}
	}
}

// Private

void Grid::initColors() {

	backgroundColor = hexToRgb(Config::getParameterVal(BACKGROUND_COLOR_NAME));
	borderColor = hexToRgb(Config::getParameterVal(BORDER_COLOR_NAME));
	cellColor = hexToRgb(Config::getParameterVal(CELL_COLOR_NAME));
}

void Grid::updateCell(Cell &cell, const size_t x, const size_t y) {
	const std::vector<Cell> livingCells = getSurroundingLivingCells(x, y);
	const size_t livingCellCount = livingCells.size();

	if (livingCellCount < 2 || livingCellCount > 3) {
		cell.setNextState(DEAD);
	} else if (cell.isAlive() == false && livingCellCount == 3) {
		cell.setNextState(ALIVE);
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

void Grid::initCellGrids() {

	for (size_t i = 0; i < height; ++i) {
		std::vector<Cell> row;
		for (size_t j = 0; j < width; ++j) {
			const float posX = j * cellSize + topLeftX;
			const float posY = i * cellSize + topLeftY;
			Cell cell(cellSize, cellColor);
			cell.setScreenPosition(posX, posY);
			cell.setCellColor(cellColor);
			cell.setState(lifeProba);
			row.push_back(cell);
		}
		grid.push_back(row);
		init_grid.push_back(row);
	}
}

void Grid::resetCellGrid() {
	grid = init_grid;
}

bool Grid::isInGridScreen(const size_t x, const size_t y) {

	return x > topLeftX && x < topLeftX + width * CELL_SIZE
	&& y > topLeftY && y < topLeftY + height * CELL_SIZE;
}
