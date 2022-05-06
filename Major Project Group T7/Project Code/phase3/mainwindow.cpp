#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <QFont>
#include <QtMath>
#include <QMessageBox>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QJsonArray>
QListWidgetItem *item1;
bool deleteComponentFlag=false;
bool createLineFlag=false;
bool resizingComponent=false;
bool insertImage=false;
int penWidth;
QString colorOfBorder="";
QColor *borderColor;
bool redColorFlag=false;
bool blueColorFlag=false;
bool blackColorFlag=false;
bool greenColorFlag=false;
bool greyColorFlag=false;
bool lightBlueColorFlag=false;
bool orangeColorFlag=false;
bool voiletColorFlag=false;
bool controlKeyIsPressed=false;
bool clearComponentFlag=false;
QList<DrawableComponent *> listForSelection;
QList<DrawableComponent *> groupList;
int posx1=0;
int posx2=0;
int posX=0;
int posY=0;
int i=0;
int j=0;
int t=0;
int u=0;
int groupSelect=0;
int row=0;
int column=0;
int select=-1;
int previousX;
int previousY;
int posX2;
int posY2;
int X1;
int Y1;
int MainWindow::oldX=-1;
int MainWindow::oldY=-1;
int MainWindow::currentX=0;
int MainWindow::currentY=0;
int var=0;
TMView tmView;
DrawableComponent *d;
QModelIndex index;
QList<DrawableComponent *> list;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Thinking machines");
    this->ui->mainFrame->setVisible(false);
    ui->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    ui->listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QFont font;
    font.setBold(true);
   // ui->viewToolBox->setFont(font);
    model=new QStringListModel(this);
    //this->setStyleSheet("background-color:black");
    ui->horizontalSlider->setRange(0,10);
    QIcon freeHandIcon(QPixmap(":/images/pencil_icon.png"));
    this->ui->freeHandTool->setIcon(freeHandIcon);
    this->ui->freeHandTool->setToolTip(QString("Free Hand Tool"));
    this->ui->freeHandTool->setIconSize(QSize(48,48));
    QIcon lineIcon(QPixmap(":/images/line_icon.png"));
    this->ui->goToLineInfoPanel->setIcon(lineIcon);
    this->ui->goToLineInfoPanel->setIconSize(QSize(48,48));
    this->ui->goToLineInfoPanel->setToolTip("Line");
    QIcon circleIcon(QPixmap(":/images/circle_icon1.png"));
    this->ui->goToEllipseInfoPanel->setIcon(circleIcon);
    this->ui->goToEllipseInfoPanel->setToolTip("Circle");
    this->ui->goToEllipseInfoPanel->setIconSize(QSize(48,48));
    QIcon rectangleIcon(QPixmap(":/images/rectangle_icon.png"));
    this->ui->goToRectangleInfoPanel->setIcon(rectangleIcon);
    this->ui->goToRectangleInfoPanel->setIconSize(QSize(48,48));
    this->ui->goToRectangleInfoPanel->setToolTip("Rectangle");
    QIcon pickIcon(QPixmap(":/images/pick_tool_icon.png"));
    this->ui->pickTool->setIcon(pickIcon);
    this->ui->pickTool->setIconSize(QSize(48,48));
    this->ui->pickTool->setToolTip("Pick tool");
    QIcon deleteIcon(QPixmap(":/images/delete_icon.png"));
    this->ui->deleteButton->setIcon(deleteIcon);
    this->ui->deleteButton->setIconSize(QSize(48,48));
    this->ui->deleteButton->setToolTip("Delete");
    QIcon groupIcon(QPixmap(":/images/group_icon.png"));
    this->ui->groupButton->setIcon(groupIcon);
    this->ui->groupButton->setIconSize(QSize(48,48));
    this->ui->groupButton->setToolTip("Group");
    QIcon ungroupIcon(QPixmap(":/images/ungroup_icon.png"));
    this->ui->ungroupButton->setIcon(ungroupIcon);
    this->ui->ungroupButton->setIconSize(QSize(48,48));
    this->ui->ungroupButton->setToolTip("Ungroup");
    QIcon saveIcon(QPixmap(":/images/save.png"));
    this->ui->saveButton->setIcon(saveIcon);
    this->ui->saveButton->setToolTip("Save");
    this->ui->saveButton->setIconSize(QSize(48,48));
    QIcon openIcon(QPixmap(":/images/open.png"));
    this->ui->openButton->setIcon(openIcon);
    this->ui->openButton->setIconSize(QSize(48,48));
    this->ui->openButton->setToolTip("Open");
    QIcon resizeIcon(QPixmap(":/images/resize_icon.png"));
    this->ui->resizePushButton->setIcon(resizeIcon);
    this->ui->resizePushButton->setIconSize(QSize(48,48));
    this->ui->resizePushButton->setToolTip("Resize components");
    QIcon addNewPageIcon(":/images/add_new_icon.png");
    this->ui->addNewPage->setIcon(addNewPageIcon);
    this->ui->addNewPage->setIconSize(QSize(48,48));
    this->ui->addNewPage->setToolTip("Add new page");
    QIcon insertImageIcon(":/images/insert_image_icon.png");
    this->ui->insertImage->setIcon(insertImageIcon);
    this->ui->insertImage->setIconSize(QSize(48,48));
    this->ui->insertImage->setToolTip("Insert image");
    QIcon createLineIcon(":/images/page-icon.png");
    this->ui->createLine->setIcon(createLineIcon);
    this->ui->createLine->setIconSize(QSize(48,48));
    this->ui->createLine->setToolTip("Insert page");
    QIcon clearCanvasIcon(QPixmap(":/images/clear_icon.png"));
    this->ui->clearCanvas->setIcon(clearCanvasIcon);
    this->ui->clearCanvas->setToolTip("Clear canvas");
    this->ui->clearCanvas->setIconSize(QSize(48,48));
    QIcon chemistryBookIcon(QPixmap(":/images/chemistry_icon.png"));
    this->ui->chemistryBoard->setIcon(chemistryBookIcon);
    this->ui->chemistryBoard->setIconSize(QSize(48,48));
    this->ui->chemistryBoard->setToolTip("Chemistry tools");
}
int radius;
int p=0;
void MainWindow::paintEvent(QPaintEvent *event)
{
    QRect mainWindowRect(0,0,this->width(),this->height());
    QColor color(173, 216, 230);
    QPainter painter(this);
    painter.setBrush(color);
    painter.drawRect(mainWindowRect);
   /* QRect boardBorder(200+30,40,1492,970);
    QPainter boardBorderPainter(this);
    boardBorderPainter.drawPixmap(boardBorder,QPixmap(":/images/board2.png"));
    */
    QRect boundingRect(200+30,44,1492-30,961);
    QPen boundingPen;
    boundingPen.setColor(Qt::black);
    boundingPen.setWidth(2);
    QPainter p(this);
    p.eraseRect(QRect(200+30,44,1492-30,961));
    p.setBrush(Qt::white);
    p.setPen(boundingPen);
    p.drawRect(boundingRect);
    p.setClipRect(boundingRect,Qt::ReplaceClip);
    if(createLineFlag==true)
    {
       // QPainter linePainter(this);
        QRect lineCanvasRect(200+30,44,1492-30,961);
        p.setBrush(QColor(244,244,244));
        p.drawRect(lineCanvasRect);
        int w=0;
        while(w<961)
        {
            w=w+43;
            //p.setPen(QColor(47,79,79));
            p.setPen(QColor(138,43,226));
            p.drawLine(230,w,1692,w);
        }
    }
    p.setBrush(Qt::NoBrush);
    tmView.draw(&p);

if(clearComponentFlag!=true)
{
    if(i==5)
    {
        select=tmView.processClick(currentX,currentY,&p);
    if(controlKeyIsPressed==false)
    {
        listForSelection.clear();
        int y=0;
        while(y<listForSelection.size())
        {
            listForSelection.removeAt(y);
            y++;
        }
      if(select==(-1))
      {
          return;
      }
      DrawableComponent *d=tmView.getComponentList()[select];
      listForSelection.push_back(d);
      }
    else
    {
      if(select==(-1))return;
      DrawableComponent *d=tmView.getComponentList()[select];
      listForSelection.push_back(d);
      int i=0;
      while(i<listForSelection.size())
      {
          listForSelection[i]->select(&p);
          i++;
      }
      qDebug()<<i;
      }

    if(groupSelect==1)
    {
     int e=0;
     while(e<groupList.size())
     {
         groupList[e]->select(&p);
         e++;
     }
    }
    this->ui->listWidget->setCurrentRow(select);
    this->ui->listWidget->currentItem();
     j=0;
     u=1;
    }

    if(i==1)
    {
        QPen pen;
        if(colorOfBorder.compare("")==0)
        {
            pen.setColor(Qt::black);
        }
        else
        {
            pen.setColor(QColor(colorOfBorder));
        }
       pen.setWidth(this->ui->horizontalSlider->value());
       p.setPen(pen);
        p.drawLine(oldX,oldY,currentX,currentY);
    }
    if(i==2)
    {
        QPen pen;
        if(colorOfBorder.compare("")==0)
        {
            pen.setColor(Qt::black);
        }
        else
        {
            pen.setColor(QColor(colorOfBorder));
        }
       pen.setWidth(this->ui->horizontalSlider->value());
       p.setPen(pen);
        p.drawLine(oldX,oldY,currentX,currentY);
    }
    if(i==3)
    {
         QPen pen;
        /*if(borderColor!=NULL)
        {
        pen.setColor(*borderColor);
        }
        else
        {
        pen.setColor(QColor(Qt::black));
        }
        pen.setWidth(this->ui->horizontalSlider->value());
        p.setPen(pen);
        */
        if(colorOfBorder.compare("")==0)
        {
            pen.setColor(Qt::black);
        }
        else
        {
            pen.setColor(QColor(colorOfBorder));
        }
        pen.setWidth(this->ui->horizontalSlider->value());
        p.setPen(pen);
        p.drawRect(oldX,oldY,currentX-oldX,currentY-oldY);
    }
    if(i==4)
    {
        QPen pen;
        if(colorOfBorder.compare("")==0)
        {
            pen.setColor(Qt::black);
        }
        else
        {
            pen.setColor(QColor(colorOfBorder));
        }
       pen.setWidth(this->ui->horizontalSlider->value());
       p.setPen(pen);
        radius= qSqrt(qPow((currentX-oldX),2)+qPow((currentY-oldY),2));
        p.drawEllipse(QPointF(oldX,oldY),radius,radius);
    }
    if(t==1)
    {
      tmView.getComponentList()[row]->select(&p);
      t=0;
    }
    if(redColorFlag==true)
        {
            borderColor=new QColor(255,0,0);
            redColorFlag=false;
        }
        if(blueColorFlag==true)
        {
            borderColor=new QColor(85, 0, 255);
            blueColorFlag=false;
        }
        if(blackColorFlag==true)
        {
            borderColor=new QColor(0,0,0);
            blackColorFlag=false;
        }
        if(greenColorFlag==true)
        {
            borderColor=new QColor(0,255,0);
            greenColorFlag=false;
        }
        if(greyColorFlag==true)
        {
            borderColor=new QColor(169,169,169);
            greyColorFlag=false;
        }
        if(lightBlueColorFlag==true)
        {
            borderColor=new QColor(85,255,255);
            lightBlueColorFlag=false;
        }
        if(orangeColorFlag==true)
        {
            borderColor=new QColor(255,170,0);
            orangeColorFlag=false;
        }
        if(voiletColorFlag==true)
        {
            borderColor=new QColor(170,0,255);
            voiletColorFlag=false;
        }
}
clearComponentFlag=false;
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
 oldX=e->x();
 oldY=e->y();
 if(i==5)
 {
     if(controlKeyIsPressed==true)
     {
         select=tmView.processClick(oldX,oldY,NULL);
         if(select==(-1))return;
         groupList.push_back(tmView.getComponentList()[select]);
     }

 }
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    currentX=e->x();
    currentY=e->y();
    if(i==1)
    {
     TMFreeHandComponent *tmFreeHandComponent=new TMFreeHandComponent;
     tmFreeHandComponent->setX1(oldX);
     tmFreeHandComponent->setY1(oldY);
     tmFreeHandComponent->setX2(currentX);
     tmFreeHandComponent->setY2(currentY);
     tmFreeHandComponent->setBorderColor(colorOfBorder);
     tmFreeHandComponent->setPenWidth(this->ui->horizontalSlider->value());
     tmView.add(tmFreeHandComponent);
     QWidget::update();
     oldX=currentX;
     oldY=currentY;
   }
    if(i==2)
   {
       QWidget::update();
   }
    if(i==3)
    {
        //TMRectangleComponent *tmRectangleComponent=new TMRectangleComponent;
        //tmRectangleComponent->setX(oldX);
        //tmRectangleComponent->setY(oldY);
        //tmRectangleComponent->setWidth(currentX-oldX);
        //tmRectangleComponent->setHeight(currentY-oldY);
        QWidget::update();
    }
    if(i==4)
    {
        QWidget::update();
    }
    if(i==5)
       {
            int diffX;
            int diffY;
            diffX=currentX-oldX;
            diffY=currentY-oldY;
            oldX=currentX;
            oldY=currentY;

            if(groupSelect==0)
            {
           if(select==(-1))return;
           DrawableComponent *d=tmView.getComponentList()[select];
           if(d->toString().compare("Rectangle")==0)
          {
             TMRectangleComponent *t=(TMRectangleComponent *)d;
             t->setX(t->getX()+(diffX));
             t->setY(t->getY()+(diffY));
           }
           if(d->toString().compare("Circle")==0)
           {
               TMEllipseComponent *t=(TMEllipseComponent *)d;
               //t->setX(currentX+posX);
               //t->setY(currentY+posY);
               t->setX(t->getX()+diffX);
               t->setY(t->getY()+diffY);
           }
           if(d->toString().compare("Line")==0)
           {
               TMLineComponent *t=(TMLineComponent *)d;
               t->setX1(t->getX1()+diffX);
               t->setY1(t->getY1()+diffY);
               t->setX2(t->getX2()+diffX);
               t->setY2(t->getY2()+diffY);
           }
           if(d->toString().compare("Image")==0)
          {
             TMImageComponent *t=(TMImageComponent *)d;
             t->setX(t->getX()+(diffX));
             t->setY(t->getY()+(diffY));
           }
            }
           else
           {
                if(select==(-1))return;
                DrawableComponent *d=tmView.getComponentList()[select];
                if(d->toString().compare("Rectangle")==0)
               {
                  TMRectangleComponent *t=(TMRectangleComponent *)d;
                  t->setX(t->getX()+(diffX));
                  t->setY(t->getY()+(diffY));
                }
                //add kiya
                if(d->toString().compare("Circle")==0)
                {
                    TMEllipseComponent *t=(TMEllipseComponent *)d;
                    t->setX(t->getX()+diffX);
                    t->setY(t->getY()+diffY);
                }
                if(d->toString().compare("Line")==0)
                {
                    TMLineComponent *t=(TMLineComponent *)d;
                    t->setX1(t->getX1()+diffX);
                    t->setY1(t->getY1()+diffY);
                    t->setX2(t->getX2()+diffX);
                    t->setY2(t->getY2()+diffY);
                }
                if(d->toString().compare("Image")==0)
               {
                  TMImageComponent *t=(TMImageComponent *)d;
                  t->setX(t->getX()+(diffX));
                  t->setY(t->getY()+(diffY));
                }
                //yaha tak
               DrawableComponent  *m;
               int k=0;
               while(k<groupList.size())
               {
                   m=groupList.at(k);
                   if(d==m)
                   {
                       k++;
                       continue;
                   }
                   if(m->toString().compare("Rectangle")==0)
                  {
                     TMRectangleComponent *t=(TMRectangleComponent *)m;
                     t->setX(t->getX()+(diffX));
                     t->setY(t->getY()+(diffY));
                   }
                   if(m->toString().compare("Circle")==0)
                   {
                       TMEllipseComponent *t=(TMEllipseComponent *)m;
                       t->setX(t->getX()+diffX);
                       t->setY(t->getY()+diffY);
                   }
                   if(m->toString().compare("Line")==0)
                   {
                       TMLineComponent *t=(TMLineComponent *)m;
                       t->setX1(t->getX1()+diffX);
                       t->setY1(t->getY1()+diffY);
                       t->setX2(t->getX2()+diffX);
                       t->setY2(t->getY2()+diffY);
                   }
                   if(m->toString().compare("Image")==0)
                  {
                     TMImageComponent *t=(TMImageComponent *)m;
                     t->setX(t->getX()+(diffX));
                     t->setY(t->getY()+(diffY));
                   }
                   k++;
               }
               QWidget::update();
           }
        QWidget::update();
    }

    if(resizingComponent==true)
    {
        if(select==(-1))return;
        int diffX=currentX-oldX;
        int diffY=currentY-oldY;
        DrawableComponent *m=tmView.getComponentList()[select];
        if(m->toString().compare("Rectangle")==0)
       {
          TMRectangleComponent *t=(TMRectangleComponent *)m;
          if(oldX==t->getX() && oldY==t->getY())
          {
              qDebug()<<"Clicked1";
          t->setX(t->getX()+diffX);
          t->setY(t->getY()+diffY);
          t->setWidth(t->getWidth()-diffX);
          t->setHeight(t->getHeight()-diffY);
          }
          if(oldX==t->getX()+t->getWidth() && t->getY()==oldY)
          {
              t->setY(t->getY()+diffY);
              t->setWidth(t->getWidth()+diffX);
              t->setHeight(t->getHeight()-diffY);
          }
          if(oldX==t->getX() && oldY==t->getY()+t->getHeight())
          {
              qDebug()<<"Clicked";
              t->setX(t->getX()+diffX);
              t->setWidth(t->getWidth()-diffX);
              t->setHeight(t->getHeight()+diffY);
          }
          if(oldX==t->getX()+t->getWidth()&&oldY==t->getY()+t->getHeight())
          {
              t->setWidth(t->getWidth()+diffX);
              t->setHeight(t->getHeight()+diffY);
          }
        }
        if(m->toString().compare("Circle")==0)
        {
            TMEllipseComponent *t=(TMEllipseComponent *)m;
            t->setWidth(t->getWidth()-diffY);
            t->setHeight(t->getWidth());
            /*if(oldX==t->getX() && oldY==(t->getY()-t->getWidth()))
            {
                t->setWidth(t->getY()-diffY);
                t->setHeight(t->getWidth());

            }*/
        }
        if(m->toString().compare("Line")==0)
        {
            TMLineComponent *t=(TMLineComponent *)m;
            if(t->getX1()==oldX && t->getY1()==oldY)
            {
                t->setX1(t->getX1()+diffX);
                t->setY1(t->getY1()+diffY);
            }
            if(t->getX2()==oldX && t->getY2()==oldY)
            {
                t->setX2(t->getX2()+diffX);
                t->setY2(t->getY2()+diffY);
            }
        }
        if(m->toString().compare("Image")==0)
       {
          TMImageComponent *t=(TMImageComponent *)m;
          if(oldX==t->getX() || oldY==t->getY())
          {
              qDebug()<<"Clicked1";
          t->setX(t->getX()+diffX);
          t->setY(t->getY()+diffY);
          t->setWidth(t->getWidth()-diffX);
          t->setHeight(t->getHeight()-diffY);
          }
         /* if(oldX==t->getX()+t->getWidth() && t->getY()==oldY)
          {
              t->setY(t->getY()+diffY);
              t->setWidth(t->getWidth()+diffX);
              t->setHeight(t->getHeight()-diffY);
          }
          if(oldX==t->getX() && oldY==t->getY()+t->getHeight())
          {
              qDebug()<<"Clicked";
              t->setX(t->getX()+diffX);
              t->setWidth(t->getWidth()-diffX);
              t->setHeight(t->getHeight()+diffY);
          }
          if(oldX==t->getX()+t->getWidth()&&oldY==t->getY()+t->getHeight())
          {
              t->setWidth(t->getWidth()+diffX);
              t->setHeight(t->getHeight()+diffY);
          }*/
        }
        oldX=currentX;
        oldY=currentY;
        QWidget::update();
    }
    }


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{

    if(i==1)
    {
        QString name=tmView.lastAddedComponentName();
        this->ui->listWidget->insertItem(0,name);
    }
    if(i==2)
    {
        currentX=e->x();
        currentY=e->y();
        TMLineComponent *tmLineComponent=new TMLineComponent;
        tmLineComponent->setX1(oldX);
        tmLineComponent->setY1(oldY);
        tmLineComponent->setX2(currentX);
        tmLineComponent->setY2(currentY);
        tmLineComponent->setBorderColor(colorOfBorder);
        tmLineComponent->setPenWidth(this->ui->horizontalSlider->value());
        tmView.add(tmLineComponent);
        QString name=tmView.lastAddedComponentName();
        this->ui->listWidget->insertItem(0,name);
        QWidget::update();
    }
    if(i==3)
    {
        TMRectangleComponent *tmRectangleComponent=new TMRectangleComponent;
        tmRectangleComponent->setX(oldX);
        tmRectangleComponent->setY(oldY);
        //tmRectangleComponent->setIsFilled(true);
        tmRectangleComponent->setWidth(currentX-oldX);
        tmRectangleComponent->setHeight(currentY-oldY);
        tmRectangleComponent->setBorderColor(colorOfBorder);
        tmRectangleComponent->setPenWidth(this->ui->horizontalSlider->value());
        //tmRectangleComponent->setFillColor(fillColor);
        tmView.add(tmRectangleComponent);
        QString name=tmView.lastAddedComponentName();
        this->ui->listWidget->insertItem(0,name);
        //this->ui->listWidget->clear();
        //this->ui->listWidget->addItems(tmView.update());
        QWidget::update();
    }
    if(i==4)
    {
        TMEllipseComponent *tmEllipseComponent=new TMEllipseComponent;
        tmEllipseComponent->setX(oldX);
        tmEllipseComponent->setY(oldY);
        tmEllipseComponent->setWidth(radius);
        tmEllipseComponent->setHeight(radius);
        tmEllipseComponent->setBorderColor(colorOfBorder);
        tmEllipseComponent->setPenWidth(this->ui->horizontalSlider->value());
        tmView.add(tmEllipseComponent);
        QString name=tmView.lastAddedComponentName();
        this->ui->listWidget->insertItem(0,name);
        QWidget::update();
    }

    if(i==5)
       {

           currentX=e->x();
           currentY=e->y();
           QWidget::update();
         if(u==1)
         {

           u=0;
         }

    }

}

