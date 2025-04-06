#include "ImageBox.h"

ImageBox::ImageBox() : Entity(EntityType::image_box) {
	
	/*if (!texture.loadFromFile("./Images/demo.png")) {
		std::cout << "Error occured while loading file\n";
		return;
	}

	sprite.setTexture(texture);*/
}

ImageBox::ImageBox(std::string imageFile, sf::Vector2f pos, sf::Vector2f factor) : Entity(EntityType::image_box) {
	
	if (!texture.loadFromFile(imageFile)) {
		std::cout << "Error occured while loading file\n";
		return;
	}

	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.scale(factor);
}

void ImageBox::setPosition(sf::Vector2f pos) {
	sprite.setPosition(pos);
}

void ImageBox::movePosition(sf::Vector2f offset) {
	sprite.move(offset);
}

void ImageBox::scaleImage(sf::Vector2f factor) {
	sprite.scale(factor);
}

void ImageBox::drawTo(sf::RenderWindow& window) {
	window.draw(sprite);
}

bool ImageBox::isMouseHover(sf::Vector2f mouse_pos) const {
	return false;
}

SceneId ImageBox::get_next_scene() {
	return SceneId::_default;
}