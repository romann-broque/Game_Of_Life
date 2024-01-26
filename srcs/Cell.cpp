/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:23 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 02:14:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cell.hpp"

// Static

static unsigned char newColorComponentBrightness(const unsigned char color, const int lightFactor) {
	unsigned int newColor = color;
	if (newColor + lightFactor > MIN_COLOR_COMP && newColor + lightFactor < MAX_COLOR_COMP) {
		newColor += lightFactor;
	}
	return newColor;
}

// Constructor

Cell::Cell(const size_t cellSize, const sf::Color &color):
	_cellScreen(sf::Vector2f(cellSize, cellSize)), _initColor(color), _color(color), _state(ALIVE), _nextState(ALIVE), _age(0) {

	setCellColor(_color);
}

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

	newColor.r = newColorComponentBrightness(newColor.r, lightFactor);
	newColor.g = newColorComponentBrightness(newColor.g, lightFactor);
	newColor.b = newColorComponentBrightness(newColor.b, lightFactor);
	setCellColor(newColor);
}

void Cell::refresh() {
	_state = _nextState;
	update();
}

void Cell::setNextState(const t_state newState) {
	_nextState = newState;
}

void Cell::setState(const t_state newState) {
	_state = newState;
}

void Cell::setState(const unsigned char lifeProba) {

	std::random_device rd; // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(1, 100);

	const int randomNumber = distrib(gen);
	_state = randomNumber <= lifeProba ? ALIVE : DEAD;
}

void Cell::update() {
	if (_state == ALIVE) {
		++_age;
		changeBrightness(DARK_FACTOR);
	} else if (_state == DEAD) {
		_age = 0;
		setCellColor(_initColor);
	}
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
		window.draw(_cellScreen);
}
