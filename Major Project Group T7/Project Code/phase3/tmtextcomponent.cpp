#include "tmtextcomponent.h"

QString TMTextComponent::getText() const
{
    return text;
}

void TMTextComponent::setText(const QString &value)
{
    text = value;
}

QString TMTextComponent::getFont() const
{
    return font;
}

void TMTextComponent::setFont(const QString &value)
{
    font = value;
}

int TMTextComponent::getSize() const
{
    return size;
}

void TMTextComponent::setSize(int value)
{
    size = value;
}

int TMTextComponent::getPositionInX() const
{
    return positionInX;
}

void TMTextComponent::setPositionInX(int value)
{
    positionInX = value;
}

int TMTextComponent::getPositionInY() const
{
    return positionInY;
}

void TMTextComponent::setPositionInY(int value)
{
    positionInY = value;
}

QString TMTextComponent::getColor() const
{
    return color;
}

void TMTextComponent::setColor(const QString &value)
{
    color = value;
}

TMTextComponent::TMTextComponent()
{

}
void TMTextComponent::draw(QPainter *device)
{
QPainter *painter=device;
QPen pen;
pen.setColor(color);
painter->setFont(QFont(font,size,QFont::Bold));
painter->setPen(pen);
painter->drawText(QPoint(positionInX,positionInY),text);
}
