/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:34:22 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/29 13:01:50 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

# include "array_bag.hpp"
# include "searchable_bag.hpp"
# include <iostream>

class searchable_array_bag: public array_bag, public searchable_bag
{
public:
	searchable_array_bag();
	searchable_array_bag(const searchable_array_bag &);
	searchable_array_bag &operator=(const searchable_array_bag &other);
	~searchable_array_bag();
	
	bool	has(int) const;
};

#endif