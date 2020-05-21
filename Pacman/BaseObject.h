#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QPixmap>

class BaseObject
{
public:
    BaseObject();

public:
    //图片资源 对象
    QPixmap image;

    //移动速度和方向
    int speed;
    int direction;

    //实际坐标
    int actual_x;
    int actual_y;

    //逻辑坐标
    int logic_x;
    int logic_y;

public:
    //设置坐标
    void SetPosition();

    // 将实际坐标转换为逻辑坐标
    int PtTransform(int k);
};

#endif // BASEOBJECT_H
