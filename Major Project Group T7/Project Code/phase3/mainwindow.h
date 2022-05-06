#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPainter>
#include <tmtextcomponent.h>
#include <tmlinecomponent.h>
#include <tmarccomponent.h>
#include <tmpolylinecomponent.h>
#include <tmview.h>
#include <tmrectanglecomponent.h>
#include <tmroundedrectangle.h>
#include <tmellipsecomponent.h>
#include<tmpolygoncomponent.h>
#include <QMouseEvent>
#include <QStringListModel>
#include <tmfreehandcomponent.h>
#include <QListWidgetItem>
#include <QKeyEvent>
#include <tmimagecomponent.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static int currentX;
    static int currentY;
    static int oldX;
    static int oldY;
    int x;
    int y;
    int x2;
    int y2;
    QStringListModel *model;
    QStringList list;
    void mouseMoveEvent(QMouseEvent *e)override;
    void mousePressEvent(QMouseEvent *e)override;
    void mouseReleaseEvent(QMouseEvent *e)override;
    //void mouseDoubleClickEvent(QMouseEvent *e)override;
    void keyPressEvent(QKeyEvent *event)override;
    void keyReleaseEvent(QKeyEvent *event)override;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_goToLineInfoPanel_clicked();
   void on_goToRectangleInfoPanel_clicked();
   void on_goToEllipseInfoPanel_clicked();
   void on_freeHandTool_clicked();
   void on_pickTool_clicked();


   void on_listWidget_itemClicked(QListWidgetItem *item);

   void on_groupButton_clicked();

   void on_ungroupButton_clicked();

   void on_saveButton_clicked();

   void on_openButton_clicked();

   void on_redColorButton_clicked();

   void on_blueColorButton_clicked();

   void on_horizontalSlider_valueChanged(int value);

   void on_blackColorButton_clicked();

   void on_greenColorButton_clicked();

   void on_greyColorButton_clicked();

   void on_lightBlueColorButton_clicked();

   void on_orangeColorButton_clicked();


   void on_voiletColorButton_clicked();

   void on_resizePushButton_clicked();

   void on_insertImage_clicked();

   void on_createLine_clicked();

   void on_deleteButton_clicked();

   void on_clearCanvas_clicked();

   void on_chemistryBoard_clicked();

   void on_cancelButton_clicked();

   void on_mole_clicked();

   void on_atomicStructure_clicked();

   void on_bodyCentered_clicked();

   void on_faceCentered_clicked();

   void on_periodicTable_clicked();

   void on_periodicFormula_clicked();

   void on_methane_clicked();

   void on_methylAlcohol_clicked();

   void on_formaldehyde_clicked();

   void on_methylAmine_clicked();

   void on_diethylEther_clicked();

   void on_bohrModel_clicked();

   void on_hexagonal_clicked();

   void on_acetone_clicked();

private:
    Ui::MainWindow *ui;
    virtual void paintEvent(QPaintEvent *event)override;
};
#endif // MAINWINDOW_H
