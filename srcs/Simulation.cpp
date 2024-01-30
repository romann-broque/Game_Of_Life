/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:36:47 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 18:29:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simulation.hpp"

Simulation::Simulation():
	_window(sf::VideoMode(
		UserInputs::getParameterVal(WINDOW_WIDTH_NAME),
		UserInputs::getParameterVal(WINDOW_HEIGHT_NAME)), WINDOW_TITLE),
	_handler(_window),
	_state(RUNNING),
	_grid(_window, initParameters()) {

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

t_gridParameter Simulation::initParameters() {

	t_gridParameter grid;

	grid.width = UserInputs::getParameterVal(GRID_WIDTH_NAME);
	grid.height = UserInputs::getParameterVal(GRID_HEIGHT_NAME);
	grid.cellSize = UserInputs::getParameterVal(CELL_SIZE_NAME);
	grid.borderThick = UserInputs::getParameterVal(BORDER_THICK_NAME);
	grid.lifeProba = UserInputs::getParameterVal(LIFE_PROBA_NAME);
	grid.topLeftX = (UserInputs::getParameterVal(WINDOW_WIDTH_NAME) -  grid.width * grid.cellSize) / 2;
	grid.topLeftY = (UserInputs::getParameterVal(WINDOW_HEIGHT_NAME) -  grid.height * grid.cellSize) / 2;
	grid.borderColor = UserInputs::getParameterColor(BORDER_COLOR_NAME);
	grid.backgroundColor = UserInputs::getParameterColor(BACKGROUND_COLOR_NAME);
	grid.cellColor = UserInputs::getParameterColor(CELL_COLOR_NAME);
	grid.foodColor = UserInputs::getParameterColor(FOOD_COLOR_NAME);

	grid.cellConfig.darkening = UserInputs::getParameterVal(DARKENING_NAME);
	grid.cellConfig.foodPresence = UserInputs::getParameterVal(FOOD_NAME);
	grid.cellConfig.foodConv = UserInputs::getParameterVal(FOOD_CONV_NAME);
	grid.cellConfig.foodProba = UserInputs::getParameterVal(FOOD_PROBA_NAME);
	grid.cellConfig.cellLifetime = UserInputs::getParameterVal(CELL_LIFETIME_NAME);
	grid.cellConfig.lifeColor = UserInputs::getParameterColor(CELL_COLOR_NAME);
	grid.cellConfig.foodColor = UserInputs::getParameterColor(FOOD_COLOR_NAME);
	return grid;
}

void Simulation::refresh() {

	_window.clear(); // Clear the window
	_grid.draw();
	_window.display(); // Display the contents of the window
}

void Simulation::wait() {

	usleep(GameState::getTickTime());
}

void Simulation::updateState() {
	if (UserInputs::isEmptyMousePos() == false) {
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
	UserInputs::clearMousePos();
}
