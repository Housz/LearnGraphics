#include "line.h"

Line::Line()
{

}

Line::~Line()
{

}

void Line::draw(QPainter &painter)
{
    painter.drawLine(start, end);
}
