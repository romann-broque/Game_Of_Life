/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:14 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/24 13:59:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KeyHandler.hpp"

KeyHandler::KeyHandler(sf::RenderWindow &window) : _window(window) {
	_keyBindingMap[sf::Keyboard::Space] = &Config::togglePaused;
	_keyBindingMap[sf::Keyboard::H] = &Config::slowTime;
	_keyBindingMap[sf::Keyboard::J] = &Config::accelerateTime;
	for (size_t i = 0; i < sf::Keyboard::KeyCount; ++i) {
		_keys[i] = false;
	}
}

// void KeyHandler::processEvents() {
// 	sf::Event event;
// 	while (_window.pollEvent(event)) {
// 		if (event.type == sf::Event::KeyPressed) {
// 			_keys[event.key.code] = true;
// 			executeFunction(event.key.code);
// 		}
// 		if (event.type == sf::Event::KeyReleased) {
// 			_keys[event.key.code] = false;
// 		}
// 		if (event.type == sf::Event::Closed) {
// 			_window.close();
// 		}
// 	}
// }

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

KeyHandler::~KeyHandler() {}

// Private methods


void KeyHandler::executeFunction(const sf::Keyboard::Key &key) {

	std::map<sf::Keyboard::Key, FunctionType>::iterator it = _keyBindingMap.find(key);
	if (it != _keyBindingMap.end())
		_keyBindingMap[key]();

}
