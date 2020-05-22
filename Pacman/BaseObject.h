#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QPixmap>
#include <QLabel>
#include "GMap.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject(){}

public:
    //图片资源 对象
    //QPixmap image;
    QLabel * imagif;

    //移动速度和方向
    int speed;
    int m_dir; //实际方向
    int m_cmd; //指令缓存

    //实际中心坐标
    int actual_x;
    int actual_y;

    //逻辑坐标
    int logic_x;
    int logic_y;

    //指向地图的指针,所有对象共用
    static GMap * map;

public:
    //设置坐标
    void SetPosition();

    // 将实际坐标转换为逻辑坐标
    int PtTransform(int k);

    //判断物体是否达到中心坐标
    bool Achive();
    virtual void AchiveCtrl();

    //判断碰撞
    bool collision();
};

#endif // BASEOBJECT_H
