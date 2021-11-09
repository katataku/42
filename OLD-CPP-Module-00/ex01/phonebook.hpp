/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:38:43 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/09 15:47:23 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <string> 
#include <iostream>
# include "contact.hpp"

class PhoneBook
{
	private:
		std::string truncate_10(std::string str);

	public:
		contact contact_array[8];
		int			contact_count;
		int 		add_contact(contact contact);
		int 		add_contact_wrapper();
		int			search_contact();
		std::string	show_contact(int index);
		PhoneBook();

};

#endif
