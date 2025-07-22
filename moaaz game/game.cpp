#include "game.h"
#include "source.h"
#include <QTableWidget>

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

void game::adjustFontSizeToLabel(QLabel* label, const QString& text)
{
    QFont font = label->font();
    int fontSize = 30;
    font.setPointSize(fontSize);

    QFontMetrics fm(font);
    QRect rect = fm.boundingRect(label->rect(), Qt::AlignCenter | Qt::TextWordWrap, text);


    while ((rect.width() > label->width() || rect.height() > label->height()) && fontSize > 1) {
        fontSize--;
        font.setPointSize(fontSize);
        fm = QFontMetrics(font);
        rect = fm.boundingRect(label->rect(), Qt::AlignCenter | Qt::TextWordWrap, text);
    }

    label->setFont(font);
    label->setText(text);
}

void game::UserStatus(userStatus status)
{
    if (status == userStatus::win)
    {
        QString text = "Win +1";
        ui->play_status->setText("<span style='color: green;'>" + text + "</span>");
    }

    else if (status == userStatus::tie)
    {
        QString text = "Tie +0";
        ui->play_status->setText("<span style='color: gray;'>" + text + "</span>");
    }

    else if (status == userStatus::lose)
    {
        QString text = "Lose -1";
        ui->play_status->setText("<span style='color: red;'>" + text + "</span>");
    }
}

cmpchoice game::randPicture()
{
    cmpchoice rand = randomchoice();

    if (rand == cmpchoice::paper)
    {
        QPixmap view(":/game/paper hand.png");
        ui->cmp_ch->setPixmap(view.scaled(ui->cmp_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui->cmp_ch->setScaledContents(false);
        ui->cmp_ch->setAlignment(Qt::AlignCenter);
    }
    else if (rand == cmpchoice::rock)
    {
        QPixmap view(":/game/rock hand.png");
        ui->cmp_ch->setPixmap(view.scaled(ui->cmp_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui->cmp_ch->setScaledContents(false);
        ui->cmp_ch->setAlignment(Qt::AlignCenter);
    }
    else if (rand == cmpchoice::scissor)
    {
        QPixmap view(":/game/scissor hand.png");
        ui->cmp_ch->setPixmap(view.scaled(ui->cmp_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui->cmp_ch->setScaledContents(false);
        ui->cmp_ch->setAlignment(Qt::AlignCenter);
    }
    return rand;
}
void game::on_rec_but_play_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->record_page);
    on_records_button_clicked();
}
void game::on_paper_button_clicked()
{
    ui->rec_but_play->setVisible(true);
    cmpchoice com = randPicture();
    ui->play_widget->show();
    QPixmap view(":/game/paper hand.png");
    ui->user_ch->setPixmap(view.scaled(ui->user_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->user_ch->setScaledContents(false);
    ui->user_ch->setAlignment(Qt::AlignCenter);
    UserStatus(WhoWins(cmpchoice::paper, com));
}

void game::on_scissor_button_clicked()
{
    ui->rec_but_play->setVisible(true);
    cmpchoice com = randPicture();
    ui->play_widget->show();
    QPixmap view(":/game/scissor hand.png");
    ui->user_ch->setPixmap(view.scaled(ui->user_ch->size() * 0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->user_ch->setScaledContents(false);
    ui->user_ch->setAlignment(Qt::AlignCenter);
    UserStatus(WhoWins(cmpchoice::scissor, com));
}

void game::on_play_button_clicked()
{
    ui->rec_but_play->setVisible(false);
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

    ui->opponent->setRowCount(2);
    ui->opponent->setColumnCount(4);

    QStringList headers;
    headers << "name" << "Wins" << "Loses" << "Ties";
    ui->opponent->setHorizontalHeaderLabels(headers);

    
    ui->opponent->horizontalHeader()->setFont(QFont("Segoe UI", 12, QFont::Bold));
    ui->opponent->horizontalHeader()->setStyleSheet("color: white; background-color: #a97c50;");

    
    auto createItem = [](const QString& text, bool bold = false) {
        QTableWidgetItem* item = new QTableWidgetItem(text);
        item->setTextAlignment(Qt::AlignCenter);
        item->setFont(QFont("Segoe UI", 12, bold ? QFont::Bold : QFont::Normal));
        item->setForeground(QBrush(QColor("#3e3e3e")));  
        return item;
        };

    
    ui->opponent->setItem(0, 0, createItem("user", true));
    ui->opponent->setItem(0, 1, createItem(QString::number(user_points.wins)));
    ui->opponent->setItem(0, 2, createItem(QString::number(user_points.loses)));
    ui->opponent->setItem(0, 3, createItem(QString::number(user_points.ties)));

   
    ui->opponent->setItem(1, 0, createItem("opponent", true));
    ui->opponent->setItem(1, 1, createItem(QString::number(user_points.loses)));
    ui->opponent->setItem(1, 2, createItem(QString::number(user_points.wins)));
    ui->opponent->setItem(1, 3, createItem(QString::number(user_points.ties)));

    
    ui->opponent->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->opponent->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

   
    ui->opponent->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    ui->badge->setVisible(0);

    if (user_points.wins > user_points.loses)
    {
        ui->badge->setVisible(1);

        QPixmap view50(":/game/winner.png");
        ui->badge->setPixmap(view50.scaled(ui->badge->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui->badge->setScaledContents(true);

 


        ui->name->setText("user");
        adjustFontSizeToLabel(ui->name, "user");

        
    }
    else if (user_points.wins < user_points.loses)
    {
        ui->badge->setVisible(1);

        QPixmap view51(":/game/winner.png");
        ui->badge->setPixmap(view51.scaled(ui->badge->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui->badge->setScaledContents(true);

        ui->name->setText("opponent");
        adjustFontSizeToLabel(ui->name, "opponent");
    }
    else if (user_points.wins == user_points.loses)
    {
        ui->name->setText("(tie)");
        adjustFontSizeToLabel(ui->name, "(tie)");
    }

}



void game::on_back_from_rec_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->welcome_pagePage1);
}



void game::on_rock_button_clicked()
{
    ui->rec_but_play->setVisible(true);
     cmpchoice com= randPicture();
    ui->play_widget->show();
    
    QPixmap view(":/game/rock hand.png");
    ui->user_ch->setPixmap(view.scaled(ui->user_ch->size()*0.8, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    ui->user_ch->setScaledContents(false);
    ui->user_ch->setAlignment(Qt::AlignCenter);

    UserStatus(WhoWins(cmpchoice::rock, com));

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


    

}

void game::on_back_from_instructions_clicked()
{
    ui->welcome_page->setCurrentWidget(ui->welcome_pagePage1);
    
}