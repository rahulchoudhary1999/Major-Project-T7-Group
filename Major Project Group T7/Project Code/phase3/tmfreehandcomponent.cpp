#include "tmfreehandcomponent.h"

#include <QPainter>
int TMFreeHandComponent::getX1() const
{
    return x1;
}

void TMFreeHandComponent::setX1(int value)
{
    x1 = value;
}

int TMFreeHandComponent::getY1() const
{
    return y1;
}

void TMFreeHandComponent::setY1(int value)
{
    y1 = value;
}

int TMFreeHandComponent::getX2() const
{
    return x2;
}

void TMFreeHandComponent::setX2(int value)
{
    x2 = value;
}

int TMFreeHandComponent::getY2() const
{
    return y2;
}

void TMFreeHandComponent::setY2(int value)
{
    y2 = value;
}

QString TMFreeHandComponent::getColor() const
{
    return color;
}

void TMFreeHandComponent::setColor(const QString &value)
{
    color = value;
}

int TMFreeHandComponent::getWidth() const
{
    return width;
}

void TMFreeHandComponent::setWidth(int value)
{
    width = value;
}

/*TMLineComponent::TMLineComponent(int x1,int y1,int x2,int y2,QString color,int width)
{
    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;
    this->color=color;
    this->width=width;
}*/
QString TMFreeHandComponent::toString()
{
    return "Free hand tool";
}
QString TMFreeHandComponent::getBorderColor() const
{
    return borderColor;
}

void TMFreeHandComponent::setBorderColor(QString value)
{
    borderColor = value;
}

int TMFreeHandComponent::getPenWidth() const
{
    return penWidth;
}

void TMFreeHandComponent::setPenWidth(int value)
{
    penWidth = value;
}

void TMFreeHandComponent::draw(QPainter *event)
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
    painter->drawLine(x1,y1,x2,y2);
}

bool TMFreeHandComponent::isOwnedByYou(int currentX, int currentY)
{
return false;
}
void TMFreeHandComponent::select(QPainter *event)
{

}
