#include "BlueEnemy.h"
#include "config.h"

BlueEnemy::BlueEnemy()
{

}

void BlueEnemy::MakeDirection()
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
    return;
}
