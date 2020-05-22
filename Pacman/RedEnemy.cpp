#include "RedEnemy.h"
#include "config.h"
#include <ctime>

RedEnemy::RedEnemy()
{
    imagif = new QLabel;
    imagif->setFixedSize(MONSTERSIZE, MONSTERSIZE);
    QMovie * movie = new QMovie(":/res/ghost2.gif");
    movie->setScaledSize(QSize(imagif->width(), imagif->height()));
    imagif->setMovie(movie);
    movie->start();

    //imagif->setText("ads");
    actual_x = 100;
    actual_y = 100;

    speed = 5;
    direction = RIGHT;

}

void RedEnemy::MakeDirection()
{
    srand(time(0));
    int i = rand();
    if (i % 5 == 0) { 											// 逆时针转向
        direction == UP ? direction = LEFT : direction = UP;				// 面向上，向左拐
    }
    else if (i % 3 == 0) {
        direction == DOWN ? direction = RIGHT : direction = DOWN;			// 面向下，向右拐
    }
    else if (i % 2 == 0) {
        direction == RIGHT ? direction = UP : direction = RIGHT;			// 面向右，向上拐
    }
    else {
        direction == LEFT ? direction = DOWN : direction = LEFT;			// 面向左，向下拐
    }
    return;													// 提前结束函数，返回
}
