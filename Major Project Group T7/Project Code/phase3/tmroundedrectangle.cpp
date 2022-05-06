#include "tmroundedrectangle.h"

int TMRoundedRectangle::getX() const
{
    return x;
}

void TMRoundedRectangle::setX(int value)
{
    x = value;
}

int TMRoundedRectangle::getY() const
{
    return y;
}

void TMRoundedRectangle::setY(int value)
{
    y = value;
}

int TMRoundedRectangle::getWidth() const
{
    return width;
}

void TMRoundedRectangle::setWidth(int value)
{
    width = value;
}

int TMRoundedRectangle::getHeight() const
{
    return height;
}

void TMRoundedRectangle::setHeight(int value)
{
    height = value;
}

QString TMRoundedRectangle::getBorderColor() const
{
    return borderColor;
}

void TMRoundedRectangle::setBorderColor(const QString &value)
{
    borderColor = value;
}

QString TMRoundedRectangle::getFillColor() const
{
    return fillColor;
}

void TMRoundedRectangle::setFillColor(const QString &value)
{
    fillColor = value;
}

bool TMRoundedRectangle::getIsFilled() const
{
    return isFilled;
}

void TMRoundedRectangle::setIsFilled(bool value)
{
    isFilled = value;
}

int TMRoundedRectangle::getXRadius() const
{
    return xRadius;
}

void TMRoundedRectangle::setXRadius(int value)
{
    xRadius = value;
}

int TMRoundedRectangle::getYRadius() const
{
    return yRadius;
}

void TMRoundedRectangle::setYRadius(int value)
{
    yRadius = value;
}

TMRoundedRectangle::TMRoundedRectangle()
{

}
void TMRoundedRectangle::draw(QPainter *event)
{
    QPainter *painter=event;
    painter->setPen(borderColor);
    if(isFilled)painter->setBrush(QColor(fillColor));
    else painter->setBrush(Qt::white);
    painter->drawRoundedRect(QRect(x,y,width,height),xRadius,yRadius);
}
