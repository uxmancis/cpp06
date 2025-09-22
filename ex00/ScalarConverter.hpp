/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:03:20 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/18 17:11:07 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
    public:
        ScalarConverter();        
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);       
        ~ScalarConverter();
      
    private:
        /* Member function: */
        static bool isChar(const std::string &input_str);
        static bool isInt(const std::string &input_str);
            static bool isAllDigits(const std::string &input_str);
            static bool isValidRange(const std::string &input_str);

        static bool isFloat(const std::string &input_str);
            static bool is_substr_double(const std::string &input_str);

        static bool isDouble(const std::string &input_str);
            static bool is_order_ok(const std::string &input_str);
            static bool is_only_one_dot_and_exp(const std::string &input_str);
        static int detectLiteral(const std::string &input_str);

        
    public:
        /* A static member function can be called without creating
        * an instance (object) of the class. */
        static int32_t convert(const std::string &input); /* Subject says the class must not be instantiable */
};

#endif

//TO-DO
// 1.- 'a' or a ? How should chars be passed ass argument to my program?
// 2.- '0' is currently  identified as int. What happens with single columns?

// Lista de casuísticas que no está identificando bien:
// 3.14
// -0.5