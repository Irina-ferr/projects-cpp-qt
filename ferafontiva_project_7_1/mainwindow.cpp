#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{  setWindowTitle("Calculator");
    // создание в
    lineEdit1 = new QLineEdit(this);
    lineEdit2 = new QLineEdit(this);
    plusLabel = new QLabel("+", this);
    calculateButton = new QPushButton("=", this);
    resultLabel = new QLabel("Результат: ", this);

    // ввод и плюс
    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(lineEdit1);
    inputLayout->addWidget(plusLabel);
    inputLayout->addWidget(lineEdit2);

    // основной верт
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(calculateButton);
    mainLayout->addWidget(resultLabel);

    // центральный
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // подключение кнопки
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculateSum);
}

MainWindow::~MainWindow()
{
}

void MainWindow::calculateSum()
{
    // ввод в число
    bool ok1, ok2;
    double num1 = lineEdit1->text().toDouble(&ok1);
    double num2 = lineEdit2->text().toDouble(&ok2);

    //корректность
    if (ok1 && ok2) {
        double sum = num1 + num2;
        resultLabel->setText( QString::number(sum));
    } else {
        resultLabel->setText("Ошибка ввода");
    }
}
