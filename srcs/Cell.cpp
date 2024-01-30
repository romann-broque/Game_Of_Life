/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:23 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/27 02:400 by rbroque          ###   ########.fr       */
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

Cell::Cell(const t_cellParameter &params):
	_params(params), _color(_params.lifeColor),
	_state(ALIVE), _nextState(ALIVE),
	_age(0), _livingCount(0), _foodCount(0), _deadCount(0) {

	setCellColor(_color);
}

Cell &Cell::operator=(const Cell &cell) {
	this->_state = cell._state;
	this->_age = cell._age;
	return *this;
}

// Destructor

Cell::~Cell() {}

// Setters

void Cell::setCellColor(const sf::Color newColor) {

	_color = newColor;
}

void Cell::setCellStateColor(const t_state state) {

	if (state == ALIVE) {
		_color = _params.lifeColor;
	} else if (state == FOOD) {
		_color = _params.foodColor;
	}
}

void Cell::refresh() {
	_state = _nextState;
	update();
}

void Cell::setNextState(const t_state newState) {
	_nextState = newState;
}

void Cell::initState(const unsigned char lifeProba) {

	std::random_device rd; // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(1, 100);

	const unsigned int randomNumber = distrib(gen);
	if (randomNumber <= lifeProba) {
		_state = ALIVE;
	} else if (_params.foodPresence && randomNumber <= lifeProba + _params.foodProba) {
		_state = FOOD;
	} else {
		_state = DEAD;
	}
	_nextState = _state;
	update();
}

void Cell::toggleState() {
	if (_state == ALIVE) {
		_state = DEAD;
		_nextState = DEAD;
	}
	else {
		_state = ALIVE;
		_nextState = ALIVE;
		if (_age == 0)
			setCellStateColor(ALIVE);
	}
}

// Getters

t_state Cell::getState() const {
	return _state;
}

sf::Color Cell::getColor() const {
	return _color;
}

bool Cell::canBeDrawn() const {
	return (_state != DEAD);
}

// Actions

void Cell::evolve(const size_t livingCount, const size_t foodCount, const size_t deadCount) {

	static const std::map<t_state, void (Cell::*)()> mapState = {
		{ALIVE, &Cell::lifeRoutine},
		{FOOD, &Cell::foodRoutine},
		{DEAD, &Cell::deadRoutine}
	};

	_livingCount = livingCount;
	_foodCount = foodCount;
	_deadCount = deadCount;
	_nextState = _state;
	(this->*(mapState.at(_state)))();
}

// Private

void Cell::changeBrightness(const int lightFactor) {

	sf::Color newColor = _color;

	newColor.r = newColorComponentBrightness(newColor.r, lightFactor);
	newColor.g = newColorComponentBrightness(newColor.g, lightFactor);
	newColor.b = newColorComponentBrightness(newColor.b, lightFactor);
	setCellColor(newColor);
}

void Cell::update() {
	if (_state == ALIVE) {
		if (_age == 0)
			setCellStateColor(ALIVE);
		++_age;
		if (_params.darkening)
			changeBrightness(DARK_FACTOR);
	} else if (_state == DEAD) {
		_age = 0;
	} else if (_state == FOOD) {
		_age = 0;
		setCellStateColor(FOOD);
	}
}

void Cell::lifeRoutine() {
	if (_params.foodPresence && _params.foodConv && _age > _params.cellLifetime) {
		if (_params.foodConv)
			setNextState(FOOD);
		else
			setNextState(DEAD);
	} else if (_params.foodPresence && _foodCount > 0)
		setNextState(ALIVE);
	else if (_livingCount < 2 || _livingCount > 3)
		setNextState(DEAD);
}

void Cell::foodRoutine() {
	if (_livingCount >= 2)
		setNextState(DEAD);
}

void Cell::deadRoutine() {
	if (_params.foodPresence && _foodCount > 5)
		setNextState(FOOD);
	else if (_livingCount == 3)
		setNextState(ALIVE);
}
