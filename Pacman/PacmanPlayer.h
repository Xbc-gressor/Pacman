#ifndef PACMANPLAYER_H
#define PACMANPLAYER_H

#include "BaseObject.h"
#include <QPixmap>

class PacmanPlayer : public BaseObject
{
public:
    PacmanPlayer(int x, int y);

    //重载AchiveCtrl()
    void AchiveCtrl();

public:
    QPixmap image;
};

#endif // PACMANPLAYER_H
