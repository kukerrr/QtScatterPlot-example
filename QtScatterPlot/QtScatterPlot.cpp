#include "QtScatterPlot.h"
#include <QGridLayout>
#include <QApplication>
#include <QStyle>
#include <QIcon>

QtScatterPlot::~QtScatterPlot() {
    stop();
};

QtScatterPlot::QtScatterPlot(QWidget *parent)
    : QWidget(parent)
{
    m_curStatus = Status::stop;
    createGui();
    connectGui();
}
void    QtScatterPlot::connectGui() {
    connect(m_playBut,  &QPushButton::released, this, &QtScatterPlot::play);
    connect(m_pauseBut, &QPushButton::released, this, &QtScatterPlot::pause);
    connect(m_stopBut,  &QPushButton::released, this, &QtScatterPlot::stop);
};

void QtScatterPlot::createGui() {
    
    m_chartView = new ChartView();
    m_playBut   = new QPushButton("Play");
    m_playBut->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPlay));
    m_pauseBut = new QPushButton("Pause");
    m_pauseBut->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaPause));
    m_stopBut = new QPushButton("Stop");
    m_stopBut->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaStop));

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(m_chartView, 0, 0, 0, 5);
    layout->addWidget(m_playBut, 3, 1);
    layout->addWidget(m_pauseBut, 3, 2);
    layout->addWidget(m_stopBut, 3, 3);
    this->show();
}
bool QtScatterPlot::changeStatus(Status s){
    if (s != m_curStatus) {
        return true;
    };
    return false;
};

void QtScatterPlot::createThread() {
    m_genThread = new QThread;
    m_pointsGen = new PointsGenerator(this);

    connect(m_pointsGen, &PointsGenerator::newPoint, 
                m_chartView, &ChartView::addPoint);

    connect(m_pointsGen, &PointsGenerator::newPoints,
            m_chartView, &ChartView::addPoints);

    m_pointsGen->moveToThread(m_genThread);
    connect(m_genThread, &QThread::finished, m_pointsGen, &QObject::deleteLater);
    m_genThread->start();
}

void QtScatterPlot::play() {
    if (!changeStatus(Status::play))
        return;
    m_curStatus = Status::play;
    if (m_curStatus == Status::pause) {
        m_pointsGen->start();
    }
    createThread();
    return;

};
void QtScatterPlot::pause() {
    if (!changeStatus(Status::pause))
        return;
    m_curStatus = Status::pause;
    if (m_pointsGen!=nullptr) {
        m_pointsGen->stop();
    }
    
};
void QtScatterPlot::stop() {
    if (!changeStatus(Status::stop))
        return;
    m_curStatus = Status::stop;
    //delete thread;
    if (m_pointsGen != nullptr) {
        m_pointsGen->stop();
        m_pointsGen = nullptr;
    }
    if (m_genThread != nullptr) {
        m_genThread->quit();
        m_genThread->wait();
        m_genThread = nullptr;
    }
    //Clear Points
    m_chartView->clearAll();

};
