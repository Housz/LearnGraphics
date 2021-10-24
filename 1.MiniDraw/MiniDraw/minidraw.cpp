#include "minidraw.h"
#include "ui_minidraw.h"

MiniDraw::MiniDraw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MiniDraw)
{
    ui->setupUi(this);

    _viewWidget = new ViewWidget();
    Creat_Action();
    Creat_ToolBar();
    Creat_Menu();

    setCentralWidget(_viewWidget);
}

MiniDraw::~MiniDraw()
{
    delete ui;
}

void MiniDraw::Creat_Action()
{
    Action_About = new QAction(tr("&About"), this);
    connect(Action_About, &QAction::triggered, this, &MiniDraw::AboutBox);

    Action_Line = new QAction(tr("&Line"), this);
    connect(Action_Line, SIGNAL(triggered()), _viewWidget, SLOT(setLine()));

    Action_Rect = new QAction(tr("&Rect"), this);
    connect(Action_Rect, &QAction::triggered, _viewWidget, &ViewWidget::setRect);
}

void MiniDraw::Creat_ToolBar()
{
    pToolBar = addToolBar(tr("&Main"));
//    pToolBar->addAction(Action_About);
//    pToolBar->addAction(Action_Line);
//    pToolBar->addAction(Action_Rect);
}

void MiniDraw::Creat_Menu()
{
    pMenu = menuBar()->addMenu(tr("&Figure Tool"));
    pMenu->addAction(Action_About);
    pMenu->addAction(Action_Line);
    pMenu->addAction(Action_Rect);
}

void MiniDraw::AboutBox()
{
    QMessageBox::about(this, tr("About"), tr("MiniDraw"));
}
