/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameState.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:54:33 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/29 15:54:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Defines.hpp"

#include <unistd.h>

class GameState {
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
