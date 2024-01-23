/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:46:18 by rbroque           #+#    #+#             */
/*   Updated: 2024/01/23 10:29:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Config {

	public:

		// Setters
		static void togglePaused();
		// Getters
		static bool isPaused();

	private:
		static bool _isPaused;
};
