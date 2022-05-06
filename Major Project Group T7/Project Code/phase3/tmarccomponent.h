#ifndef TMARCCOMPONENT_H
#define TMARCCOMPONENT_H
#include <QString>
#include <DrawableComponent.h>
class TMArcComponent:public DrawableComponent
{
    int startAngle;
    int spanAngle;
    QString color;
    int width;
    int x;
    int y;
    int height;
public:
    TMArcComponent();
    int getStartAngle() const;
    void setStartAngle(int value);
    int getSpanAngle() const;
    void setSpanAngle(int value);
    QString getColor() const;
    void setColor(const QString &value);
    int getWidth() const;
    void setWidth(int value);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    virtual void draw(QPainter *event);
    int getHeight() const;
    void setHeight(int value);
};

#endif // TMARCCOMPONENT_H
