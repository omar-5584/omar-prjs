#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_game.h"
#include <QApplication>
#include <QPushButton>
#include<QString>
using namespace std;
namespace Ui { class Register; };

class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

private slots:
    void on_rock_button_clicked();
    void on_play_button_clicked();
private:
    Ui::gameClass* ui;
};

