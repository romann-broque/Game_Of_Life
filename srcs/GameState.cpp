/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:55:03 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 15:53:44 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameState.hpp"

bool GameState::_isPaused = false;
bool GameState::_isReset = false;
size_t GameState::_tickTime = DEFAULT_TICK_TIME;

void GameState::togglePaused() {
	_isPaused = !_isPaused;
}

void GameState::slowTime() {
	if (_tickTime < TICK_TIME_MAX)
		_tickTime *= TIME_FACTOR;
}

void GameState::accelerateTime() {
	if (_tickTime <= TIME_FACTOR)
		_tickTime = 1;
	else
		_tickTime /= TIME_FACTOR;
}

void GameState::reset() {
	_isReset = true;
}

void GameState::setResetState(const bool newState) {
	_isReset = newState;
}

// Getters

bool GameState::isPaused() {
	return _isPaused;
}

bool GameState::isReset() {
	return _isReset;
}

size_t GameState::getTickTime() {
	return _tickTime;
}
