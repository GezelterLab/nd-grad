// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex2_01.cpp
// Author: crdrisko
// Date: 04/16/2020-11:42:19
// Description: Writing values of variables to cout

#include <iostream>

int main()
{
    int apple_count {15};                           // Number of apples
    int orange_count {5};                           // Number of oranges
    int total_fruit {apple_count + orange_count};   // Total number of fruit

    std::cout << "The value of apple_count is " << apple_count << std::endl;
    std::cout << "The value of orange_count is " << orange_count << std::endl;
    std::cout << "The value of total_fruit is " << total_fruit << std::endl;
}
