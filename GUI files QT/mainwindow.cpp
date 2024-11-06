#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Machine.h"
#include "Memory.h"
#include <QFileDialog>
#include<QMessageBox>
#include "dialog.h"

machine* M = new machine();
QString start = "0A";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Dialog dialog;
    dialog.setWindowTitle("Starting Point");
    dialog.setModal(1);
    dialog.exec();
    if(dialog.getSelectedValue() != "invalid")
    {
        start = dialog.getSelectedValue();
        M->MainCPU()->setProgramCounter(stoi(start.toStdString(), nullptr, 16));
        M->SetCnt(stoi(start.toStdString(), nullptr, 16));
    }

    for (int i = 0; i < 256; ++i) {
        ui->textBrowser_2->setText(ui->textBrowser_2->toPlainText() +  QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainMemory().getCell(i)) + '\n');
    }

    for (int i = 0; i < 16; ++i) {
        ui->textBrowser_4->setText(ui->textBrowser_4->toPlainText() + QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainCPU()->MainRegister().getCell(i)) + '\n');
    }

    ui->label_8->setText("Program counter: " + QString::number(M->MainCPU()->programCounter()));
    ui->label_9->setText("Output : " + QString::fromStdString(M->MainCPU()->MainRegister().getCell(0)));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    if(M->MainMemory().getCell(M->MainCPU()->programCounter()) != "00")
    {
        QMessageBox::warning(this,"","Please reset machine first");
        return;
    }
    QString filter = "Text File (*.txt)";
    QString fname = QFileDialog::getOpenFileName(this, "Open a file", "C://",filter);
    if(M->LoadProgrameFile(fname.toStdString()))
    {
        QMessageBox::information(this,"Status","Operation Successfull");
        ui->textBrowser_2->setText("");
        for (int i = 0; i < 256; ++i) {
            ui->textBrowser_2->setText(ui->textBrowser_2->toPlainText() +  QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainMemory().getCell(i)) + '\n');
        }
    }
    else
    {
        QMessageBox::warning(this,"Status","Operation UnSuccessfull");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(M->MainMemory().getCell(stoi(start.toStdString(), nullptr, 16)) == "00")
    {
        QMessageBox::warning(this,"","No Memory Values");
        return;
    }
    if(M->MainMemory().getCell(M->GetLastCell()-2) != "C0" )
    {
        QMessageBox::warning(this,"","No Halt Code");
        return;
    }
    else
    {
        M->operate();
        ui->label_8->setText("Program counter: " + QString::number(M->MainCPU()->programCounter()));
        ui->label_9->setText("Output : " + QString::fromStdString(M->MainCPU()->MainRegister().getCell(0)));
        ui->textBrowser_4->setText("");
        for (int i = 0; i < 16; ++i) {
            ui->textBrowser_4->setText(ui->textBrowser_4->toPlainText() + QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainCPU()->MainRegister().getCell(i)) + '\n');
        }
        ui->textBrowser_2->setText("");
        for (int i = 0; i < 256; ++i) {
            ui->textBrowser_2->setText(ui->textBrowser_2->toPlainText() +  QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainMemory().getCell(i)) + '\n');
        }
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    QString text = ui->lineEdit->text();
    string strTxt = text.toStdString();
    if(M->MainMemory().getCell(254) != "00")
    {
        QMessageBox::warning(this,"","Memory Filled");
    }
    else if(!M->StoreOperation(strTxt))
        QMessageBox::warning(this,"","Invalid Operation");
    else
    {
        ui->lineEdit->clear();
        ui->textBrowser_2->setText("");
        for (int i = 0; i < 256; ++i) {
            ui->textBrowser_2->setText(ui->textBrowser_2->toPlainText() +  QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainMemory().getCell(i)) + '\n');
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    delete M;
    M = new machine();
    start = "0A";
    Dialog dialog;
    dialog.setWindowTitle("Starting Point");
    dialog.setModal(1);
    dialog.exec();
    if(dialog.getSelectedValue() != "invalid")
    {
        start = dialog.getSelectedValue();
        M->MainCPU()->setProgramCounter(stoi(start.toStdString(), nullptr, 16));
        M->SetCnt(stoi(start.toStdString(), nullptr, 16));
    }
    ui->label_8->setText("Program counter: " + QString::number(M->MainCPU()->programCounter()));
    ui->label_9->setText("Output : " + QString::fromStdString(M->MainCPU()->MainRegister().getCell(0)));
    ui->textBrowser_2->setText("");
    for (int i = 0; i < 256; ++i) {
        ui->textBrowser_2->setText(ui->textBrowser_2->toPlainText() +  QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainMemory().getCell(i)) + '\n');
    }
    ui->textBrowser_4->setText("");
    for (int i = 0; i < 16; ++i) {
        ui->textBrowser_4->setText(ui->textBrowser_4->toPlainText() + QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainCPU()->MainRegister().getCell(i)) + '\n');
    }
}

bool flag = true;

void MainWindow::on_pushButton_5_clicked()
{

    if(M->MainMemory().getCell(stoi(start.toStdString(), nullptr, 16)) == "00")
    {
        QMessageBox::warning(this,"","No Memory Values");
        return;
    }

    if(M->MainMemory().getCell(M->GetLastCell()-2) != "C0" )
    {
        QMessageBox::warning(this,"","No Halt Code");
        return;
    }
    M->nextStep();
    if(M->MainCPU()->IsHalted())
    {
        QMessageBox::information(this,"","Program is halted.");
        if(flag)
        {
            ui->label_8->setText("Program counter: " + QString::number(M->MainCPU()->programCounter()));
            flag = false;
        }
        return;
    }
    ui->label_8->setText("Program counter: " + QString::number(M->MainCPU()->programCounter()));
    ui->label_9->setText("Output : " + QString::fromStdString(M->MainCPU()->MainRegister().getCell(0)));
    ui->textBrowser_4->setText("");
    ui->textBrowser_2->setText("");
    for (int i = 0; i < 16; ++i) {
        ui->textBrowser_4->setText(ui->textBrowser_4->toPlainText() + QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainCPU()->MainRegister().getCell(i)) + '\n');
    }
    for (int i = 0; i < 256; ++i) {
        ui->textBrowser_2->setText(ui->textBrowser_2->toPlainText() +  QString::number(i, 16).rightJustified(2, '0').toUpper() + "\t |  " +QString::fromStdString(M->MainMemory().getCell(i)) + '\n');
    }
}

