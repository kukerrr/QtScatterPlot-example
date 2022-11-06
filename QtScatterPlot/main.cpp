
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
//#include "chartview.h"
#include "QtScatterPlot.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    QtScatterPlot chartView(&window);
    window.setCentralWidget(&chartView);
    window.resize(400, 300);
    window.show();

   /* ChartView chartView(&window);
    window.setCentralWidget(&chartView);
    window.resize(400, 300);
    window.show();*/

    return a.exec();
}