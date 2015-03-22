#ifndef SOUND
#define SOUND

#include <QMediaPlayer>
#include <QString>

class TSound {

public:
    TSound();
    void SoundPlayed();
    void SoundStop();
    void setFile(const QString& fileName);
    QMediaPlayer::State getState();

public:
     QString fileAdress = "";
private:
    QMediaPlayer* sound;

};

#endif // SOUND

