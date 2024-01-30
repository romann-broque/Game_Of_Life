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

// Constructor

Cell::Cell(const t_cellParameter &params):
	_params(params), _color(_params.lifeColor),
	_state(ALIVE), _nextState(ALIVE), _age(0) {}

Cell &Cell::operator=(const Cell &cell) {
	this->_state = cell._state;
	this->_age = cell._age;
	return *this;
}

// Destructor

Cell::~Cell() {}

// Setters

void Cell::refresh() {
	_state = _nextState;
	update();
}

void Cell::setNextState(const t_state newState) {
	_nextState = newState;
}

void Cell::setNeighborhood(const std::vector<Cell *> &surroundingCells) {
	for (size_t i = 0; i < 8; ++i) {
		_neighboors[i] = surroundingCells[i];
	}
}

void Cell::setRandomState() {

	std::random_device rd; // Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(1, 100);
	const unsigned int randomNumber = distrib(gen);

	if (randomNumber <= _params.lifeProba) {
		_state = ALIVE;
	} else if (_params.foodPresence && randomNumber <= _params.lifeProba + _params.foodProba) {
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

void Cell::evolve() {

	static const std::map<t_state, void (Cell::*)()> mapState = {
		{ALIVE, &Cell::lifeRoutine},
		{FOOD, &Cell::foodRoutine},
		{DEAD, &Cell::deadRoutine}
	};

	scanNeighborhood();
	_nextState = _state;
	(this->*(mapState.at(_state)))();
}

// Private

// Colors //

void Cell::changeBrightness(const int lightFactor) {

	sf::Color newColor = _color;

	newColor.r = newColorComponentBrightness(newColor.r, lightFactor);
	newColor.g = newColorComponentBrightness(newColor.g, lightFactor);
	newColor.b = newColorComponentBrightness(newColor.b, lightFactor);
	setCellColor(newColor);
}

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

// Update

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

void Cell::scanNeighborhood() {
	_neighboorCount[ALIVE] = countStateCells(ALIVE);
	_neighboorCount[FOOD] = countStateCells(FOOD);
	_neighboorCount[DEAD] = countStateCells(DEAD);
}

// Routines //

void Cell::lifeRoutine() {
	if (_params.foodPresence && _params.foodConv && _age > _params.cellLifetime) {
		if (_params.foodConv)
			setNextState(FOOD);
		else
			setNextState(DEAD);
	} else if (_params.foodPresence && _neighboorCount[FOOD] > 0)
		setNextState(ALIVE);
	else if (_neighboorCount[ALIVE] < 2 || _neighboorCount[ALIVE] > 3)
		setNextState(DEAD);
}

void Cell::foodRoutine() {
	if (_neighboorCount[ALIVE] >= 2)
		setNextState(DEAD);
}

void Cell::deadRoutine() {
	if (_params.foodPresence && _neighboorCount[FOOD] > 5)
		setNextState(FOOD);
	else if (_neighboorCount[ALIVE] == 3)
		setNextState(ALIVE);
}

size_t Cell::countStateCells(const t_state state) const {
	size_t	count = 0;

	for (size_t i = 0; i < NEIGHBOOR_COUNT; ++i) {
		count += (_neighboors[i]->getState() == state);
	}
	return count;
}

unsigned char Cell::newColorComponentBrightness(const unsigned char color, const int lightFactor) {
	unsigned int newColor = color;
	if (newColor + lightFactor > MIN_COLOR_COMP && newColor + lightFactor < MAX_COLOR_COMP) {
		newColor += lightFactor;
	}
	return newColor;
}
