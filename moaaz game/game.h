#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_game.h"
#include <QApplication>
#include <QPushButton>
#include<QString>
#include"source.h"
using namespace std;
namespace Ui { class Register; };

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    void UserStatus(userStatus status);
   

private slots:
    void on_back_from_instructions_clicked();
    void on_instruction_button_clicked();
    void on_rock_button_clicked();
    void on_paper_button_clicked();
    void on_scissor_button_clicked();
    void on_play_button_clicked();
    void on_back_from_play_clicked();
    void on_records_button_clicked();
    void adjustFontSizeToLabel(QLabel* label, const QString& text);
    void on_back_from_rec_clicked();
    cmpchoice randPicture();
    void on_rec_but_play_clicked();
private:
    Ui::gameClass* ui;
};

