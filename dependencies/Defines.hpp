/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Defines.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:11:54 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 11:32:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define WINDOW_TITLE		"Simulation"

// DIMENSIONS //

#define WINDOW_WIDTH		1900
#define WINDOW_HEIGHT		1080
#define GRID_WIDTH			100
#define GRID_HEIGHT			100
#define CELL_SIZE	 		5.0f // in pixels
//
// TIME //
#define DEFAULT_TICK_TIME	100000 // in microsecondes
#define TIME_FACTOR			10
#define TICK_TIME_MAX		1000000

// DISTRIBUTION //

#define LIFE_PROBA			20 // in percentage
