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

void game::on_instruction_button_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->Instructions_page);

    QPixmap view(":/game/mooaz.png");
    ui->arrow1->setPixmap(view.scaled(ui->arrow1->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow1->setScaledContents(true);

    QPixmap view2(":/game/mooaz.png");
    ui->arrow2->setPixmap(view2.scaled(ui->arrow2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow2->setScaledContents(true);

    QPixmap view3(":/game/down-arrow.png");
    ui->arrow3->setPixmap(view3.scaled(ui->arrow3->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow3->setScaledContents(true);

    QPixmap view4(":/game/arrow-left.png");
    ui->arrow4->setPixmap(view4.scaled(ui->arrow4->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow4->setScaledContents(true);

    QPixmap view5(":/game/up-arrow.png");
    ui->arrow5->setPixmap(view5.scaled(ui->arrow5->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow5->setScaledContents(true);

    QPixmap view6(":/game/stone.png");
    ui->rock->setPixmap(view6.scaled(ui->rock->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->rock->setScaledContents(true);

    QPixmap view7(":/game/scissors.png");
    ui->scissors->setPixmap(view7.scaled(ui->scissors->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->scissors->setScaledContents(true);

    QPixmap view8(":/game/scroll.png");
    ui->paper->setPixmap(view8.scaled(ui->paper->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->paper->setScaledContents(true);

    QPixmap view9(":/game/arrow-left.png");
    ui->arrow4_2->setPixmap(view9.scaled(ui->arrow4_2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow4_2->setScaledContents(true);

    QPixmap view10(":/game/arrow-left.png");
    ui->arrow4_3->setPixmap(view10.scaled(ui->arrow4_3->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow4_3->setScaledContents(true);


    QPixmap view11(":/game/arrow-left.png");
    ui->arrow4_4->setPixmap(view11.scaled(ui->arrow4_4->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow4_4->setScaledContents(true);


    /*QPixmap view9(":/game/sign-in.png");
    ui->arrow_in->setPixmap(view9.scaled(ui->arrow_in->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow_in->setScaledContents(true);*/

   /* QPixmap view10(":/game/logout.png");
    ui->arrow_out->setPixmap(view10.scaled(ui->arrow_out->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->arrow_out->setScaledContents(true);*/

}

void game::on_back_from_instructions_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->welcome_pagePage1);
    
}