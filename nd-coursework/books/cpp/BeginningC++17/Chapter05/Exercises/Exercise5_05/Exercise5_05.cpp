// Copyright (c) 2019-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: Exercise5_05.cpp
// Author: crdrisko
// Date: 04/30/2020-14:07:48
// Description: Reversing a C-style string using a while loop

#include <iostream>

int main()
{
    const std::size_t maxLength {1000};

    char cStyleString[maxLength] {};
    std::cout << "Enter a string of up to 1000 characters: ";
    std::cin.getline(cStyleString, maxLength);

    int count {};
    while (count < maxLength && cStyleString[count] != '\0')
        ++count;

    for (int i {}; i <= (count - 1) / 2; ++i)
    {
        char temporaryStorage {cStyleString[i]};

        cStyleString[i]             = cStyleString[count - 1 - i];
        cStyleString[count - 1 - i] = temporaryStorage;
    }

    std::cout << cStyleString << std::endl;
}
