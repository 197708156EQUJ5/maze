#include "maze/ObjectManager.hpp"

#include <iostream>
#include <stdlib.h>

namespace maze
{

ObjectManager::ObjectManager(int boardX, int boardY, int boardWidth, int boardHeight, LTexture &lTexture) :
    boardX(boardX),
    boardY(boardY),
    boardWidth(boardWidth),
    boardHeight(boardHeight),
    lTexture(lTexture)
{
}

void ObjectManager::createWalls()
{
}

void ObjectManager::updateWalls()
{
    for (Wall &wall : walls)
    {
    }
}

void ObjectManager::render()
{
    lTexture.render((boardWidth - boardX) / 2, (boardHeight - boardY) / 2);
}

std::vector<Wall> ObjectManager::getWalls()
{
    return walls;
}

} // namespace maze

