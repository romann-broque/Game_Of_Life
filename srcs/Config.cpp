/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:48:37 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 11:53:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

bool Config::_isPaused = false;
bool Config::_isReset = false;
size_t Config::_tickTime = DEFAULT_TICK_TIME;

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
