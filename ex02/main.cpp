/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:58:43 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/24 16:16:25 by uxmancis         ###   ########.fr       */
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

/*
*   dynamic_cast<T*>(p) --> returns nullptr if the cast fails.
*
*   p: pointer to the base class.
*   > At compile time the compiler only knows "this is a Base"
*   > At runtime, p might actually be pointing to an A, B or C.
*
*   dynamic_cast lets us safely ask the runtime, hey, is this Base*
*   really an A*, or B* or C*? If so, give me that pointer. If not,
*   return nullptr.
*
*   Conclusion: the dynamic_cast<X*>(p) that actually exists (checked
*   by if conditions) is the one that is printed. :)
*/
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


/*  dynamic_cast<T&>(p) --> cannot return "no object", so instead it
*   throws std::bad_cast. That's why the function wraps each cast in
*   a try/catch. */
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

/* Exercise summary:
*   Challenge: How can we figure out which derived type (A, B or C)
*              it really is, if we get only a Base* or Base& to some
*              object?
*
*   Solution:
*   1) We'll use dynamic_cast in this exercise. Why? It uses RTTI
*      (Run-Time Type Information) t safely check the real type
*      behind a polymorphic base pointer/reference.
*
*   2) Take into account what does dynamic_cast return in each case:
*           a) Pointer case: void identify(Base* p); --> 
*                   dynamic_cast returns nullptr if not valid pointer.
*
*           b) Reference case: void identify(Base& p);
*                   dynamic_cast sends std::bad_cast exception, take with
*                   try/catch.
*/
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