/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:17:27 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/29 13:54:54 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"
#include <iostream>

class set
{
private:
	searchable_bag *_target;
public:
	set();
	set(searchable_bag &target);
	set(const set &src);
	set&	operator=(const set &src);
	~set();

	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();
	bool has(int) const;
	bag& get_bag() const;
};

#endif