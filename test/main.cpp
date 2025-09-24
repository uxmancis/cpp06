/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:25:10 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/24 14:06:06 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* static_cast */
#include <iostream>
#include <stdlib.h>

/*************************** STATIC_CAST ************************** */
/* Casts:
*    C style cast: compiler decides which cast type to use (static_cast, reinterpret_cast
*    or const_cast). "Do whatever conversion you can, compiler, I don't care"
*
*    C++ style cast: more explicit, we choose conversion type. "Choose a safe, checked, 
*    compile--time conversion."
*
*    *For simple type conversions (double->int, int->float, char->int, ...) they produce
*    the same result at runtime. The difference is i the safety & clarity.
*
*/
int main()
{
    // double x = 3.9;

    // int a = (int)x;                // cast estilo C
    // int b = static_cast<int>(x);   // cast estilo C++

    // std::cout << "x = " << x << "\n";
    // std::cout << "a = " << a << " (cast estilo C)\n";
    // std::cout << "b = " << b << " (static_cast)\n";

    /* TODO: convert these with static_cast*/
    // double d = 7.8;
    // int i = 42;
    // char c = 'A';
    
    // int d_to_i = static_cast<int>(d);
    // double i_to_d = static_cast<double>(i);
    // float d_to_f = static_cast<float>(d);
    // int c_to_i = static_cast<int>(c);
    // char i_to_c = static_cast<char>(i);

    // std::cout << "d_to_i = " << d_to_i << std::endl;
    // std::cout << "d_to_f = " << d_to_f << std::endl;
    // std::cout << "i_to_d = " << i_to_d << std::endl;
    // std::cout << "c_to_i = " << c_to_i << std::endl;
    // std::cout << "i_to_c = " << i_to_c << std::endl;

    std::string str = "3.456";
    int i = 1;
    // str = str + i;
    std::cout << str << std::endl;
    float f = std::atof(str_c.str()) + i;
    std::cout << "float = " << f << std::endl;
}


/*************************************************************************** */


// #include <iostream>

// struct Base { virtual ~Base() {} }; /*destructor virtual = permite a dynamic_cast saber en
// tiempo de ejecución si un objeto realmente es de tipo Derivada o no*/.

// struct Derivada : Base {};

// int main()
// {
//     Derivada d;
//     Base& ref = d;   // referencia a un Derivada

//     // static_cast con referencia
//     Derivada& s = static_cast<Derivada&>(ref); // correcto

//     // dynamic_cast con referencia
//     try
//     {
//         Derivada& d_ok = dynamic_cast<Derivada&>(ref); // correcto
//         std::cout << "dynamic_cast correcto\n";
//     }
//     catch (std::bad_cast&)
//     {
//         std::cout << "dynamic_cast fallo\n";
//     }
//     return 0;
// }
