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
    position({((MAZE_COLUMNS * CELL_SIZE) / 2) * 8, ((MAZE_ROWS * CELL_SIZE) / 2) * 8}),
    showMap(false)
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
                position.y -= DOT_MOVE;
                break;
            case SDLK_DOWN:
                position.y += DOT_MOVE;
                break;
            case SDLK_LEFT:
                position.x -= DOT_MOVE;
                break;
            case SDLK_RIGHT:
                position.x += DOT_MOVE;
                break;
        }
    }

    if (e.key.keysym.sym == SDLK_m && e.type == SDL_KEYDOWN)
    {
        this->showMap = !this->showMap;
    }
    else
    {
        std::cout << position.x << ", " << position.y << std::endl;
    }
}

bool ObjectManager::isMapVisible()
{
    return showMap;
}

std::vector<Cell> ObjectManager::getRoom()
{
    std::vector<Cell> room;
    for (Cell cell : this->cells)
    {
        if (isInside(position.x, position.y, cell))
        {
            room.push_back(cell);
        }
    }

    return room;
}

Position ObjectManager::getPosition()
{
    return position;
}

bool ObjectManager::isInside(int x, int y, Cell cell)
{
    int cellX = (cell.col * ObjectManager::CELL_SIZE);
    int cellY = (cell.row * ObjectManager::CELL_SIZE);
    bool isInside = false;
    if (x + (ObjectManager::CELL_SIZE / 2) >= cellX || x - (ObjectManager::CELL_SIZE / 2) >= cellX)
    {
        isInside = true;
    }
    else
    {
        return false;
    }
    if (y + (ObjectManager::CELL_SIZE / 2) > cellY || y - (ObjectManager::CELL_SIZE / 2) > cellY)
    {
        isInside = true;
    }
    else
    {
        return false;
    }
    if (x + (ObjectManager::CELL_SIZE / 2) <= cellX + ObjectManager::CELL_SIZE || 
            x - (ObjectManager::CELL_SIZE / 2) <= cellX + ObjectManager::CELL_SIZE)
    {
        isInside = true;
    }
    else
    {
        return false;
    }
    if (y + (ObjectManager::CELL_SIZE / 2) <= cellY + ObjectManager::CELL_SIZE || 
            y - (ObjectManager::CELL_SIZE / 2) <= cellY + ObjectManager::CELL_SIZE)
    {
        isInside = true;
    }
    else
    {
        return false;
    }

    return isInside;
}

} // namespace maze

