/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:38:43 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/09 17:24:12 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string contact::get_first_name(void)
{
	return (this->first_name);
}

std::string contact::get_last_name(void)
{
	return (this->last_name);
}

std::string contact::get_nickname(void)
{
	return (this->nickname);
}

std::string contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}


void contact::set_first_name(std::string str)
{
	this->first_name = str;
}
void contact::set_last_name(std::string str)
{
	this->last_name = str;
}
void contact::set_nickname(std::string str)
{
	this->nickname = str;
}
void contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}
void contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}
