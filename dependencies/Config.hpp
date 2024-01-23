/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 11:04:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include "Defines.hpp"

class Config {

	public:

		// Setters
		static void togglePaused();
		static void slowTime();
		static void accelerateTime();
		// Getters
		static bool isPaused();
		static size_t getTickTime();

	private:
		static bool _isPaused;
		static size_t _tickTime;
};
