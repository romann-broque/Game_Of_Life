/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:48:37 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 00:59:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

bool Config::_isPaused = false;
bool Config::_isReset = false;
size_t Config::_tickTime = DEFAULT_TICK_TIME;
std::map<std::string, unsigned int> Config::_argNb = {
	{WINDOW_WIDTH_NAME, WINDOW_WIDTH},
	{WINDOW_HEIGHT_NAME, WINDOW_HEIGHT},
	{GRID_WIDTH_NAME, GRID_WIDTH},
	{GRID_HEIGHT_NAME, GRID_HEIGHT},
	{CELL_SIZE_NAME, CELL_SIZE},
	{LIFE_PROBA_NAME, LIFE_PROBA},
	{BORDER_THICK_NAME,  BORDER_THICKNESS},
	{BORDER_COLOR_NAME, BORDER_COLOR},
	{BACKGROUND_COLOR_NAME, BACKGROUND_COLOR},
	{CELL_COLOR_NAME, CELL_COLOR}
};

// Static methods

bool startsWithDoubleDash(const std::string& str) {
    return str.compare(0, 2, "--") == 0;
}

static bool isValidUnsignedInt(const std::string& str) {

	try {
		auto value = std::stol(str);
		return value > 0;
	} catch (const std::invalid_argument&) {
		return false;
	} catch (const std::out_of_range&) {
		return false;
	}
}

static unsigned int hexToDec(const std::string& hexStr) {
	std::stringstream ss;
	unsigned int decNum;
	ss << std::hex << hexStr;
	ss >> decNum;
	return decNum;
}

static bool isHexadecimal(const std::string& str) {
	for (char c : str) {
		if (!(std::isxdigit(c))) {
			return false;
		}
	}
	return true;
}

static bool isHexKey(const std::string& key) {
	return key == BACKGROUND_COLOR_NAME
	|| key == BORDER_COLOR_NAME
	|| key == CELL_COLOR_NAME;
}

// Public methods

void Config::init(char **av) {

	size_t i = 0;

	while (av[i]) {
		std::string arg = av[i];
		size_t pos = arg.find('=');

		if (pos == std::string::npos)
			throw InvalidFormatException();

		std::string key = arg.substr(0, pos);
		if (startsWithDoubleDash(key) == false)
			throw InvalidFormatException();
		key = key.substr(2);
		if (_argNb.find(key) == _argNb.end()) {
			throw InvalidParameterException();
		}
		std::string value = arg.substr(pos + 1);
		associateValueToKey(key, value);
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

unsigned int Config::getParameterVal(const std::string &paramName) {
	if (_argNb.find(paramName) == _argNb.end())
		throw InvalidParameterRequestException();
	return _argNb[paramName];
}

// Private methods

void Config::associateValueToKey(const std::string &key, const std::string &value) {

	if (isHexKey(key)) {
		if (isHexadecimal(value) == false)
			throw InvalidValueException();
		const unsigned int numericValue = hexToDec(value);
		assignValueToKey(key, numericValue);
	} else if (isValidUnsignedInt(value)) {
		const unsigned int numericValue = std::stoul(value);
		assignValueToKey(key, numericValue);
	} else {
		throw InvalidValueException();
	}
}
void Config::assignValueToKey(const std::string &key, const unsigned int value) {

	if (key == LIFE_PROBA_NAME && value > 100)
		throw InvalidValueException();
	_argNb[key] = value;
}
