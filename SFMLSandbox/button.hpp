#ifndef button_hpp
#define button_hpp

#include <SFML/Graphics.hpp>

/**
 * Generate a clickable toggle button.
 */
class Button {
    // Relative position in window
    float xPosition, yPosition;
    // Height and width of button
    float xSize = 150.f;
    float ySize = 50.f;
    // Label text
    sf::String text;
    sf::Text label;
    // Button shape
    sf::RectangleShape shape;
    // Button color
    sf::Color color;
    // Label font
    sf::Font font;
public:
    // Constructors
    Button();
    Button(float, float, sf::String);
    // Returns true if the button is toggled "on"
    bool isPressed;
    // Provide X/Y coordinates of mouse pointer.
    // Returns true if pointer is overlapping the button.
    bool mouseOver(float, float);
    // Toggles button from white to green and changes isPressed value.
    // false - white, true - green.
    void toggle();
    // Draw the button and label to the render window
    void drawButton(sf::RenderWindow&);
};

#endif /* button_hpp */
