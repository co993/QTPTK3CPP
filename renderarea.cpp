#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0, 0, 255),
    mShapeColor (255, 150, 255),
    mShape(Astroid)
{
    on_shape_changed();
}
QSize RenderArea:: minimumSizeHint () const
{

    return QSize(100, 100);
}
QSize RenderArea:: sizeHint () const
{
    return QSize(400, 200);
}
void RenderArea::on_shape_changed (){
    switch(mShape){
    case Astroid:
    mScale=40;
    mintervalLength =2* M_PI;
    mStepCount=256;

  case Cycloid:
    break;


    case HuygensCycloid:

        break;
    case HypoCycloid:



        break;
    case FutureCurves:

        break;
      default:
        break;
    }
}
QPointF RenderArea::compute(float t){
    switch(mShape){
    case Astroid:
return compute_astroid(t);


    break;
   case Cycloid:
return compute_cycloid(t);
      break;
    case HuygensCycloid:
return compute_huygens_cycloid(t);
        break;
    case HypoCycloid:
  return compute_hypo_cycloid(t);
        break;
    case FutureCurves:
return compute_future_curves(t);
        break;
      default:
        break;
    }
}
QPointF RenderArea::compute_astroid(float t){
 Q_UNUSED(t);
 float cos_t =cos (t);
 float sin_t =sin (t);
 float x=2 * cos_t* cos_t* cos_t;//pow (cos_t,3);
 float y=2*  sin_t* sin_t* sin_t;//pow (sin_t,3);
 return QPointF (x,y);
}
QPointF RenderArea::compute_cycloid(float t){
    Q_UNUSED(t);
 //TBD
}
QPointF RenderArea::compute_huygens_cycloid(float t){
    Q_UNUSED(t);
 //TDB
}
QPointF RenderArea::compute_hypo_cycloid(float t){
    Q_UNUSED(t);
//TBD
}

QPointF RenderArea::compute_future_curves(float t){
    Q_UNUSED(t);
    //TBD:
}
void  RenderArea::paintEvent (QPaintEvent *event)
{
    Q_UNUSED(event);
 QPainter painter(this);

 painter.setRenderHint( QPainter::Antialiasing, true);


  painter.setBrush(mBackgroundColor);
   painter.setPen(mShapeColor);
   painter.drawRect(this->rect());
   QPoint center=this->rect().center();
 //draw area

  float step=mintervalLength/mStepCount;
for(float t=0;t<mintervalLength;t+=step){
   QPointF point=compute(t);
   QPoint pixel;
   pixel.setX(point.x() *mScale+center.x());
   pixel.setY(point.y() *mScale+center.y());
   painter.drawPoint(pixel);

}
}
