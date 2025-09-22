/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:05:10 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/22 11:26:18 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "main.hpp"

class Serializer
{
    /* private, so that class is not instantiable by user */
    private:
        std::string name_for_test;
        Serializer();
        Serializer(const Serializer &src_to_copy);
        Serializer &operator=(const Serializer &src_to_copy);
        ~Serializer();
        
    public: 
        /* Required member functions, required to be static : */
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif