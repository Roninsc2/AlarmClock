#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <activationtime.h>
#include <QTimer>
#include <sound.h>



namespace Ui {
class Widget;
}

class TWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TWidget(QWidget *parent = 0);
    ~TWidget();
    void timerEvent(QTimerEvent *);

private:
    Ui::Widget *ui;

public:
    TTime Time;
    TSound Sound;
    int idTimer;
    bool checkToPlay = false;
private slots:

    void on_checkBox_Sunday_clicked();
    void on_checkBox_Saturday_clicked();
    void on_checkBox_Friday_clicked();
    void on_checkBox_Thursday_clicked();
    void on_checkBox_Wednesday_clicked();
    void on_checkBox_Tuesday_clicked();
    void on_checkBox_Monday_clicked();
    void on_setTime_timeChanged(const QTime &time);
    void on_setDateandTime_clicked();
    void on_hideSetTime_clicked();
    void on_stop_clicked();
    void on_setMusic_clicked();
    void on_hideMusic_clicked();
    void on_lineEdit_textEdited(const QString &arg1);
};

#endif // WIDGET_H
