#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>


class RenderArea : public  QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint () const Q_DECL_OVERRIDE;
    QSize sizeHint () const Q_DECL_OVERRIDE;

    enum Shapes { Astroid, Cycloid, HuygensCycloid, HypoCycloid,FutureCurves};
    void setBackgroundColor (QColor color){mBackgroundColor=color;}//setter
    QColor backgroundColor ()const {return mBackgroundColor;}//getter
    void setShape (Shapes shape){mShape=shape; on_shape_changed();}//setter
    Shapes shape () const {return mShape;}//getter
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
    QPointF compute_future_curves(float t);
private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    Shapes mShape;


float mintervalLength;
float mScale;
int mStepCount;


};

#endif // RENDERAREA_H
