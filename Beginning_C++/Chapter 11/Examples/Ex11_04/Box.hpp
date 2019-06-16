// Name: Box.hpp
// Author: crdrisko
// Date: 06/15/2019-16:29:06
// Description: For use with Ex11_04.cpp

#ifndef BOX_HPP
#define BOX_HPP

class Box
{
private:
    double length {1.0};
    double width {1.0};
    double height {1.0};

public:
    // Constructors
    Box() = default;
    Box(double length, double width, double height);

    double volume();                                        // Function to calculate the volume of a box
    
    // Functions to provide access to the values of member variables 
    double getLength() { return length; }
    double getWidth()  { return width;  }
    double getHeight() { return height; }

    // Functions to set member variable values
    void setLength(double lv) { if (lv > 0) length = lv; }
    void setWidth(double wv)  { if (wv > 0) width  = wv; }
    void setHeight(double hv) { if (hv > 0) height = hv; }
};

#endif

