#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{
public:
    Line();
    ~Line();

    void draw(QPainter &painter);
};

#endif // LINE_H
