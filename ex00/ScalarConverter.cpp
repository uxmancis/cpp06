/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:03:29 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/18 18:04:45 by uxmancis         ###   ########.fr       */
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

/*
*   Pseudo-literals: -inff, +inff, nanf, -inf, +inf, nan
*       +inf/-inf --> Positive or negative infinity
*       nan/nanf --> Not a Number
*/
bool isPseudoDisplay(std::string input_str)
{
    const std::string pseudo_double[3] = {"-inf", "+inf", "nan"};
    const std::string pseudo_float[3] = {"-inff", "+inff", "nanf"};
    
    int occurrences_double = std::count(pseudo_double, pseudo_double + 3, input_str);
    int occurrences_float = std::count(pseudo_float, pseudo_float + 3, input_str);
    // std::cout << "occurrences = " << occurrences << std::endl;
    if (occurrences_double == 0 && occurrences_float == 0)
        return (false);
    else
    {
        std::cout << "char: " << "impossible" << "\n";
		std::cout << "int: " << "impossible" << "\n";
        if (occurrences_double > 0) //If double
        {   
            std::cout << "float : " << input_str << "f" << std::endl; //f is added at the end
            std::cout << "double: " << input_str << std::endl;
        }
        else if (occurrences_float > 0)
        {
            std::cout << "float: " << input_str << std::endl;
            std::cout << "double: " << input_str.substr(0, input_str.size() - 1) << std::endl;
        }
        return (true);
    }
        
}

/* Details:
*
*   isprint: checks whether if character is printable
*       0: no printable character
*       Any other number different from 0: YES it is a printable character
*
*   isdigit: checks whether if character is a digit
*       0: no digit
*       Any other number different from 0: YES it is a printable character
*
*/
bool ScalarConverter::isChar(const std::string &input_str)
{
    if (input_str.size() == 1 && isprint(input_str[0]) && !isdigit(input_str[0]))
        return (true);
    return (false);
}

/* is_all_digits: checks whether if 100% of characters are digits or not.
*
*   Returns:
*       0: NO, NOT 100% characters are digits
*       1: YES, 100% characters are digits
*/
bool ScalarConverter::isAllDigits(const std::string &input_str)
{
    // std::cout << "input_str = " << input_str << std::endl;
    bool all_digits = (std::find_if(input_str.begin(), 
                                    input_str.end(), 
                                    std::not1(std::ptr_fun<int,int>(std::isdigit))) == input_str.end());
    
    // std::cout << ">> Is all digits? " << all_digits << std::endl;
    return (all_digits);
}

bool ScalarConverter::isValidRange(const std::string &input_str)
{
    long value = std::atol(input_str.c_str());

    if (value >= INT_MIN && value <= INT_MAX)
        return (true);
    return(false);
}

/* isInt: checks whether if it is a valid int
*
*       1.- is_all_digits: Makes sure 100% of characters are digits
*       2.- is_valid_range: Makes sure digits are between INT MIN and INT MAX range = Valid INT 
*/
bool ScalarConverter::isInt(const std::string &input_str)
{
    // std::cout << "isInt, input_str = " << input_str << std::endl;

    std::string substr_no_sign;

    //If there is sign, when checking if all_digits, go with substr
    if (input_str[0] == '+' || input_str[0] == '-')
    {
        substr_no_sign = input_str.substr(1, input_str.size());
        if (isAllDigits(substr_no_sign) && isValidRange(input_str))
            return (true);
        return(false);
    }
    else //If no sign, we check 100% of characters are digits. This is int, no dot possible! :)
    {
        if (isAllDigits(input_str) && isValidRange(input_str))
            return (true);
        return (false);
    }   
    return (false);
}


/* is_only_one_dot_and_exp checks the followings:
*   1.- 1 dot '.' at most.
*   2.- 1 exponent 'e' or 'E' at most.
*   3.- '-' and '+' 2 at most, 1 as a sign and another one after exponent.
*   4.- rest are digits --> is now commented as we're also using it for floats, which 
*       have a 'f' or 'F' at the end. total_sum and count_digits are commented as well.
*
*/
bool ScalarConverter::is_only_one_dot_and_exp(const std::string &input_str)
{
    int count_dot = std::count(input_str.begin(), input_str.end(), '.');
    int count_exp_low = std::count(input_str.begin(), input_str.end(), 'e');
    int count_exp_up = std::count(input_str.begin(), input_str.end(), 'E');
    int count_plus = std::count(input_str.begin(), input_str.end(), '+');
    int count_minus = std::count(input_str.begin(), input_str.end(), '-');
    // int total_sum = count_dot + count_exp_low + count_exp_up + count_plus + count_minus;
    // int count_digits = std::count_if(input_str.begin(), input_str.end(), std::ptr_fun<int,int>(std::isdigit));
    
    if (count_dot <=1 && (count_exp_low + count_exp_up) <=1
        && (count_plus + count_minus)<=2 
        /*&& (((int)input_str.length() - total_sum) == count_digits)*/)
    {
        // printf("yes here yes\n");
        return(true);
    }
        
    // printf("we're saying false here\n");
    return(false);
}

