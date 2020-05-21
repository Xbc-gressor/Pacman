#include "GameRule.h"
#include "MyPushButton.h"
#include <QTimer>
#include <QSound>
#include <QPainter>
#include <QPlainTextEdit>

GameRule::GameRule(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(800,840);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/ghost1.png"));

    //设置标题
    this->setWindowTitle("游戏规则");

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

    QPlainTextEdit* rule = new QPlainTextEdit(":/res/rule.txt");
    rule->setParent(this);
    rule->setFixedSize(300,200);
    rule->move(250,320);
    rule->setReadOnly(true);
    rule->show();

}

//显示背景图片
void GameRule::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MainScenebgIMG.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
