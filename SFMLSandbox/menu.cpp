#include "menu.hpp"

void generateMenu(std::vector<Button> &buttons, std::vector<Sine> &sines) {
    
    // draw buttons
    buttons.push_back(Button(100, 150, "250"));
    buttons.push_back(Button(100, 250, "1000"));
    buttons.push_back(Button(100, 350, "2000"));
    
    // load up sounds
    sines.push_back(Sine(250));
    sines.push_back(Sine(1000));
    sines.push_back(Sine(2000));
    
}

void updateMenu(float mouseX, float mouseY, bool mouseDown, bool mouseWasDown, std::vector<Button> &buttons, std::vector<Sine> &sines, sf::RenderWindow &window){
    // generate iterators
    std::vector<Button>::iterator i = buttons.begin();
    std::vector<Button>::iterator end = buttons.end();
    int x = 0;
    for (; i!=end; i++) {
        // check if mouse is over the button
        if (buttons[x].mouseOver(mouseX, mouseY) && mouseDown && !mouseWasDown) {
            // if yes, toggle the button and turn on/off sound
            buttons[x].toggle();
            sines[x].toggle();
        }
        // draw buttons to render window
        buttons[x].drawButton(window);
        x++;
    }
}