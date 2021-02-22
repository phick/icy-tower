#include "Platform.h"



Platform::Platform()
{
	

}


Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow & window)
{
	window.draw(body);

}

void Platform::setProp(sf::Texture* tex, sf::Vector2f size, sf::Vector2f position)
{
	body.setTexture(tex);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}
