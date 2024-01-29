/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simulation.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:34:06 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 09:41:29 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Grid.hpp"
#include "KeyHandler.hpp"

class Simulation {

	public:
		Simulation();
		void start();
	private:
		sf::RenderWindow _window;
		Grid			 _grid;
		KeyHandler		 _handler;
		void refresh();
		void wait();
};
