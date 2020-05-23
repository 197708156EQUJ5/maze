#pragma once

struct Cell
{
    bool hasNorth;
    bool hasEast;
    bool hasSouth;
    bool hasWest;
    int row;
    int col;
    bool isHidden;
};

