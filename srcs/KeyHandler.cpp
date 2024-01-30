/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:14 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 23: by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KeyHandler.hpp"

bool isClicked = false;

KeyHandler::KeyHandler(sf::RenderWindow &window) : _window(window) {
	initKeyBindingMap();
	initKeysStatus();
}

void KeyHandler::processEvents() {
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			_keys[event.key.code] = true;
			executeFunction(event.key.code);
		}
		if (event.type == sf::Event::KeyReleased) {
			_keys[event.key.code] = false;
		}
		if (isClicked == false && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			addMousePos(sf::Mouse::getPosition(_window));
		} else {
			isClicked = false;
		}
		if (event.type == sf::Event::Closed) {
			_window.close();
		}
	}
}

bool KeyHandler::isKeyPressed(const sf::Keyboard::Key &key) const {
	return _keys[key];
}

bool KeyHandler::isKeyReleased(const sf::Keyboard::Key &key) const {
	return !_keys[key];
}

void KeyHandler::addMousePos(const sf::Vector2i &mousePos) {
	_mousePos.push_back(mousePos);
}

void KeyHandler::clearMousePos() {
	_mousePos.clear();
}

// Getters

std::vector<sf::Vector2i> KeyHandler::getMousePos() {
	return _mousePos;
}

bool KeyHandler::isEmptyMousePos() {
	return _mousePos.size() == 0;
}

// Private methods

void KeyHandler::initKeyBindingMap() {
	_keyBindingMap[sf::Keyboard::Space] = &GameState::togglePaused;
	_keyBindingMap[sf::Keyboard::H] = &GameState::slowTime;
	_keyBindingMap[sf::Keyboard::J] = &GameState::accelerateTime;
	_keyBindingMap[sf::Keyboard::R] = &GameState::reset;
}

void KeyHandler::initKeysStatus() {
	for (size_t i = 0; i < sf::Keyboard::KeyCount; ++i) {
		_keys[i] = false;
	}
}

void KeyHandler::executeFunction(const sf::Keyboard::Key &key) {

	std::map<sf::Keyboard::Key, FunctionType>::iterator it = _keyBindingMap.find(key);
	if (it != _keyBindingMap.end())
		_keyBindingMap[key]();

}
