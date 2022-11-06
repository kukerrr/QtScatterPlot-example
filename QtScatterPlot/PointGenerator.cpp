#include "PointsGenerator.h"
#include <QRandomGenerator>

void PointsGenerator::generatePoint() {
	
	/*qreal w = QRandomGenerator::global()->bounded(5.);
	qreal h = QRandomGenerator::global()->bounded(5.);
	emit newPoint(QPointF(w, h));
	return;*/

	QList<QPointF> points;
	for (int i = 0; i < 10;i++) {
		qreal w = QRandomGenerator::global()->bounded(5.) ;
		qreal h = QRandomGenerator::global()->bounded(5.) ;
		points.append(QPointF( w, h ));
	}
	emit newPoints(points);
}
void PointsGenerator::start(){
	m_timer->start();
}
void PointsGenerator::stop(){
	m_timer->stop();
}
PointsGenerator::PointsGenerator(QObject* parent)
	: QObject(parent) 
{
	m_timer = new QTimer(this);
	m_timer->setInterval(500);
	connect(m_timer, &QTimer::timeout, this, &PointsGenerator::generatePoint);
	m_timer->start();
}