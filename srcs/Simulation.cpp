/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:36:47 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 15:55:29 by rbroque          ###   ########.fr       */
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
	_handler(_window),
	_state(RUNNING) {

	sf::View view(_window.getDefaultView());
	view.setCenter(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
	_window.setView(view);
}

void Simulation::start() {

	static const std::map<t_gameState, void (Simulation::*)()> mapState = {
		{RUNNING, &Simulation::runningRoutine},
		{PAUSED, &Simulation::pausedRoutine},
		{RESET, &Simulation::resetRoutine},
		{CLICKED, &Simulation::clickRoutine}
	};


	while (_window.isOpen()) {
		(this->*(mapState.at(_state)))();
		_handler.processEvents();
		updateState();
	}
}

// Private

void Simulation::refresh() {

	_window.clear(); // Clear the window
	_grid.draw();
	_window.display(); // Display the contents of the window
}

void Simulation::wait() {

	usleep(GameState::getTickTime());
}

void Simulation::updateState() {
	if (Config::isEmptyMousePos() == false) {
		_state = CLICKED;
	} else if (GameState::isPaused()) {
		_state = PAUSED;
	} else if (GameState::isReset()) {
		_state = RESET;
	} else {
		_state = RUNNING;
	}
}


void Simulation::runningRoutine() {
	_grid.update();
	refresh();
	wait();
}

void Simulation::pausedRoutine() {

}

void Simulation::resetRoutine() {
	_grid.reset();
	GameState::setResetState(false);
}

void Simulation::clickRoutine() {
	_grid.toggleCells();
	refresh();
	Config::clearMousePos();
}
