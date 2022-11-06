#pragma once

#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QScatterSeries>
#include <QMutex>

QT_USE_NAMESPACE

class ChartView : public QChartView
{
    Q_OBJECT


public:
    ChartView(QWidget* parent = 0);
    ~ChartView();
    void clearAll();
public Q_SLOTS:
    void handleClickedPoint(const QPointF& point);
    void addPoint(const QPointF& point);
    void addPoints(const QList<QPointF>& point);
    
private:
    QScatterSeries* m_scatter;
    //QScatterSeries* m_scatter2;
    QMutex*         m_mutex;
};

#endif // CHARTVIEW_H
