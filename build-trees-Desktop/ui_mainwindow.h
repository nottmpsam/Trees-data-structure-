/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *toAdd;
    QPushButton *Add;
    QLineEdit *toDelete;
    QPushButton *Delete;
    QPushButton *button_min;
    QPushButton *button_height;
    QPushButton *button_max;
    QLineEdit *line_height;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        toAdd = new QLineEdit(centralwidget);
        toAdd->setObjectName(QString::fromUtf8("toAdd"));
        toAdd->setGeometry(QRect(10, 440, 113, 24));
        toAdd->setMaximumSize(QSize(16777214, 16777215));
        toAdd->setContextMenuPolicy(Qt::PreventContextMenu);
        Add = new QPushButton(centralwidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(130, 440, 80, 24));
        Add->setMaximumSize(QSize(16777214, 16777215));
        Add->setContextMenuPolicy(Qt::PreventContextMenu);
        toDelete = new QLineEdit(centralwidget);
        toDelete->setObjectName(QString::fromUtf8("toDelete"));
        toDelete->setGeometry(QRect(10, 470, 113, 24));
        toDelete->setMaximumSize(QSize(16777214, 16777215));
        toDelete->setContextMenuPolicy(Qt::PreventContextMenu);
        Delete = new QPushButton(centralwidget);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setGeometry(QRect(130, 470, 80, 24));
        Delete->setMaximumSize(QSize(16777214, 16777215));
        Delete->setContextMenuPolicy(Qt::PreventContextMenu);
        button_min = new QPushButton(centralwidget);
        button_min->setObjectName(QString::fromUtf8("button_min"));
        button_min->setGeometry(QRect(130, 530, 80, 24));
        button_min->setMaximumSize(QSize(16777214, 16777215));
        button_min->setContextMenuPolicy(Qt::PreventContextMenu);
        button_height = new QPushButton(centralwidget);
        button_height->setObjectName(QString::fromUtf8("button_height"));
        button_height->setGeometry(QRect(130, 500, 80, 24));
        button_height->setMaximumSize(QSize(16777214, 16777215));
        button_height->setContextMenuPolicy(Qt::PreventContextMenu);
        button_max = new QPushButton(centralwidget);
        button_max->setObjectName(QString::fromUtf8("button_max"));
        button_max->setGeometry(QRect(40, 530, 80, 24));
        button_max->setMaximumSize(QSize(16777214, 16777215));
        button_max->setContextMenuPolicy(Qt::PreventContextMenu);
        line_height = new QLineEdit(centralwidget);
        line_height->setObjectName(QString::fromUtf8("line_height"));
        line_height->setGeometry(QRect(10, 500, 113, 24));
        line_height->setMaximumSize(QSize(16777214, 16777215));
        line_height->setContextMenuPolicy(Qt::PreventContextMenu);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "AddValue", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "DeleteValue", nullptr));
        button_min->setText(QCoreApplication::translate("MainWindow", "SearchMinValue", nullptr));
        button_height->setText(QCoreApplication::translate("MainWindow", "SearchHeight", nullptr));
        button_max->setText(QCoreApplication::translate("MainWindow", "SearchMaxValue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
