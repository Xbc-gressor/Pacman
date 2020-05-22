#ifndef ENEMY_H
#define ENEMY_H

#include "BaseObject.h"
#include "PacmanPlayer.h"
#include "GMap.h"
#include <QLabel>

class Enemy : public BaseObject
{
public:
    Enemy();    

    //形象
    //QLabel * imagif;

    //指向玩家
    static PacmanPlayer * player;

    //指向地图
    //



    void virtual MakeDirection(bool b);
};

//红色随机乱走
class RedEnemy : public Enemy
{
public:
    RedEnemy(int x, int y);

    //决定前进方向
    virtual void MakeDirection(bool b);

public:

    //QMovie * movie;

};

class BlueEnemy : public Enemy
{
public:
    BlueEnemy(int x, int y);

    void virtual MakeDirection(bool b);
};

class YellowEnemy : public Enemy
{
public:
    YellowEnemy(int x, int y);

    void virtual MakeDirection(bool b);
};

#endif // ENEMY_H
