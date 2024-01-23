/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 16:18:31 by rbroque          ###   ########.fr       */
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
		Cell();
		Cell &operator=(const Cell &cell);
		void setScreenPosition(const float screenX, const float screenY);
		void setCellColor(const sf::Color color);
		void setState(const t_state);
		void setState();
		bool isAlive() const;
		void draw(sf::RenderWindow &window) const;
		~Cell();

	private:
		const float cellSize = CELL_SIZE;
		sf::RectangleShape _cellScreen;
		t_state _state;
};
