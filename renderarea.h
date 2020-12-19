#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public  QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint () const Q_DECL_OVERRIDE;
    QSize sizeHint () const Q_DECL_OVERRIDE;

    enum Shapes { Astroid, Cycloid, HuygensCycloid, HypoCycloid,Circle,Line,ellipe,Waterlily,StarFish};
    void setBackgroundColor (QColor color){mBackgroundColor=color;}//setter of BackgroundColor
    QColor backgroundColor ()const {return mBackgroundColor;}//getter of of BackgroundColor
    void setShapeColor(QColor color){mPen.setColor(color);}
   QColor  shapecolor()const{return mPen.color();}

    void setShape (Shapes shape){mShape=shape; on_shape_changed();}//setter of Shape
    Shapes shape () const {return mShape;}//getter of Shape
    void setScale (float scale){mScale=scale; repaint();}//setter of Scale
    float scale()const {return mScale;}//getter of Scale
    void setIntervalLength(float interval){ mintervalLength=interval; repaint();}//setter of intervalLength
    float interval()const {return mintervalLength;}//getter of intervalLength
    void setStepCount(double count) { mStepCount=count; repaint();}//setter of StepCount
   double count()const {return mStepCount;}//getter of StepCount


protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:
private:
    void on_shape_changed();
    QPointF compute (float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens_cycloid(float t);
    QPointF compute_hypo_cycloid(float t);
    QPointF compute_circle(float t);
    QPointF compute_Line(float t);
    QPointF compute_ellipe(float t);
    QPointF compute_Waterlily(float t);
    QPointF compute_StarFish(float t);
private:
    QColor mBackgroundColor;
    Shapes mShape;
    QPen mPen;


float mintervalLength;
float mScale;
int mStepCount;



};

#endif // RENDERAREA_H
