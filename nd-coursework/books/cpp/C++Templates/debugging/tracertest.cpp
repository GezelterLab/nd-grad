// Copyright (c) 2017 by Addison-Wesley, David Vandevoorde, Nicolai M. Josuttis, and Douglas Gregor. All rights reserved.
// See the LICENSE file in the project root for more information.
//
// Name: tracertest.cpp
// Author: crdrisko
// Date: 10/05/2020-07:58:45
// Description: Testing the std::sort algorithm with our SortTracers

#include "tracer.hpp"

#include <algorithm>
#include <iostream>

int main()
{
    // prepare sample input:
    SortTracer input[] = {7, 3, 5, 6, 4, 2, 0, 1, 9, 8};

    // print initial values:
    for (int i = 0; i < 10; ++i)
        std::cerr << input[i].val() << ' ';
    std::cerr << '\n';

    // remember initial conditions:
    long created_at_start  = SortTracer::creations();
    long max_live_at_start = SortTracer::max_live();
    long assigned_at_start = SortTracer::assignments();
    long compared_at_start = SortTracer::comparisons();

    // execute algorithm:
    std::cerr << "-------------[ Start std::sort() ]-------------\n";
    std::sort<>(&input[0], &input[9] + 1);
    std::cerr << "--------------[ End std::sort() ]--------------\n";

    // verify result:
    for (int i = 0; i < 10; ++i)
        std::cerr << input[i].val() << ' ';
    std::cerr << "\n\n";

    // final report:
    std::cerr << "std::sort() of 10 SortTracer's was performed by:\n " << SortTracer::creations() - created_at_start
              << " temporary tracers\n up to " << SortTracer::max_live() << " tracers at the same time ("
              << max_live_at_start << " before)\n " << SortTracer::assignments() - assigned_at_start << " assignments\n "
              << SortTracer::comparisons() - compared_at_start << " comparisons\n\n";
}
