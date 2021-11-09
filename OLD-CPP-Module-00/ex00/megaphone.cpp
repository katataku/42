/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:38:43 by takkatao          #+#    #+#             */
/*   Updated: 2021/11/09 17:57:27 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string> 

int main(int argc, char** argv)
{
	std::string str;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (int j = 0; argv[i][j] != '\0'; j++)
			{
				std::cout << (char)std::toupper(str[j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
