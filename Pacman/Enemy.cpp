#include <QMovie>
#include "Enemy.h"
#include "config.h"


Enemy::Enemy(): BaseObject()
{

}

void Enemy::MakeDirection(bool b)
{

}


PacmanPlayer * Enemy::player = nullptr;



RedEnemy::RedEnemy(int x, int y)
{
    //动图
    imagif = new QLabel;
    imagif->setFixedSize(MONSTERSIZE, MONSTERSIZE);
    QMovie * movie = new QMovie(":/res/ghost2.gif");
    movie->setScaledSize(QSize(imagif->width(), imagif->height()));
    imagif->setMovie(movie);
    movie->start();

    actual_x = x;
    actual_y = y;

    speed = REDSPEED;
    m_cmd = RIGHT;

}

void RedEnemy::MakeDirection(bool b)
{
    srand(time(0));
    int i = rand();
    if (b) {  													// 撞到墙壁,改变方向
        if (i % 4 == 0) { 											// 逆时针转向
            m_dir == UP ? m_cmd = LEFT : m_cmd = UP;				// 面向上，向左拐
        }
        else if (i % 3 == 0) {
            m_dir == DOWN ? m_cmd = RIGHT : m_cmd = DOWN;			// 面向下，向右拐
        }
        else if (i % 2 == 0) {
            m_dir == RIGHT ? m_cmd = UP : m_cmd = RIGHT;			// 面向右，向上拐
        }
        else {
            m_dir == LEFT ? m_cmd = DOWN : m_cmd = LEFT;			// 面向左，向下拐
        }
        return;													// 提前结束函数，返回
    }

    // 程序运行到这里，说明没有撞墙，继续处理
    if (i % 4 == 0) {
        m_dir != UP ? m_cmd = DOWN : m_cmd == UP;		// 非向上移动则使之面向下，否则面向上
    }
    else if (i % 3 == 0) {
        m_dir != DOWN ? m_cmd = UP : m_cmd = DOWN;		// 非向下移动则使之面向上，否则面向下
    }
    else if (i % 2 == 0) {
        m_dir != RIGHT ? m_cmd = LEFT : m_cmd = RIGHT;	// 非向右移动则使之面向左，否则面向右
    }
    else {
        m_dir != LEFT ? m_cmd = RIGHT : m_cmd = LEFT;	// 非向左移动则使之面向右，否则面向左
    }
}



BlueEnemy::BlueEnemy(int x, int y)
{
    imagif = new QLabel;
    imagif->setFixedSize(MONSTERSIZE, MONSTERSIZE);
    QMovie * movie = new QMovie(":/res/ghost1.gif");
    movie->setScaledSize(QSize(imagif->width(), imagif->height()));
    imagif->setMovie(movie);
    movie->start();

    //imagif->setText("ads");
    actual_x = x;
    actual_y = y;

    speed = BLUESPEED;
    m_cmd = RIGHT;
}

void BlueEnemy::MakeDirection(bool b)
{
    const int DR = this->logic_y - player->logic_y;
    const int DA = this->logic_x - player->logic_x;
    if (!b && DR == 0) {
        if (DA <= BLUEALERT && DA > 0) {  // 玩家在左侧边警戒范围s
            m_cmd = LEFT;                   // 向左移动
            return;
        }
        if (DA < 0 && DA >= -BLUEALERT) {  // 右侧警戒范围
            m_cmd = RIGHT;                   // 向右移动
            return;
        }
    }
    if (!b && DA == 0) {
        if (DR <= BLUEALERT && DR > 0) {   // 下方警戒范围
            m_cmd = UP;                      // 向上移动
            return;
        }
        if (DR < 0 && DR >= -BLUEALERT) {  // 上方警戒范围
            m_cmd = DOWN;                    // 向下移动
            return;
        }
    }

    int i = rand();
    if (b) {  													// 撞到墙壁,改变方向
        if (i % 4 == 0) { 											// 逆时针转向
            m_dir == UP ? m_cmd = LEFT : m_cmd = UP;				// 面向上，向左拐
        }
        else if (i % 3 == 0) {
            m_dir == DOWN ? m_cmd = RIGHT : m_cmd = DOWN;			// 面向下，向右拐
        }
        else if (i % 2 == 0) {
            m_dir == RIGHT ? m_cmd = UP : m_cmd = RIGHT;			// 面向右，向上拐
        }
        else {
            m_dir == LEFT ? m_cmd = DOWN : m_cmd = LEFT;			// 面向左，向下拐
        }
        return;													// 提前结束函数，返回
    }

    // 程序运行到这里，说明没有撞墙，继续处理
    if (i % 4 == 0) {
        m_dir != UP ? m_cmd = DOWN : m_cmd == UP;		// 非向上移动则使之面向下，否则面向上
    }
    else if (i % 3 == 0) {
        m_dir != DOWN ? m_cmd = UP : m_cmd = DOWN;		// 非向下移动则使之面向上，否则面向下
    }
    else if (i % 2 == 0) {
        m_dir != RIGHT ? m_cmd = LEFT : m_cmd = RIGHT;	// 非向右移动则使之面向左，否则面向右
    }
    else {
        m_dir != LEFT ? m_cmd = RIGHT : m_cmd = LEFT;	// 非向左移动则使之面向右，否则面向左
    }

}


YellowEnemy::YellowEnemy(int x, int y)
{
    imagif = new QLabel;
    imagif->setFixedSize(MONSTERSIZE, MONSTERSIZE);
    QMovie * movie = new QMovie(":/res/ghost3.gif");
    movie->setScaledSize(QSize(imagif->width(), imagif->height()));
    imagif->setMovie(movie);
    movie->start();

    actual_x = x;
    actual_y = y;

    speed = YELLOWSPEED;
    m_cmd = DOWN;
}

void YellowEnemy::MakeDirection(bool b)
{
    const int DR = this->logic_y - player->logic_y;
    const int DA = this->logic_x - player->logic_x;
    if (!b) {
        if (DR * DR > DA * DA) {
            if (DA > 0) {  		// 玩家在左侧边警戒范围
                m_cmd = LEFT;  	// 向左移动
                return;
            }
            else if (DA < 0) {  	// 右侧警戒范围
                m_cmd = RIGHT;	// 向右移动
                return;
            }
        }
        else {
            if (DR > 0) {  		// 下方警戒范围
                m_cmd = UP;		// 向上移动
                return;
            }
            if (DR < 0) {  		// 上方警戒范围
                m_cmd = DOWN;		// 向下移动
                return;
            }
        }
    }

    int i = rand();
    if (b) {  													// 撞到墙壁,改变方向
        if (i % 4 == 0) { 											// 逆时针转向
            m_dir == UP ? m_cmd = LEFT : m_cmd = UP;				// 面向上，向左拐
        }
        else if (i % 3 == 0) {
            m_dir == DOWN ? m_cmd = RIGHT : m_cmd = DOWN;			// 面向下，向右拐
        }
        else if (i % 2 == 0) {
            m_dir == RIGHT ? m_cmd = UP : m_cmd = RIGHT;			// 面向右，向上拐
        }
        else {
            m_dir == LEFT ? m_cmd = DOWN : m_cmd = LEFT;			// 面向左，向下拐
        }
        return;													// 提前结束函数，返回
    }


}
