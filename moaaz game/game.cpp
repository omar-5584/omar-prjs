#include "game.h"

game::game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gameClass)
{
    ui->setupUi(this);
    ui->welcome_page->setCurrentWidget(ui->welcome_pagePage1);
}

game::~game()
{
    delete ui;
}

void game::on_play_button_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->page);
}

void game::on_rock_button_clicked()
{


}