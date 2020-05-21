#include "maze/Board.hpp"

#include <iostream>
#include <memory>

int main(int argc, char* args[])
{
    std::unique_ptr<maze::Board> board = std::make_unique<maze::Board>();

    if (!board->init())
    {
        std::cout << "Could not initialize maze" << std::endl;
    }
    else
    {
        board->gameLoop();
    }

    board->close();

    return 0;
}
