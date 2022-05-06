#ifndef TMRECTANGLECOMPONENT_H
#define TMRECTANGLECOMPONENT_H
#include <QtMath>
#include<DrawableComponent.h>
class TMRectangleComponent:public DrawableComponent
{
    int x;
    int y;
    int width;
    int height;
    QString  borderColor;
    QString fillColor;
    bool isFilled;
    int penWidth;
public:
    TMRectangleComponent();
    virtual void draw(QPainter *event)override;
    virtual QString toString() override;
    virtual bool isOwnedByYou(int currentX, int currentY) override;
    virtual void select(QPainter *event) override;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
    QString getFillColor() const;
    void setFillColor(const QString &value);
    bool getIsFilled() const;
    void setIsFilled(bool value);
    QString getBorderColor() const;
    void setBorderColor(QString value);
    int getPenWidth() const;
    void setPenWidth(int value);
};

#endif // TMRECTANGLECOMPONENT_H
