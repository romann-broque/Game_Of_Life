/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:06 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 11:34:41 by rbroque          ###   ########.fr       */
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
		sf::RenderWindow _window;
		KeyHandler		 _handler;
		t_gameState		 _state;
		Grid			 _grid;
		t_gridParameter initParameters();
		void refresh();
		void wait();
		void updateState();
		void runningRoutine();
		void pausedRoutine();
		void resetRoutine();
		void clickRoutine();
};
