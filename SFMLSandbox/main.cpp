
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

#include "ResourcePath.hpp"
#include "menu.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    // initialize vectors for menu options
    std::vector<Sine> sines;
    std::vector<Button> buttons;
    
    // generate the menu
    generateMenu(buttons, sines);
    
    // initialize variables for update loop
    sf::Vector2i mousePosition;
    float mouseX = 0.f;
    float mouseY = 0.f;
    bool mousePressed = false;
    bool mouseWasPressed = false;

    // Start the main loop
    while (window.isOpen())
    {
        // get mouse status
        mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        mousePosition = sf::Mouse::getPosition(window);
        mouseX = (float) mousePosition.x;
        mouseY = (float) mousePosition.y;
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear(sf::Color(128, 128, 128, 255));
        
        // Update the menu
        updateMenu(mouseX, mouseY, mousePressed, mouseWasPressed, buttons, sines, window);

        // Update the window
        window.display();
        
        // Store current mouse value
        mouseWasPressed = mousePressed;
    }

    return EXIT_SUCCESS;
}
