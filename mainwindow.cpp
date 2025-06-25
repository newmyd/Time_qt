#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <unistd.h>
#include <thread.h>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    thread = new Thread();

    connect(thread, SIGNAL(returnResult(int)), this, SLOT(showTim()));

    thread->start();
}



QString MainWindow::getTime()
{

    QTime qt = QTime::currentTime();

    return QString().sprintf("%02d : %02d : %02d . %02d", qt.hour(), qt.minute(), qt.second(), qt.msec() / 10);
}



void MainWindow::showTim()
{
    ui->nowTime->setText(getTime());
    return ;
}



void MainWindow::on_getTim_clicked()
{
    ui->tim->setText(getTime());

    return ;
}



MainWindow::~MainWindow()
{
    delete ui;
}
