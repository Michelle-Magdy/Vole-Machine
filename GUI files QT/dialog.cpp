#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include <QApplication>
using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), selectedValue("invalid")
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QApplication::setStyle("windowsvista");

}

Dialog::~Dialog()
{
    delete ui;
}

bool Isvalid(string line)
{
    if(line.length() > 2 or line.length() == 0) return false;
    for (size_t i = 0; i < line.length(); ++i){
        line[i] = toupper(line[i]);
        QChar ch = line[i];
        if (!ch.isDigit() && (ch < 'A' || ch > 'F'))
            return false;
    }
    return stoi(line,nullptr,16) % 2 == 0 && stoi(line,nullptr,16) < 254;
}

QString Dialog::getSelectedValue() const {
    return selectedValue;  // Return the stored result
}

void Dialog::on_pushButton_clicked()
{
    QString input = ui->lineEdit->text();
    if(!Isvalid(input.toStdString()))
    {
        QMessageBox::warning(this,"Status","Please enter a valid hexadecimal number");
    }
    else
    {
        QMessageBox::information(this,"Status","Operation Successfull");
        selectedValue = input;
        accept();
    }
}


void Dialog::on_pushButton_2_clicked()
{
    accept();
}

