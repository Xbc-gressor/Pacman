#include "ChooseLevelScene.h"
#include "config.h"
#include <QSound>
#include <QPainter>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "MyPushButton.h"

chooselevelscene::chooselevelscene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(WIDTH, HEIGHT);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/ghost1.png"));

    //设置标题
    this->setWindowTitle("选择关卡");

    //返回按钮
    myPushButton *backBtn=new myPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    //返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);
    //点击返回按钮事件
    connect(backBtn,&myPushButton::clicked,[=]()
    {
        //qDebug()<<"choose quit";
        //告诉主场景返回了 主场景接受信号
        //播放返回按钮音效
        backSound->play();
        QTimer::singleShot(400,this,[=](){
            emit this->chooseSceneBack();
        });

    });

    //选择关卡图标
    for(int i = 0; i<4; i++)
    {
        QPushButton *menuBtn=new QPushButton(":/res/BoardNode.png");
        menuBtn->setFixedSize(100,100);
        menuBtn->setParent(this);

        //背景上设置关卡号
        QLabel*Label=new QLabel;
        Label->setParent(this);
        Label->setFixedSize(menuBtn->width(),menuBtn->height());
        Label->setText(QString::number(i+1));

        if(i==0||i==1)
        {
            menuBtn->move(150,200+i%4*330);
            QString str=QString("YOU CHOOSE CHALlenge %1").arg(i+1);
            qDebug()<<str;
            Label->move(150,200+i%4*330);
            //设置label文字对齐
            Label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
        else if(i==2)
        {
            menuBtn->move(500,600);
            QString str=QString("YOU CHOOSE CHALlenge %1").arg(i+1);
            qDebug()<<str;
            Label->move(500,600);
            //设置label文字对齐
            Label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
        else
        {
           menuBtn->move(420,350);
           QString str=QString("YOU CHOOSE CHALlenge %1").arg(i+1);
           qDebug()<<str;
           Label->move(420,350);
           //设置label文字对齐
           Label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }

       //设置让鼠标穿透
       Label->setAttribute(Qt::WA_TransparentForMouseEvents);

       //监听每个按钮点击事件
       connect(menuBtn,&myPushButton::clicked,[=](){
           //播放选择关卡音效

           //chooseSound->play();
           QString str=QString("YOU CHOOSE%i CHALlenge").arg(i+1);
           qDebug()<<str;


           //进入到游戏场景
           this->hide();
           play = new GameScene(i+1);
           //设置游戏场景初始位置
           play->setGeometry(this->geometry());
           play->show();

           connect(play, &GameScene::chooseSceneBack,[=](){
              this->setGeometry(play->geometry());
              this->show();
              play->close();
              delete play;
              play =NULL;
           });
       });

    }

}
//显示背景图片，当做后期的选择页面图，几个数字改成按钮，进入三个不同关卡
void chooselevelscene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MainScenebgIMG.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
