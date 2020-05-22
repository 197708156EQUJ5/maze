#pragma once

struct Cell
{
    bool hasNorth;
    bool hasEast;
    bool hasSouth;
    bool hasWest;
    int row;
    int col;

    const int SIZE = 45;
    const int WALL_SIZE = 3;
};

