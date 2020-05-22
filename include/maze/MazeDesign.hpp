#pragma once

#include <cstdint>
#include <vector>

namespace maze
{

class MazeDesign
{
public:
    static const std::vector<uint8_t> MAZE_1;

private:
    static const uint8_t XXXX = 0x00;
    static const uint8_t NXXX = 0x01;
    static const uint8_t XEXX = 0x02;
    static const uint8_t NEXX = 0x03;
    static const uint8_t XXSX = 0x04;
    static const uint8_t NXSX = 0x05;
    static const uint8_t XESX = 0x06;
    static const uint8_t NESX = 0x07;
    static const uint8_t XXXW = 0x08;
    static const uint8_t NXXW = 0x09;
    static const uint8_t XEXW = 0x0a;
    static const uint8_t NEXW = 0x0b;
    static const uint8_t XXSW = 0x0c;
    static const uint8_t NXSW = 0x0d;
    static const uint8_t XESW = 0x0e;
    static const uint8_t NESW = 0x0f;
};

} // namespace maze
