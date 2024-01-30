/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:28:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 23:53:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

#include "UserInputs.hpp"
#include "GameState.hpp"

typedef void (*FunctionType)();

class KeyHandler {
	public:
		KeyHandler(sf::RenderWindow &window);
		void processEvents();
		bool isKeyPressed(const sf::Keyboard::Key &key) const;
		bool isKeyReleased(const sf::Keyboard::Key &key) const;
		void addMousePos(const sf::Vector2i &mousePos);
		void clearMousePos();
		std::vector<sf::Vector2i> getMousePos();
		bool isEmptyMousePos();

	private:
		// Attributes
		sf::RenderWindow &_window;
		bool _keys[sf::Keyboard::KeyCount];
		std::map<sf::Keyboard::Key, FunctionType> _keyBindingMap;
		std::vector<sf::Vector2i> _mousePos;

		// Methods
		void initKeyBindingMap();
		void initKeysStatus();
		void executeFunction(const sf::Keyboard::Key &key);
};
