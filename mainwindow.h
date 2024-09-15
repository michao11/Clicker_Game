#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QMessageBox>
#include <QListWidget>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startGame_pushButton_clicked();

    void on_first_pushButton_clicked();

    void on_second_pushButton_clicked();

    void on_third_pushButton_clicked();

    void on_fourth_pushButton_clicked();

    void checkCorrectButtonClicked(int index);

    void randomButtons();

    void clearGame();

private:
    Ui::MainWindow *ui;
    int userClickNumber = 0;
    int userCorrectClicks = 0;
    int buttonCorrectIndex = 0;
    QList<QPushButton*> buttons;
    QElapsedTimer gameTimer;
};

#endif // MAINWINDOW_H
