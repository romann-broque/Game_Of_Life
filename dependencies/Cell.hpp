/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/27 01:27:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "Config.hpp"
#include "Defines.hpp"

typedef enum e_state {
	ALIVE,
	FOOD,
	DEAD
} t_state;

class Cell {
	public:
		Cell(const size_t cellSize, const sf::Color &color);
		~Cell();
		Cell &operator=(const Cell &cell);
		// Setters
		void setScreenPosition(const float screenX, const float screenY);
		void setCellColor(const sf::Color color);
		void setCellStateColor(const t_state state, const sf::Color color);
		void setState(const t_state newState);
		void setNextState(const t_state newState);
		void initState(const unsigned char lifeProba);
		void toggleState();
		// Getters
		bool isAlive() const;
		t_state getState() const;
		size_t getAge() const;
		// Action
		void draw(sf::RenderWindow &window);
		void evolve(const size_t livingCount, const size_t foodCount, const size_t deadCount);
		void refresh();

	private:
		// Attributes
		const bool			_darkening = Config::getParameterVal(DARKENING_NAME);
		const bool			_cycle = Config::getParameterVal(CYCLE_NAME);
		const bool			_foodPresence = Config::getParameterVal(FOOD_NAME);
		const unsigned int	_foodProba = Config::getParameterVal(FOOD_PROBA_NAME);
		const unsigned int	_cellLifetime = Config::getParameterVal(CELL_LIFETIME_NAME);
		sf::RectangleShape	_cellScreen;
		sf::Color			_initColor;
		sf::Color			_color;
		sf::Color			_foodColor;
		t_state 			_state;
		t_state 			_nextState;
		size_t				_age;
		size_t				_livingCount;
		size_t				_foodCount;
		size_t				_deadCount;
		// Private methods
		void changeBrightness(const int lightFactor);
		void update();
		void lifeRoutine();
		void foodRoutine();
		void deadRoutine();
};
