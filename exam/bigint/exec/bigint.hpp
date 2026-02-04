/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:33:58 by hporta-c          #+#    #+#             */
/*   Updated: 2026/01/29 18:26:41 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <stdlib.h>

class bigint
{
private:
    std::string data;
public:
	bigint();
	bigint(unsigned int num);
	bigint(const std::string &str);
	bigint(const bigint& src);
	bigint&	operator=(const bigint &other);
	~bigint();
	
	bigint operator+(const bigint &other) const;
	bigint& operator+=(const bigint &other);
	
	bigint& operator++();
	bigint operator++(int);
	
	bigint operator<<(int) const;
	bigint operator>>(int) const;
	bigint& operator<<=(int);
	bigint& operator>>=(int);
	bigint& operator<<=(const bigint &k);
	bigint& operator>>=(const bigint &k);

	bool	operator==(const bigint& other) const;
	bool	operator!=(const bigint& other) const;
	bool	operator>(const bigint& other) const;
	bool	operator>=(const bigint& other) const;
	bool	operator<(const bigint& other) const;
	bool	operator<=(const bigint& other) const;

	const std::string& getData() const;
	
};

std::ostream&	operator<<(std::ostream& os, const bigint& obj);

#endif