#pragma once

#include <sstream>
#include <string>
#include <iomanip>

namespace maze
{

struct Wall
{
    int x;
    int y;
    int width;
    int height;

    static const int THICKNESS = 10;
    
    std::string toString()
    {
        std::stringstream ss;
        ss << std::setw(3) << x << "," << std::setw(3) << y << ") (" 
            << std::setw(3) << (x + width) << "," << std::setw(3) << (y + height) << ")"
            << " width: " << std::setw(3) << width << " height: " << std::setw(3) << height;
        return ss.str();
    }

};

} // namespace maze

