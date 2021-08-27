#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();
    void on_spinBox_valueChanged(int value);
    void on_unitBox_currentTextChanged(const QString &text);

private:
    Ui::MainWindow *ui;

    int height { 0 };
    QString unit {};
};

#endif // MAINWINDOW_H
