#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace debug {
	bool active = false;
	bool show_grid;
	std::vector<sf::VertexArray> grid;
	std::vector<sf::Text> grid_coord;
	sf::Font grid_font;
	sf::Color grid_color;
	sf::Color grid_coord_color;
	int side_length;

	void activate() {
		active = true;
		show_grid = false;
		grid.clear();
		grid_coord.clear();
		grid_font.loadFromFile("Resources/NotoSans.ttf");
		grid_color = sf::Color(255, 0, 0, 255);
		grid_coord_color = sf::Color(255, 0, 0, 255);
		side_length = 100;

		for (int i = 0; i < 3000; i += side_length) {
			sf::VertexArray line(sf::Lines, 2);
			line[0] = sf::Vertex(sf::Vector2f(i * 1.0f, 0.0f), grid_color);
			line[1] = sf::Vertex(sf::Vector2f(i * 1.0f, 2000.0f), grid_color);

			grid.push_back(line);
		}
		for (int i = 0; i < 2000; i += side_length) {
			sf::VertexArray line(sf::Lines, 2);
			line[0] = sf::Vertex(sf::Vector2f(0.0f, i * 1.0f), grid_color);
			line[1] = sf::Vertex(sf::Vector2f(3000.0f, i * 1.0f), grid_color);

			grid.push_back(line);
		}
		for (int i = 0; i < 3000; i += side_length) {
			for (int j = 0; j < 2000; j += side_length) {
				sf::Text _text;
				std::string coord = std::to_string(i) + ", " + std::to_string(j);
				_text.setFont(grid_font);
				_text.setFillColor(grid_coord_color);
				_text.setCharacterSize(20u);
				_text.setPosition(i * 1.0f, j * 1.0f);
				_text.setString(coord);
				_text.setStyle(sf::Text::Bold);

				grid_coord.push_back(_text);
			}
		}
	}

	void deactivate() {
		active = false;
	}

	void update() {
		if(!active) return;

		show_grid = (!show_grid);
	}

	void draw(sf::RenderWindow& window) {
		if(!active) return;

		if (show_grid) {
			for (auto& itr : debug::grid) window.draw(itr);
			for (auto& itr : debug::grid_coord) window.draw(itr);
		}
	}
};