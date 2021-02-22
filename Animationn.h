#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

namespace Com
{
	class Animationn
	{
	public:
		Animationn(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime);
		~Animationn();


		void Update(int row, float deltaTime, bool faceRight);




	public:

		sf::IntRect uvRect;


	private:
		sf::Vector2u ImageCount;
		sf::Vector2u CurrentImage;

		float totalTime;
		float switchTIme;
	};

}