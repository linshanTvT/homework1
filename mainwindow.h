#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QMap>
#include <QPushButton>
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString sum;
    QString ans;
    QStack<QString> operands;
    QStack<QString> opcodes;
    QMap<int, QPushButton *> btnNums;
    QString calculation1(bool *ok = NULL)
    {
        double result = 0;
        if (operands.size() == 2 && opcodes.size() > 0) {
            double op1 = operands.front().toDouble();
            operands.pop_front();
            double op2 = operands.front().toDouble();
            operands.pop_front();
            QString op = opcodes.front();
            opcodes.pop_front();
            if (op == "+") {
                result = op1 + op2;
            }
            if (op == "-") {
                result = op1 - op2;
            }
            if (op == "×") {
                result = op1 * op2;
            }
            if (op == "÷") {
                result = op1 / op2;
            }
            operands.push_back(QString::number(result));
        }
        return QString::number(result);
    }

private slots:
    void numclicked();
    void numclicked1();
    void numclicked2();
    void on_pushButton_17_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_deng_clicked();
    virtual void keyPressEvent(QKeyEvent *event);

    void on_pushButton_24_clicked();

private:
    Ui::MainWindow *ui;
    QString calculation();
};
#endif // MAINWINDOW_H
