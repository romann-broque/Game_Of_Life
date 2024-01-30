/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:41 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/30 18:05:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include <unistd.h>
#include <cmath>
#include <vector>

#include "Defines.hpp"

#define DEFAULT_SIZE 20

typedef struct GridParameter {
	size_t width;
	size_t height;
	unsigned int topLeftX;
	unsigned int topLeftY;
	unsigned int borderThick;
	unsigned int cellSize;
	unsigned int lifeProba;
	sf::Color borderColor;
	sf::Color backgroundColor;
	sf::Color cellColor;
	sf::Color foodColor;
	t_cellParameter cellConfig;
} t_gridParameter;

class Grid {
	public:
		Grid(sf::RenderWindow &window, const t_gridParameter &params);
		void update();
		void reset();
		void draw_background();
		void draw_grid();
		void draw();
		void toggleCells();

	private:
		// Attributes
		sf::RenderWindow &_window;
		sf::RectangleShape _background;
		const t_gridParameter _params;
		std::vector<std::vector<Cell>> _init_grid;
		std::vector<std::vector<Cell>> _grid;

		// Methods
		void initCellGrids();
		void initBackground();
		void preArrange();
		void arrange();
		void resetCellGrid();
		void drawCell(const size_t x, const size_t y);
		void drawCellIfNotDead(Cell &cell, const size_t x, const size_t y);
		void updateCell(Cell &cell, const size_t i, const size_t j);
		std::vector<Cell> getSurroundingCells(const size_t i, const size_t j);
		size_t countStateCells(const std::vector<Cell> &surroundingCells, const t_state state);
		bool isInGridScreen(const size_t x, const size_t y);
		void refreshCell(Cell &cell,
			__attribute__((unused)) const size_t x,
			__attribute__((unused)) const size_t y);
		template<typename Function>
		void forEachCell(Grid& grid, const Function &func) {
			for (size_t i = 0; i < _params.height; ++i) {
				for (size_t j = 0; j < _params.width; ++j) {
					(grid.*func)(grid._grid[i][j], j, i);
				}
			}
		}
};
