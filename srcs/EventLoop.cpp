/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EventLoop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:40:33 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:24:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EventLoop.hpp"

EventLoop::EventLoop(sf::RenderWindow &window): _handler(window) {

	_keyBindingMap[sf::Keyboard::Space] = &Config::togglePaused;
}

void EventLoop::checkEvent() {
	_handler.processEvents(_keyBindingMap);
}

EventLoop::~EventLoop() {}
