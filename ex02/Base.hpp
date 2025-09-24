/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:51:28 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/24 16:01:35 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/* Subject specifies that this classes don't have to be designed in the
*  Orthodox Canonical Form. */

class Base
{
    public:
        /* Virtual destructor makes it safe to use an abstract class as a 
        *  base for derived classes, because the runtime wil always know
        *  the real type and destroy it correctly. */
        virtual ~Base();
        /*virtual function makes Base polymorphic, vtable is created, where 
        RTTI (Run-Time Type Information) is stored, like is it A or is it B really?*/
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

class D : public Base
{};

#endif