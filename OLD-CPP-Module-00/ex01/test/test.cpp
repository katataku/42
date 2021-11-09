/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:48:51 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/09 17:25:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../phonebook.hpp"
#include "../contact.hpp"


TEST(phonebook, count_0)
{
	PhoneBook a;
	EXPECT_EQ(a.contact_count ,0);
}

TEST(phonebook,count_1)
{
	PhoneBook a;
	contact contact;
	
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,1);
}

TEST(phonebook,count_max)
{
	PhoneBook a;
	contact contact;
	contact.set_first_name("1");

	a.add_contact(contact);
	contact.set_first_name("2");
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,7);
	EXPECT_EQ(a.contact_array[0].get_first_name() ,"1");
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,8);
	EXPECT_EQ(a.contact_array[0].get_first_name() ,"1");
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,8);
	EXPECT_EQ(a.contact_array[0].get_first_name() ,"2");
}

TEST(phonebook,content_init)
{
	PhoneBook a;
	contact contact;
	
	EXPECT_EQ(a.show_contact(0),"");
}

TEST(phonebook,content_add)
{
	PhoneBook a;
	contact contact;
	
	contact.set_first_name("12345678901");
	contact.set_last_name("1234567890");
	contact.set_nickname("123456789");
	a.add_contact(contact);
	EXPECT_EQ(a.show_contact(0),"         0|123456789.|1234567890| 123456789");
}