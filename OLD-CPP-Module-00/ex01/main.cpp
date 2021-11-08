/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:38:43 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/08 18:03:59 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

int main(void)
{
	PhoneBook phonebook;

	std::string input;
	while(1)
	{
		std::cout << "input Command : ";
		std::cin >> input;
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook.add_contact_wrapper();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else 
			std::cout << "incorrect input!!" << std::endl;
		
	}
	return (0);
}
