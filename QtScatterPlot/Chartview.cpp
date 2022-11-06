#include "chartview.h"
#include <QtCore/QtMath>
#include <QtCore/QDebug>

QT_USE_NAMESPACE

ChartView::ChartView(QWidget* parent)
    : QChartView(new QChart(), parent),
    m_scatter(0)
    //,m_scatter2(0)
{
    m_mutex=new QMutex();
    setRenderHint(QPainter::Antialiasing);
    chart()->setTitle("Points count: 0");

    m_scatter = new QScatterSeries(parent);
    
    //m_scatter->setName("Points count: 0");
    //*m_scatter << QPointF(1, 1);
    //m_scatter2 = new QScatterSeries(parent);
    //m_scatter2->setName("scatter2");

    chart()->addSeries(m_scatter);
    chart()->legend()->setVisible(false);

    //chart()->addSeries(m_scatter2);
    chart()->createDefaultAxes();
    chart()->axes(Qt::Horizontal).first()->setRange(0, 5.5);
    chart()->axes(Qt::Vertical).first()->setRange(0, 5.5);

    connect(m_scatter, &QScatterSeries::clicked, this, &ChartView::handleClickedPoint);
    //connect(m_scatter, &QScatterSeries::doubleClicked, this, &ChartView::addPoint);
}

ChartView::~ChartView()
{
    m_mutex->lock();
    m_scatter->clear();
    //m_scatter2->clear();
    m_mutex->unlock();
}
void ChartView::clearAll() {
    m_mutex->lock();
    m_scatter->clear();
    //m_scatter2->clear();
    
    QString name = QString("Point count: ") + QString::number(m_scatter->points().size());
        //QString::number(m_scatter->points().size() + m_scatter2->points().size());
    chart()->setTitle(name);
    //m_scatter->setName(name);
    this->update();
    m_mutex->unlock();

    this->repaint();
};
void ChartView::addPoints(const QList<QPointF>& points) {
    m_mutex->lock();
    m_scatter->append(points);
    QString name = QString("Point count: ") + QString::number(m_scatter->points().size());
        //QString::number(m_scatter->points().size() + m_scatter2->points().size());
    chart()->setTitle(name);
    //m_scatter->setName(name);
    this->update();
    m_mutex->unlock();
};

void ChartView::addPoint(const QPointF& point) {
    m_mutex->lock();
    
    m_scatter->append(point);
    QString name = QString("Point count: ") + QString::number(m_scatter->points().size());
                   //QString::number(m_scatter->points().size()+ m_scatter2->points().size());
    chart()->setTitle(name);
    //m_scatter->setName(name);
    this->update();
    m_mutex->unlock();
};

void ChartView::handleClickedPoint(const QPointF& point)
{
    //TODO: kuker, drops sometimes if move point from scatter1 it to another
    return;
    
    //m_mutex->lock();
    //QPointF clickedPoint = point;
    //// Find the closest point from series 1
    //QPointF closest(INT_MAX, INT_MAX);
    //qreal distance(INT_MAX);
    //const auto points = m_scatter->points();
    ////find the closest;
    //for (const QPointF& currentPoint : points) {
    //    qreal currentDistance = qSqrt((currentPoint.x() - clickedPoint.x())
    //        * (currentPoint.x() - clickedPoint.x())
    //        + (currentPoint.y() - clickedPoint.y())
    //        * (currentPoint.y() - clickedPoint.y()));
    //    if (currentDistance < distance) {
    //        distance = currentDistance;
    //        closest = currentPoint;
    //    }
    //}
   
    //// Remove the closes point from series 1 and append it to series 2
    //m_scatter->remove(closest);
    //m_scatter2->append(closest);
    //chart()->update();
    //m_mutex->unlock();
}