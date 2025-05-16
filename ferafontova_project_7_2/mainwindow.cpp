#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle("Calculator");
    // все кнопки кроме C и =
    for (QPushButton *btn : findChildren<QPushButton*>()) {
        if (btn->text() != "C" && btn->text() != "=") {
            connect(btn, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        }
    }

    connect(ui->pushButton_Delete, &QPushButton::clicked, this, &MainWindow::onClearClicked);
    connect(ui->pushButton_Equals, &QPushButton::clicked, this, &MainWindow::onEqualsClicked);
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::handleReturnPressed);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleButtonClick() {
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QString text = btn->text();

    if (text == "x") text = "*";

    ui->lineEdit->setText(ui->lineEdit->text() + text);
}

void MainWindow::onClearClicked() {
    ui->lineEdit->clear();
}

void MainWindow::onEqualsClicked() {
    QString expr = ui->lineEdit->text().trimmed();
    if (expr.isEmpty()) return;

    double result;
    if (calculate(expr, result)) {
        QString resText = QString::number(result, 'f', 6)
        .replace(QRegularExpression("\\.?0+$"), "");
        ui->lineEdit->setText(resText);
    } else {
        ui->lineEdit->setText("Error");
    }
}

void MainWindow::handleReturnPressed() {
    onEqualsClicked();
}

bool MainWindow::calculate(const QString &expression, double &result) {
    QList<double> numbers;
    QList<QChar> ops;
    int pos = 0;
    int len = expression.length();

    QString numStr;
    if (pos < len && (expression[pos] == '+' || expression[pos] == '-')) {
        numStr += expression[pos++];
    }

    while (pos < len && (expression[pos].isDigit() || expression[pos] == '.')) {
        numStr += expression[pos++];
    }

    bool ok;
    double num = numStr.toDouble(&ok);
    if (!ok) return false;
    numbers.append(num);

    while (pos < len) {
        QChar op = expression[pos++];
        if (op != '+' && op != '-' && op != '*' && op != '/') return false;
        ops.append(op);

        numStr.clear();
        if (pos < len && (expression[pos] == '+' || expression[pos] == '-')) {
            numStr += expression[pos++];
        }

        while (pos < len && (expression[pos].isDigit() || expression[pos] == '.')) {
            numStr += expression[pos++];
        }

        num = numStr.toDouble(&ok);
        if (!ok) return false;
        numbers.append(num);
    }

    if (numbers.size() != ops.size() + 1) return false;

    result = numbers[0];
    for (int i = 0; i < ops.size(); ++i) {
        double next = numbers[i + 1];
        QChar op = ops[i];

        if (op == '+') result += next;
        else if (op == '-') result -= next;
        else if (op == '*') result *= next;
        else if (op == '/') {
            if (next == 0) return false;
            result /= next;
        }
    }

    return true;
}
