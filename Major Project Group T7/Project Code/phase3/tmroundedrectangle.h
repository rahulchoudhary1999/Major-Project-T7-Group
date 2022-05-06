#ifndef TMROUNDEDRECTANGLE_H
#define TMROUNDEDRECTANGLE_H
#include <DrawableComponent.h>

class TMRoundedRectangle:public DrawableComponent
{
    int x;
    int y;
    int width;
    int height;
    QString borderColor;
    QString fillColor;
    bool isFilled;
    int xRadius;
    int yRadius;
public:
    TMRoundedRectangle();
    void draw(QPainter *event) override;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
    QString getBorderColor() const;
    void setBorderColor(const QString &value);
    QString getFillColor() const;
    void setFillColor(const QString &value);
    bool getIsFilled() const;
    void setIsFilled(bool value);
    int getXRadius() const;
    void setXRadius(int value);
    int getYRadius() const;
    void setYRadius(int value);
};

#endif // TMROUNDEDRECTANGLE_H
