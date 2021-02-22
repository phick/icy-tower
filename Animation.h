#pragma once
#include "SFML/Graphics.hpp"
#include "DEFINITIONS.h"

namespace Engine
{
	class Animation
	{
	public:
		Animation();
		~Animation();


		

		void initAnimation(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime);

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