/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:03:29 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/17 16:10:35 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/* Default Constructor */
ScalarConverter::ScalarConverter()
{}

/* Copy constructor */
ScalarConverter::ScalarConverter(const ScalarConverter &src_to_copy)
{
    *this = src_to_copy;
}

/* Copy Assignment Operator */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src_to_copy)
{
    (void)src_to_copy; //in this case as no attributes, this would be enough for OCF
    return (*this);
}

/* Destructor */
ScalarConverter::~ScalarConverter()
{}

/* Member function */
void ScalarConverter::convert(const std::string &str)
{
    (void)str;
}

