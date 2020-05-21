#pragma once

#include "maze/LTexture.hpp"
#include "maze/Wall.hpp"

#include <vector>
#include <memory>

namespace maze
{

class ObjectManager
{
public:

    ObjectManager(int boardX, int boardY, int boardWidth, int boardHeight, LTexture &lTexture);
    ~ObjectManager() = default;

    void createWalls();
    void updateWalls();
    void render();
    std::vector<Wall> getWalls();

private:
    
    int boardX;
    int boardY;
    int boardWidth;
    int boardHeight;
    LTexture lTexture;
    std::vector<Wall> walls;
};

} // namespace maze