void MainWindow::on_freeHandTool_clicked()
{
    i=1;
}

void MainWindow::on_goToLineInfoPanel_clicked()
{
    i=2;
}

void MainWindow::on_goToRectangleInfoPanel_clicked()
{
    i=3;
}

void MainWindow::on_goToEllipseInfoPanel_clicked()
{
    i=4;
}

void MainWindow::on_pickTool_clicked()
{
i=5;
resizingComponent=false;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
   item1=item;
  i=0;
  row=this->ui->listWidget->row(item);
  t=1;
  QWidget::update();
  item->setFlags(item->flags() | Qt::ItemIsEditable);

}

void MainWindow::on_groupButton_clicked()
{
 groupSelect=1;
 i=5;
}

void MainWindow::on_ungroupButton_clicked()
{
    groupSelect=0;
   groupList.clear();
}

void MainWindow::on_saveButton_clicked()
{
    //QString jsonFilter="JSON(*.json)";
    QString jsonFilter="CHY(*.chy)";
    //QString fileName=QFileDialog::getSaveFileName(this,"Open the file","/","JSON(*.json)",&jsonFilter,QFileDialog::DontUseNativeDialog);
    QString fileName=QFileDialog::getSaveFileName(this,"Open the file","/","CHY(*.chy)",&jsonFilter,QFileDialog::DontUseNativeDialog);
    QFile output(fileName);
    if(!output.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::warning(this,"Warning","Cannot open File"+output.errorString());
    }
    QJsonDocument document;
    QList<DrawableComponent *> list;
    DrawableComponent *d;
    QByteArray data_json;
    QJsonArray listArray;
    list=tmView.getComponentList();
    int i=0;
    while(i<list.size())
    {
        d=list[i];
        QJsonObject obj;
        if(d->toString().compare("Rectangle")==0)
        {
           TMRectangleComponent *t=(TMRectangleComponent *)d;
           obj.insert("x",QJsonValue::fromVariant(t->getX()));
           obj.insert("y",QJsonValue::fromVariant(t->getY()));
           obj.insert("width",QJsonValue::fromVariant(t->getWidth()));
           obj.insert("height",QJsonValue::fromVariant(t->getHeight()));
           obj.insert("borderColor",QJsonValue::fromVariant(t->getBorderColor()));
           obj.insert("penWidth",QJsonValue::fromVariant(t->getPenWidth()));
           obj.insert("componentName",QJsonValue::fromVariant(t->toString()));
           listArray.push_back(obj);
        }
        if(d->toString().compare("Image")==0)
        {
           TMImageComponent *t=(TMImageComponent *)d;
           obj.insert("x",QJsonValue::fromVariant(t->getX()));
           obj.insert("y",QJsonValue::fromVariant(t->getY()));
           obj.insert("width",QJsonValue::fromVariant(t->getWidth()));
           obj.insert("height",QJsonValue::fromVariant(t->getHeight()));
           obj.insert("filepath",QJsonValue::fromVariant(t->getFilePath()));
           obj.insert("componentName",QJsonValue::fromVariant(t->toString()));
           listArray.push_back(obj);
        }
        if(d->toString().compare("Circle")==0)
        {
            TMEllipseComponent *t=(TMEllipseComponent *)d;
            obj.insert("x",QJsonValue::fromVariant(t->getX()));
            obj.insert("y",QJsonValue::fromVariant(t->getY()));
            obj.insert("width",QJsonValue::fromVariant(t->getWidth()));
            obj.insert("height",QJsonValue::fromVariant(t->getHeight()));
            obj.insert("borderColor",QJsonValue::fromVariant(t->getBorderColor()));
            obj.insert("penWidth",QJsonValue::fromVariant(t->getPenWidth()));
            obj.insert("componentName",QJsonValue::fromVariant(t->toString()));
            listArray.push_back(obj);
        }
        if(d->toString().compare("Line")==0)
        {
            TMLineComponent *t=(TMLineComponent *)d;
            obj.insert("x1",QJsonValue::fromVariant(t->getX1()));
            obj.insert("y1",QJsonValue::fromVariant(t->getY1()));
            obj.insert("x2",QJsonValue::fromVariant(t->getX2()));
            obj.insert("y2",QJsonValue::fromVariant(t->getY2()));
            obj.insert("borderColor",QJsonValue::fromVariant(t->getBorderColor()));
            obj.insert("penWidth",QJsonValue::fromVariant(t->getPenWidth()));
            obj.insert("componentName",QJsonValue::fromVariant(t->toString()));
            listArray.push_back(obj);
        }
        if(d->toString().compare("Free hand tool")==0)
        {
            TMFreeHandComponent *t=(TMFreeHandComponent *)d;
            obj.insert("x1",QJsonValue::fromVariant(t->getX1()));
            obj.insert("y1",QJsonValue::fromVariant(t->getY1()));
            obj.insert("x2",QJsonValue::fromVariant(t->getX2()));
            obj.insert("y2",QJsonValue::fromVariant(t->getY2()));
            obj.insert("borderColor",QJsonValue::fromVariant(t->getBorderColor()));
            obj.insert("penWidth",QJsonValue::fromVariant(t->getPenWidth()));
            obj.insert("componentName",QJsonValue::fromVariant(t->toString()));
            listArray.push_back(obj);
        }
        i++;

    }
    document.setArray(listArray);
    data_json=document.toJson();
    output.write(data_json);
    output.close();
}

