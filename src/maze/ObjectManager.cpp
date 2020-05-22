#include "maze/ObjectManager.hpp"

#include "maze/MazeDesign.hpp"
#include "maze/CellFactory.hpp"

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstdint>

namespace maze
{

ObjectManager::ObjectManager(int boardX, int boardY, int boardWidth, int boardHeight, LTexture &lTexture) :
    boardX(boardX),
    boardY(boardY),
    boardWidth(boardWidth),
    boardHeight(boardHeight),
    lTexture(lTexture),
    x((boardWidth - boardX) / 2),
    y((boardHeight - boardY) / 2)
{
}

void ObjectManager::createCells()
{
    std::vector<uint8_t> maze1 = MazeDesign::MAZE_1;

    int index = 0;
    for (uint8_t cellCode : maze1)
    {
        Cell cell = CellFactory::convertCellCode(cellCode);
        cell.row = index / MAZE_ROWS;
        cell.col = index % MAZE_COLUMNS;
        
        cells.push_back(cell);
        
        index++;
    }
}

void ObjectManager::render()
{
    lTexture.render((boardWidth - boardX) / 2, (boardHeight - boardY) / 2);
}

std::vector<Cell> ObjectManager::getCells()
{
    return cells;
}

void ObjectManager::handleEvent(SDL_Event& e)
{
    //If a key was pressed
    //if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    if (e.type == SDL_KEYDOWN)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
            case SDLK_UP:
                y -= DOT_MOVE;
                break;
            case SDLK_DOWN:
                y += DOT_MOVE;
                break;
            case SDLK_LEFT:
                x -= DOT_MOVE;
                break;
            case SDLK_RIGHT:
                x += DOT_MOVE;
                break;
        }
    }
    //If a key was released
    //else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    else if (e.type == SDL_KEYUP)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
            case SDLK_UP:
                y += DOT_MOVE;
                break;
            case SDLK_DOWN:
                y -= DOT_MOVE;
                break;
            case SDLK_LEFT:
                x += DOT_MOVE;
                break;
            case SDLK_RIGHT:
                x -= DOT_MOVE;
                break;
        }
    }

    std::cout << x << ", " << y << std::endl;
}

} // namespace maze

