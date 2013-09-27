#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPixmap tPixmap(*ui->rLabel->pixmap());
    QSize size;
    QRect rc;
    int w, h, x, y;
    x=tPixmap.width();
    y=tPixmap.height();
    size=tPixmap.size();
    rc=ui->rLabel->geometry();
    w=rc.width();
    h=rc.height();
    rc.setWidth(h);
    rc.setHeight(w);
    QPixmap rotatePixmap(size*2);
    QPainter p(&rotatePixmap);
    p.translate(rotatePixmap.size().width()/2,rotatePixmap.size().height()/2);
    p.rotate(90);
    p.translate(-rotatePixmap.size().width()/2, -rotatePixmap.size().height()/2);
    p.drawPixmap(y,x, tPixmap);
    p.end();
    tPixmap=rotatePixmap.copy(0, 2*y-x, y, x);
    ui->rLabel->setGeometry(rc);
    ui->rLabel->setPixmap(tPixmap);
}
