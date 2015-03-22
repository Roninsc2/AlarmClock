#include "widget.h"
#include "ui_widget.h"

TWidget::TWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    Time(),
    Sound()
{
    ui->setupUi(this);
    ui->stop->hide();
    ui->checkBox_Friday->hide();
    ui->checkBox_Monday->hide();
    ui->checkBox_Saturday->hide();
    ui->checkBox_Sunday->hide();
    ui->checkBox_Thursday->hide();
    ui->checkBox_Tuesday->hide();
    ui->checkBox_Wednesday->hide();
    ui->setTime->hide();
    ui->hideSetTime->hide();
    ui->stop->hide();
    ui->hours->display(Time.currentTime.hour());
    ui->minutes->display(Time.currentTime.minute());
    idTimer = startTimer(1000);
}

TWidget::~TWidget()
{
    killTimer(idTimer);
    delete ui;
}

void TWidget::timerEvent(QTimerEvent *)
{
    Time.updateDateAndTime();
    ui->hours->display(Time.currentTime.hour());
    ui->minutes->display(Time.currentTime.minute());
    if(Time.ReadyToPlay() && Sound.fileAdress != "") {
       Sound.SoundPlayed();
       ui->stop->show();
       checkToPlay = true;
    }
    if(checkToPlay && Sound.getState() == QMediaPlayer::StoppedState) {
        Sound.SoundPlayed();
    }
    update();
}

void TWidget::on_checkBox_Sunday_clicked()
{
    if(Time.dayOfWeek.find(7) != Time.dayOfWeek.end()){
        Time.dayOfWeek.remove(7);
    } else {
       Time.dayOfWeek.insert(7);
    }
}

void TWidget::on_checkBox_Saturday_clicked()
{
    if(Time.dayOfWeek.find(6) != Time.dayOfWeek.end()){
        Time.dayOfWeek.remove(6);
    } else {
       Time.dayOfWeek.insert(6);
    }
}

void TWidget::on_checkBox_Friday_clicked()
{
    if(Time.dayOfWeek.find(5) != Time.dayOfWeek.end()){
        Time.dayOfWeek.remove(5);
    } else {
       Time.dayOfWeek.insert(5);
    }
}

void TWidget::on_checkBox_Thursday_clicked()
{
    if(Time.dayOfWeek.find(4) != Time.dayOfWeek.end()){
        Time.dayOfWeek.remove(4);
    } else {
       Time.dayOfWeek.insert(4);
    }
}

void TWidget::on_checkBox_Wednesday_clicked()
{
     if(Time.dayOfWeek.find(3) != Time.dayOfWeek.end()){
         Time.dayOfWeek.remove(3);
     } else {
        Time.dayOfWeek.insert(3);
     }
}

void TWidget::on_checkBox_Tuesday_clicked()
{
    if(Time.dayOfWeek.find(2) != Time.dayOfWeek.end()){
        Time.dayOfWeek.remove(2);
    } else {
       Time.dayOfWeek.insert(2);
    }
}

void TWidget::on_checkBox_Monday_clicked()
{
    if(Time.dayOfWeek.find(1) != Time.dayOfWeek.end()){
        Time.dayOfWeek.remove(1);
    } else {
       Time.dayOfWeek.insert(1);
    }
}

void TWidget::on_setTime_timeChanged(const QTime &time)
{
    Time.hoursToPlay = time.hour();
    Time.minuteToPlay = time.minute();
}

void TWidget::on_setDateandTime_clicked()
{
    ui->setMusic->hide();
    ui->checkBox_Friday->show();
    ui->checkBox_Monday->show();
    ui->checkBox_Saturday->show();
    ui->checkBox_Sunday->show();
    ui->checkBox_Thursday->show();
    ui->checkBox_Tuesday->show();
    ui->checkBox_Wednesday->show();
    ui->setTime->show();
    ui->setDateandTime->hide();
    ui->hideSetTime->show();
}

void TWidget::on_hideSetTime_clicked()
{
    ui->setMusic->show();
    ui->checkBox_Friday->hide();
    ui->checkBox_Monday->hide();
    ui->checkBox_Saturday->hide();
    ui->checkBox_Sunday->hide();
    ui->checkBox_Thursday->hide();
    ui->checkBox_Tuesday->hide();
    ui->checkBox_Wednesday->hide();
    ui->setTime->hide();
    ui->hideSetTime->hide();
    ui->setDateandTime->show();
}

void TWidget::on_stop_clicked()
{
    checkToPlay = false;
    Sound.SoundStop();
    ui->stop->hide();
}

void TWidget::on_setMusic_clicked()
{
    ui->setDateandTime->hide();
    ui->setMusic->hide();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Directory"),
                                                   "/home", "*.mp3 *.wav");
    Sound.setFile(fileName);
    ui->setDateandTime->show();
    ui->setMusic->show();

}

