/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/31 00:43:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "UserInputs.hpp"
#include "Defines.hpp"

#define NEIGHBOOR_COUNT	8
#define STATE_COUNT		3

typedef enum e_state {
	ALIVE,
	FOOD,
	DEAD
} t_state;

typedef struct CellParameter {
	bool			darkening;
	bool			foodPresence;
	bool			foodConv;
	unsigned int	lifeProba;
	unsigned int	foodProba;
	unsigned int	cellLifetime;
	sf::Color		lifeColor;
	sf::Color		foodColor;
}	t_cellParameter;

class Cell {
	public:
		Cell(const CellParameter &cellConfig);
		~Cell();
		Cell &operator=(const Cell &cell);
		// Setters
		void setRandomState();
		void setNextState(const t_state newState);
		void setNeighborhood(const std::vector<Cell *> &surroundingCells);
		void toggleState();
		void clearClick();
		// Getters
		t_state getState() const;
		sf::Color getColor() const;
		bool canBeDrawn() const;
		bool isToggled() const;
		// Action
		void refresh();
		void evolve();

	private:
		// Attributes
		const t_cellParameter	_params;
		sf::Color				_color;
		t_state 				_state;
		t_state 				_nextState;
		size_t					_age;
		Cell					*_neighboors[NEIGHBOOR_COUNT];
		size_t					_neighboorCount[STATE_COUNT];
		bool					_isToggled;
		// Private methods
		void setCellColor(const sf::Color color);
		void setCellStateColor(const t_state state);
		void changeBrightness(const int lightFactor);
		unsigned char newColorComponentBrightness(const unsigned char color, const int lightFactor);
		void update();
		void lifeRoutine();
		void foodRoutine();
		void deadRoutine();
		size_t countStateCells(const t_state state) const;
		void scanNeighborhood();
};