/* is_order_ok: checks to make sure if input_str could be a legit double.
*      Returns:
*           true: OK proper double format
*           false: KO no proper double format
*   
*
*   In which cases does it tell us that's not a proper format for being a double?
*       1.- A different character from DIGIT or DOT '.' follows sign. Not possible.
*       2.- There is no digit after 'e' or 'E'.
*
*   If input_str passes all of the checks, is_order_ok function finally returns true.
*
**/
bool ScalarConverter::is_order_ok(const std::string &input_str)
{
    int i;
    
    i = 0;
        
    //Sign must go at the beginning (optional). If sign, it's OK move on.
    if(input_str[i] == '+' || input_str[i] == '-')
        i++;

    //After the sign it must follow a digit or a dot. If not, that's not a legit double. 
    //Apart from those, there could only be 'E' or 'e', but not acceptable after sign,
    //as they must have digits previously.
    if (!isdigit(input_str[i]) && input_str[i] != '.')
        return (false);
    
    //Particularly a dot? OK Move on.
    if (input_str[i])
        i++;
    
    //While digit it's OK, move on.
    while ((input_str[i] && isdigit(input_str[i])) || (input_str[i] && input_str[i] == '.'))
        i++;

    //If 'e' or 'E' are found, make sure there are digits after those.
    if ((input_str[i] == 'e' || input_str[i] == 'E'))
    {
        i++;
        // printf("i = %d, input_str[%d] = %c\n", i, i, input_str[i]);
        // printf("yes/no, isdigit = %d\n", isdigit(input_str[i]));
        if (input_str[i] && (!isdigit(input_str[i]) && input_str[i] != '-' && input_str[i] != '+'))
            return (false);
    }
    return (true);
}

bool ScalarConverter::is_substr_double(const std::string &input_str)
{
    std::string substr = input_str.substr(0, input_str.size() - 1);

    if (isDouble(substr))
        return (true);
    printf("substr is NOT double\n");
    return (false);
}


bool ScalarConverter::isFloat(const std::string &input_str)
{
    if (is_substr_double(input_str) 
        && ((input_str[input_str.size() - 1] == 'f') 
            || (input_str[input_str.size() - 1] == 'F')))
        return (true);
    return (false);
}

bool ScalarConverter::isDouble(const std::string &input_str)
{
    if (is_only_one_dot_and_exp(input_str) && is_order_ok(input_str))
        return (true);
    return (false);
}

int ScalarConverter::detectLiteral(const std::string &input_str)
{
    // std::cout << "detecLiteral, input_str = " << input_str << std::endl;
    if (isChar(input_str))
		return (CHAR);
	if (isInt(input_str))
		return (INT);
	if (isFloat(input_str))
		return (FLOAT);
	if (isDouble(input_str))
		return (DOUBLE);
	return(INVALID);
}

/* convert member function: converts std::string to the following
* scalar types:
*   > char: 'c', 'a', ...
*   > int: 42, 56, 21, 9, -780, ...
*   > float: 0.0f, -4.2f, 4.2f, ... (4 bytes, 32 bits normalmente, 7 cifras decimales significativas)
*   > double: 0.0, -4,2, 4,2, ... (8 bytes, 64 bits normalmente, 15-16 cifras decimales significativas)
*       E.g.:
*          float x = 1.0f / 3.0f;   // ~0.33333334  (7 dígitos)
*          double y = 1.0  / 3.0;   // ~0.3333333333333333 (15 dígitos)
*       Using double by default is recommended, while using float when you're willing to save memory.
*
*   Scalar type means indivisible unitary value.
*
*/
int ScalarConverter::convert(const std::string &input_str)
{
    if (isPseudoDisplay(input_str))
        return(1);
    else
    {
        switch (ScalarConverter::detectLiteral(input_str))
        {
            case CHAR:
            {
                std::cout << "CHAR - pdte." << std::endl;
                return(3);
            }
            case INT:
            {
                std::cout << "INT - pdte." << std::endl;
                return(3);
            }
            case FLOAT:
            {
                std::cout << "FLOAT - pdte." << std::endl;
                return(3);
            }
            case DOUBLE:
            {
                std::cout << "DOUBLE - pdte." << std::endl;
                return(3);
            }
            case INVALID:
                std::cerr << "Error: invalid input" << std::endl;
                return (1);
            default:
                std::cerr << "Unexpected Error: ScalarConverter can not convert " << input_str << std::endl;
                return (2);
        }
        return (0);
    }
    
}

