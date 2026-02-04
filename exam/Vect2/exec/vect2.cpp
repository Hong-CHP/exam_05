/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:12:30 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 11:27:48 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

std::ostream& operator<<(std::ostream& os, const vect2& obj) {
	os << "{" << obj.v_x << ", " << obj.v_y << "}";
	return os;
}

vect2	operator*(const int scalar, const vect2& obj) {
	return obj * scalar;
}

vect2::vect2(): v_x(0), v_y(0) {}

vect2::vect2(int x, int y): v_x(x), v_y(y) {}

vect2::vect2(const vect2 &src): v_x(src.v_x), v_y(src.v_y) {}

vect2& vect2::operator=(const vect2 &other) {
	if (this != &other) {
		v_x = other.v_x;
		v_y = other.v_y;
	}
	return *this;
}

vect2::~vect2() {}

vect2	vect2::operator+() const {
	return *this;
}

vect2	vect2::operator-() const {
	return vect2(-v_x, -v_y);
}

vect2	vect2::operator+(const vect2& other) const {
	int _x = v_x + other.v_x;
	int _y = v_y + other.v_y;
	return vect2(_x, _y);
}

vect2	vect2::operator-(const vect2& other) const {
	int _x = v_x - other.v_x;
	int _y = v_y - other.v_y;
	return vect2(_x, _y);
}


vect2	vect2::operator*(const int scalar) const {
	int _x = v_x * scalar;
	int _y = v_y * scalar;
	return vect2(_x, _y);
}

vect2&	vect2::operator++() {
	this->v_x++;
	this->v_y++;
	return *this;
}

vect2	vect2::operator++(int) {
	vect2 tmp = *this;
	this->v_x++;
	this->v_y++;
	return tmp;
}

vect2&	vect2::operator--() {
	this->v_x--;
	this->v_y--;
	return *this;
}

vect2	vect2::operator--(int) {
	vect2 tmp = *this;
	this->v_x--;
	this->v_y--;
	return tmp;
}

vect2& vect2::operator+=(const vect2 &other) {
	*this = *this + other;
	return *this;
}

vect2& vect2::operator-=(const vect2 &other) {
	*this = *this - other;
	return *this;
}

vect2& vect2::operator*=(int scalar) {
	*this = *this * scalar;
	return *this;
}

bool vect2::operator==(const vect2 &other) const {
	if (this->v_x == other.v_x && this->v_y == other.v_y)
		return true;
	return false;
}

bool vect2::operator!=(const vect2 &other) const {
	if (*this == other)
		return false;
	return true;
}

int& vect2::operator[](int idx) {
	if (idx > 1 || idx < 0)
		throw std::out_of_range("Out of bound vect2");
	if (idx == 0)
		return v_x;
	else
		return v_y;
}

const int& vect2::operator[](int idx) const {
	if (idx > 1 || idx < 0)
		throw std::out_of_range("Out of bound vect2");
	if (idx == 0)
		return v_x;
	else
		return v_y;
}