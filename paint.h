#ifndef PAINT_H
#define PAINT_H
#include <QWidget>
#include "binarytree.h"
#include <QPainter>
#include "node.h"
#include <QGraphicsEllipseItem>
#include <QRectF>
#include <QGridLayout>
class Node;
class Paint : public QWidget
{
    int leftborder, rightborder;
    QRect el;
    QPen pen;
    int _height, _width, _font, _level;
    enum {HEIGHT = 40, WIDTH = 40};
    enum {FONT = WIDTH/3, LEVEL = 50};
public:
    Node* qqq = nullptr;
    Paint(QWidget*p = nullptr);
    void getBT(Node* t, const int _rightborder);
    void paintEvent(QPaintEvent* event);
    void drawLines(QPainter* qp, Node* p, int l, int r, int y, int lastx = 0);
};

#endif // PAINT_H
