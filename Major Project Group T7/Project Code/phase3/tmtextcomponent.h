#ifndef TMTEXTCOMPONENT_H
#define TMTEXTCOMPONENT_H
#include <DrawableComponent.h>
#include<QString>
class TMTextComponent:public DrawableComponent
{
    QString text;
    QString font;
    int size;
    int positionInX;
    int positionInY;
    QString color;

public:
    TMTextComponent();
    QString getText() const;
    void setText(const QString &value);
    QString getFont() const;
    void setFont(const QString &value);
    int getSize() const;
    void setSize(int value);
    int getPositionInX() const;
    void setPositionInX(int value);
    int getPositionInY() const;
    void setPositionInY(int value);
    QString getColor() const;
    void setColor(const QString &value);
    virtual void draw(QPainter *event) override;
};

#endif // TMTEXTCOMPONENT_H
