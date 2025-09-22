/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 10:45:51 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/22 11:45:53 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/* The objective of the exercise: 
*
*   Take the address of a pointer as an input. 
*   Pointer --> serialize() --> unsigned int.
*   unsigned int --> deserialize() --> pointer.
*
*/
int main(void)
{
    /* Test 1: Make sure Serializer objects are not instantiable */
    // Serializer s; //Uncomment and make sure it doesn't compile

    /* Test 2: serialize() and deserialize() work as expected */
    Data *ptr1 = new Data;
    std::cout << "Pointer address (hex): " << ptr1 << std::endl;
    
    uintptr_t decimal = Serializer::serialize(ptr1);
    std::cout << "As integer (decimal): " << decimal << std::endl;

    Data *ptr2 = Serializer::deserialize(decimal);
    std::cout << "Pointer2 address (hex):" << ptr2 << std::endl;

    /* Test 3: pointers ptr1 and ptr2 are the exact same */
    if (ptr1 == ptr2)
        std::cout << GREEN "Both pointers point to the same address!" RESET_COLOUR << std::endl;
    else
        std::cout << RED "Different addresses." RESET_COLOUR << std::endl;
    
    /* Delete is only called once. Reason? we'd be calling delete twice for the same memory
    address, as ptr1 and ptr2 point the same memory addres*/
    delete(ptr1);
    
    return (0);
}
