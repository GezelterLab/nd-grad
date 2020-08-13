// Name: foreachinvoke.hpp - Version 1.0.0
// Author: crdrisko
// Date: 08/13/2020-11:09:32
// Description: Using std::invoke() to generalize our foreach<> function template

#ifndef FOREACHINVOKE_HPP
#define FOREACHINVOKE_HPP

#include <functional>
#include <utility>

template<typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, Args const&... args)
{
    while (current != end)                                  // as long as not reached the end of the elements
    {
        std::invoke(op,                                     // call passed callable with
                    args...,                                // any additional args
                    *current);                              // and the current element

        ++current;
    }
}

#endif
