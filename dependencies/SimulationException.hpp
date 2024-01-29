/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimulationException.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:55:26 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 15:59:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

#include <Defines.hpp>

#define INVALID_FORMAT_MESSAGE "Invalid format"
#define INVALID_PARAMETER_MESSAGE "Invalid parameter"
#define INVALID_VALUE_MESSAGE "Invalid value"
#define OUT_OF_WINDOW_MESSAGE \
"Grid dimensions are too big compared to window's ones. \n\
Look at " CELL_SIZE_NAME ", " GRID_WIDTH_NAME " or " GRID_HEIGHT_NAME " parameters."

class SimulationException : public std::exception {
	private:
		const std::string _message;
	public:
		SimulationException(const std::string &message): _message("Simulation: " + message) {}
		virtual const char* what() const throw() {
			return _message.c_str();
		}
};

class InvalidFormatException : public SimulationException {

	public:
		InvalidFormatException(): SimulationException(INVALID_FORMAT_MESSAGE) {}
};

class InvalidParameterException : public SimulationException {
	public:
		InvalidParameterException(): SimulationException(INVALID_PARAMETER_MESSAGE) {}
};

class InvalidValueException : public SimulationException {
	public:
		InvalidValueException(): SimulationException(INVALID_VALUE_MESSAGE) {}
};

class InvalidParameterRequestException : public SimulationException {
	public:
		InvalidParameterRequestException(): SimulationException(INVALID_PARAMETER_MESSAGE) {}
};

class OutOfWindowException : public SimulationException {
	public:
		OutOfWindowException(): SimulationException(OUT_OF_WINDOW_MESSAGE) {}
};
