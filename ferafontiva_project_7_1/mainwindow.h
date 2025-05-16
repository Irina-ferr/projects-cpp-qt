#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateSum();

private:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLabel *plusLabel;
    QPushButton *calculateButton;
    QLabel *resultLabel;
};

#endif // MAINWINDOW_H