void MainWindow::on_openButton_clicked()
{
    QString jsonFilter="CHY(*.chy)";
    QString filename=QFileDialog::getOpenFileName(this,"Open the File","/",jsonFilter,&jsonFilter,QFileDialog::DontUseNativeDialog);
    QFile input(filename);
    if(!input.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::warning(this,"warning","Cannot open file"+input.errorString());
    }

    QByteArray data_json=input.readAll();
    input.close();
    QJsonDocument document=document.fromJson(data_json);
    QJsonArray jsonArray=document.array();
    for(QJsonValue value:jsonArray)
    {
        QJsonObject obj(value.toObject());
        if(obj.value(QString("componentName")).toString().compare("Rectangle")==0)
       {
            TMRectangleComponent *t=new TMRectangleComponent;
            t->setX(obj["x"].toInt());
            t->setY(obj["y"].toInt());
            t->setWidth(obj["width"].toInt());
            t->setHeight(obj["height"].toInt());
            t->setBorderColor(obj["borderColor"].toString());
            t->setPenWidth(obj["penWidth"].toInt());
            tmView.add(t);
        }
        if(obj.value(QString("componentName")).toString().compare("Image")==0)
       {
            TMImageComponent *t=new TMImageComponent;
            t->setX(obj["x"].toInt());
            t->setY(obj["y"].toInt());
            t->setWidth(obj["width"].toInt());
            t->setHeight(obj["height"].toInt());
            t->setFilePath(obj["filepath"].toString());
            tmView.add(t);
        }
        if(obj.value(QString("componentName")).toString().compare("Circle")==0)
       {
            TMEllipseComponent *t=new TMEllipseComponent;
            t->setX(obj["x"].toInt());
            t->setY(obj["y"].toInt());
            t->setWidth(obj["width"].toInt());
            t->setHeight(obj["height"].toInt());
            t->setBorderColor(obj["borderColor"].toString());
            t->setPenWidth(obj["penWidth"].toInt());
            tmView.add(t);
        }
        if(obj.value(QString("componentName")).toString().compare("Free hand tool")==0)
       {
            TMFreeHandComponent *t=new TMFreeHandComponent;
            t->setX1(obj["x1"].toInt());
            t->setY1(obj["y1"].toInt());
            t->setX2(obj["x2"].toInt());
            t->setY2(obj["y2"].toInt());
            t->setBorderColor(obj["borderColor"].toString());
            t->setPenWidth(obj["penWidth"].toInt());
            tmView.add(t);
           // QWidget::update();
        }
        if(obj.value(QString("componentName")).toString().compare("Line")==0)
       {
            TMLineComponent *t=new TMLineComponent;
            t->setX1(obj["x1"].toInt());
            t->setY1(obj["y1"].toInt());
            t->setX2(obj["x2"].toInt());
            t->setY2(obj["y2"].toInt());
            t->setBorderColor(obj["borderColor"].toString());
            t->setPenWidth(obj["penWidth"].toInt());
            tmView.add(t);
        }
    }
    QWidget::update();

    for(DrawableComponent *d:tmView.getComponentList())
    {
        this->ui->listWidget->insertItem(0,d->toString());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Control)
    {
        controlKeyIsPressed=true;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Control)
    {
        controlKeyIsPressed=false;
    }
}

