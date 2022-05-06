#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include <QPainter>
class DrawableComponent
{
public:
    virtual void draw(QPainter *event)=0;
    virtual QString toString()=0;
    virtual bool isOwnedByYou(int currentX,int currentY)=0;
    virtual void select(QPainter *event)=0;
};

#endif // DRAWABLECOMPONENT_H
