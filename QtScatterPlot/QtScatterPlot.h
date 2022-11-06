#pragma once

#include <QtWidgets/QWidget>
#include <QPushbutton>
#include <QTimer>
#include <QThread>
#include "Chartview.h"
#include "PointsGenerator.h"

enum class Status { play, pause, stop };


class QtScatterPlot : public QWidget
{
    Q_OBJECT

   Status           m_curStatus ;
   ChartView*       m_chartView = nullptr;
   QPushButton*     m_playBut   = nullptr;
   QPushButton*     m_pauseBut  = nullptr;
   QPushButton*     m_stopBut   = nullptr;
   PointsGenerator* m_pointsGen = nullptr;
   QThread*         m_genThread = nullptr;

   bool             changeStatus(Status s);
   void             createThread();
   void             createGui();
   void             connectGui();
public:
    QtScatterPlot(QWidget *parent = nullptr);
    ~QtScatterPlot();
    

private Q_SLOTS:
    void play();
    void pause();
    void stop();
};
