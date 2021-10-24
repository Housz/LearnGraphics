#include "viewwidget.h"

ViewWidget::ViewWidget(QWidget *parent) : QWidget(parent)
{
    _drawStatus = false;
    shape = NULL;
    _type = Shape::kLine;

}

ViewWidget::~ViewWidget()
{

}
void ViewWidget::setLine()
{
    _type = Shape::kLine;
}

void ViewWidget::setRect()
{
//    _type = Shape::kRect;
}

void ViewWidget::mousePressEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->button())
    {
        switch(_type)
        {
            case Shape::kLine:
                shape = new Line();
                break;

//            case Shape::kDefault:
//                break;

//            case Shape::kRect:
//                break;
        }

        if(shape != NULL)
        {
            _drawStatus = true;
            startPoint = endPoint = event->pos();
            shape->setStart(startPoint);
            shape->setEnd(endPoint);
        }
    }

    update();
}

void ViewWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (_drawStatus && shape != NULL)
    {
        endPoint = event->pos();
        shape->setEnd(endPoint);
    }
}

void ViewWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (shape != NULL)
    {
        _drawStatus = false;
        shapeList.push_back(shape);
        shape = NULL;
    }
}

void ViewWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    for (int i = 0; i < shapeList.size()  ; i++ )
    {
        shapeList[i]->draw(painter);
    }

    if (shape != NULL)
    {
        shape->draw(painter);
    }

    update();
}

