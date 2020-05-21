#include "PacmanPlayer.h"

PacmanPlayer::PacmanPlayer()
{
    image.load(":/res/001.png");
    image = image.scaled(100,100);

    actual_x = 0;
    actual_y = 0;
}
