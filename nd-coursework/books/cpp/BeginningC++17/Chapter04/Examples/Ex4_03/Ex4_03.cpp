// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex4_03.cpp
// Author: crdrisko
// Date: 04/24/2020-13:57:01
// Description: Using a nested if

#include <iostream>

int main()
{
    char letter {};                    // Store input here
    std::cout << "Enter a letter: ";   // Prompt for the input
    std::cin >> letter;

    if (letter >= 'A')
    {   // letter is 'A' or larger
        if (letter <= 'Z')
        {   // letter is 'Z' or smaller
            std::cout << "You entered an uppercase letter." << std::endl;
            return 0;
        }
    }

    if (letter >= 'a')   // Test for 'a' or larger
        if (letter <= 'z')
        {   // letter is >= 'a' and <= 'z'
            std::cout << "You entered a lowercase letter." << std::endl;
            return 0;
        }

    std::cout << "You did not enter a letter." << std::endl;
}
