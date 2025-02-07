// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex4_06.cpp
// Author: crdrisko
// Date: 04/25/2020-11:46:19
// Description: Using the conditional operator to select output

#include <iostream>

int main()
{
    int mice {};    // Count of all mice
    int brown {};   // Count of brown mice
    int white {};   // Count of white mice

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;
    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    mice = brown + white;

    std::cout << "You have " << mice << (mice == 1 ? " mouse" : " mice") << " in total." << std::endl;
}
