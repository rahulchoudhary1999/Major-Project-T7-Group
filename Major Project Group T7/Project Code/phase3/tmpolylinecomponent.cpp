#include "tmpolylinecomponent.h"

/*TMPolylineComponent::TMPolylineComponent(QPointF *point,QString color,int width)
{
this->point=point;
this->color=color;
this->width=width;
}*/


QPointF *TMPolylineComponent::getPoint() const
{
    return point;
}

void TMPolylineComponent::setPoint(QPointF *value)
{
    point = value;
}

QString TMPolylineComponent::getColor() const
{
    return color;
}

void TMPolylineComponent::setColor(const QString &value)
{
    color = value;
}

int TMPolylineComponent::getWidth() const
{
    return width;
}

void TMPolylineComponent::setWidth(int value)
{
    width = value;
}

int TMPolylineComponent::getSize() const
{
    return size;
}

void TMPolylineComponent::setSize(int value)
{
    size = value;
}

void TMPolylineComponent::draw(QPainter *event)
{
    QPainter *painter=event;
    QPen myPolyLinePen;
    myPolyLinePen.setColor(color);
    myPolyLinePen.setWidth(width);
    painter->setPen(myPolyLinePen);
    painter->drawPolyline(point,size);
}
