#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "stldata.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void showHistogram(QString path);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_OKButton_clicked();

    void on_bunnyButton_clicked();

    void on_boxButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
