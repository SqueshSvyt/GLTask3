#include "audiooutput.h"

AudioOutput::AudioOutput(QObject* parent):
    QAudioOutput{parent}
{
    this->setVolume(0.5);
}

void AudioOutput::mute_audio(){
    this->setMuted(!isMute());

    emit isMuteChanged();
}

bool AudioOutput::isMute() const{
    return this->isMuted();
}

float AudioOutput::vol() const{
    return this->volume();
}

void AudioOutput::setVol(float volume){
    this->setVolume(volume);

    emit volChanged();
}
