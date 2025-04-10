#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int fun_sfml(){
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    // 1920 x 1200
    unsigned window_width	= desktop.width;
    unsigned window_height	= desktop.height;
    sf::RenderWindow window(desktop, "SFML works!", sf::Style::Fullscreen);
    //std::cout << window_width << " " << window_height << "\n";
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    std::vector<sf::VertexArray> grid;
    std::vector<sf::Text> grid_coord;
    sf::Font grid_font;
    grid_font.loadFromFile("Resources/NotoSans.ttf");
    int side_length = 100;

    for (int i = 0; i < 3000; i += side_length) {
        sf::VertexArray line(sf::Lines, 2);
        line[0] = sf::Vertex(sf::Vector2f(i * 1.0f, 0.0f), sf::Color::Red);
        line[1] = sf::Vertex(sf::Vector2f(i * 1.0f, 2000.0f), sf::Color::Red);

        grid.push_back(line);
    }
    for (int i = 0; i < 2000; i += side_length) {
        sf::VertexArray line(sf::Lines, 2);
        line[0] = sf::Vertex(sf::Vector2f(0.0f, i * 1.0f), sf::Color::Red);
        line[1] = sf::Vertex(sf::Vector2f(3000.0f, i * 1.0f), sf::Color::Red);

        grid.push_back(line);
    }
    for (int i = 0; i < 3000; i += side_length) {
        for (int j = 0; j < 2000; j += side_length) {
            sf::Text _text;
            std::string coord = std::to_string(i) + ", " + std::to_string(j);
            _text.setFont(grid_font);
            _text.setFillColor(sf::Color::Green);
            _text.setCharacterSize(20u);
            _text.setPosition(i * 1.0f, j * 1.0f);
            _text.setString(coord);

            grid_coord.push_back(_text);
        }
    }

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            else if (event.type == sf::Event::Closed){
                window.close();
            }

        }

        window.clear();
        for (auto& itr : grid) {
            window.draw(itr);
        }
        for (auto& itr : grid_coord) {
            window.draw(itr);
        }
        window.display();
    }

    return 0;
}