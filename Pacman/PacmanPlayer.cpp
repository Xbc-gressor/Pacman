#include "PacmanPlayer.h"
#include "config.h"
#include <QDebug>

PacmanPlayer::PacmanPlayer(int x, int y)
{
    image.load(":/res/001.png");
    image = image.scaled(PACMANSIZE,PACMANSIZE);

    qDebug()<< PACSPEED;
    speed = PACSPEED;

    actual_x = x;
    actual_y = y;
}

void PacmanPlayer::AchiveCtrl()
{

    BaseObject::AchiveCtrl();
    if (Achive()) {
        if (logic_x >= 0 && logic_x < MAPLENGTH &&
            logic_y >= 0 && logic_y < MAPLENGTH) {  // 防止数组越界
            if (map->BeanData[logic_y][logic_x]) {
                map->BeanData[logic_y][logic_x] = false;
            }
        }
    }

}
