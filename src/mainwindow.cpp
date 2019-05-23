#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xmlparser.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->doThisShitButton, &QPushButton::released, this, &MainWindow::doThisShit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doThisShit() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/test", tr(""));
    AbstractCalculator *abcr = AbstractCalculator::getConstructorByPath(filePath);
    abcr->write(QFileDialog::getSaveFileName(this, tr("Save File"), "/home/test", tr("")),
               abcr->parse(filePath))

}
