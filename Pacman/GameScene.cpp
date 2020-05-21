#include "GameScene.h"
#include "MyPushButton.h"
#include "config.h"
#include <QDebug>
#include "config.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QSound>

//GameScene::GameScene(QWidget *parent) : QMainWindow(parent)
//{

//    gameTimer.setInterval(10);
//    initConnect();

//}

GameScene::GameScene(int GameLevel)
{
    //设置刷新间隔
    gameTimer.setInterval(1);

    //设置大小
    this->setFixedSize(WIDTH, HEIGHT);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/ghost1.png"));
    //设置标题
    this->setWindowTitle("PACMAN");

    //创建菜单栏
    QMenuBar * bar = menuBar();
    setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("begin");
    //创建退出 菜单项
    QAction *  quitAction = startMenu->addAction("quit");
    QAction *  quitAction1 = startMenu->addAction("game rule");
    QAction *  quitAction2 = startMenu->addAction("stop the game");

    //点击退出 实现退出游戏
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });

    //链接信号和槽
    initConnect();

    //开始游戏
    startGame();
}

void GameScene::startGame()
{
    gameTimer.start();
}

void GameScene::initConnect()
{
    //更新图像
    connect(&gameTimer, &QTimer::timeout, [=](){
        update();
    });



    //添加音效资源
    //返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);

    //翻金币音效
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
    //胜利按钮音效
    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);

    //返回按钮
    myPushButton *backBtn=new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    connect(backBtn,&myPushButton::clicked,[=](){
        qDebug()<<"play scene:choose quit";
        backSound->play();
        //告诉关卡选择场景返回了 接受信号
        QTimer::singleShot(400,this,[=](){
            emit this->chooseSceneBack();
        });

    });
};

//响应键盘按下事件
void GameScene::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_W)
    {
        pacman->direction = UP;
        pacman->actual_y -= 5;
        qDebug()<< pacman->direction;
    }
    else if(event->key() == Qt::Key_S)
    {
        pacman->direction = DOWN;
        pacman->actual_y += 5;
        qDebug()<< pacman->direction;
    }
    else if(event->key() == Qt::Key_A)
    {
        pacman->direction = LEFT;
        pacman->actual_x -= 5;
        qDebug()<< pacman->direction;
    }
    else if(event->key() == Qt::Key_D)
    {
        pacman->direction = RIGHT;
        pacman->actual_x += 5;
        qDebug()<< pacman->direction;
    }

}

void GameScene::paintEvent(QPaintEvent *)
{
    //创建画图对象
    QPainter painter(this); //this 代表画在当前屏幕

    //绘制吃豆人
    painter.drawPixmap(pacman->actual_x, pacman->actual_y, pacman->image);
}

//更新各单位坐标
void GameScene::updatePosition()
{

}
