/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:36:47 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 17:51:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simulation.hpp"

Simulation::Simulation():
	_window(sf::VideoMode(
		Config::getParameterVal(WINDOW_WIDTH_NAME),
		Config::getParameterVal(WINDOW_HEIGHT_NAME)), WINDOW_TITLE),
	_grid(_window,
		Config::getParameterVal(GRID_WIDTH_NAME),
		Config::getParameterVal(GRID_HEIGHT_NAME)),
	_handler(_window) {

	sf::View view(_window.getDefaultView());
	view.setCenter(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
	_window.setView(view);
}

void Simulation::start() {

	while (_window.isOpen()) {
		_handler.processEvents();
		if (Config::isPaused() == false) {
			_window.clear(); // Clear the window
			_grid.display();
			_window.display(); // Display the contents of the window
			if (Config::isReset()) {
				_grid.reset();
				Config::setResetState(false);
			} else {
				_grid.update();
			}
			usleep(Config::getTickTime());
		}
	}
}

Simulation::~Simulation() {}
