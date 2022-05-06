#ifndef TMVIEW_H
#define TMVIEW_H
#include <QList>
#include <DrawableComponent.h>
#include<QPainter>
class TMView
{
private:
    QList <DrawableComponent *> list;
    QList <QString> componentNameList;
public:
    void add(DrawableComponent *);
    void draw(QPainter *);
    QList<DrawableComponent *> getComponentList();
    QString lastAddedComponentName();
    int processClick(int x,int y,QPainter *event);
   QList<QString> update();
   void addComponentName(DrawableComponent *);
   void clear();
   void deleteComponent(int index);

};

#endif // TMVIEW_H
