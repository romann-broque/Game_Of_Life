/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 10:48:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "Config.hpp"
#include "Defines.hpp"

typedef enum e_state {
	ALIVE,
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
		void setState(const t_state newState);
		void setNextState(const t_state newState);
		void setState(const unsigned char lifeProba);
		void toggleState();
		// Getters
		bool isAlive() const;
		size_t getAge() const;
		// Action
		void draw(sf::RenderWindow &window);
		void refresh();

	private:
		// Attributes
		sf::RectangleShape _cellScreen;
		sf::Color			_initColor;
		sf::Color			_color;
		const bool			_darkening = Config::getParameterVal(DARKENING_NAME);
		t_state _state;
		t_state _nextState;
		size_t	_age;
		// Private methods
		void changeBrightness(const int lightFactor);
		void update();
};
