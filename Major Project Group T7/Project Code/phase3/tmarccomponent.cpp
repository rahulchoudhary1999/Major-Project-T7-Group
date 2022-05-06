#include "tmarccomponent.h"

int TMArcComponent::getStartAngle() const
{
    return startAngle;
}

void TMArcComponent::setStartAngle(int value)
{
    startAngle = value;
}

int TMArcComponent::getSpanAngle() const
{
    return spanAngle;
}

void TMArcComponent::setSpanAngle(int value)
{
    spanAngle = value;
}

QString TMArcComponent::getColor() const
{
    return color;
}

void TMArcComponent::setColor(const QString &value)
{
    color = value;
}

int TMArcComponent::getWidth() const
{
    return width;
}

void TMArcComponent::setWidth(int value)
{
    width = value;
}

int TMArcComponent::getX() const
{
    return x;
}

void TMArcComponent::setX(int value)
{
    x = value;
}

int TMArcComponent::getY() const
{
    return y;
}

void TMArcComponent::setY(int value)
{
    y = value;
}

int TMArcComponent::getHeight() const
{
    return height;
}

void TMArcComponent::setHeight(int value)
{
    height = value;
}

TMArcComponent::TMArcComponent()
{

}
void TMArcComponent::draw(QPainter *event)
{
    QPen pen;
    pen.setColor(color);
    QPainter *painter=event;
    painter->setPen(pen);
    painter->drawArc(x,y,width,height, startAngle*16, spanAngle*16);
}
