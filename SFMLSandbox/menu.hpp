#ifndef menu_hpp
#define menu_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "ResourcePath.hpp"
#include "sine.hpp"
#include "button.hpp"

/**
 * Generate menu with specified buttons and corresponding sine frequencies.
 */
void generateMenu(std::vector<Button>&, std::vector<Sine>&);

/**
 * Updates the menu state - detect clicks on buttons, toggle buttons and audio.
 */
void updateMenu(float, float, bool, bool, std::vector<Button>&, std::vector<Sine>&, sf::RenderWindow&);

#endif /* menu_hpp */
