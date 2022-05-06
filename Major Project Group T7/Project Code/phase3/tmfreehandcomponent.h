#ifndef TMFREEHANDCOMPONENT_H
#define TMFREEHANDCOMPONENT_H
#include <DrawableComponent.h>
#include <QtMath>
class TMFreeHandComponent:public DrawableComponent
{
    int x1;
    int y1;
    int x2;
    int y2;
    QString borderColor;
    int penWidth;
    QString color;
    int width;
public:
    /*TMLineComponent(int x1,int y1,int x2,int y2,QString color,int width);*/

    // DrawableComponent interface
public:
    virtual void draw(QPainter *event)override;
    virtual QString toString() override;
    virtual bool isOwnedByYou(int currentX, int currentY) override;
    virtual void select(QPainter *event) override;
    int getX1() const;
    void setX1(int value);
    int getY1() const;
    void setY1(int value);
    int getX2() const;
    void setX2(int value);
    int getY2() const;
    void setY2(int value);
    QString getColor() const;
    void setColor(const QString &value);
    int getWidth() const;
    void setWidth(int value);
    QString getBorderColor() const;
    void setBorderColor(QString value);
    int getPenWidth() const;
    void setPenWidth(int value);
};

#endif // TMFREEHANDCOMPONENT_H
