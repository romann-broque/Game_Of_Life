/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHandler.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:28:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:37:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>

#include "Config.hpp"

typedef void (*FunctionType)();

class KeyHandler {
	public:
		KeyHandler(sf::RenderWindow& window);
		void processEvents();
		bool isKeyPressed(const sf::Keyboard::Key key) const;
		bool isKeyReleased(const sf::Keyboard::Key key) const;
		~KeyHandler();

	private:
		sf::RenderWindow& _window;
		bool _keys[sf::Keyboard::KeyCount];
		std::map<sf::Keyboard::Key, FunctionType> _keyBindingMap;
};
