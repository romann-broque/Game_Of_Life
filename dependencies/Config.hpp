/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 00:38:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>

#include <string>
#include <map>
#include <exception>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include "Defines.hpp"

// Error Messages //

#define INVALID_FORMAT_MESSAGE "Invalid format"
#define INVALID_PARAMETER_MESSAGE "Invalid parameter"
#define INVALID_VALUE_MESSAGE "Invalid value"

class Config {

	public:

		static void init(char **);
		// Setters
		static void togglePaused();
		static void slowTime();
		static void accelerateTime();
		static void reset();
		static void setResetState(const bool newState);
		// Getters
		static bool isPaused();
		static bool isReset();
		static size_t getTickTime();
		static unsigned int getParameterVal(const std::string &paramName);
		// Exceptions
		class InvalidFormatException : public std::exception {};
		class InvalidParameterException : public std::exception {};
		class InvalidValueException : public std::exception {};
		class InvalidParameterRequestException : public std::exception {};

	private:
		static bool _isPaused;
		static bool _isReset;
		static size_t _tickTime;
		static std::map<std::string, unsigned int> _argNb;

		static void associateValueToKey(const std::string &key, const std::string &value);
		static void assignValueToKey(const std::string &key, const unsigned int value);
};
