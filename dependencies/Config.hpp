/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 09:05:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>

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
		static void togglePaused();
		static void slowTime();
		static void accelerateTime();
		static void reset();
		static void setResetState(const bool newState);
		static void addMousePos(const sf::Vector2i &mousePos);
		static void clearMousePos();
		// Getters
		static bool isPaused();
		static bool isReset();
		static size_t getTickTime();
		static std::vector<sf::Vector2i> getMousePos();
		static bool isEmptyMousePos();
		static unsigned int getParameterVal(const std::string &paramName);

	private:
		static bool _isPaused;
		static bool _isReset;
		static size_t _tickTime;
		static std::vector<sf::Vector2i> _mousePos;
		static std::map<std::string, unsigned int> _argNb;

		static void associateValueToKey(const std::string &key, const std::string &value);
		static void assignValueToKey(const std::string &key, const unsigned int value);
		static void checkParameters();
};
