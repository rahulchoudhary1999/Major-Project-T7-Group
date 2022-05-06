#include "tmimagecomponent.h"

int TMImageComponent::getX() const
{
    return x;
}

void TMImageComponent::setX(int value)
{
    x = value;
}

int TMImageComponent::getY() const
{
    return y;
}

void TMImageComponent::setY(int value)
{
    y = value;
}

int TMImageComponent::getWidth() const
{
    return width;
}

void TMImageComponent::setWidth(int value)
{
    width = value;
}

int TMImageComponent::getHeight() const
{
    return height;
}

void TMImageComponent::setHeight(int value)
{
    height = value;
}

QString TMImageComponent::getFilePath() const
{
    return filePath;
}

void TMImageComponent::setFilePath(const QString &value)
{
    filePath = value;
}


QString TMImageComponent::toString()
{
    return "Image";
}
TMImageComponent::TMImageComponent()
{

}

void TMImageComponent::draw(QPainter *event)
{
    QPainter *painter=event;
    QRect rect(x,y,width,height);
    QPen pen;
    pen.setColor(Qt::yellow);
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
    painter->drawPixmap(rect,QPixmap(filePath));
}
bool TMImageComponent::isOwnedByYou(int currentX, int currentY)
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
void TMImageComponent::select(QPainter *event)
{
    if(event==NULL)return;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    event->setPen(pen);
    event->setBrush(Qt::red);
    //p.setBrush(Qt::red);
    event->drawRect(QRectF(x,y,10,10));
    event->drawRect(QRectF(x+width,y,10,10));
    event->drawRect(QRectF(x+width,y+height,10,10));
    event->drawRect(QRectF(x,y+height,10,10));
    pen.setStyle(Qt::DotLine);
    event->setPen(pen);
    event->setBrush(Qt::NoBrush);
    event->drawRect(x,y,width,height);
}
