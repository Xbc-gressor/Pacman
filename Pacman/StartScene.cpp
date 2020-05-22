#include "StartScene.h"
#include "config.h"
#include "ui_startscene.h"

StartScene::StartScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScene)
{
    ui->setupUi(this);

    InitConnect();

    this->setFixedSize(HEIGHT, HEIGHT);

    startGameBtn->setParent(this);
    startGameBtn->setFixedSize(200, 80);
    startGameBtn->setText("开始游戏");
    startGameBtn->setGeometry( (this->width()-startGameBtn->width()) * 0.5, this->height() * 0.5,
                               startGameBtn->width(), startGameBtn->height());

    gameRulesBtn->setParent(this);
    gameRulesBtn->setFixedSize(200, 80);
    gameRulesBtn->setText("游戏规则");
    gameRulesBtn->setGeometry( (this->width()-startGameBtn->width()) * 0.5, this->height() * 0.5 + 150,
                               startGameBtn->width(), startGameBtn->height());

}

StartScene::~StartScene()
{
    delete ui;
}

void StartScene::InitConnect()
{
    //进入关卡选择场景
    connect(startGameBtn, &QPushButton::clicked,[=](){
        this->hide();
        chooseLevel->setGeometry(this->geometry());
        chooseLevel->show();
    });

    //进入游戏规则场景
    connect(gameRulesBtn, &QPushButton::clicked,[=](){
        //延时进入
        QTimer::singleShot(400,this,[=](){
            gameRule->setGeometry(this->geometry());
            this->hide();
            gameRule->show();
        });
     });

    //从选择游戏规则场景返回
    connect(gameRule, &GameRule::chooseSceneBack,this,[=](){
        this->setGeometry(gameRule->geometry());
        gameRule->hide();
        this->show();

    });

    //从关卡选择场景返回
    connect(chooseLevel,&chooselevelscene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseLevel->geometry());
        chooseLevel->hide();
        this->show();

    });
}

