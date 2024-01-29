/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:53 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 09:04:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simulation.hpp"
#include <iostream>

static bool isHelpMode(const int ac, char **av) {

	std::string firstArg;
	if (ac == 1)
		firstArg = av[0];
	return firstArg == HELP_CMD1 || firstArg == HELP_CMD2;
}

int main(__attribute__((unused))int ac, char **av) {

	if (isHelpMode(ac - 1, av + 1)) {
		std::cout << HELP_MESSAGE << std::endl;
		return EXIT_SUCCESS;
	}
	try {
		Config::init(av + 1);
		Simulation game;
		game.start();
		return EXIT_SUCCESS;
	} catch (SimulationException &e) {
		std::cerr << e.what()<< std::endl;
	}
	std::cerr << TYPE_HELP_MESSAGE << std::endl;
	return EXIT_FAILURE;
}
