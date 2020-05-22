#ifndef YELLOWENEMY_H
#define YELLOWENEMY_H

#include "Enemy.h"

class YellowEnemy : public Enemy
{
public:
    YellowEnemy();

    void virtual MakeDirection();
};

#endif // YELLOWENEMY_H
