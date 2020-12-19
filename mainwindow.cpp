#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderarea->scale());
    this->ui->SpinInterval->setValue(this->ui->renderarea->interval());
    this->ui->SpinCount->setValue(this->ui->renderarea->count());
}
void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Astroid);
    this->ui->renderarea->repaint();
    update_ui();
}




void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderarea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderarea->repaint();
        update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderarea->setShape(RenderArea::HypoCycloid);
    this->ui->renderarea->repaint();
        update_ui();
}



void MainWindow::on_btCicloid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Cycloid);
    this->ui->renderarea->repaint();
    update_ui();
}

void MainWindow::on_btn_circle_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Circle);
    this->ui->renderarea->repaint();
        update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Line);
    this->ui->renderarea->repaint();
        update_ui();

}

void MainWindow::on_spinScale_valueChanged(double sca1e)
{
this->ui->renderarea->setScale(sca1e);
}

void MainWindow::on_SpinInterval_valueChanged(double interval)
{
    this->ui->renderarea->setIntervalLength(interval);
}

void MainWindow::on_SpinCount_valueChanged(double count)
{
    this->ui->renderarea->setStepCount(count);
}

void MainWindow::on_btnBackground_clicked()
{
    QColor color=QColorDialog::getColor(ui->renderarea->backgroundColor(), this,"Selet the Color which you want to paint");
    ui->renderarea->setBackgroundColor(color);
}

void MainWindow::on_btnLinecolors_clicked()
{
    QColor color=QColorDialog::getColor(ui->renderarea->shapecolor(), this,"Selet the Color which you want to paint");
    ui->renderarea->setShapeColor(color);
}

void MainWindow::on_btnellipe_clicked()
{
    this->ui->renderarea->setShape(RenderArea::ellipe);
    ui->renderarea->repaint();
    update_ui();
}



void MainWindow::on_btnWaterLily_clicked()
{
    ui->renderarea->setShape(RenderArea::Waterlily);
    ui->renderarea->repaint();
    update_ui();
}




void MainWindow::on_btnStarFish_clicked()
{
    ui->renderarea->setShape(RenderArea::StarFish);
    ui->renderarea->repaint();
    update_ui();
}
