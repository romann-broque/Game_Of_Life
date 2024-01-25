/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:23 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 19:38:24 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cell.hpp"

// Constructor

Cell::Cell(const size_t cellSize):
	_cellScreen(sf::Vector2f(cellSize, cellSize)), _color(CELL_COLOR), _state(ALIVE), _age(0) {}

Cell &Cell::operator=(const Cell &cell) {
	this->_state = cell._state;
	this->_cellScreen = cell._cellScreen;
	this->_age = cell._age;
	return *this;
}

// Destructor

Cell::~Cell() {}

// Setters

void Cell::setScreenPosition(const float screenX, const float screenY) {
	_cellScreen.setPosition(screenX, screenY);
}

void Cell::setCellColor(const sf::Color color) {
	_color = color;
	_cellScreen.setFillColor(_color);
}

void Cell::changeBrightness(const int lightFactor) {

	sf::Color newColor = _color;

	if (newColor.r < 10)
		newColor.r -= lightFactor;
	if (newColor.g < 10)
		newColor.g -= lightFactor;
	if (newColor.b > 10)
		newColor.b -= lightFactor;
	setCellColor(newColor);
}

void Cell::setState(const t_state state) {
	_state = state;
}

void Cell::setState() {
	std::random_device rd; // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(1, 100);

	const int randomNumber = distrib(gen);
	const int probFactor = 100 / LIFE_PROBA;

	_state = randomNumber % probFactor == 0 ? ALIVE : DEAD;
}

// Getters

bool Cell::isAlive() const {
	return _state == ALIVE;
}

size_t Cell::getAge() const {
	return _age;
}

// Actions

void Cell::draw(sf::RenderWindow &window) {
	if (isAlive())
	{
		changeBrightness(DARK_FACTOR);
		++_age;
		window.draw(_cellScreen);
	} else {
		_age = 0;
		setCellColor(CELL_COLOR);
	}
}

