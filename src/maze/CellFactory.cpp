#include "maze/CellFactory.hpp"

#include <iostream>

namespace maze
{

Cell CellFactory::convertCellCode(uint8_t cellCode)
{
    return Cell{(cellCode & 0x01) == 0x01, (cellCode & 0x02) == 0x02, (cellCode & 0x04) == 0x04, (cellCode & 0x08) == 0x08, -1, -1}; 
}

}
