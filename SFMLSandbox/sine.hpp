#ifndef sine_hpp
#define sine_hpp

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define PI 3.1415926535

/**
 * Class for generating and playing sine wave at specified frequency.
 */
class Sine {
    // Sine frequency.
    int frequency;
    // Buffer size in samples.
    int bufferSize;
    // Volume (0-100).
    float volume;
    // Sample buffer.
    sf::Int16 *samples;
    // SoundBuffer object for storing samples.
    sf::SoundBuffer buffer;
    // SFML Sound object with the signal.
    sf::Sound sine;
    // Calculate size of the buffer in samples provided sine frequency.
    int calculateBufferSize(int);
    // Generate the samples of the sine signal.
    void generateBuffer(int, int);
public:
    // Contstructors.
    Sine();
    Sine(int);
    // Returns true if the sound is currently playing.
    bool isPlaying;
    // Volume setter.
    void setVolume(float);
    // Volume getter.
    float getVolume();
    // Turn sound on and off.
    void toggle();
};

#endif /* sine_hpp */
