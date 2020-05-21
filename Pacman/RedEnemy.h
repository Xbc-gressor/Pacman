#ifndef ENEMY_H
#define ENEMY_H

#include "BaseObject.h"

class RedEnemy : public BaseObject
{
public:
    RedEnemy();

    //决定前进方向
    void virtual MakeDirection();

};

#endif // ENEMY_H
