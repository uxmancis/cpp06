/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:36 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/24 11:56:05 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    if (argc != 2)
    {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Example: ./convert 3,3.5" << std::endl;
    }
        
    else
    {
        ScalarConverter::convert((std::string)argv[1]);
    }

    return (0);
}

//To solve: 3,3.5

