/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/22 23:07:56 by rbroque          ###   ########.fr       */
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

typedef struct sPos {
	const size_t x;
	const size_t y;
}				tPos;

class Cell {
	public:
		Cell(const size_t x, const size_t y);
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
		tPos	_pos;
		t_state _state;
};