void MainWindow::on_redColorButton_clicked()
{
    //redColorFlag=true;
    colorOfBorder=QString("red");
    //QWidget::update();
}

void MainWindow::on_blueColorButton_clicked()
{
    //blueColorFlag=true;
    colorOfBorder=QString("blue");
    //QWidget::update();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    penWidth=value;
}

void MainWindow::on_blackColorButton_clicked()
{
    //blackColorFlag=true;
    //QWidget::update();
    colorOfBorder=QString(QColor(0,0,0).name());
}

void MainWindow::on_greenColorButton_clicked()
{
    //greenColorFlag=true;
    //QWidget::update();
    colorOfBorder=QString(QColor(0,255,0).name());
}

void MainWindow::on_greyColorButton_clicked()
{
    //greyColorFlag=true;
    //QWidget::update();
    colorOfBorder=QString(QColor(169,169,169).name());
}

void MainWindow::on_lightBlueColorButton_clicked()
{
   // lightBlueColorFlag=true;
    //QWidget::update();
    colorOfBorder=QString(QColor(85,255,255).name());
}

void MainWindow::on_orangeColorButton_clicked()
{
    //orangeColorFlag=true;
    //QWidget::update();
    colorOfBorder=QString(QColor(255,170,0).name());
}


void MainWindow::on_voiletColorButton_clicked()
{
    //voiletColorFlag=true;
    //QWidget::update();
    colorOfBorder=QString(QColor(170,0,255).name());
}

