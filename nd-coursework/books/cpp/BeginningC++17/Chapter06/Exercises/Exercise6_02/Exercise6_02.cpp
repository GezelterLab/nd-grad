// Copyright (c) 2019-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: Exercise6_02.cpp
// Author: crdrisko
// Date: 05/02/2020-10:50:08
// Description: Printing the first 50 odd numbers with pointer increments and decrements

#include <iomanip>
#include <iostream>

int main()
{
    const int numberOfOdds {50};
    int odds[numberOfOdds] {};

    // Setting and printing the odd numbers
    std::cout << "The odd numbers are: " << std::endl;

    int* pOdds {odds};

    for (int i {}, count {}; i < numberOfOdds; ++i)
    {
        odds[i] = (2 * i) + 1;

        std::cout << std::setw(5) << *pOdds++;

        if (!(++count % 10))
            std::cout << std::endl;
    }

    // Reversing and printing the odd numbers
    std::cout << "\nIn reverse order the odd numbers are:" << std::endl;

    for (int i {numberOfOdds - 1}, count {}; i >= 0; --i)
    {
        std::cout << std::setw(5) << *(--pOdds);

        if (!(++count % 10))
            std::cout << std::endl;
    }

    std::cout << std::endl;
}
