/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:28:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/31 00:40:25 by rbroque          ###   ########.fr       */
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
		bool isClickOn() const;
		bool isClickOff() const;
		bool isKeyPressed(const sf::Keyboard::Key &key) const;
		bool isKeyReleased(const sf::Keyboard::Key &key) const;
		void addMousePos(const sf::Vector2i &mousePos);
		void clearMouse();
		std::vector<sf::Vector2i> getMousePos();

	private:
		// Attributes
		sf::RenderWindow &_window;
		bool _keys[sf::Keyboard::KeyCount];
		std::map<sf::Keyboard::Key, FunctionType> _keyBindingMap;
		bool _mouseClick;
		std::vector<sf::Vector2i> _mousePos;

		// Methods
		void initKeyBindingMap();
		void initKeysStatus();
		void executeFunction(const sf::Keyboard::Key &key);
};
