/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:38:43 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/08 18:26:41 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

std::string truncate_10(std::string str)
{
	std::string ans;

	if (str.length() <= 10)
	{
		ans = str;
		while  (ans.length() < 10)
			ans = " " + ans;
		return (ans);
	}
	return (str.substr(0,9) + ".")	;
}

int PhoneBook::add_contact(contact contact)
{
	if (this->contact_count < 8)
	{
		this->contact_array[this->contact_count] = contact;
		this->contact_count++;
	}
	return(0);
};

int PhoneBook::add_contact_wrapper()
{
	if (this->contact_count <8)
	{
		contact contact;

		std::cout << "input first name : ";
		std::cin >> contact.first_name;

		std::cout << "input last name : ";
		std::cin >> contact.last_name;

		std::cout << "input nickname : ";
		std::cin >> contact.nickname;

		std::cout << "input phone number : ";
		std::cin >> contact.phone_number;

		std::cout << "input darkest secret : ";
		std::cin >> contact.darkest_secret;

		this->add_contact(contact);
	}
	else
	{
		std::cout << "ERROR! Full Contacts Resistered." << std::endl;
	}

	return(0);
};


std::string PhoneBook::show_contact(int i)
{
	std::string ans = "";
	
	if (this->contact_count > i)
	{
		ans += truncate_10(std::to_string(i)) + "|";
		ans += truncate_10(this->contact_array[i].first_name) + "|";
		ans += truncate_10(this->contact_array[i].last_name) + "|";
		ans += truncate_10(this->contact_array[i].nickname) ;
	}
	return (ans);
};

int PhoneBook::search_contact()
{
	for (int i = 0; i < this->contact_count; i++)
		std::cout << this->show_contact(i) << std::endl;
	return(0);
};
