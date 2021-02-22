#include "Input.h"

namespace Engine{

	bool Input::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);


			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;

	}





	bool Input::isSpriteLighted(sf::Sprite object, sf::RenderWindow& window)
	{
		
		
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);


			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		
		  return false;

	}


	// FUNKCJA OBSLUGUJACA MYSZ, ZWRACA JEJ POZYCJE **************************************************

	sf::Vector2i Input::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}


}