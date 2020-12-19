#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
#include <math.h>


RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0, 0, 255),
    mPen(Qt::white),
    mShape(Astroid)
{
    mPen.setWidth(2);

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
    mScale=90;
    mintervalLength =2* M_PI;
    mStepCount=700;

  case Cycloid:
     mScale=10;
     mintervalLength= 4* M_PI;
     mStepCount=128;
    break;


    case HuygensCycloid:
     mScale=12;
     mintervalLength =4 * M_PI;
     mStepCount=256;
        break;

    case HypoCycloid:
    mScale=40;
    mintervalLength=2* M_PI;
    mStepCount=256;


        break;
    case Circle:
     mScale=128;
     mintervalLength =2* M_PI;
     mStepCount=256;
        break;

      default:
        break;
    case Line:
        mScale=100;
        mintervalLength =2;
        mStepCount=128;

    case ellipe:
        mScale=75;
        mintervalLength =2*M_PI;
        mStepCount=256;

    case Waterlily:
        mScale=10;
        mintervalLength =12*M_PI;
        mStepCount=512;

    case StarFish:
        mScale=25;
        mintervalLength =6*M_PI;
        mStepCount=256;
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
    case Circle:
return compute_circle(t);

    case Line:
        return compute_Line(t);
    case ellipe:
        return compute_ellipe(t);
    case Waterlily:
        return compute_Waterlily(t);
    case StarFish:
        return compute_StarFish(t);
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

QPointF RenderArea::compute_circle(float t){
    Q_UNUSED(t);
    //TBD:
    /*
     * x=fx(t)
     * y=fx(t)
     */
   float  cos_t =cos (t);
   float sin_t =sin (t);
   float x=cos_t;
   float y=sin_t;
   return QPointF(x,y);
                // 7*(3*cos(t)-cos(3*t)),
                //7*(3*sin(t)+cos(3*t)ကတော့estesကိုင်ထားတဲ့စာရွက်ပုံစံမျိုးရလိမ့်မယ်+ထားတာမို့ရှေ့နောက်ချိန်းလို့ရတယ်
                // 7*(3*cos(t)-cos(3*t)),
                //7*(3*sin(t)+sin(3*t))ဆိုရင်လက်ကိုင်ပဝါစကိုလေးဖက်လေးလံကနေစွဲထားတဲ့ပုံစံ
                //        7*(3*cos(t)-cos(3*t)),
               // 7*(3*cos(t)+cos(3*t))ဆိုရင်Sစောင်းစောင်းလေး
                //  7*(3*cos(t)+cos(3*t)),
                //7*(3*sin(t)-cos(3*t))ဆိုရင်မှန်ဘီးလူး(ပုံတော့သိပ်မကျဘူး)

}
QPointF RenderArea::compute_Line(float t){
Q_UNUSED(t);
return QPointF(1-t,1-t);

}
QPointF RenderArea::compute_ellipe(float t){
    Q_UNUSED(t);
    float a=2;
    float b=1.1;
    return QPointF(a*cos(t),b*sin(t)
                   );
}
QPointF RenderArea::compute_Waterlily(float t){
    Q_UNUSED(t);
    float num1=11;
    float num2=6;
    return QPointF(num1*cos(t)-num2*cos(num1/num2*t),num1*sin(t)-num2*sin(num1/num2*t));
    //num1=11;
    //num2=6;

    //အပေါ်ကဒီအမှတ်ကိုဆွဲရင်tကိုမြောက်တဲ့11/6ကိုfloating point ဖြစ်ဖို့လိုတယ်ဒါမှသာမျဉ်းကြောင်းတွေတွေများများထွက်မှာမဟုတ်ရင်မျဉ်းကြောင်းတစ်ကြောင်းတည်းထွက်ပြီးစက်ဝိုင်းဖြစ်သွားလိမ့်မယ်
    //ဒီအမှတ်
    //num1=11;
    //num2=6;ကို
    //stepcount=88.0နဲ့ဆွဲကြည့်ရန်
    //51.၀နဲ့ဆွဲရင် ကြာလုံး(အဲ့လိုဘဲနာမည်ပေးလိုက်တော့မယ်)
    //num1=8;
    //num2=12;
    //အပေါ်ကဒီအမှတ်ကိုဆွဲမယ်ဆိုရင်တော့ခြံဝန်းထဲကဘေးတိုက်အသည်းလေးပေါ့
    //num1=15;
    //num2=4;
    //ဒီအမှတ်ကတော့အလယ်ကနေရာလွတ်လေးကိုပိုကျယ်စေတယ်ပြောရရင်အလယ်အပေါက်အကျယ်ကြီးနဲ့ကြာလုံးကြီးပေါ့
    //မှတ်ချက်(၁)num1=15;
    //num2=4;
    //ထားပြီးဆွဲမယ်ဆိုရင်intervalLengthကိုတိုးဖို့လိုသေးတယ်နော်
    //scaleကတော့၁၀ဆိုအတော်ဘဲ
    //မှတ်ချက်(၂)num1နဲ့num2နေရာမှာရှိမယ့်ဂဏန်းတိုင်းကိုfloating point ဖြစ်စေဖို့တော့လိုတယ်


}
QPointF RenderArea::compute_StarFish(float t){
    Q_UNUSED(t);
 float R=5;
   float r=3;
    float d=5;
    return QPointF(
    (R-r)*cos(t)+d*cos(t*(R-r)/r),
    (R-r)*sin(t)-d*sin(t*(R-r)/r)

                );
}

void  RenderArea::paintEvent (QPaintEvent *event)
{
    Q_UNUSED(event);
 QPainter painter(this);

 painter.setRenderHint( QPainter::Antialiasing, true);


  painter.setBrush(mBackgroundColor);
   painter.setPen(mPen);
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
QPointF point=compute(mintervalLength);
QPoint pixel;

pixel.setX(point.x() *mScale+center.x());
pixel.setY(point.y() *mScale+center.y());

painter.drawLine(pixel, prevPixel);
prevPixel=pixel;
}
