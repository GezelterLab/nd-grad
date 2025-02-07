// Copyright (c) 2018 Ivor Horton and Peter Van Weert. Some rights reserved.
// Licensed under the Freeware License. See the LICENSE file in the project root for more information.
//
// Name: Ex5_14.cpp
// Author: crdrisko
// Date: 04/29/2020-13:59:34
// Description: Using array<T, N> to create Body Mass Index (BMI) table

#include <array>   // For array<T, N>
#include <iomanip>
#include <iostream>

int main()
{
    const unsigned min_wt {100};   // Minimum weight in table (in pounds)
    const unsigned max_wt {250};   // Maximum weight in table
    const unsigned wt_step {10};
    const std::size_t wt_count {1 + (max_wt - min_wt) / wt_step};

    const unsigned min_ht {48};   // Minimum height in table (in inches)
    const unsigned max_ht {84};   // Maximum height in table
    const unsigned ht_step {2};
    const std::size_t ht_count {1 + (max_ht - min_ht) / ht_step};

    const double lbs_per_kg {2.2};    // Pounds per kilogram
    const double ins_per_m {39.37};   // Inches per meter
    std::array<unsigned, wt_count> weight_lbs {};
    std::array<unsigned, ht_count> height_ins {};

    // Create weights from 100 lbs in steps of 10 lbs
    for (std::size_t i {}, w {min_wt}; i < wt_count; w += wt_step, ++i)
    {
        weight_lbs[i] = w;
    }

    // Create heights from 48 inches in steps of 2 inches
    for (std::size_t i {}, h {min_ht}; h <= max_ht; h += ht_step)
    {
        height_ins.at(i++) = h;
    }

    // Output table headings
    std::cout << std::setw(7) << " |";
    for (auto w : weight_lbs)
        std::cout << std::setw(5) << w << "  |";
    std::cout << std::endl;

    // Output line below headings
    for (std::size_t i {1}; i < wt_count; ++i)
        std::cout << "---------";
    std::cout << std::endl;

    double bmi {};            // Stores BMI
    unsigned int feet {};     // Whole feet for output
    unsigned int inches {};   // Whole inches for output
    const unsigned int inches_per_foot {12U};
    for (auto h : height_ins)
    {
        feet   = h / inches_per_foot;
        inches = h % inches_per_foot;
        std::cout << std::setw(2) << feet << "'" << std::setw(2) << inches << '"' << '|';
        std::cout << std::fixed << std::setprecision(1);
        for (auto w : weight_lbs)
        {
            bmi = h / ins_per_m;
            bmi = (w / lbs_per_kg) / (bmi * bmi);
            std::cout << std::setw(2) << " " << bmi << " |";
        }
        std::cout << std::endl;
    }

    // Output line below table
    for (std::size_t i {1}; i < wt_count; ++i)
        std::cout << "---------";
    std::cout << "\nBMI from 18.5 to 24.9 is normal" << std::endl;
}
