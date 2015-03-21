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

public:
     QString fileAdress = "";
private:
    QMediaPlayer* sound;

};

#endif // SOUND

