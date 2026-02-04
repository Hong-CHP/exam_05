/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:10:12 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/21 13:14:35 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag *target_bag;

	public:
		set();
		set(searchable_bag &data);
		set(const set &);
		set& operator=(const set &src);
		~set();

		searchable_bag&	get_bag();
};

set::set(): target_bag(nullptr) {
}

set::set(searchable_bag &data): target_bag(&data) {
}

set::set(const set &src): target_bag(src.target_bag) {
}

set&	set::operator=(const set &src) {
	if (this != &src) {
		target_bag = src.target_bag;
	}
	return *this;
}

set::~set() {}

searchable_bag&	set::get_bag() {
	return *target_bag;
}

#endif