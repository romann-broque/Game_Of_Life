/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:20:53 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 17:13:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simulation.hpp"

int main(__attribute__((unused))int ac, char **av) {

	Config::init(av + 1);

	Simulation game;
	game.start();
	return 0;
}
