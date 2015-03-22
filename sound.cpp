#include <sound.h>


TSound::TSound() {
    sound = new QMediaPlayer;
    sound->setVolume(100);
}

void TSound::SoundPlayed() {
    sound->play();
}
void TSound::SoundStop() {
    sound->stop();
}

QMediaPlayer::State TSound::getState() {
    return sound->state();
}

void TSound::setFile(const QString & fileName) {
    fileAdress  = fileName;
    sound->setMedia(QUrl::fromLocalFile(fileName));
}
