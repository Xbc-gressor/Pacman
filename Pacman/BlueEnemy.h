#ifndef BLUEENEMY_H
#define BLUEENEMY_H

#include "Enemy.h"

class BlueEnemy : public Enemy
{
public:
    BlueEnemy();

    void virtual MakeDirection();
};

#endif // BLUEENEMY_H
