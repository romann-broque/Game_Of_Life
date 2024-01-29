/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:41 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 09:53:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include "Config.hpp"
#include <unistd.h>
#include <cmath>
#include <vector>

#include "Defines.hpp"

#define DEFAULT_SIZE 20

class Grid {
	public:
		Grid(sf::RenderWindow &window);
		Grid(sf::RenderWindow &window, const size_t width, const size_t height);
		void update();
		void reset();
		void draw_background();
		void draw_grid();
		void draw();
		void toggleCells();

	private:
		// Attributes
		const size_t width;
		const size_t height;
		const unsigned int borderThick = Config::getParameterVal(BORDER_THICK_NAME);
		const unsigned int cellSize = Config::getParameterVal(CELL_SIZE_NAME);
		const unsigned int lifeProba = Config::getParameterVal(LIFE_PROBA_NAME);
		const float topLeftX = (WINDOW_WIDTH - width * cellSize) / 2;
		const float topLeftY = (WINDOW_HEIGHT - height * cellSize) / 2;
		sf::RenderWindow &window;
		std::vector<std::vector<Cell>> grid;
		std::vector<std::vector<Cell>> init_grid;
		sf::Color borderColor;
		sf::Color backgroundColor;
		sf::Color cellColor;
		sf::Color foodColor;

		// Methods
		void initColors();
		void initCellGrids();
		void preArrange();
		void arrange();
		void resetCellGrid();
		void updateCell(Cell &cell, const size_t i, const size_t j);
		std::vector<Cell> getSurroundingCells(const size_t i, const size_t j);
		size_t countStateCells(const std::vector<Cell> &surroundingCells, const t_state state);
		bool isInGridScreen(const size_t x, const size_t y);
};
