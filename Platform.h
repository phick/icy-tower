#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"

class Platform
{
public:
	Platform();
	~Platform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); };
	void setProp(sf::Texture* tex, sf::Vector2f size, sf::Vector2f position);
private:


	sf::RectangleShape body;
};

