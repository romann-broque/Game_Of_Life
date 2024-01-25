/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:06 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 11:41:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "KeyHandler.hpp"

class Simulation {

	public:
		Simulation();
		void start();
		~Simulation();
	private:
		sf::RenderWindow _window;
		Grid			 _grid;
		KeyHandler		 _handler;
};
