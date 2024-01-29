/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:06 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 16:31:32 by rbroque          ###   ########.fr       */
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
		Grid			 _grid;
		KeyHandler		 _handler;
		t_gameState		 _state;
		void refresh();
		void wait();
		void updateState();
		void runningRoutine();
		void pausedRoutine();
		void resetRoutine();
		void clickRoutine();
};
