#include "mainwindow.h"
#include "avltree.h"
#include <QApplication>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));
    int n = 20;
    int* array = new int[n];
    for (int i = 0; i < n; ++i)
    {
        array[i] = 0;
    }
    BinaryTree* temp = new BinaryTree(array,n);
    SearchTree* temp1 =  new SearchTree(array,n);
    int array1[] = {6,  85,  69,  95,  44 , 2 , 105, 7,  4,  27};
    avlTree* temp2= new avlTree(array1,10);


    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.setPointer(temp2);
    w.show();

    return a.exec();
}
