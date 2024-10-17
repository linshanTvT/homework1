#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btnNums = {{Qt::Key_0, ui->num0},
        {Qt::Key_1, ui->num1},
        {Qt::Key_2, ui->num2},
        {Qt::Key_3, ui->num3},
        {Qt::Key_4, ui->num4},
        {Qt::Key_5, ui->num5},
        {Qt::Key_6, ui->num6},
        {Qt::Key_7, ui->num7},
        {Qt::Key_8, ui->num8},
        {Qt::Key_9, ui->num9},
    };
    foreach (auto btn, btnNums)
        connect(btn, SIGNAL(clicked()), this, SLOT(numclicked()));

    connect(ui->cheng, SIGNAL(clicked()), this, SLOT(numclicked1()));
    connect(ui->chu, SIGNAL(clicked()), this, SLOT(numclicked1()));
    connect(ui->jian, SIGNAL(clicked()), this, SLOT(numclicked1()));
    connect(ui->jia, SIGNAL(clicked()), this, SLOT(numclicked1()));
    connect(ui->key1, SIGNAL(clicked()), this, SLOT(numclicked2()));
    connect(ui->key2, SIGNAL(clicked()), this, SLOT(numclicked2()));
    connect(ui->key3, SIGNAL(clicked()), this, SLOT(numclicked2()));
    connect(ui->key4, SIGNAL(clicked()), this, SLOT(numclicked2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::numclicked()
{
    QString str = qobject_cast<QPushButton *>(sender())->text();
    if (str == "0" && sum == "0")
        str = "";
    else if (str != "0" && sum == "0")
        sum = "";
    sum += str;
    ui->line->setText(sum);
}


void MainWindow::on_pushButton_17_clicked()
{
    if (!sum.contains(".")) {
        sum += qobject_cast<QPushButton *>(sender())->text();
    }
    ui->line->setText(sum);
}


void MainWindow::on_pushButton_4_clicked()
{
    sum = sum.left(sum.length() - 1);
    ui->line->setText(sum);
}


void MainWindow::on_pushButton_3_clicked()
{
    sum.clear();
    ans.clear();
    operands.clear();
    opcodes.clear();
    ui->line->setText(sum);
}

void MainWindow::numclicked1()
{
    QString ans = qobject_cast<QPushButton *>(sender())->text();
    qDebug() << ans;
    if (sum != "") {
        operands.push_back(sum);
        sum = "";
        opcodes.push_back(ans);
    }
    if (operands.size() >= 2) {
        QString result = calculation1();
        ui->line->setText(result);
    }
}

void MainWindow::numclicked2()
{
    if (sum != "") {
        double result = sum.toDouble();
        sum = "";
        QString op = qobject_cast<QPushButton *>(sender())->text();
        if (op == "%")
            result /= 100.0;
        else if (op == "1/x")
            result = 1 / result;
        else if (op == "x*2")
            result *= result;
        else if (op == "√")
            result = sqrt(result);
        ui->line->setText(QString::number(result));
    }
}


void MainWindow::on_deng_clicked()
{
    if (sum != "") {
        operands.push_back(sum);
        sum = "";
    }
    QString result = calculation1();
    ui->line->setText(result);
    sum = result;
    operands.clear();
    opcodes.clear();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach (auto btnKey, btnNums.keys() ) {
        if (event->key() == btnKey)
            btnNums[btnKey]->animateClick();
    }
}

void MainWindow::on_pushButton_24_clicked()
{
    int num = sum.toInt();
    int negativeNum = -num;
    sum = QString::number(negativeNum);
    ui->line->setText(sum);
}

