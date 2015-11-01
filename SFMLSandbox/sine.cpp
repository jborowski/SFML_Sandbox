#include <cmath>
#include "sine.hpp"

Sine::Sine() {
    frequency = 0;
}

Sine::Sine(int freq) {
    frequency = freq;
    bufferSize = calculateBufferSize(frequency);
    samples = new sf::Int16[bufferSize];
    generateBuffer(frequency, bufferSize);
    buffer.loadFromSamples(samples, bufferSize, 1, 44100);
    volume = 50.f;
    isPlaying = false;
}

int Sine::calculateBufferSize(int frequency) {
    return 44100 / frequency;
}

void Sine::generateBuffer(int frequency, int bufferSize) {
    for (int i=0; i<bufferSize; i++) {
        samples[i] = floor(32767 * sin(i * 2 * PI / bufferSize));
    }
}

void Sine::setVolume(float vol) {
    sine.setVolume(vol);
    volume = vol;
}

float Sine::getVolume() {
    return volume;
}

void Sine::toggle() {
    if (isPlaying) {
        sine.stop();
        isPlaying = false;
    } else {
        sine.setBuffer(buffer);
        sine.setLoop(true);
        sine.setVolume(volume);
        sine.play();
        isPlaying = true;
    }
}