#include "tmrectanglecomponent.h"

int TMRectangleComponent::getX() const
{
    return x;
}

void TMRectangleComponent::setX(int value)
{
    x = value;
}

int TMRectangleComponent::getY() const
{
    return y;
}

void TMRectangleComponent::setY(int value)
{
    y = value;
}

int TMRectangleComponent::getWidth() const
{
    return width;
}

void TMRectangleComponent::setWidth(int value)
{
    width = value;
}

int TMRectangleComponent::getHeight() const
{
    return height;
}

void TMRectangleComponent::setHeight(int value)
{
    height = value;
}



QString TMRectangleComponent::getFillColor() const
{
    return fillColor;
}

void TMRectangleComponent::setFillColor(const QString &value)
{
    fillColor = value;
}

bool TMRectangleComponent::getIsFilled() const
{
    return isFilled;
}

void TMRectangleComponent::setIsFilled(bool value)
{
    isFilled = value;
}

QString TMRectangleComponent::getBorderColor() const
{
    return borderColor;
}

void TMRectangleComponent::setBorderColor(QString value)
{
    borderColor = value;
}


int TMRectangleComponent::getPenWidth() const
{
    return penWidth;
}

void TMRectangleComponent::setPenWidth(int value)
{
    penWidth = value;
}

TMRectangleComponent::TMRectangleComponent()
{

}
QString TMRectangleComponent::toString()
{
    return "Rectangle";
}
void TMRectangleComponent::draw(QPainter *event)
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
    painter->drawRect(QRect(x,y,width,height));
}
bool TMRectangleComponent::isOwnedByYou(int currentX, int currentY)
{
    int x=this->x;
    int y=this->y;
    int x2=width+this->x;
    int y2=this->y+height;
    if(x<=currentX && x2>=currentX && y<=currentY && y2>=currentY )
    {
       return true;
    }
    return false;
}
void TMRectangleComponent::select(QPainter *event)
{
    if(event==NULL)return;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    event->setPen(pen);
    event->setBrush(Qt::red);
    //p.setBrush(Qt::red);
    event->drawRect(QRectF(x-5,y-5,10,10));
    event->drawRect(QRectF(x+width-5,y-5,10,10));
    event->drawRect(QRectF(x+width-5,y+height-5,10,10));
    event->drawRect(QRectF(x-5,y+height-5,10,10));
}
