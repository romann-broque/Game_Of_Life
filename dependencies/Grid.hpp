/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:41 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 11:33:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include <unistd.h>
#include <cmath>
#include <vector>
#include <iostream>

#include "Defines.hpp"

#define DEFAULT_SIZE 4

class Grid {
	public:
		Grid(sf::RenderWindow &window);
		Grid(sf::RenderWindow &window, const size_t width, const size_t height);
		void update();
		void display_background();
		void display_grid();
		void display();
		~Grid();

	private:
		// Attributes
		sf::RenderWindow &window;
		const size_t width;
		const size_t height;
		std::vector<std::vector<Cell>> grid;
		std::vector<std::vector<Cell>> grid_temp;
		const float topLeftX = (WINDOW_WIDTH - width * CELL_SIZE) / 2;
		const float topLeftY = (WINDOW_HEIGHT - height * CELL_SIZE) / 2;

		// Methods
		void initCellGrids();
		void updateCell(Cell &cell, const size_t i, const size_t j);
		std::vector<Cell> getSurroundingLivingCells(const size_t i, const size_t j);
};
