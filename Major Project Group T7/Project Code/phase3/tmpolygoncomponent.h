#ifndef TMPOLYGONCOMPONENT_H
#define TMPOLYGONCOMPONENT_H

#include<DrawableComponent.h>
class TMPolygonComponent:public DrawableComponent
{
    QPointF *point;
    QString borderColor;
    QString fillColor;
    bool isFilled;
    int width;
    int size;
public:
    TMPolygonComponent();
    QPointF *getPoint() const;
    void setPoint(QPointF *value);
    QString getBorderColor() const;
    void setBorderColor(const QString &value);
    QString getFillColor() const;
    void setFillColor(const QString &value);
    bool getIsFilled() const;
    void setIsFilled(bool value);
    int getWidth() const;
    void setWidth(int value);
    int getSize() const;
    void setSize(int value);
   virtual void draw(QPainter *event);
};

#endif // TMPOLYGONCOMPONENT_H
