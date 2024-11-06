#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ui_dialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Ui::Dialog *ui;
    QString getSelectedValue() const;
private:
    QString selectedValue;
public slots:
    void on_pushButton_clicked();
private slots:
    void on_pushButton_2_clicked();
};

#endif // DIALOG_H
