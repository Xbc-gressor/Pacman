#ifndef STARTSCENE_H
#define STARTSCENE_H

#include <QMainWindow>
#include <QPushButton>
#include "ChooseLevelScene.h"
#include "GameRule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StartScene; }
QT_END_NAMESPACE

class StartScene : public QMainWindow
{
    Q_OBJECT

public:
    StartScene(QWidget *parent = nullptr);
    ~StartScene();

    void InitConnect();

public:
    QPushButton * startGameBtn = new QPushButton;

    QPushButton * gameRulesBtn = new QPushButton;

    chooselevelscene * chooseLevel = new chooselevelscene;

    GameRule * gameRule = new GameRule;

private:
    Ui::StartScene *ui;
};
#endif // STARTSCENE_H
