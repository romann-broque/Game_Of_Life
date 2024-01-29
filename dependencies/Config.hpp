/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 15:54:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>

#include <string>
#include <map>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include "Defines.hpp"
#include "SimulationException.hpp"

class Config {

	public:

		static void init(char **);
		// Setters
		static void addMousePos(const sf::Vector2i &mousePos);
		static void clearMousePos();
		// Getters
		static std::vector<sf::Vector2i> getMousePos();
		static bool isEmptyMousePos();
		static unsigned int getParameterVal(const std::string &paramName);

	private:
		static std::vector<sf::Vector2i> _mousePos;
		static std::map<std::string, unsigned int> _argNb;

		static void associateValueToKey(const std::string &key, const std::string &value);
		static void assignValueToKey(const std::string &key, const unsigned int value);
		static void checkParameters();
};
