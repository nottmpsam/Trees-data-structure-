#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "paint.h"
#include <QMainWindow>
#include <QGraphicsEllipseItem>
#include <QRectF>

class QGridLayout;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class avlTree;
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QRect el;
    QPen pen;
    int _height, _width, _font, _level;
    enum {HEIGHT = 40, WIDTH = 40};
    enum {FONT = WIDTH/3, LEVEL = 50};
    BinaryTree* tq = nullptr;
public slots:
    void check();
    void check1();
    void check2();
    void check3();
    void check4();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setPointer(BinaryTree* _tq)
    {
        tq = _tq;
    }
    void paintEvent(QPaintEvent* p);
    void drawLines(QPainter* qp, Node*p, int l, int r, int y, int lastx=0);
    QGridLayout* grid;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
