/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:51:28 by uxmancis          #+#    #+#             */
/*   Updated: 2025/09/23 11:18:30 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

/* Subject specifies that this classes don't have to be designed in the
*  Orthodox Canonical Form. */

class Base
{
    public:
        virtual ~Base(); //must be virtual for polymorphic deletion & RTTI
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