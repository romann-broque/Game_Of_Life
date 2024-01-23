/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EventLoop.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:27:57 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:18:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Config.hpp"
#include "KeyHandler.hpp"

typedef void (*FunctionType)();

class EventLoop {

	public:
		EventLoop(sf::RenderWindow &window);
		void checkEvent();
		~EventLoop();

	private:
		KeyHandler _handler;
		std::map<sf::Keyboard::Key, FunctionType> _keyBindingMap;
};
