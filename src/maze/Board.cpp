#include "maze/Board.hpp"

#include <iostream>
#include <sstream>

namespace maze
{

Board::Board() :
    isCursorVertical(true),
    cursor(nullptr),
    window(nullptr),
    renderer(nullptr)
{
}

bool Board::init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;;
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;;
        }

        //Create window
        window = SDL_CreateWindow("Rat in a Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                //SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
                BOARD_WIDTH, BOARD_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;;
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL)
            {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;;
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;;
                    success = false;
                }
            }
            cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_SIZENS);
            SDL_SetCursor(cursor);
        }
    }
    
    atomTexture.setRenderer(renderer);

    if (!loadMedia())
    {
        success = false;
    }

    return success;    
}

void Board::gameLoop()
{
    bool quit = false;
    SDL_Event e;

    this->objectManager = std::make_unique<ObjectManager>(SCREEN_X, SCREEN_Y, BOARD_WIDTH, BOARD_HEIGHT, atomTexture);
    this->objectManager->createCells();

    while(!quit)
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        //Handle events on queue
        while(SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            switch (e.type)
            {
                case SDL_QUIT:
                {
                    quit = true;
                    break;
                }
                case SDL_KEYUP:
                case SDL_KEYDOWN:
                    this->objectManager->handleEvent(e);
                    break;
            }
        }
        
        //this->objectManager->updateDot();
        if (this->objectManager->isMapVisible())
        {
            drawMap();
        }

        this->objectManager->render();

        //Update screen
        SDL_RenderPresent(renderer);
    }
}

void Board::drawMap()
{
    for (Cell cell : this->objectManager->getCells())
    {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, SDL_ALPHA_OPAQUE);
        
        if (cell.hasNorth)
        {
            SDL_Rect wallRect;
            wallRect.x = (cell.col * cell.SIZE);
            wallRect.y = cell.row * cell.SIZE;
            wallRect.w = cell.SIZE;
            wallRect.h = cell.WALL_SIZE;

            SDL_RenderFillRect(renderer, &wallRect);
        }
        if (cell.hasEast)
        {
            SDL_Rect wallRect;
            wallRect.x = (cell.col * cell.SIZE) + (cell.SIZE - cell.WALL_SIZE);
            wallRect.y = cell.row * cell.SIZE;
            wallRect.w = cell.WALL_SIZE;
            wallRect.h = cell.SIZE;

            SDL_RenderFillRect(renderer, &wallRect);
        }
        if (cell.hasSouth)
        {
            SDL_Rect wallRect;
            wallRect.x = (cell.col * cell.SIZE);
            wallRect.y = (cell.row * cell.SIZE) + (cell.SIZE - cell.WALL_SIZE);
            wallRect.w = cell.SIZE;
            wallRect.h = cell.WALL_SIZE;

            SDL_RenderFillRect(renderer, &wallRect);
        }
        if (cell.hasWest)
        {
            SDL_Rect wallRect;
            wallRect.x = cell.col * cell.SIZE;
            wallRect.y = cell.row * cell.SIZE;
            wallRect.w = cell.WALL_SIZE;
            wallRect.h = cell.SIZE;

            SDL_RenderFillRect(renderer, &wallRect);
        }
    }
}

bool Board::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load dot texture
    if(!atomTexture.loadFromFile("resources/red_dot_20x20.png"))
    {
        std::cout << "Failed to load dot texture!" << std::endl;
        success = false;
    }

    return success;
}

void Board::close()
{
    //Free loaded images
    atomTexture.free();

    //Destroy window    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

} // namespace maze

