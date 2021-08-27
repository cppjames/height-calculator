#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

// MainWindow constructor, sets up the Ui and initializes the current unit to the default
// value of the unit dropdown field.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    unit = ui->unitBox->currentText();
}

// MainWindows destructor, responsible for destroying and freeing the Ui member variable.
MainWindow::~MainWindow()
{
    delete ui;
}

// Callback function for when the "Calculate" button is clicked.
// The algorithm is as follows:
//   1. Button is triggered
//   2. Message box is initialized
//   3. Message box is displayed with calculated height
void MainWindow::on_calculateButton_clicked()
{
    // Holds the icon for the message box that will display the calculated height.
    // QMessageBox::Information has been chosen because the purpose of the message box
    // is to communicate the height that has been obtained.
    QMessageBox::Icon heightBoxIcon { QMessageBox::Information };

    // Title of the message box that will be displayed. A simple value of "Result" will
    // suffice, as the context provides enough information to make it clear that the
    // displayed value represents the calculated height.
    QString heightBoxTitle { "Result" };

    // Text content of the message box. This is trickier to compute, but the algorithm can
    // be summed up to the following:
    //
    // +------Hardcoded string------+    +--String constructed from integer--+
    // | 1                          |    | 2                                 |
    // |     "Your height is "      |    |              height               |
    // |                            |    |                                   |
    // +---------+------------------+    +-----------------+-----------------+
    //           |                                         |
    //           +----+------------------------------------+
    //                |
    // +----Concatenated string----+    +----Space character----+
    // | I                         |    | 3                     |
    // |         (1) + (2)         |    |          ' '          |
    // |                           |    |     (it is there)     |
    // +--------+------------------+    +----------+------------+
    //          |                                  |
    //          +-----+----------------------------+
    //                |
    // +----Concatenated string----+    +----Unit of measurement----+
    // | II                        |    | 4                         |
    // |         (I) + (3)         |    |           unit            |
    // |                           |    |                           |
    // +--------+------------------+    +----------+----------------+
    //          |                                  |
    //          +-----+----------------------------+
    //                |
    // +----Concatenated string----+    +----Exclamation character----+
    // | III                       |    | 5                           |
    // |        (II) + (4)         |    |            '!'              |
    // |                           |    |                             |
    // +--------+------------------+    +----------+------------------+
    //          |                                  |
    //          +----------------+-----------------+
    //                           |
    // +------------------Final computed string----------------------+
    // |                                                             |
    // |                        (III) + (5)                          |
    // |                                                             |
    // +-------------------------------------------------------------+
    QString heightBoxText {
        QString("Your height is ")
            + QString::number(height)
            + QString(' ')
            + QString(unit)
            + QString('!')
    };

    // Interactive button that will appear at the bottom of the message dialog.
    // We have chosen QMessageBox::Ok because "Ok" is a reasonable response
    // to expect from someone who has just been told what their height is.
    QMessageBox::StandardButton heightBoxButton { QMessageBox::Ok };

    QMessageBox heightBox {
        heightBoxIcon,
        heightBoxTitle,
        heightBoxText,
        heightBoxButton
    };

    // The message box gets displayed and the main thread is blocked until the user
    // closes the dialog or triggers the "Ok" button.
    heightBox.exec();

    // Intentional fallthrough to the end of the compound statement.
}

// Callback function that gets called every time the value of the spin box
// is changed by the user.
void MainWindow::on_spinBox_valueChanged(int value)
{
    // Update internal height value to store the new value of the spin box field.
    height = value;

    // Intentional fallthrough to the end of the compound statement.
}

// Callback function that gets called every time the value of the unit dropdown
// field is changed by the user.
void MainWindow::on_unitBox_currentTextChanged(const QString &text)
{
    // Update internal unit string to store the new value of the unit field.
    unit = text;

    // Intentional fallthrough to the end of the compound statement.
}
