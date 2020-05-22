#ifndef MAP_H
#define MAP_H

#include "config.h"

//抽象类GMap
class GMap
{

public:
    bool WallData[MAPLENGTH][MAPLENGTH];
    bool BeanData[MAPLENGTH][MAPLENGTH];
    //friend class GObject;                   // 允许物体类使用直线的起点和终点的信息做碰撞检测
    //friend class PacMan;                    // 允许"大嘴"访问豆子地图
};

//"第一关"
class Stage_1 : public GMap
{
private:
    static bool  initData[MAPLENGTH][MAPLENGTH];	// 地图数据
public:
    Stage_1();
};

//第二关
class Stage_2 : public GMap
{
private:
    static bool initData[MAPLENGTH][MAPLENGTH]; 	// 地图数据
public:
    Stage_2();
};

// 第三关
class Stage_3 : public GMap
{
private:
    static bool initData[MAPLENGTH][MAPLENGTH]; 	// 地图数据
public:
    Stage_3();
};

// 第四关
class Stage_4 : public GMap
{
private:
    static bool initData[MAPLENGTH][MAPLENGTH]; 	// 地图数据
public:
    Stage_4();
};


#endif // MAP_H
