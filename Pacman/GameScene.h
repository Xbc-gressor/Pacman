#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include "PacmanPlayer.h"
#include "RedEnemy.h"
#include "BlueEnemy.h"
#include "YellowEnemy.h"

class GameScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit GameScene(QWidget *parent = nullptr);

    GameScene(int GameLevel );

    //开始游戏
    void startGame();

    //建立信号与槽的连接
    void initConnect();

    //重写键盘事件
    void keyPressEvent(QKeyEvent *);

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //更新每个单位的坐标
    void updatePosition();



public:
    //吃豆人
    PacmanPlayer * pacman = new PacmanPlayer;

    //敌人

    //定时器
    QTimer gameTimer;

//    //画图对象
//    QPainter painter;

signals:
    //返回信号
    void chooseSceneBack();
};

#endif // GAMESCENE_H
