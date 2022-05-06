#include "tmellipsecomponent.h"

int TMEllipseComponent::getX() const
{
    return x;
}

void TMEllipseComponent::setX(int value)
{
    x = value;
}

int TMEllipseComponent::getY() const
{
    return y;
}

void TMEllipseComponent::setY(int value)
{
    y = value;
}

int TMEllipseComponent::getWidth() const
{
    return width;
}

void TMEllipseComponent::setWidth(int value)
{
    width = value;
}

int TMEllipseComponent::getHeight() const
{
    return height;
}

void TMEllipseComponent::setHeight(int value)
{
    height = value;
}

QString TMEllipseComponent::getFillColor() const
{
    return fillColor;
}

void TMEllipseComponent::setFillColor(const QString &value)
{
    fillColor = value;
}

bool TMEllipseComponent::getIsFilled() const
{
    return isFilled;
}

void TMEllipseComponent::setIsFilled(bool value)
{
    isFilled = value;
}

QString TMEllipseComponent::getBorderColor() const
{
    return borderColor;
}

void TMEllipseComponent::setBorderColor(QString value)
{
    borderColor = value;
}

int TMEllipseComponent::getPenWidth() const
{
    return penWidth;
}

void TMEllipseComponent::setPenWidth(int value)
{
    penWidth = value;
}

TMEllipseComponent::TMEllipseComponent()
{
    
}
QString TMEllipseComponent::toString()
{
    return "Circle";
}
void TMEllipseComponent::draw(QPainter *event)
{
    QPainter *painter=event;
    QPen pen;
    if(borderColor.compare("")==0)
    {
    pen.setColor(Qt::black);
    }
    else
    {
    pen.setColor(QColor(borderColor));
    }
    pen.setWidth(penWidth);
    painter->setPen(pen);
    painter->drawEllipse(QPointF(x,y),width,height);
}
bool TMEllipseComponent::isOwnedByYou(int currentX, int currentY)
{
    if(qPow(currentX-x,2)+qPow(currentY-y,2)-qPow(width,2)<=0)
    {
        return true;
    }
    return false;
}
void TMEllipseComponent::select(QPainter *event)
{
    if(event==NULL)return;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    event->setPen(pen);
    event->setBrush(Qt::red);
    //p.setBrush(Qt::red);
    event->drawRect(QRectF(x-5,y+width-5,7,7));
    event->drawRect(QRectF(x-width-5,y-5,7,7));
    event->drawRect(QRectF(x-5,y-width-5,7,7));
    event->drawRect(QRectF(x+width-5,y-5,7,7));
}
