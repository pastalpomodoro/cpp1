/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:41:18 by alacroix          #+#    #+#             */
/*   Updated: 2025/06/19 11:44:09 by alacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	public:
		Data();
		Data (int value);
		Data(Data const &other);
		~Data();

		Data &operator=(Data const &other);

		int getValue() const;

	private:
		int	_value;
};

#endif
