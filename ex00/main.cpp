/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:27:36 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/17 16:36:21 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool is_pseudo(std::string input_str)
{
    const char *arr[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    int occurrences = std::count(arr, arr + 6, input_str);
    std::cout << "occurrences = " << occurrences << std::endl;
    if (occurrences == 0)
        return (false);
    else
        return (true);
}

int main(void)
{
    std::string input_str;

    if (is_pseudo(input_str))
        std::cout << "Pseudo-literal, not possible to print" << std::endl;

    
    std::string str1 = "uxue";
    std::string str2 = "uxue";

    if (str1 == str2)
        std::cout << "yess same" << std::endl;
    else
        std::cout << "NOT the same" << std::endl;

    
    
    return (0);
}
