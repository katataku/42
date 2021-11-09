/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:38:43 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/09 17:23:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
}

std::string PhoneBook::truncate_10(std::string str)
{
	std::string ans;

	if (str.length() <= 10)
	{
		ans = str;
		while  (ans.length() < 10)
			ans = " " + ans;
		return (ans);
	}
	return (str.substr(0,9) + ".");
}

int PhoneBook::add_contact(contact contact)
{
	if (this->contact_count >= 8)
	{
		for (int i = 0; i < 7; i++)
		{
			this->contact_array[i] = this->contact_array[i+1];
		}
		this->contact_count--;
	}
	this->contact_array[this->contact_count] = contact;
	this->contact_count++;
	return(0);
}

int PhoneBook::add_contact_wrapper()
{
	contact contact;
	std::string str;

	std::cout << "input first name : ";
	std::cin >> str;
	contact.set_first_name(str);

	std::cout << "input last name : ";
	std::cin >> str;
	contact.set_last_name(str);

	std::cout << "input nickname : ";
	std::cin >> str;
	contact.set_nickname(str);

	std::cout << "input phone number : ";
	std::cin >> str;
	contact.set_phone_number(str);

	std::cout << "input darkest secret : ";
	std::cin >> str;
	contact.set_darkest_secret(str);

	this->add_contact(contact);
	
	return(0);
}


std::string PhoneBook::show_contact(int i)
{
	std::string ans = "";
	
	if (this->contact_count > i)
	{
		ans += PhoneBook::truncate_10(std::to_string(i)) + "|";
		ans += PhoneBook::truncate_10(this->contact_array[i].get_first_name()) + "|";
		ans += PhoneBook::truncate_10(this->contact_array[i].get_last_name()) + "|";
		ans += PhoneBook::truncate_10(this->contact_array[i].get_nickname()) ;
	}
	return (ans);
}

int PhoneBook::search_contact()
{
	for (int i = 0; i < this->contact_count; i++)
		std::cout << this->show_contact(i) << std::endl;
	return(0);
}
