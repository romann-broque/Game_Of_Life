/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 22:03:59 by rbroque          ###   ########.fr       */
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
	unsigned int	foodProba;
	unsigned int	cellLifetime;
	sf::Color		lifeColor;
	sf::Color		foodColor;
}	t_cellParameter;

class Grid;

class Cell {
	public:
		Cell(const CellParameter &cellConfig);
		~Cell();
		Cell &operator=(const Cell &cell);
		// Setters
		void setCellStateColor(const t_state state);
		void setNextState(const t_state newState);
		void initState(const unsigned char lifeProba);
		void setNeihborhood(const std::vector<Cell *> &surroundingCells);
		void toggleState();
		// Getters
		t_state getState() const;
		sf::Color getColor() const;
		bool canBeDrawn() const;
		// Action
		void evolve();
		void refresh();

	private:
		// Attributes
		const t_cellParameter	_params;
		sf::Color				_color;
		t_state 				_state;
		t_state 				_nextState;
		size_t					_age;
		Cell					*_neighboors[8];
		size_t					_neighboorCount[STATE_COUNT];
		// Private methods
		void setCellColor(const sf::Color color);
		void changeBrightness(const int lightFactor);
		unsigned char newColorComponentBrightness(const unsigned char color, const int lightFactor);
		void update();
		void lifeRoutine();
		void foodRoutine();
		void deadRoutine();
		size_t countStateCells(const t_state state) const;
		void scanNeighborhood();
};
