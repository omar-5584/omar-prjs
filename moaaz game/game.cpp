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

void game::on_paper_button_clicked()
{
    ui->play_widget->show();
    QPixmap view(":/game/paper hand.png");
    ui->user_ch->setPixmap(view.scaled(ui->user_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->user_ch->setScaledContents(false);
    ui->user_ch->setAlignment(Qt::AlignCenter);
}

void game::on_scissor_button_clicked()
{
    ui->play_widget->show();
    QPixmap view(":/game/scissor hand.png");
    ui->user_ch->setPixmap(view.scaled(ui->user_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->user_ch->setScaledContents(false);
    ui->user_ch->setAlignment(Qt::AlignCenter);

}

void game::on_play_button_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->play_page);
    ui->play_widget->hide();
    QPixmap view(":/game/vs.png");
    ui->vs_photo->setPixmap(view.scaled(ui->vs_photo->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->vs_photo->setScaledContents(false);
    ui->vs_photo->setAlignment(Qt::AlignCenter);

}

void game::on_back_from_play_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->welcome_pagePage1);
    
}

void game::on_records_button_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->record_page);
}

void game::on_back_from_rec_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->welcome_pagePage1);
}

void game::on_rock_button_clicked()
{
    ui->play_widget->show();
    
    QPixmap view(":/game/rock hand.png");
    ui->user_ch->setPixmap(view.scaled(ui->user_ch->size()*0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->user_ch->setScaledContents(false);
    ui->user_ch->setAlignment(Qt::AlignCenter);

}