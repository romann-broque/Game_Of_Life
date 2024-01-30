/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:35:28 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 23:42:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"

// Public methods

Grid::Grid(sf::RenderWindow &window, const t_gridParameter &params):
	_window(window),
	_params(params) {

	initBackground();
	initCellGrids();
	initNeighboors();
}

void Grid::update() {

	preArrange();
	arrange();
}

void Grid::reset() {

	_grid.clear();
	resetCellGrid();
}

void Grid::draw_background() {
	_window.draw(_background);
}

void Grid::draw_grid() {

	forEachCell(*this, &Grid::drawCellIfNotDead);
}

void Grid::draw() {
	draw_background();
	draw_grid();
}

void Grid::toggleCell(const size_t screenX, const size_t screenY) {
	const size_t gridX = (screenX - _params.topLeftX) / _params.cellSize;
	const size_t gridY = (screenY - _params.topLeftY) / _params.cellSize;
	if (isInGridScreen(gridX, gridY)) {
		Cell *const cell = &(_grid[gridY][gridX]);
		cell->toggleState();
		drawCellIfNotDead(*cell, gridX, gridY);
	}
}

// Private

void Grid::drawCellIfNotDead(Cell &cell, const size_t x, const size_t y) {
	if (cell.canBeDrawn())
		drawCell(x, y);
}

void Grid::drawCell(const size_t x, const size_t y) {
	const Cell cell = _grid[y][x];
	const float posX = x * _params.cellSize + _params.topLeftX;
	const float posY = y * _params.cellSize + _params.topLeftY;
	sf::RectangleShape	cellScreen(sf::Vector2f(_params.cellSize, _params.cellSize));
	cellScreen.setFillColor(cell.getColor());
	cellScreen.setPosition(posX, posY);
	_window.draw(cellScreen);
}

void Grid::updateCell(
	Cell &cell,
	__attribute__((unused)) const size_t x,
	__attribute__((unused)) const size_t y) {

	cell.evolve();
}

void Grid::initCellGrids() {

	for (size_t i = 0; i < _params.height; ++i) {
		std::vector<Cell> row;
		for (size_t j = 0; j < _params.width; ++j) {
			Cell cell(_params.cellConfig);
			cell.setRandomState();
			row.push_back(cell);
		}
		_grid.push_back(row);
		_init_grid.push_back(row);
	}
}

void Grid::initNeighboors() {
	forEachCell(*this, &Grid::initCellNeighborhood);
}

void Grid::initCellNeighborhood(Cell &cell, const size_t x, const size_t y) {

	static const std::vector<std::pair<int, int>> directions
		= {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	std::vector<Cell *> surroundingCells;

	for (std::vector<std::pair<int, int>>::const_iterator it = directions.begin();
		it != directions.end(); ++it) {
		const int newX = x + it->first;
		const int newY = y + it->second;
		const size_t finalX = (newX + _params.width) % _params.width;
		const size_t finalY = (newY + _params.height) % _params.height;
		surroundingCells.push_back(&(_grid[finalY][finalX]));
	}
	cell.setNeighborhood(surroundingCells);
}

void Grid::initBackground() {

	const sf::RectangleShape background(sf::Vector2f(_params.width * _params.cellSize, _params.height * _params.cellSize));
	_background = background;
	_background.setPosition(_params.topLeftX, _params.topLeftY);
	_background.setOutlineColor(_params.borderColor); // Set the outline color
	_background.setOutlineThickness(_params.borderThick); // Set the outline thickness
	_background.setFillColor(_params.backgroundColor);
}

void Grid::preArrange() {

	forEachCell(*this, &Grid::updateCell);
}

void Grid::arrange() {
	forEachCell(*this, &Grid::refreshCell);
}

void Grid::refreshCell(
	Cell &cell,
	__attribute__((unused)) const size_t x,
	__attribute__((unused)) const size_t y) {
	cell.refresh();
}

void Grid::resetCellGrid() {
	_grid = _init_grid;
	initNeighboors();

}

bool Grid::isInGridScreen(const size_t x, const size_t y) {
	return x < _params.width && y < _params.height;
}
