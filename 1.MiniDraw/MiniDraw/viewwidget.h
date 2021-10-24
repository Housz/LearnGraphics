#ifndef ViewWidget_H
#define ViewWidget_H

#include <QWidget>

#include "line.h"

#include <qevent.h>
#include <qpainter.h>
#include <vector>

class ViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViewWidget(QWidget *parent = nullptr);
    ~ViewWidget();

private:
    bool _drawStatus;
    QPoint startPoint;
    QPoint endPoint;
    Shape::Type _type;
    Shape* shape;
    std::vector<Shape*> shapeList;

public:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    void paintEvent(QPaintEvent*);

signals:
public slots:
    void setLine();
    void setRect();

};

#endif // ViewWidget_H
