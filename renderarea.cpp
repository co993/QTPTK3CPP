#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
this->setStyleSheet ("background-color:blue;");
}
QSize RenderArea:: minimumSizeHint () const
{

    return QSize(100, 100);
}
QSize RenderArea:: sizeHint () const
{
    return QSize(400, 200);
}
void  RenderArea::paintEvent (QPaintEvent *event)
{
 QPainter painter(this);
 painter.setBrush(QColor (0, 0, 255));
 painter.setRenderHint( QPainter::Antialiasing, true);
 painter.drawRect(this->rect());
}
