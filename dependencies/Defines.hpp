/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:54 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 01:09:26 by rbroque          ###   ########.fr       */
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

#define BACKGROUND_COLOR 0x0000ff
#define BORDER_COLOR	 0x0000ff
#define CELL_COLOR		 0xffffff
#define DARK_FACTOR		 -5
#define MIN_COLOR_COMP	10
#define MAX_COLOR_COMP	256

// TIME //

#define DEFAULT_TICK_TIME	100000 // in microsecondes
#define TIME_FACTOR			10
#define TICK_TIME_MAX		1000000

// DISTRIBUTION //

#define LIFE_PROBA			20 // in percentage

// Parameters name //

#define WINDOW_WIDTH_NAME "window_width"
#define WINDOW_HEIGHT_NAME "window_height"
#define GRID_WIDTH_NAME "grid_width"
#define GRID_HEIGHT_NAME "grid_height"
#define CELL_SIZE_NAME "cell_size"
#define LIFE_PROBA_NAME "life"
#define BORDER_THICK_NAME "border_thick"
#define BORDER_COLOR_NAME "border_color"
#define BACKGROUND_COLOR_NAME "background_color"
#define CELL_COLOR_NAME "cell_color"

// STRING //

#define HELP_CMD1 "-h"
#define HELP_CMD2 "--help"
#define TYPE_HELP_MESSAGE "Use './Simulation -h' or './Simulation --help' for help"
#define HELP_MESSAGE \
	"Usage: ./Simulation [OPTIONS]\n\n"\
	"Options:\n\n"\
	" -h, --help         Display this help message and exit\n"\
	" --" WINDOW_WIDTH_NAME "     (in pixels)\n" \
	" --" WINDOW_HEIGHT_NAME "    (in pixels)\n" \
	" --" GRID_WIDTH_NAME "       (in cases)\n" \
	" --" GRID_HEIGHT_NAME "      (in cases)\n" \
	" --" CELL_SIZE_NAME "        (in pixels)\n" \
	" --" LIFE_PROBA_NAME "             (in percentage)\n" \
	" --" BORDER_THICK_NAME "     (in pixels) \n" \
	" --" BORDER_COLOR_NAME "     (in hexadecimal)\n" \
	" --" BACKGROUND_COLOR_NAME " (in hexadecimal)\n" \
	" --" CELL_COLOR_NAME "       (in hexadecimal)\n\n"\
	"Examples:\n\n"\
	" ./Simulation\n"\
	" ./Simulation border_thick=12 background_color=1200ff window_width=1200 window_height=920\n"\
	" ./Simulation --help"
