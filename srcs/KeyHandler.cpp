/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:35:14 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:39:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KeyHandler.hpp"

KeyHandler::KeyHandler(sf::RenderWindow& window) : _window(window) {
	_keyBindingMap[sf::Keyboard::Space] = &Config::togglePaused;
	for (size_t i = 0; i < sf::Keyboard::KeyCount; ++i) {
		_keys[i] = false;
	}
}

void KeyHandler::processEvents() {
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (_keys[event.key.code] == false)
				_keyBindingMap[event.key.code]();
			_keys[event.key.code] = true;
		}
		if (event.type == sf::Event::KeyReleased) {
			_keys[event.key.code] = false;
		}
		if (event.type == sf::Event::Closed) {
			_window.close();
		}
	}
}

bool KeyHandler::isKeyPressed(sf::Keyboard::Key key) const {
	return _keys[key];
}

bool KeyHandler::isKeyReleased(sf::Keyboard::Key key) const {
	return !_keys[key];
}

KeyHandler::~KeyHandler() {}
