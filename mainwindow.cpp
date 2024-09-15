#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons = {ui->first_pushButton, ui->second_pushButton, ui->third_pushButton, ui->fourth_pushButton};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startGame_pushButton_clicked()
{
    clearGame();
    userClickNumber = ui->userNumber_lineEdit->text().toInt();
    if (userClickNumber <= 0) {
        QMessageBox::information(this, "Information", "Enter correct number");
        return;
    }
    else {
        ui->game_progressBar->setRange(0, userClickNumber);
        ui->game_progressBar->setValue(0);
        randomButtons();
        gameTimer.start();
    }
}

void MainWindow::randomButtons()
{
    buttonCorrectIndex = QRandomGenerator::global()->bounded(buttons.size());

    for (int i = 0; i < buttons.size(); i++) {
        if (i == buttonCorrectIndex) {
            buttons[i]->setText("Click");
        }
        else {
            buttons[i]->setText("");
        }
    }
}

void MainWindow::clearGame()
{
    userCorrectClicks = 0;
    buttonCorrectIndex = -1;
    ui->first_pushButton->setText("Click");
    ui->second_pushButton->setText("Click");
    ui->third_pushButton->setText("Click");
    ui->fourth_pushButton->setText("Click");
    ui->scoreboard_listWidget->clear();
    ui->game_progressBar->reset();
}

void MainWindow::on_first_pushButton_clicked()
{
    checkCorrectButtonClicked(0);
}

void MainWindow::on_second_pushButton_clicked()
{
    checkCorrectButtonClicked(1);
}

void MainWindow::on_third_pushButton_clicked()
{
    checkCorrectButtonClicked(2);
}

void MainWindow::on_fourth_pushButton_clicked()
{
    checkCorrectButtonClicked(3);
}

void MainWindow::checkCorrectButtonClicked(int buttonIndex)
{
    if (buttonIndex == buttonCorrectIndex) {
        userCorrectClicks = userCorrectClicks + 1;
        ui->game_progressBar->setValue(userCorrectClicks);

        if (userCorrectClicks == userClickNumber) {
            qint64 userTime = gameTimer.elapsed();
            ui->scoreboard_listWidget->addItem("Your time: " + QString::number(userTime) + " ms");
            ui->first_pushButton->setText("Click");
            ui->second_pushButton->setText("Click");
            ui->third_pushButton->setText("Click");
            ui->fourth_pushButton->setText("Click");
            ui->game_progressBar->reset();
        }
        else {
            randomButtons();
        }
    }
    else {
        QMessageBox::information(this, "Information", "You clicked the wrong button, the game has been reset");
        clearGame();
    }
}
