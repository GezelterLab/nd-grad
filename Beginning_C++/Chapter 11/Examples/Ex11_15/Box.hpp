// Name: Box.hpp
// Author: Cody R. Drisko (crdrisko)
// Date: 06/26/2019-10:21:19
// Description: For use with Ex11_15.cpp

#ifndef BOX_HPP
#define BOX_HPP
#include <iostream>
#include <iomanip>

class Box
{
private:
    double length {1.0};
    double width  {1.0};
    double height {1.0};

public:
    // Constructors
    Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {};

    Box() = default;                            // Default constructor

    double volume() const                       // Volume of a box
    {
        return length * width * height;
    }

    int compare(const Box& box) const
    {
        if (volume() < box.volume()) return -1;
        if (volume() == box.volume()) return 0;
        return +1;
    }

    void listBox() const
    {
        std::cout << " Box(" << std::setw(2) << length << ','
                             << std::setw(2) << width  << ','
                             << std::setw(2) << height << ')';
    }
};

#endif
