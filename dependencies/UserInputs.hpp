/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInputs::.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:30 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 16:04:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#include "SimulationException.hpp"
#include "Defines.hpp"

class UserInputs {
public:
	static void init(char **argv);
	static void addMousePos(const sf::Vector2i &mousePos);
	static void clearMousePos();
	static std::vector<sf::Vector2i> getMousePos();
	static bool isEmptyMousePos();
	static unsigned int getParameterVal(const std::string &paramName);
	static sf::Color getParameterColor(const std::string &paramName);

private:
	// Attributes
	static std::map<std::string, unsigned int> _argNb;
	static std::map<std::string, sf::Color> _argColor;
	static std::vector<sf::Vector2i> _mousePos;
	// Private Methods
	static void associateValueToKey(const std::string &key, const std::string &value);
	static void assignValueToKey(const std::string &key, const unsigned int value);
	static void assignColorToKey(const std::string &key, const sf::Color &color);
	static void checkParameters();
	static bool startsWithDoubleDash(const std::string& str);
	static bool isValidUnsignedInt(const std::string& str);
	static bool isHexadecimal(const std::string& str);
	static bool isHexKey(const std::string& key);
	static unsigned int hexToDec(const std::string& hexStr);
	static sf::Color hexToRgb(const std::string &str);
};
