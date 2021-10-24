#ifndef SHAPE_H
#define SHAPE_H

#include <QtGui>

class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual void draw(QPainter &paint) = 0;

    void setStart(QPoint s);
    void setEnd(QPoint e);

public:
    enum Type
    {
        kLine = 1,
    };

protected:
    QPoint start;
    QPoint end;
};

#endif // SHAPE_H
