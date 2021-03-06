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
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                   "/home/test", tr("*.xml *.txt"));
    QString savePath = QFileDialog::getSaveFileName(this, tr("Save File"), "/home/test",
                                                    tr("*.xml *.txt"));

    AbstractCalculator *abcr = AbstractCalculator::getConstructorByPath(filePath);
    AbstractCalculator *save = AbstractCalculator::getConstructorByPath(savePath);

    QVector<int> result = abcr->parse(filePath);
    save->write(savePath, result);


}
