#ifndef OTHERS_H
#define OTHERS_H

#include <QWidget>

namespace Ui {
class Others;
}

class Others : public QWidget
{
    Q_OBJECT

public:
    explicit Others(QWidget *parent = nullptr);
    ~Others();

signals:
    void LogOut();

private slots:

    void on_pushButton_5_clicked();

private:
    Ui::Others *ui;
};

#endif // OTHERS_H
