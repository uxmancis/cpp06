/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:36 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/18 13:17:19 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    if (argc != 2)
        std::cout << "Invalid input" << std::endl;
    else
    {
        ScalarConverter::convert((std::string)argv[1]);
    }

    return (0);
}
