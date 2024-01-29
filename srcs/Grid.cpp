/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:35:28 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 11:26:21 by rbroque          ###   ########.fr       */
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

Grid::Grid(sf::RenderWindow &window, const size_t width, const size_t height):
	_width(width),
	_height(height),
	window(window) {

	initColors();
	initCellGrids();
}

void Grid::update() {

	preArrange();
	arrange();
}

void Grid::reset() {

	grid.clear();
	resetCellGrid();
}

void Grid::draw_background() {

	sf::RectangleShape background(sf::Vector2f(_width * cellSize, _height * cellSize));
	background.setPosition(topLeftX, topLeftY);
	background.setOutlineColor(borderColor); // Set the outline color
	background.setOutlineThickness(borderThick); // Set the outline thickness
	background.setFillColor(backgroundColor);
	window.draw(background);
}

void Grid::draw_grid() {

	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j) {
			const Cell cell = grid[i][j];
			if (cell.canBeDrawn()) {
				drawCell(j, i);
			}
		}
	}
}

void Grid::draw() {
	draw_background();
	draw_grid();
}

void Grid::toggleCells() {
	const std::vector<sf::Vector2i> mousePos = Config::getMousePos();

	for (std::vector<sf::Vector2i>::const_iterator it = mousePos.begin();
	it != mousePos.end(); ++it) {
		const sf::Vector2f worldPos = window.mapPixelToCoords(*it);
		const size_t gridX = (worldPos.x - topLeftX) / cellSize;
		const size_t gridY = (worldPos.y - topLeftY) / cellSize;
		if (isInGridScreen(gridX, gridY)) {
			grid[gridY][gridX].toggleState();
			drawCell(gridX, gridY);
		}
	}
}

// Private

void Grid::initColors() {

	backgroundColor = hexToRgb(Config::getParameterVal(BACKGROUND_COLOR_NAME));
	borderColor = hexToRgb(Config::getParameterVal(BORDER_COLOR_NAME));
	cellColor = hexToRgb(Config::getParameterVal(CELL_COLOR_NAME));
	foodColor = hexToRgb(Config::getParameterVal(FOOD_COLOR_NAME));
}

void Grid::drawCell(const size_t x, const size_t y) {
	const Cell cell = grid[y][x];
	const float posX = x * cellSize + topLeftX;
	const float posY = y * cellSize + topLeftY;
	sf::RectangleShape	cellScreen(sf::Vector2f(cellSize, cellSize));
	cellScreen.setFillColor(cell.getColor());
	cellScreen.setPosition(posX, posY);
	window.draw(cellScreen);
}

void Grid::updateCell(Cell &cell, const size_t x, const size_t y) {
	const std::vector<Cell> surroundingCells = getSurroundingCells(x, y);
	const size_t livingCellCount = countStateCells(surroundingCells, ALIVE);
	const size_t foodCellCount = countStateCells(surroundingCells, FOOD);
	const size_t deadCellCount = fabs(livingCellCount - foodCellCount);

	cell.evolve(livingCellCount, foodCellCount, deadCellCount);
}

std::vector<Cell> Grid::getSurroundingCells(const size_t x, const size_t y) {

	const std::vector<std::pair<int, int>> directions
		= {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	std::vector<Cell> surroundingCells;

	for (std::vector<std::pair<int, int>>::const_iterator it = directions.begin();
		it != directions.end(); ++it) {
		const int newX = x + it->first;
		const int newY = y + it->second;
		const size_t finalX = (newX + _width) % _width;
		const size_t finalY = (newY + _height) % _height;
		surroundingCells.push_back(grid[finalY][finalX]);
	}
	return surroundingCells;
}

void Grid::initCellGrids() {

	for (size_t i = 0; i < _height; ++i) {
		std::vector<Cell> row;
		for (size_t j = 0; j < _width; ++j) {
			Cell cell( cellColor);
			cell.setCellStateColor(FOOD, foodColor);
			cell.setCellStateColor(ALIVE, cellColor);
			cell.initState(lifeProba);
			row.push_back(cell);
		}
		grid.push_back(row);
		init_grid.push_back(row);
	}
}

void Grid::preArrange() {

	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j) {
			updateCell(grid[i][j], j, i);
		}
	}
}

void Grid::arrange() {
	for (size_t i = 0; i < _height; ++i) {
		for (size_t j = 0; j < _width; ++j)
			grid[i][j].refresh();
	}
}

void Grid::resetCellGrid() {
	grid = init_grid;
}

bool Grid::isInGridScreen(const size_t x, const size_t y) {
	return x < _width && y < _height;
}

size_t Grid::countStateCells(const std::vector<Cell> &surroundingCells, const t_state state) {
	size_t	count = 0;

	for (std::vector<Cell>::const_iterator it = surroundingCells.begin();
		it != surroundingCells.end(); ++it) {
		count += (it->getState() == state);
	}
	return count;
}
