/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:41 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/22 22:42:47 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include <unistd.h>
#include <cmath>
#include <vector>

#include "Defines.hpp"

#define DEFAULT_SIZE 4

class Grid {
	public:
		Grid(sf::RenderWindow &window);
		Grid(sf::RenderWindow &window, const size_t width, const size_t height);
		void display();
		~Grid();

	private:
		// Attributes
		sf::RenderWindow &window;
		const size_t width;
		const size_t height;
		std::vector<std::vector<Cell>> grid;
		const float centerX = (WINDOW_WIDTH - CELL_SIZE * width) / 2;
		const float centerY = (WINDOW_HEIGHT - CELL_SIZE * height) / 2;
		// Methods
		void initCellGrid();
};
