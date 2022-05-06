#ifndef TMPOLYLINECOMPONENT_H
#define TMPOLYLINECOMPONENT_H

#include <QPainter>
#include <DrawableComponent.h>
class TMPolylineComponent:public DrawableComponent
{
    QPointF *point;
    QString color;
    int width;
    int size;
public:
    //TMPolylineComponent(QPointF *point,QString color,int width);
   virtual void draw(QPainter *event);

    QPointF *getPoint() const;
    void setPoint(QPointF *value);
    QString getColor() const;
    void setColor(const QString &value);
    int getWidth() const;
    void setWidth(int value);
    int getSize() const;
    void setSize(int value);
};

#endif // TMPOLYLINECOMPONENT_H
