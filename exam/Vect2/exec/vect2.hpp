/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:10:42 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 11:27:14 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2
{
	private:
		int v_x;
		int v_y;
	public:
		vect2();
		vect2(int, int);
		vect2(const vect2 &src);
		vect2& operator=(const vect2 &other);
		~vect2();
	
		vect2	operator+() const;
		vect2	operator-() const;
		vect2	operator+(const vect2& other) const;
		vect2	operator-(const vect2& other) const;
		vect2	operator*(const int) const;
		
		vect2&	operator++();
		vect2	operator++(int);
		
		vect2&	operator--();
		vect2	operator--(int);
		
		vect2& operator+=(const vect2 &other);
		vect2& operator-=(const vect2 &other);
		vect2& operator*=(int);

		bool operator==(const vect2 &other) const;
		bool operator!=(const vect2 &other) const;

		int& operator[](int);
		const int& operator[](int) const;
		
	friend std::ostream& operator<<(std::ostream& os, const vect2& obj);
};

vect2	operator*(const int, const vect2& obj);

#endif