#ifndef MINIDRAW_H
#define MINIDRAW_H

#include <QMainWindow>

#include <viewwidget.h>
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MiniDraw; }
QT_END_NAMESPACE

class MiniDraw : public QMainWindow
{
    Q_OBJECT

public:
    MiniDraw(QWidget *parent = nullptr);
    ~MiniDraw();

    QMenu *pMenu;
    QToolBar *pToolBar;
    QAction* Action_About;
    QAction* Action_Line;
    QAction* Action_Rect;

    void Creat_Menu();
    void Creat_ToolBar();
    void Creat_Action();

    void AboutBox();

private:
    Ui::MiniDraw *ui;
    ViewWidget *_viewWidget;

};
#endif // MINIDRAW_H
