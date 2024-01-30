/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:06 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 18:00:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Grid.hpp"
#include "KeyHandler.hpp"
#include "SimulationException.hpp"

typedef enum e_gameState {
	RUNNING,
	PAUSED,
	RESET,
	CLICKED
}	t_gameState;

class Simulation {

	public:
		Simulation();
		void start();
	private:
		// Attributes
		sf::RenderWindow _window;
		KeyHandler		 _handler;
		t_gameState		 _state;
		Grid			 _grid;
		// Methods
		t_gridParameter initParameters();
		void refresh();
		void wait();
		void updateState();
		void runningRoutine();
		void pausedRoutine();
		void resetRoutine();
		void clickRoutine();
};
