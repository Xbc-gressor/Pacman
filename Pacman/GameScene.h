#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include "BaseObject.h"
#include "PacmanPlayer.h"
#include "Enemy.h"
#include "GMap.h"

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
    //void keyReleaseEvent(QKeyEvent *);


    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //重写绘制背景函数
    //void drawBackground(QPainter *painter, const QRectF &rect);

    //更新每个单位的坐标
    void updatePosition();

    //检测胜利和失败
    void gameResult();



public:
    //吃豆人
    PacmanPlayer * pacman;

    //敌人
    Enemy * enemys[4];

    //定时器
    QTimer gameTimer;

    //地图
    GMap * map;

    //胜利图片
    QLabel* winLabel;
    //失败图片
    QLabel* failLabel;


signals:
    //返回信号
    void chooseSceneBack();
};

#endif // GAMESCENE_H
