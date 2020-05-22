#ifndef CONFIG_H
#define CONFIG_H

//方向
enum DIRECTION{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
};

/***********************场景大小*************************/
#define WIDTH 1300
#define HEIGHT 950
#define BRICKSIZE 50
#define MAPLENGTH 19						// 逻辑地图大小

/*********************吃豆人属性***************************/
#define PACSPEED 5
#define PACMANSIZE 40


/*********************怪物属性*****************************/
#define REDSPEED 5

#define BLUESPEED 5
#define BLUEALERT 8

#define YELLOWSPEED 5

#define MONSTERSIZE 50

#endif // CONFIG_H
