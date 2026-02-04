/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:06:22 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/29 13:14:44 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src): tree_bag(src)
{
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other) {
		tree_bag::operator=(other);
	}
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool	searchable_tree_bag::has(int val) const
{
	if (tree == nullptr)
		return false;
	node* cur = tree;
	while (cur != nullptr) {
		if (val < cur->value)
			cur = cur->l;
		else if (val > cur->value)
			cur = cur->r;
		else
			return true;
	}
	return false;
}