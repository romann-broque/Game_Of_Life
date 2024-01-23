/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:28:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:25:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

typedef void (*FunctionType)();

class KeyHandler {
public:
	KeyHandler(sf::RenderWindow& window) : _window(window) {
		for (int i = 0; i < sf::Keyboard::KeyCount; ++i) {
			_keys[i] = false;
		}
	}

	void processEvents(std::map<sf::Keyboard::Key, FunctionType> keyBindingMap) {
		sf::Event event;
		while (_window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (_keys[event.key.code] == false)
					keyBindingMap[event.key.code]();
				_keys[event.key.code] = true;
			}
			if (event.type == sf::Event::KeyReleased) {
				_keys[event.key.code] = false;
			}
		}
	}

	bool isKeyPressed(sf::Keyboard::Key key) const {
		return _keys[key];
	}

	bool isKeyReleased(sf::Keyboard::Key key) const {
		return !_keys[key];
	}

private:
    sf::RenderWindow& _window;
    bool _keys[sf::Keyboard::KeyCount];
};
