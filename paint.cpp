#include "paint.h"
#include <QPainter>
#include "binarytree.h"
#include "node.h"
#include <iostream>
#include <QGridLayout>
using namespace std;
class Node;

Paint::Paint (QWidget* P) :QWidget(P)
{
}
void Paint::getBT(Node* t, const int _rightborder)
{
    leftborder = 0;
    rightborder = _rightborder;
    qqq = t;
  // cout << "fdlaflas" << &(t.root) << " ### " << t.root->getValue() << endl;
    //cout <<" lfodslfoasl" << "### " << qqq->root->getValue() << endl;
}
void Paint::paintEvent(QPaintEvent* p)
{
    Q_UNUSED(p);
    QPainter qp (this); //создаем объект рисовальщика
    if (qqq)
    {
        pen.color() = Qt::black;
        pen.setWidth(2);
        QFont font  = qp.font();
        font.setPixelSize(15);
        qp.setFont(font);
        qp.setRenderHint(QPainter::Antialiasing);
        qp.setPen(pen);
        drawLines(&qp, qqq, leftborder, rightborder, LEVEL);
    }
   else
   {
       qp.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования
       qp.drawLine(0,0,width(),height()); // Рисование линии
   }

}
void Paint::drawLines(QPainter* qp, Node*p, int l, int r, int y, int lastx)
{
        int x = (l+r)/2;
        el.setRect(x,y,WIDTH,HEIGHT);
        QPoint ot = el.center();
        QRect temp;
        qp->setBrush(Qt::green);
        if (p->left)
        {
            temp.setRect((l+x)/2, y+LEVEL, WIDTH,HEIGHT);
            qp->drawLine(ot, temp.center());
            drawLines(qp, p->left, l,x, y+LEVEL, x);
        }
        if (p->right)
        {
            temp.setRect((r+x)/2, y+LEVEL, WIDTH,HEIGHT);
            qp->drawLine(ot, temp.center());
            drawLines(qp, p->right, x,r, y+LEVEL, x);
        }
        QPoint tpoint;
        if (!p->left && !p->right)
        {
            qp->drawEllipse(el);
            tpoint = el.center();
            qp->drawText(tpoint.rx() - WIDTH/4, tpoint.ry()+HEIGHT/4, QString::number(p->pr->getValue()));
        }
        if (p->pr)
        {
            temp.setRect(lastx, y-LEVEL, WIDTH, HEIGHT);
            qp->drawEllipse(temp);
            tpoint = temp.center();
            qp->drawText(tpoint.rx() - WIDTH/4, tpoint.ry() + HEIGHT/4, QString::number(p->pr->getValue()));
        }

}
