#pragma once

#include "maze/LTexture.hpp"
#include "maze/Cell.hpp"
#include "maze/Position.hpp"

#include <vector>
#include <memory>

namespace maze
{

class ObjectManager
{
public:

    ObjectManager(int boardX, int boardY, int boardWidth, int boardHeight, LTexture &lTexture);
    ~ObjectManager() = default;

    void createCells();
    void updateWalls();
    void render();
    void handleEvent(SDL_Event& e);
    bool isMapVisible();
    std::vector<Cell> getCells();
    std::vector<Cell> getRoom();;
    static const int CELL_SIZE = 20;
    static const int WALL_SIZE = CELL_SIZE * 0.1;
    static const int MAZE_COLUMNS = 10;
    static const int MAZE_ROWS = 10;

private:

    bool isInside(int x, int y, Cell cell);
    
    const int DOT_MOVE = 1;
    int boardX;
    int boardY;
    int boardWidth;
    int boardHeight;
    LTexture lTexture;
    Position position;
    bool showMap;
    std::vector<Cell> cells;

};

} // namespace maze

