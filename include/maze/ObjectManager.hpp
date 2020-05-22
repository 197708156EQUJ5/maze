#pragma once

#include "maze/LTexture.hpp"
#include "maze/Cell.hpp"

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
    std::vector<Cell> getCells();
    void handleEvent(SDL_Event& e);

private:
    
    const int DOT_MOVE = 1;
    const int MAZE_COLUMNS = 10;
    const int MAZE_ROWS = 10;
    int boardX;
    int boardY;
    int boardWidth;
    int boardHeight;
    LTexture lTexture;
    std::vector<Cell> cells;

    int x;
    int y;
};

} // namespace maze

