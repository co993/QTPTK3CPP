#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();

    void on_btCicloid_clicked();

    void on_btnHuygens_clicked();

    void on_btnHypo_clicked();

    void on_btn_futurecave_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double sca1e);
    void on_SpinInterval_valueChanged(double interval);
    void on_SpinCount_valueChanged(double count);

    void on_btnBackground_clicked();

    void on_btnLinecolors_clicked();

private:
    void update_ui();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
