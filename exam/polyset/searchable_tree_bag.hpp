/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:02:50 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/29 13:03:36 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"
# include <iostream>

class searchable_tree_bag: public tree_bag, public searchable_bag
{
public:
	searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag &);
	searchable_tree_bag &operator=(const searchable_tree_bag &other);
	~searchable_tree_bag();
	
	bool	has(int) const;
};

#endif