void MainWindow::on_resizePushButton_clicked()
{
    resizingComponent=true;
    i=0;
}

void MainWindow::on_insertImage_clicked()
{
    insertImage=true;
QString imgFilter="PNG(*.png)";
QString fileName=QFileDialog::getOpenFileName(this,"Insert image","/",imgFilter,&imgFilter,QFileDialog::DontUseNativeDialog);
if(fileName=="")return;
TMImageComponent *d=new TMImageComponent;
d->setX(440);
d->setY(200);
d->setWidth(371);
d->setHeight(341);
d->setFilePath(fileName);
tmView.add(d);
QWidget::update();
this->ui->listWidget->insertItem(0,d->toString());

}

void MainWindow::on_createLine_clicked()
{
  if(createLineFlag==false)
  {
      createLineFlag=true;
  }
  else
  {
      createLineFlag=false;
  }
  QWidget::update();
}

void MainWindow::on_deleteButton_clicked()
{
   if(select==(-1))return;
   //deleteComponentFlag=true;
   tmView.deleteComponent(select);
   QWidget::update();
   //qDebug()<<row;
    delete (this->ui->listWidget->takeItem(select));
}

void MainWindow::on_clearCanvas_clicked()
{
    clearComponentFlag=true;
    tmView.clear();
    QWidget::update();
    this->ui->listWidget->clear();
}

void MainWindow::on_chemistryBoard_clicked()
{
this->ui->mainFrame->setVisible(true);
}

void MainWindow::on_cancelButton_clicked()
{
    this->ui->mainFrame->setVisible(false);
}

void MainWindow::on_mole_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/mole1.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_atomicStructure_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/atomic1.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_bodyCentered_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/bodyCentered_solid.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_faceCentered_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/faceCentered_solid.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_periodicTable_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/periodic_table.jpg");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_periodicFormula_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/periodic1_imp_formula.jpg");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_methane_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/methane.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_methylAlcohol_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/methylAlcohol.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_formaldehyde_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/formaldehyde.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_methylAmine_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/Methylamine.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_diethylEther_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/diethylEther.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_bohrModel_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/bohr_model.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_hexagonal_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/hexagonal_closed.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}

void MainWindow::on_acetone_clicked()
{
    TMImageComponent *d=new TMImageComponent;
    d->setX(440);
    d->setY(200);
    d->setWidth(371);
    d->setHeight(341);
    d->setFilePath(":/images/acetone.png");
    tmView.add(d);
    QWidget::update();
    this->ui->listWidget->insertItem(0,d->toString());
}
