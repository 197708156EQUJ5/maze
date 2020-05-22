#pragma once

#include "maze/Cell.hpp"

#include <cstdint>

namespace maze
{

class CellFactory
{
public:

    static Cell convertCellCode(uint8_t cellCode);

private:

    //static const createNXXX();
};
}
