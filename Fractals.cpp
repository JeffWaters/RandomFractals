#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
    // create window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Random Fractals");

    // create fractal
    sf::ConvexShape fractal;
    fractal.setPointCount(3);

    // random number generator
    std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> dist_x(0, WIDTH);
    std::uniform_int_distribution<int> dist_y(0, HEIGHT);
    std::uniform_int_distribution<int> dist_col(0, 255);

    // set initial triangle
    fractal.setPoint(0, sf::Vector2f(WIDTH / 2, 0));
    fractal.setPoint(1, sf::Vector2f(0, HEIGHT));
    fractal.setPoint(2, sf::Vector2f(WIDTH, HEIGHT));
    fractal.setFillColor(sf::Color(dist_col(rng), dist_col(rng), dist_col(rng)));

    // run game loop
    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // update fractal
        for (int i = 0; i < 1000; i++) {
            int rand_point = std::uniform_int_distribution<int>(0, 2)(rng);
            sf::Vector2f point = fractal.getPoint(rand_point);
            float x = (point.x + dist_x(rng)) / 2.0f;
            float y = (point.y + dist_y(rng)) / 2.0f;
            fractal.setPoint(i, sf::Vector2f(x, y));
        }

        // render
        window.clear();
        window.draw(fractal);
        window.display();
    }

    return 0;
}
