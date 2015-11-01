#include "button.hpp"
#include "ResourcePath.hpp"

Button::Button() {
    xPosition = 0;
    yPosition = 0;
}

Button::Button(float x, float y, sf::String labelText) {
    xPosition = x;
    yPosition = y;
    text = labelText;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    sf::Vector2f vector(xSize, ySize);
    shape.setSize(vector);
    shape.setPosition(xPosition, yPosition);
    shape.setFillColor(sf::Color::White);
    label.setString(text);
    label.setPosition(xPosition, yPosition-25);
    label.setFont(font);
    label.setColor(sf::Color(0, 0, 0, 255));
    label.setCharacterSize(30);
    label.setPosition(100, 100);
    isPressed = false;
}

bool Button::mouseOver(float xPos, float yPos) {
    sf::FloatRect rectangle(xPosition, yPosition, xSize, ySize);
    if (rectangle.contains(xPos, yPos)) {
        return true;
    } else {
        return false;
    }
}

void Button::toggle() {
    if (!isPressed) {
        shape.setFillColor(sf::Color::Green);
        isPressed = true;
    } else {
        shape.setFillColor(sf::Color::White);
        isPressed = false;
    }
}

void Button::drawButton(sf::RenderWindow &window) {
    //window.draw(label);
    window.draw(shape);
}