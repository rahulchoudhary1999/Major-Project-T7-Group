#ifndef TMIMAGECOMPONENT_H
#define TMIMAGECOMPONENT_H
#include <QtMath>
#include<DrawableComponent.h>
class TMImageComponent:public DrawableComponent
{
    int x;
    int y;
    int width;
    int height;
    QString filePath;
public:
    TMImageComponent();
    virtual void draw(QPainter *event)override;
    virtual QString toString() override;
    virtual bool isOwnedByYou(int currentX, int currentY) override;
    virtual void select(QPainter *event) override;
    QString getFilePath() const;
    void setFilePath(const QString &value);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
};
#endif // TMIMAGECOMPONENT_H
