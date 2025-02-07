// Copyright (c) 2017 by Addison-Wesley, David Vandevoorde, Nicolai M. Josuttis, and Douglas Gregor. All rights reserved.
// See the LICENSE file in the project root for more information.
//
// Name: stack6decl.hpp
// Author: crdrisko
// Date: 07/30/2020-21:43:52
// Description: A Stack class with a parameterized internal container

#ifndef STACK6DECL_HPP
#define STACK6DECL_HPP

#include <deque>

template<typename T, typename Cont = std::deque<T>>
class Stack
{
private:
    Cont elems;   // elements

public:
    void push(T const&);                           // push element
    void pop();                                    // pop element
    T const& top() const;                          // return top element
    bool empty() const { return elems.empty(); }   // return whether the stack is empty

    // assign stack of elements of type T2
    template<typename T2, typename Cont2>
    Stack& operator=(Stack<T2, Cont2> const&);

    // to get access to private members of Stack<T2> for any type T2:
    template<typename, typename>
    friend class Stack;
};

#endif
