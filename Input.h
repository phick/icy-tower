#pragma once
#include<SFML/Graphics.hpp>


namespace Engine{

	class Input 
	{
	public:
		Input() {};
		~Input() {};

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);
		bool isSpriteLighted(sf::Sprite object,sf::RenderWindow& window);
		

		sf::Vector2i GetMousePosition(sf::RenderWindow& window);

		//bool enem;


	};


}
