/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:27:23 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/22 21:32:58 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cell.hpp"

Cell::Cell(const size_t x, const size_t y):
	pos{x, y}, cellScreen(sf::Vector2f(cellSize, cellSize)), isAlive(true) {}

void Cell::setScreenPosition(const float screenX, const float screenY) {
	cellScreen.setPosition(screenX, screenY);
}

void Cell::setCellColor(const sf::Color color) {
	(void)pos;
	cellScreen.setFillColor(color);
}

void Cell::setStatus(const bool lifeStatus) {
	isAlive = lifeStatus;
}

void Cell::draw(sf::RenderWindow &window) const {
	window.draw(cellScreen);
}

Cell::~Cell() {}
