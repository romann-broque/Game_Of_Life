/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:48:37 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:29:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"

bool Config::_isPaused = false;

void Config::togglePaused() {
	_isPaused = !_isPaused;
}

bool Config::isPaused() {
	return _isPaused;
}
