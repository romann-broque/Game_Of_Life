/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 00:17:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "Defines.hpp"

typedef enum e_state {
	ALIVE,
	DEAD
} t_state;

class Cell {
	public:
		Cell(const size_t cellSize, const sf::Color &color);
		Cell &operator=(const Cell &cell);
		// Setters
		void setScreenPosition(const float screenX, const float screenY);
		void setCellColor(const sf::Color color);
		void setState(const t_state);
		void setState(const unsigned char lifeProba);
		// Getters
		bool isAlive() const;
		size_t getAge() const;
		// Action
		void update();
		void draw(sf::RenderWindow &window);
		~Cell();

	private:
		sf::RectangleShape _cellScreen;
		sf::Color			_initColor;
		sf::Color			_color;
		t_state _state;
		size_t	_age;
		void changeBrightness(const int lightFactor);
};
