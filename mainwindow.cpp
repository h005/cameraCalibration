#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

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

void MainWindow::on_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Load"),".",
                                                    tr("model Files(*.off *.dae *.obj)"));
    if(fileName == NULL)
        return;

    camcal = new CamCal(fileName);

}
