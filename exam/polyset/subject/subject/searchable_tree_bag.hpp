/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:45:39 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/21 12:05:28 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "tree_bag.hpp"
# include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &src);
		searchable_tree_bag &operator=(const searchable_tree_bag &src);
		~searchable_tree_bag();

		virtual bool has(int value) const;
};

searchable_tree_bag::searchable_tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src): tree_bag(src) {
	
}

searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag &src) {
	if (this != &src) {
		tree_bag::operator=(src);
	}
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool	searchable_tree_bag::has(int value) const {
	node *cur = tree;
	while (cur != nullptr) {
		if (cur->value == value)
			return true;
		else if (value < cur->value)
			cur = cur->l;
		else if (value > cur->value)
			cur = cur->r;
	}
	return false;
}

#endif