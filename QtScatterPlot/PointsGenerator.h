#pragma once

#include <QtWidgets/QWidget>
#include <QPushbutton>
#include <QTimer>

class PointsGenerator:public QObject {
    Q_OBJECT

    QTimer* m_timer;
public:
    PointsGenerator(QObject* parent);
public Q_SLOTS:
    void generatePoint(); //generate point by tick!
    void start();
    void stop();
signals:
    void newPoint(QPointF);
    void newPoints(QList<QPointF>);
};