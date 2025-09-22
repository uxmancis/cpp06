/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:09:53 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/22 11:40:14 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/* Default Constructor */
Serializer::Serializer()
{
};

/* Copy Constructor: NEW object created from scratch */
Serializer::Serializer(const Serializer &src_to_copy) : name_for_test(src_to_copy.name_for_test)
{
}

/* Copy Assignment operator: object already exists, we don't construct object, but just assign */
Serializer &Serializer::operator=(const Serializer &src_to_copy)
{
    if (this != &src_to_copy)
    {
        name_for_test = src_to_copy.name_for_test;
    }
    return *this;
}

/* Destructor */
Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*> (raw);
}