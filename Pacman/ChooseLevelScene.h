#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H
#include "GameScene.h"
#include <QMainWindow>

class chooselevelscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooselevelscene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

    //游戏场景对象指针
    GameScene * play = NULL;

signals:
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
