/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:52:37 by yuhwang           #+#    #+#             */
/*   Updated: 2022/08/03 19:08:28 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	std::string str;
	std::string tmp;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		tmp = argv[i];
		for (size_t j = 0; j < tmp.length(); j++) {
			str += std::toupper(tmp[j]);
		}
	}
	std::cout << str << std::endl;
	return 0;
}
