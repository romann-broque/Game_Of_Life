/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:54 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/26 09:50:14 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define WINDOW_TITLE		"Simulation"

// DIMENSIONS //

# define WINDOW_WIDTH		1920
# define WINDOW_HEIGHT		1080
# define GRID_WIDTH			100
# define GRID_HEIGHT		100
# define CELL_SIZE			5
# define BORDER_THICKNESS	5

// COLOR //

#define BACKGROUND_COLOR 0x0000ff
#define BORDER_COLOR	 0x0000ff
#define CELL_COLOR		 0xffffff
#define DARK_FACTOR		 -5
#define MIN_COLOR_COMP	10
#define MAX_COLOR_COMP	256
#define DARKENING		1

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
#define DARKENING_NAME "darkening"

// STRING //

#define HELP_CMD1 "-h"
#define HELP_CMD2 "--help"
#define TYPE_HELP_MESSAGE "Use './Simulation -h' or './Simulation --help' for help"
#define HELP_MESSAGE \
	"Usage: ./Simulation [OPTIONS]\n\n"\
	"Options:\n\n"\
	" --" BACKGROUND_COLOR_NAME " =<hexadecimal_value> [default:0000FF]\n\n"\
	" --" BORDER_COLOR_NAME "     =<hexadecimal_value> [default:0x000FF]\n\n"\
	" --" BORDER_THICK_NAME "     =<pixels_nb>         [default:1] \n\n" \
	" --" CELL_COLOR_NAME "       =<hexadecimal_value> [default:FFFFFF]\n\n"\
	" --" CELL_SIZE_NAME "        =<pixels_nb>         [default:5]\n\n"\
	" --" DARKENING_NAME "        =<yes|no>            [default:yes]\n\n"\
	" --" GRID_WIDTH_NAME "       =<cells_nb>          [default:100]\n\n"\
	" --" GRID_HEIGHT_NAME "      =<cells_nb>          [default:100]\n\n"\
	" -h, --help         Display this help message and exit\n\n"\
	" --" LIFE_PROBA_NAME "             =<percentage>        [default:20]\n\n"\
	" --" WINDOW_WIDTH_NAME "     =<pixels_nb>         [default:1920]\n\n"\
	" --" WINDOW_HEIGHT_NAME "    =<pixels_nb>         [default:1080]\n\n"\
	"Examples:\n\n"\
	" ./Simulation\n"\
	" ./Simulation border_thick=12 background_color=1200ff darkening=no window_width=1200 window_height=920\n"\
	" ./Simulation --help"
