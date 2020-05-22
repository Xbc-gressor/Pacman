#include "GameScene.h"
#include "MyPushButton.h"
#include "config.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <QWidget>
#include "config.h"
#include <QDebug>
#include <QPen>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QMovie>
#include <QSound>


GameScene::GameScene(int GameLevel)
{
    //设置刷新间隔
    gameTimer.setInterval(30);

    //设置大小
    this->setFixedSize(WIDTH, HEIGHT);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/ghost1.png"));
    //设置标题
    this->setWindowTitle("PACMAN");

    //初始化地图
    switch (GameLevel) {
    case 1:
        map = new Stage_1;
        break;
    case 2:
        map = new Stage_2;
        break;
    case 3:
        map = new Stage_3;
        break;
    case 4:
        map =  new Stage_4;
        break;
    }

    //胜利图片
    winLabel = new QLabel;
    QPixmap tmpPix = QPixmap(":/res/SuccessImg.png");
    tmpPix = tmpPix.scaled(tmpPix.width()*1.8, tmpPix.height()*1.8);

    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (HEIGHT - tmpPix.width())*0.5 , -tmpPix.height());

    //失败图片
    failLabel = new QLabel;
    QPixmap tmpPix1 = QPixmap(":/res/SuccessImg.png");
    tmpPix1 = tmpPix1.scaled(tmpPix1.width()*1.8, tmpPix1.height()*1.8);

    failLabel->setGeometry(0,0,tmpPix1.width(),tmpPix1.height());
    failLabel->setPixmap(tmpPix1);
    failLabel->setParent(this);
    failLabel->move( (HEIGHT - tmpPix1.width())*0.5 , -tmpPix1.height());

    //放上化吃豆人
    pacman = new PacmanPlayer(475, 875);
    //放上怪
    enemys[0] = new RedEnemy(75, 75);
    enemys[1] = new BlueEnemy(75, 75);
    enemys[2] = new YellowEnemy(875, 75);
    enemys[3] = new RedEnemy(875, 875);
    for(int i = 0; i < 4; i++)
        enemys[i]->imagif->setParent(this);
    Enemy::player = pacman;
    BaseObject::map = map;


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
        //更新坐标
        updatePosition();
        //重新绘图
        update();
        //判断胜负
        gameResult();
    });



    //添加音效资源
    //返回按钮音效
//    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);

//    //翻金币音效
//    //QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
//    //胜利按钮音效
//    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);

    //返回按钮
    myPushButton *backBtn=new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    connect(backBtn,&myPushButton::clicked,[=](){
        qDebug()<<"play scene:choose quit";
        //backSound->play();
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
        pacman->m_cmd = UP;
    }
    else if(event->key() == Qt::Key_S)
    {
        pacman->m_cmd = DOWN;
    }
    else if(event->key() == Qt::Key_A)
    {
        pacman->m_cmd = LEFT;
    }
    else if(event->key() == Qt::Key_D)
    {
        pacman->m_cmd = RIGHT;
    }

}


void GameScene::paintEvent(QPaintEvent *)
{
    //创建画图对象
    QPainter painter(this); //this 代表画在当前屏幕

    //绘制黑色背景
    painter.setBrush(Qt::black);
    painter.drawRect(rect());

    //绘制障碍物
    QPixmap GreyStone=QPixmap(":/res/greystone.png").scaled(QSize(BRICKSIZE,BRICKSIZE));
    for(int i=0;i<MAPLENGTH;++i)
        for(int j=0;j<MAPLENGTH;++j)
            if (map->WallData[i][j]) painter.drawPixmap(j*BRICKSIZE, i*BRICKSIZE,GreyStone);

    //绘制豆子
    QPen pen;
    pen.setWidth(6);
    pen.setColor(Qt::white); // 设置画笔为黄色
    painter.setPen(pen); // 设置画笔
    for(int i=0;i<MAPLENGTH;++i)
        for(int j=0;j<MAPLENGTH;++j)
            if (map->BeanData[i][j]) painter.drawPoint(j*BRICKSIZE + 23, i*BRICKSIZE + 23);

    //绘制吃豆人
    painter.drawPixmap(pacman->actual_x - PACMANSIZE * 0.5, pacman->actual_y - PACMANSIZE * 0.5, pacman->image);

    //放置怪
    for(int i = 0; i < 4; i++)
        enemys[i]->imagif->move(enemys[i]->actual_x - MONSTERSIZE * 0.5, enemys[i]->actual_y - MONSTERSIZE * 0.5);

}

//更新各单位坐标
void GameScene::updatePosition()
{

    //吃豆人和怪物进行碰撞检测
    pacman->collision();
    for(int i = 0; i < 4; i++)
    {
        bool b = enemys[i]->collision();
        enemys[i]->MakeDirection(b);
    }



}

void GameScene::gameResult()
{
    //判断是否输
    for(int i = 0; i < 4; i++)
        if(enemys[i]->logic_x == pacman->logic_x && enemys[i]->logic_y == pacman->logic_y)
        {
            gameTimer.stop();
            //将失败图片砸下来
            QPropertyAnimation * animation=new QPropertyAnimation(failLabel,"geometry");
            //设置时间间隔
            animation->setDuration(1000);
            //设置开始位置
            animation->setStartValue(QRect(failLabel->x(),failLabel->y(),failLabel->width(),failLabel->height()));
            //设置结束位置
            animation->setEndValue(QRect(failLabel->x(),failLabel->y()+230,failLabel->width(),failLabel->height()));
            //设置缓和曲线
            animation->setEasingCurve(QEasingCurve::OutBounce);
            //执行动画
            animation->start();

            return;
        }


    //判断是否胜利
    bool isWin = true;
    for(int i = 0; i < MAPLENGTH; i++)
    {
        for(int j = 0; j < MAPLENGTH; j++)
            if(map->BeanData[i][j])
            {
                isWin = false;
                break;
            }
        if(isWin = false) break;
    }

    if(isWin)
    {
        gameTimer.stop();
        //将胜利图片砸下来
        QPropertyAnimation * animation=new QPropertyAnimation(winLabel,"geometry");
        //设置时间间隔
        animation->setDuration(1000);
        //设置开始位置
        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
        //设置结束位置
        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+230,winLabel->width(),winLabel->height()));
        //设置缓和曲线
        animation->setEasingCurve(QEasingCurve::OutBounce);
        //执行动画
        animation->start();
    }


}
