// "Copyright [2023] <Brandon Nguyen>"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "hexa.hpp"

int main(int argc, char* argv[]) {
    // stod is string to double to convert and stoi is the same with integers
    // takes the first input such as ./Hexa length depth but this one is length
    // takes the second input such as ./Hexa length depth but this one is depth
    double L = std::stod(argv[1]);
    int N = std::stoi(argv[2]);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake");
    window.clear(sf::Color::White);  // makes my background white

    sf::Vector2f center(window.getSize().x / 2.0f, window.getSize().y / 2.0f);


    /* position at (400,-400) for x,y then L and N take the
    first and second input such as the size of the hexa and the depth*/
    drawHexaflake(window, 400, -400, L, N);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    return 0;
}
