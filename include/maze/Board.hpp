#pragma once

#include "maze/LTexture.hpp"
#include "maze/ObjectManager.hpp"
#include "maze/Wall.hpp"

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace maze
{

class Board
{
public:
    
    Board();
    ~Board() = default;

    bool init();
    void gameLoop();
    void close();

private:
    //Screen dimension constants
    const int SCREEN_X = 0;
    const int SCREEN_Y = 0;
    const int SCREEN_WIDTH = 700;
    const int SCREEN_HEIGHT = 550;
    const int BOARD_WIDTH = 640;
    const int BOARD_HEIGHT = 480;
    const int BOARD_X = (SCREEN_WIDTH - BOARD_WIDTH) / 2;
    const int BOARD_Y = (SCREEN_HEIGHT - BOARD_HEIGHT) / 2;
 
    void drawBoard();
    void drawCell(Cell, int, int, int, uint8_t alpha);
    bool loadMedia();
    void drawMap();
    void drawRoom();

    bool isCursorVertical;
    SDL_Cursor* cursor;
    SDL_Window* window;
    SDL_Renderer* renderer;
    LTexture atomTexture;
    LTexture mapTexture;

    std::unique_ptr<ObjectManager> objectManager;

};

} // namespace maze

