#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>


RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0, 0, 255),
    mShapeColor (255, 150, 0),
    mShape(Astroid)
{
    on_shape_changed();
}
QSize RenderArea:: minimumSizeHint () const
{

    return QSize(400, 400);
}
QSize RenderArea:: sizeHint () const
{
    return QSize(400, 400);
}
void RenderArea::on_shape_changed (){
    switch(mShape){
    case Astroid:
    mScale=40;
    mintervalLength =2* M_PI;
    mStepCount=700;

  case Cycloid:
     mScale=4;
     mintervalLength= 6* M_PI;
     mStepCount=128;
    break;


    case HuygensCycloid:
     mScale=4;
     mintervalLength =4 * M_PI;
     mStepCount=256;
        break;
    case HypoCycloid:
    mScale=15;
    mintervalLength=2* M_PI;
    mStepCount=256;


        break;
    case FutureCurves:
     mScale=4;
     mintervalLength =4* M_PI;
     mStepCount=256;
        break;

      default:
        break;
    case Line:
        mScale=100;
        mintervalLength =1;
        mStepCount=128;
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

    case Line:
        return compute_Line(t);

      default:
        break;
    }
}
QPointF RenderArea::compute_astroid(float t){
 Q_UNUSED(t);
 float cos_t =cos (t);
 float sin_t =sin (t);
 float x=20*pow (cos_t,3);
 float y=20*pow (sin_t,3);
 return QPointF (x,y);
}
QPointF RenderArea::compute_cycloid(float t){
    Q_UNUSED(t);
 return QPointF(
             1.5* (1-cos(t)),//X
             1.5* (t-sin(t))//
             //Xကို+-လုပ်ရင်ဘယ်ညာရွှေ့
             //Yကို+-လုပ်ရင်အပေါအောက်ရွှေ့

             );
}
QPointF RenderArea::compute_huygens_cycloid(float t){
    Q_UNUSED(t);
 return QPointF (
             4 * (3 * cos(t)- cos(3 *t)),
             4 * (3 * sin(t)- sin(3 *t))
            );
}
QPointF RenderArea::compute_hypo_cycloid(float t){
    Q_UNUSED(t);
    return QPointF (
                1.5 * (2*cos(t)+cos(2*t)),
                1.5 * (2*sin(t)-sin(2*t))
                );

}

QPointF RenderArea::compute_future_curves(float t){
    Q_UNUSED(t);
    //TBD:
    /*
     * x=fx(t)
     * y=fx(t)
     */
    return QPointF (
          7*(3*cos(t)+cos(3*t)),
          7*(3*sin(t)-cos(3*t))
                // 7*(3*cos(t)-cos(3*t)),
                //7*(3*sin(t)+cos(3*t)ကတော့estesကိုင်ထားတဲ့စာရွက်ပုံစံမျိုးရလိမ့်မယ်+ထားတာမို့ရှေ့နောက်ချိန်းလို့ရတယ်
                // 7*(3*cos(t)-cos(3*t)),
                //7*(3*sin(t)+sin(3*t))ဆိုရင်လက်ကိုင်ပဝါစကိုလေးဖက်လေးလံကနေစွဲထားတဲ့ပုံစံ
                //        7*(3*cos(t)-cos(3*t)),
               // 7*(3*cos(t)+cos(3*t))ဆိုရင်Sစောင်းစောင်းလေး
                //  7*(3*cos(t)+cos(3*t)),
                //7*(3*sin(t)-cos(3*t))ဆိုရင်မှန်ဘီးလူး(ပုံတော့သိပ်မကျဘူး)
                 );
}
QPointF RenderArea::compute_Line(float t){
Q_UNUSED(t);
return QPointF(1-t,1-t);

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
QPointF prevPoint =compute(0);
QPoint prevPixel;
prevPixel.setX(prevPoint.x() *mScale+center.x());
prevPixel.setY(prevPoint.y() *mScale+center.y());
  float step=mintervalLength/mStepCount;
for(float t=0;t<mintervalLength;t+=step){
   QPointF point=compute(t);
   QPoint pixel;

  pixel.setX(point.x() *mScale+center.x());
  pixel.setY(point.y() *mScale+center.y());

painter.drawLine(pixel, prevPixel);
prevPixel=pixel;
}
}
