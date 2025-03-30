#include "Button.h"
#include "TextInput.h"

static void testButton() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

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

static void testTextInput() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

	TextInput ti(30, { 500,50 }, sf::Color::White, sf::Color::Green, sf::Color::White);
	TextInput ti2(30, { 500,50 }, sf::Color::White, sf::Color::Green, sf::Color::White);

	sf::Font font;
	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}

	ti.setFont(font);
	ti.setPosition({ 200,100 });
	ti.setBackgroundColor(sf::Color::Magenta);
	ti.setLimit(true, 20);

	ti2.setFont(font);
	ti2.setPosition({ 200,300 });
	ti2.setLimit(true, 20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::TextEntered:
				ti.typedOn(event);
				ti2.typedOn(event);
				break;

			case sf::Event::MouseMoved:
				ti.isMouseHover(window);
				ti2.isMouseHover(window);
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					ti.setSelected(window);
					ti2.setSelected(window);
				}
				break;
			}
		}

		if (ti.getText() == "BYE") {
			window.close();
		}
		window.clear();
		ti.drawTo(window);
		ti2.drawTo(window);
		window.display();
	}
}

int main() {
	testTextInput();
	return 0;
}