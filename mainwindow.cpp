#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
class QPushButton;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Add, SIGNAL(clicked()), this, SLOT(check()));
    connect(ui->Delete, SIGNAL(clicked()), this, SLOT(check1()));
    connect(ui->button_height, SIGNAL(clicked()), this, SLOT(check2()));
     connect(ui->button_max, SIGNAL(clicked()), this, SLOT(check3()));
      connect(ui->button_min, SIGNAL(clicked()), this, SLOT(check4()));
}
void MainWindow::check4()
{
       QMessageBox msg;
       msg.setWindowTitle("Tree");
        msg.setDefaultButton(QMessageBox::Ok);
        QString text = ("  Minimum is   ");
        int temp = tq->searchMin();
        text.append(QString::number(temp));
        msg.setText(text);
        msg.exec();

}
void MainWindow::check3()
{
    QMessageBox msg;
    msg.setWindowTitle("Tree");
     msg.setDefaultButton(QMessageBox::Ok);
     QString text = ("  Maximum is   ");
     int temp = tq->searchMax();
     text.append(QString::number(temp));
     msg.setText(text);
     msg.exec();
}
void MainWindow::check2()
{
    QString str1 = ui->line_height->text();
    int temp = str1.toInt();
    Node* q = tq->private_SearchValue(temp, tq->getRoot());
    if (q) {
        temp = tq->searchHeight(tq->private_SearchValue(temp,tq->getRoot())) - 1;
        QMessageBox msg;
        msg.setWindowTitle("Tree");
        msg.setDefaultButton(QMessageBox::Ok);
        QString text = ("   Height is    ");
        text.append(QString::number(temp));
        msg.setText(text);
        msg.exec();
    }
}
void MainWindow::check1()
{
     QString str1 = ui->toDelete->text();
     int temp = str1.toInt();
     tq->deleteValue(temp);
     repaint();

}
void MainWindow::check()
{
     QString str1 = ui->toAdd->text();
     int temp = str1.toInt();
     tq->addValue(temp);
     repaint();
     repaint();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* p)
{
    Q_UNUSED(p);
    QPainter qp (this);

    QHBoxLayout* l = new QHBoxLayout;
    l->setAlignment(Qt::AlignCenter);
    l->addWidget(this, Qt::AlignCenter);
    if (tq)
    {
        pen.color() = Qt::black;
        pen.setWidth(2);
        QFont font  = qp.font();
        font.setPixelSize(15);
        qp.setFont(font);
        qp.setRenderHint(QPainter::Antialiasing);
        qp.setPen(pen);
        drawLines(&qp, tq->getRoot(), 0, width()-100, LEVEL);
    }
}
void MainWindow::drawLines(QPainter* qp, Node*p, int l, int r, int y, int lastx)
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
            qp->drawText(tpoint.rx() - WIDTH/4, tpoint.ry()+HEIGHT/4, QString::number(p->getValue()));
        }
        if (p->pr)
        {
            temp.setRect(lastx, y-LEVEL, WIDTH, HEIGHT);
            qp->drawEllipse(temp);
            tpoint = temp.center();
            qp->drawText(tpoint.rx() - WIDTH/4, tpoint.ry() + HEIGHT/4, QString::number(p->pr->getValue()));
        }

}


