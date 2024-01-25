/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 11:53:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>
#include "Defines.hpp"

class Config {

	public:

		// Setters
		static void togglePaused();
		static void slowTime();
		static void accelerateTime();
		static void reset();
		static void setResetState(const bool newState);
		// Getters
		static bool isPaused();
		static bool isReset();
		static size_t getTickTime();

	private:
		static bool _isPaused;
		static bool _isReset;
		static size_t _tickTime;
};
