#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QVector>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::showHistogram(QString path) {

    StlData stlDt;
    if(!stlDt.parseData(path)) {
        QMessageBox::critical(0, "Critical", "There is no such path!");
        return;
    }
    stlDt.setHistogram();
    float maxAreasSum = 0;
    for(auto it : *stlDt.getHistogram()) {
        if(it->areasSum_ > maxAreasSum)
            maxAreasSum = it->areasSum_;
    }

    QVector<double> ticks(201);
    for(int i = -100; i <= 100; ++i)
        ticks[i + 100] = i;
    ui->QHistogram->xAxis->setRange(-100, 100);
    ui->QHistogram->xAxis->setLabel("Degrees");
    ui->QHistogram->yAxis->setRange(0, maxAreasSum);
    ui->QHistogram->yAxis->setLabel("Sums");
    QVector<double> areasSum(200);
    for(auto it : *stlDt.getHistogram())
        areasSum[it->corner_ + 100] = it->areasSum_;
     QCPBars *fossil = new QCPBars(ui->QHistogram->xAxis, ui->QHistogram->yAxis);
    fossil->setData(ticks, areasSum);
    ui->QHistogram->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OKButton_clicked()
{
    ui->QHistogram->clearPlottables();
    this->showHistogram(ui->pathEdit->text());
}

void MainWindow::on_bunnyButton_clicked()
{
    ui->QHistogram->clearPlottables();
    this->showHistogram("bunny.stl");
}

void MainWindow::on_boxButton_clicked()
{
    ui->QHistogram->clearPlottables();
    this->showHistogram("box.stl");
}
