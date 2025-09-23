/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:58:43 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/23 11:49:46 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

Base *generate(void)
{
    int r = std::rand() % 3; //returns 0, 1 and 2 (std::rand() % RANGE_MAX + 1)

    switch(r)
    {
        case 0:
        {
            std::cout << "A class" << std::endl;
            return (new A);
        }
        case 1:
        {
            std::cout << "B class" << std::endl;
            return (new B);
        }
        case 2:
        {
            std::cout << "C class" << std::endl;
            return (new C);
        }
        default: /* Not expected behaviour */
        {
            std::cout << "D class" << std::endl;
            return (new D);
        }
    }
}

void identify(Base  *p)
{
    if (dynamic_cast<A*>(p)) //devuelve NULL si falla
        std::cout << "Identified by pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified by pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified by pointer: C" << std::endl;
    else
        std::cout << "Unknown type (pointer)" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified by reference: A" << std::endl;
        return;
    } 
    catch (const std::exception&){}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified by reference: B" << std::endl;
        return;
    }
    catch (const std::exception&){}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified by reference: C" << std::endl;
        return;
    }
    catch (const std::exception&){}
    
    std::cout << "Unknown type (reference)" << std::endl;
}

int main(void)
{
    /* A pointer that points a Base class type class is created,
    *  whatever that derived object is. */
    Base *ptr = generate();
    // (void)ptr;
    
    /* Identifies using pointer */
    identify(ptr);

    /* Identifies using reference */
    identify(*ptr);

    delete (ptr);
    return (0);
}