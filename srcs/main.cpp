/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:53 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 17:43:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simulation.hpp"
#include <iostream>

int main(__attribute__((unused))int ac, char **av) {
	try {
		Config::init(av + 1);
		Simulation game;
		game.start();
		return EXIT_SUCCESS;
	} catch (Config::InvalidFormatException &e) {
		std::cerr << INVALID_FORMAT_MESSAGE << std::endl;
	} catch (Config::InvalidParameterException &e) {
		std::cerr << INVALID_PARAMETER_MESSAGE << std::endl;
	} catch (Config::InvalidValueException &e) {
		std::cerr << INVALID_VALUE_MESSAGE << std::endl;
	}
	return EXIT_FAILURE;
}
