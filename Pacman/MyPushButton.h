#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H


#include <QPushButton>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:

    //构造函数，参数1，正常路径，参数2，按下后显示路径
    myPushButton(QString normalImg,QString pressImg ="");

    //保存默认路径，按下后路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1();//向上
    void zoom2();//向下

    //重写按钮按下释放
    void mousePressEvent(QMouseEvent*e);

    void mouseReleaseEvent(QMouseEvent*e);

signals:

};

#endif // MYPUSHBUTTON_H
