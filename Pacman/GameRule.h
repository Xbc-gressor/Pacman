#ifndef GAMERULE_H
#define GAMERULE_H

#include <QMainWindow>

class GameRule : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameRule(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*);

signals:
    void chooseSceneBack();

};

#endif // GAMERULE_H
