/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:41 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/22 18:24:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Cell.hpp"
#include <unistd.h>
#include <cmath>

#include "Defines.hpp"

#define DEFAULT_SIZE 4

class Grid {
	public:
		Grid(sf::RenderWindow &window);
		Grid(sf::RenderWindow &window, const size_t width, const size_t height);
		void display();
		~Grid();

	private:
		sf::RenderWindow &window;
		const size_t width;
		const size_t height;
		const float centerX = (WINDOW_WIDTH - CELL_SIZE * width) / 2;
		const float centerY = (WINDOW_HEIGHT - CELL_SIZE * height) / 2;
};
