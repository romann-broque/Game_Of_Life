/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:14:59 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/22 21:33:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <SFML/Graphics.hpp>
#include "Defines.hpp"

typedef struct sPos {
	const size_t x;
	const size_t y;
}				tPos;

class Cell {
	public:
		Cell(const size_t x, const size_t y);
		void setScreenPosition(const float screenX, const float screenY);
		void setCellColor(const sf::Color color);
		void setStatus(const bool lifeStatus);
		void draw(sf::RenderWindow &window) const;
		~Cell();

	private:
		const float cellSize = CELL_SIZE;
		tPos pos;
		sf::RectangleShape cellScreen;
		bool isAlive;
};
