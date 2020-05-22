#include "BaseObject.h"
#include "config.h"

BaseObject::BaseObject()
{

}

int BaseObject::PtTransform(int k)
{

    return k / BRICKSIZE; //- (BRICKSIZE) / 2


}

bool BaseObject::Achive()
{
    int n = (actual_x - BRICKSIZE / 2) % BRICKSIZE; // 计算x坐标的余数
    int k = (actual_y - BRICKSIZE / 2) % BRICKSIZE; // 计算y坐标的余数
    bool l = (n == 0 && k == 0);          // 如果两个余数都为0,说明到达中心位置
    return l;
}

// 到达逻辑点后更新数据
void BaseObject::AchiveCtrl()
{
    if (Achive()) {										// 如果达到逻辑坐标
        logic_x = PtTransform(actual_x);				// 更新列
        logic_y = PtTransform(actual_y);				// 更新行
    }
}

GMap * BaseObject::map = nullptr;
bool BaseObject::collision()
{
    bool b = false;

    //更新行、列的数据若是大嘴,则会执行PacMan重写的AchiveCtrl函数消除豆子
    AchiveCtrl();
    //判断指令的有效性
    if (logic_x < 0 || logic_y < 0 || logic_x > MAPLENGTH - 1
        || logic_y > MAPLENGTH - 1) {
        b = true;
    }
    else if (Achive()) {
        switch (m_cmd) {  //判断行进的方向
        case LEFT:	//如果朝向为左
                    //判断下一个格子是否能够通行
            if (logic_x > 0 &&
                map->WallData[logic_y][logic_x - 1]) {
                b = true;									// "撞墙了"
            }
            break;
            //以下方向的判断原理相同
        case RIGHT:	//如果朝向为右
            if (logic_x < MAPLENGTH - 1 &&
                map->WallData[logic_y][logic_x + 1]) {
                b = true;									// "撞墙了"
            }
            break;
        case UP:		//如果朝向为上
            if (logic_y > 0 &&
                map->WallData[logic_y - 1][logic_x]) {
                b = true;									// "撞墙了"
            }
            break;
        case DOWN: 	//如果朝向为下
            if (logic_y < MAPLENGTH - 1 &&
                map->WallData[logic_y + 1][logic_x]) {
                b = true;									// "撞墙了"
            }
            break;
        }
        if (!b) {
            m_dir = m_cmd; //没撞墙,指令成功
        }
    }
    //依照真实的方向位移
//	m_nX = m_ptCenter.x;
//	m_nY = m_ptCenter.y;
    int MAX = BRICKSIZE * MAPLENGTH + BRICKSIZE / 2;
    int MIN = BRICKSIZE / 2;
    switch (m_dir) {  //判断行进的方向
    case LEFT:
        //判断下一个格子是否能够通行
        if (logic_x > 0 &&
                map->WallData[logic_y][logic_x - 1]) {
            b = true;
            break;									// "撞墙了"
        }
        actual_x -= speed;
        if (actual_x < MIN) {
            actual_x = MAX;
        }

        break;
        //以下方向的判断原理相同
    case RIGHT:
        if (logic_x < MAPLENGTH - 1 &&
              map->WallData[logic_y][logic_x + 1]) {
            b = true;
            break;									// "撞墙了"
        }
        actual_x += speed;
        if (actual_x > MAX) {
            actual_x = MIN;
        }

        break;
    case UP:
        if (logic_y > 0 &&
            map->WallData[logic_y - 1][logic_x]) {
            b = true;
            break;									// "撞墙了"
        }
        actual_y -= speed;
        if (actual_y < MIN) {
            actual_y = MAX;
        }
        break;
    case DOWN:
        if (logic_y < MAPLENGTH - 1 &&
            map->WallData[logic_y + 1][logic_x]) {
            b = true;
            break;									// "撞墙了"
        }
        actual_y += speed;
        if (actual_y > MAX) {
            actual_y = MIN;
        }
        break;
    }
    return b;
}

