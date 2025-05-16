#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();       // Обработчик для цифр и операторов
    void onEqualsClicked();         // Вычисление результата
    void onClearClicked();          // Очистка поля ввода
    void handleReturnPressed();     // Обработка нажатия Enter

private:
    Ui::MainWindow *ui;
    bool calculate(const QString &expression, double &result); // Логика вычислений
};

#endif // MAINWINDOW_H
