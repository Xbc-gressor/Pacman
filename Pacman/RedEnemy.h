#ifndef ENEMY_H
#define ENEMY_H

#include "Enemy.h"
#include "BaseObject.h"
#include <QMovie>

class RedEnemy : public BaseObject
public:
    RedEnemy();

    //决定前进方向
    void virtual MakeDirection();

public:

    //QMovie * movie;

};

#endif // ENEMY_H
