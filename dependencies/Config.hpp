/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/25 17:07:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <unistd.h>

#include <string>
#include <map>

#include "Defines.hpp"

class Config {

	public:

		static void init(char **);
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
		static unsigned int getWindowWidth();
		static unsigned int getWindowHeight();
		static unsigned int getGridWidth();
		static unsigned int getGridHeight();
		static unsigned int getCellSize();

	private:
		static bool _isPaused;
		static bool _isReset;
		static size_t _tickTime;
		static std::map<std::string, unsigned int> _argNb;
};
