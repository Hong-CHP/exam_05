/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:43:38 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/29 13:54:37 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set()
{
	_target = nullptr;
}

set::set(searchable_bag	&target): _target(&target)
{
}

set::set(const set &src): _target(src._target)
{
}

set&	set::operator=(const set &src) 
{
	if (this != & src) {
		_target = src._target;
	}
	return *this;
}

set::~set()
{
}

bag&	set::get_bag() const 
{
	return *_target;	
}

bool	set::has(int val) const
{
	return _target->has(val);
}

void	set::insert(int item)
{
	if (has(item))
		return ;
	_target->insert(item);
}

void	set::insert(int *items, int count)
{
	for (size_t i = 0; i < count; ++i)
		insert(items[i]);
}

void	set::print() const
{
	_target->print();
}

void	set::clear()
{
	_target->clear();
}