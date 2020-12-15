#include "mainwindow.h"
#include "ui_mainwindow.h"


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


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Astroid);
    this->ui->renderarea->repaint();
}




void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderarea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderarea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderarea->setShape(RenderArea::HypoCycloid);
    this->ui->renderarea->repaint();
}



void MainWindow::on_btCicloid_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Cycloid);
    this->ui->renderarea->repaint();
}

void MainWindow::on_btn_futurecave_clicked()
{
    this->ui->renderarea->setShape(RenderArea::FutureCurves);
    this->ui->renderarea->repaint();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderarea->setShape(RenderArea::Line);
    this->ui->renderarea->repaint();
}
