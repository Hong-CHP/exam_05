/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:01:22 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 14:02:25 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(): array_bag()
{
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &src): array_bag(src)
{
}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other) {
		array_bag::operator=(other);
	}
	return *this;
}

searchable_array_bag::~searchable_array_bag()
{
}

bool	searchable_array_bag::has(int val) const
{
	for (int i = 0; i < size; ++i) {
		if (data[i] == val)
			return true;
	}
	return false;
}