/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:28:21 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 13:51:32 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

std::ostream&	operator<<(std::ostream& os, const bigint& obj)
{
	os << obj.getData();
	return os;
}

bigint::bigint(): data("0")
{
}

bigint::bigint(unsigned int num)
{
	if (num == 0) {
		data = "0";
		return ;
	}
	while (num > 0)
	{
		data.insert(data.begin(), num % 10 +'0');
		num /= 10;
	}
}

bigint::bigint(const std::string &str)
{
	data.clear();
	data = str;
}

bigint::bigint(const bigint& src)
{
	data = src.data;
}

bigint&	bigint::operator=(const bigint &other) 
{
	if (this != &other) {
		this->data.clear();
		this->data = other.data;
	}
	return *this;
}

bigint::~bigint()
{
	data.clear();
}

const std::string& bigint::getData() const 
{
	return data;
}

bigint	bigint::operator+(const	bigint &other) const
{
	std::string aa = getData();
	std::string bb = other.getData();

	int i = aa.size();
	int j = bb.size();
	
	if (i < j) {
		aa.insert(0, j - i, '0');
	} else if (j < i) {
		bb.insert(0, i - j, '0');	
	}
	
	int carry = 0;
	std::string res;
	res.clear();
	for (int k = aa.size() - 1; k >= 0; --k) {
		int sum = (aa[k] - '0') + (bb[k] - '0') + carry;
		res.insert(res.begin(), (sum % 10) + '0');
		carry = sum / 10;
	}
	if (carry > 0)
		res.insert(res.begin(), carry + '0');
	return bigint(res);
}

bigint&	bigint::operator+=(const bigint &other)
{
	*this = *this + other;
	return *this;
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint	 bigint::operator++(int)
{
	bigint	tmp(*this);
	*this = *this + bigint(1);
	return tmp;
}

bigint	bigint::operator<<(int k) const
{
	if (k <= 0)
		return bigint(data);
	
	std::string res = data;
	res.append(k, '0');
	return bigint(res);
}

bigint	bigint::operator>>(int k) const
{
	if (k <= 0)
		return bigint(data);
	if ((size_t)k >= data.size())
		return bigint(0);
	std::string res = data.substr(0, data.size() - k);
	return bigint(res);
}


bigint&	bigint::operator<<=(int k)
{
	if (k <= 0)
		return *this;
	
	std::string res = data;
	res.append(k, '0');

	data = res;
	return *this;
}

bigint&	bigint::operator>>=(int k)
{
	if (k <= 0)
		return *this;
	if ((size_t)k >= data.size()) {
		data = "0";
		return *this;
	}
	std::string res = data.substr(0, data.size() - k);
	data = res;
	return *this;
}

bigint& bigint::operator<<=(const bigint &k)
{
	int shift = atoi(k.getData().c_str());
	return *this <<= shift;	
}

bigint& bigint::operator>>=(const bigint &k)
{
	int shift = atoi(k.getData().c_str());
	return *this >>= shift;	
}

bool	bigint::operator==(const bigint& other) const {
	if (this->data.compare(other.data) == 0)
		return true;
	else
		return false;
}


bool	bigint::operator!=(const bigint& other) const {
	if (this->data.compare(other.data) != 0)
		return true;
	else
		return false;
}

bool	bigint::operator<(const bigint& other) const {
	if (this->data.size() < other.data.size())
		return true;
	else if (this->data.size() > other.data.size())
		return false;
	return data < other.data;
}

bool	bigint::operator>(const bigint& other) const {
	return other < *this;
}

bool	bigint::operator<=(const bigint& other) const {
	return !(*this > other);
}

bool	bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}

