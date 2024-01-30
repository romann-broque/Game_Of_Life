/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInputs::.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:00:23 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 16:19:51 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserInputs.hpp"

std::map<std::string, unsigned int> UserInputs::_argNb = {
	{WINDOW_WIDTH_NAME, WINDOW_WIDTH},
	{WINDOW_HEIGHT_NAME, WINDOW_HEIGHT},
	{GRID_WIDTH_NAME, GRID_WIDTH},
	{GRID_HEIGHT_NAME, GRID_HEIGHT},
	{CELL_SIZE_NAME, CELL_SIZE},
	{LIFE_PROBA_NAME, LIFE_PROBA},
	{BORDER_THICK_NAME,  BORDER_THICKNESS},
	{BORDER_COLOR_NAME, BORDER_COLOR},
	{BACKGROUND_COLOR_NAME, BACKGROUND_COLOR},
	{CELL_COLOR_NAME, CELL_COLOR},
	{DARKENING_NAME, DARKENING},
	{FOOD_NAME, FOOD_PRESENCE},
	{FOOD_COLOR_NAME, FOOD_COLOR},
	{FOOD_PROBA_NAME, FOOD_PROBA},
	{FOOD_CONV_NAME, FOOD_CONV},
	{CELL_LIFETIME_NAME, CELL_LIFETIME}
};
std::map<std::string, sf::Color> UserInputs::_argColor = {
	{BORDER_COLOR_NAME, sf::Color(BORDER_COLOR)},
	{BACKGROUND_COLOR_NAME, sf::Color(BACKGROUND_COLOR)},
	{CELL_COLOR_NAME, sf::Color(CELL_COLOR)},
	{FOOD_COLOR_NAME, sf::Color(FOOD_COLOR)}
};

// Public methods

void UserInputs::init(char **av) {

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
		const std::string value = arg.substr(pos + 1);
		associateValueToKey(key, value);
		++i;
	}
	checkParameters();
}

unsigned int UserInputs::getParameterVal(const std::string &paramName) {
	if (_argNb.find(paramName) == _argNb.end())
		throw InvalidParameterRequestException();
	return _argNb[paramName];
}

sf::Color UserInputs::getParameterColor(const std::string &paramName) {
	if (_argColor.find(paramName) == _argColor.end())
		throw InvalidParameterRequestException();
	return _argColor[paramName];
}

// Private Methods

void UserInputs::associateValueToKey(const std::string &key, const std::string &value) {

	unsigned int numericValue;

	if (key == DARKENING_NAME || key == FOOD_NAME || key == FOOD_CONV_NAME) {
		if (value != "yes" && value != "no")
			throw InvalidValueException();
		numericValue = (value == "yes");
	} else if (isHexKey(key)) {
		if (isHexadecimal(value) == false)
			throw InvalidValueException();
		const sf::Color color = hexToRgb(value);
		assignColorToKey(key, color);
		return ;
	} else if (isValidUnsignedInt(value)) {
		numericValue = std::stoul(value);
	} else {
		throw InvalidValueException();
	}
	assignValueToKey(key, numericValue);
}

void UserInputs::assignValueToKey(const std::string &key, const unsigned int value) {

	if ((key == LIFE_PROBA_NAME || key == FOOD_PROBA_NAME) && value > 100)
		throw InvalidValueException();
	_argNb[key] = value;
}

void UserInputs::assignColorToKey(const std::string &key, const sf::Color &color) {

	_argColor[key] = color;
}

void UserInputs::checkParameters() {

	if (_argNb[WINDOW_HEIGHT_NAME] < _argNb[GRID_HEIGHT_NAME] * _argNb[CELL_SIZE_NAME]
	|| _argNb[WINDOW_WIDTH_NAME] < _argNb[GRID_WIDTH_NAME] * _argNb[CELL_SIZE_NAME])
		throw OutOfWindowException();
}

// Static methods

bool UserInputs::startsWithDoubleDash(const std::string& str) {
	return str.compare(0, 2, "--") == 0;
}

bool UserInputs::isValidUnsignedInt(const std::string& str) {

	try {
		auto value = std::stol(str);
		return value > 0;
	} catch (const std::invalid_argument&) {
		return false;
	} catch (const std::out_of_range&) {
		return false;
	}
}

unsigned int UserInputs::hexToDec(const std::string& hexStr) {
	return std::stoul(hexStr, nullptr, 16);
}

bool UserInputs::isHexadecimal(const std::string& str) {
	for (char c : str) {
		if (!(std::isxdigit(c))) {
			return false;
		}
	}
	return true;
}

bool UserInputs::isHexKey(const std::string& key) {
	return key == BACKGROUND_COLOR_NAME
	|| key == BORDER_COLOR_NAME
	|| key == CELL_COLOR_NAME
	|| key == FOOD_COLOR_NAME;
}

sf::Color UserInputs::hexToRgb(const std::string &str) {
	const unsigned int colorValue = hexToDec(str);
	const unsigned char r = colorValue >> 16 & 0xFF;
	const unsigned char g = colorValue >> 8 & 0xFF;
	const unsigned char b = colorValue & 0xFF;
	return sf::Color(r, g, b);
}
