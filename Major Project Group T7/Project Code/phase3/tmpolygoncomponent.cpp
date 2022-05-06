#include "tmpolygoncomponent.h"
#include<DrawableComponent.h>
QPointF *TMPolygonComponent::getPoint() const
{
    return point;
}

void TMPolygonComponent::setPoint(QPointF *value)
{
    point = value;
}

QString TMPolygonComponent::getBorderColor() const
{
    return borderColor;
}

void TMPolygonComponent::setBorderColor(const QString &value)
{
    borderColor = value;
}

QString TMPolygonComponent::getFillColor() const
{
    return fillColor;
}

void TMPolygonComponent::setFillColor(const QString &value)
{
    fillColor = value;
}

bool TMPolygonComponent::getIsFilled() const
{
    return isFilled;
}

void TMPolygonComponent::setIsFilled(bool value)
{
    isFilled = value;
}

int TMPolygonComponent::getWidth() const
{
    return width;
}

void TMPolygonComponent::setWidth(int value)
{
    width = value;
}

int TMPolygonComponent::getSize() const
{
    return size;
}

void TMPolygonComponent::setSize(int value)
{
    size = value;
}

TMPolygonComponent::TMPolygonComponent()
{

}
void TMPolygonComponent::draw(QPainter *event)
{
    QPainter *painter=event;
    QPen pen;
    pen.setColor(borderColor);
    pen.setWidth(width);
    painter->setPen(pen);
    if(isFilled)painter->setBrush(QColor(fillColor));
    else painter->setBrush(Qt::white);
    painter->drawPolygon(point,size);
}
