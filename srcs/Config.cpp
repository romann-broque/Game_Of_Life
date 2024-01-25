/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:48:37 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 17:14:50 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

bool Config::_isPaused = false;
bool Config::_isReset = false;
size_t Config::_tickTime = DEFAULT_TICK_TIME;
std::map<std::string, unsigned int> Config::_argNb;

void Config::init(char **av) {

	_argNb["WindowWidth"] = WINDOW_WIDTH;
	_argNb["WindowHeight"] = WINDOW_HEIGHT;
	_argNb["GridWidth"] = GRID_WIDTH;
	_argNb["GridHeight"] = GRID_HEIGHT;
	_argNb["CellSize"] = CELL_SIZE;

	size_t i = 0;

	while (av[i]) {
		std::string arg = av[i];
		size_t pos = arg.find('=');

		if (pos != std::string::npos) {
			std::string key = arg.substr(0, pos);
			std::string value = arg.substr(pos + 1);
			unsigned int numericValue = std::stoul(value);


			// Store key-value pair in the map
			_argNb[key] = numericValue;
		}
		++i;
	}
}

// Setters

void Config::togglePaused() {
	_isPaused = !_isPaused;
}

void Config::reset() {
	_isReset = true;
}

void Config::setResetState(const bool newState) {
	_isReset = newState;
}

void Config::slowTime() {
	if (_tickTime < TICK_TIME_MAX)
		_tickTime *= TIME_FACTOR;
}

void Config::accelerateTime() {
	if (_tickTime <= TIME_FACTOR)
		_tickTime = 1;
	else
		_tickTime /= TIME_FACTOR;
}

// Getters

bool Config::isPaused() {
	return _isPaused;
}

bool Config::isReset() {
	return _isReset;
}

size_t Config::getTickTime() {
	return _tickTime;
}

unsigned int Config::getWindowWidth() {
	return _argNb["WindowWidth"];
}

unsigned int Config::getWindowHeight() {
	return _argNb["WindowHeight"];
}

unsigned int Config::getGridWidth() {
	return _argNb["GridWidth"];
}

unsigned int Config::getGridHeight() {
	return _argNb["GridHeight"];
}

unsigned int Config::getCellSize() {
	return _argNb["CellSize"];
}
