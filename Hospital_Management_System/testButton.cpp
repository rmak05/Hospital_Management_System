#include "Button.h"

static void testButton() {

	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");

	Button btn("Click", 30, { 200,50 }, sf::Color::Green, sf::Color::White);

	sf::Font font;
	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}

	btn.setFont(font);
	btn.setPosition({ 200,100 });

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseMoved:
				if (btn.isMouseHover(window)) {
					btn.setBgColor(sf::Color::White);
				}
				else {
					btn.setBgColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (btn.isMouseHover(window)) {
						window.close();
					}
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					btn.setBgColor(sf::Color::Red);
				}
				break;
			}
		}

		window.clear();
		btn.drawTo(window);
		window.display();
	}

}

int main() {
	testButton();
	return 0;
}