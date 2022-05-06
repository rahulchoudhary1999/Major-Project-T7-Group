#include "tmlinecomponent.h"
#include <QPainter>
int TMLineComponent::getX1() const
{
    return x1;
}

void TMLineComponent::setX1(int value)
{
    x1 = value;
}

int TMLineComponent::getY1() const
{
    return y1;
}

void TMLineComponent::setY1(int value)
{
    y1 = value;
}

int TMLineComponent::getX2() const
{
    return x2;
}

void TMLineComponent::setX2(int value)
{
    x2 = value;
}

int TMLineComponent::getY2() const
{
    return y2;
}

void TMLineComponent::setY2(int value)
{
    y2 = value;
}

QString TMLineComponent::getColor() const
{
    return color;
}

void TMLineComponent::setColor(const QString &value)
{
    color = value;
}

int TMLineComponent::getWidth() const
{
    return width;
}

void TMLineComponent::setWidth(int value)
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
QString TMLineComponent::toString()
{
    return "Line";
}
QString TMLineComponent::getBorderColor() const
{
    return borderColor;
}

void TMLineComponent::setBorderColor(QString value)
{
    borderColor = value;
}

int TMLineComponent::getPenWidth() const
{
    return penWidth;
}

void TMLineComponent::setPenWidth(int value)
{
    penWidth = value;
}

void TMLineComponent::draw(QPainter *event)
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

bool TMLineComponent::isOwnedByYou(int currentX, int currentY)
{
    int dist1=sqrt(pow(currentX-x1,2)+pow(currentY-y1,2));
        int dist2=sqrt(pow(x2-currentX,2)+pow(y2-currentY,2));
        int dist=dist1+dist2;
        int actual_dist=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        if(dist==actual_dist) return true;
    /*if(qSqrt(qPow((x2-x1),2)+qPow((y2-y1),2))<=(qSqrt(qPow((currentX-x1),2)+qPow((currentY-y1),2))+qSqrt(qPow(currentX-x2,2)+qPow(currentY-y2,2))))
    {
      return true;
    }*/
    return false;
}
void TMLineComponent::select(QPainter *event)
{
    if(event==NULL)return;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    event->setPen(pen);
    event->setBrush(Qt::red);
    //p.setBrush(Qt::red);
    event->drawRect(QRectF(x1-5,y1-5,10,10));
    event->drawRect(QRectF(x2-5,y2-5,10,10));

}
