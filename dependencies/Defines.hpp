/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:54 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 19:01:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define WINDOW_TITLE		"Simulation"

// DIMENSIONS //

# define WINDOW_WIDTH		1920
# define WINDOW_HEIGHT		1080
# define GRID_WIDTH			100
# define GRID_HEIGHT		100
# define CELL_SIZE			5.0f
# define BORDER_THICKNESS	5

// COLOR //

// Black;
// White;
// Red;
// Green;
// Blue;
// Yellow;
// Magenta;
// Cyan;
// Transparent

#ifndef BACKGROUND_COLOR_F
# define BACKGROUND_COLOR_F Black
#endif

#ifndef BORDER_COLOR_F
# define BORDER_COLOR_F Green
#endif

#ifndef CELL_COLOR_F
# define CELL_COLOR_F Green
#endif

#define BACKGROUND_COLOR sf::Color::BACKGROUND_COLOR_F
#define BORDER_COLOR	 sf::Color::BORDER_COLOR_F
#define CELL_COLOR		 sf::Color::CELL_COLOR_F

// TIME //

#define DEFAULT_TICK_TIME	100000 // in microsecondes
#define TIME_FACTOR			10
#define TICK_TIME_MAX		1000000

// DISTRIBUTION //

#define LIFE_PROBA			20 // in percentage
