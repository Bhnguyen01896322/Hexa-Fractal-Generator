// "Copyright [2023] <Brandon Nguyen>"
#include "hexa.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

void drawHexaflake(sf::RenderWindow& window, double x, double y, double size, int depth) {
    if (depth == 0) {
        // initial hexagon with 6 vertices because its a hexagon we are making
        sf::ConvexShape hexagon;
        hexagon.setPointCount(6);

        for (int i = 0; i < 6; i++) {
            double angle = (60.0 * i) * (M_PI / 180.0);
            double x_coordinate = x + size * cos(angle);
            double y_coordinate = y + size * sin(angle);
            hexagon.setPoint(i, sf::Vector2f(x_coordinate, y_coordinate));
        }
        // usage of radius, thetaDeg, and Origin from class lecture
        float radius = size / sqrt(3);
        double thetaDeg = 90;
        hexagon.setOrigin(radius, radius);  // setting the origin so that it looks centered
        hexagon.rotate(thetaDeg);  // initial rotation of the hexaflake
        hexagon.setFillColor(sf::Color::Black);  // making the hexagons black
        window.draw(hexagon);
    } else {
        double newSize = size / 3.0;

        drawHexaflake(window, x, y, newSize, depth - 1);  // center hexaflake

        for (int i = 0; i < 6; i++) {  // six surrounding hexaflakes
            double angle = (60.0 * i) * (M_PI / 180.0);

            // position of the surrounding hexaflakes
            double x_coordinate = x + 2.0 * newSize * cos(angle);
            double y_coordinate = y + 2.0 * newSize * sin(angle);

            drawHexaflake(window, x_coordinate, y_coordinate, newSize, depth - 1);
        }
    }
}
