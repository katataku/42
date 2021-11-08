/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:48:51 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/08 18:24:54 by takkatao         ###   ########.fr       */
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
	
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,7);
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,8);
	a.add_contact(contact);
	EXPECT_EQ(a.contact_count ,8);
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
	
	contact.first_name = "12345678901";
	contact.last_name = "1234567890";
	contact.nickname = "123456789";
	a.add_contact(contact);
	EXPECT_EQ(a.show_contact(0),"         0|123456789.|1234567890| 123456789");
}