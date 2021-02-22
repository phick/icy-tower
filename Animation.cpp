#include "Animation.h"


namespace Engine
{


	Animation::Animation()
	{
		
	}


	Animation::~Animation()
	{


	}


	void Animation::initAnimation(sf::Texture* texture, sf::Vector2u ImageCount, float switchTime) {

		this->ImageCount = ImageCount;
		this->switchTIme = switchTime;

		totalTime = 0.0f;

		CurrentImage.x = 0;

		uvRect.width = texture->getSize().x / float(ImageCount.x);
		uvRect.height = texture->getSize().y / float(ImageCount.y);

	}
	void Animation::Update(int row, float deltaTime, bool faceRight)
	{
		CurrentImage.y = row;

		totalTime += deltaTime;
		if (row == 0)
			ImageCount.x = 3;




		if (totalTime >= switchTIme)
		{
			totalTime -= switchTIme;
			CurrentImage.x++;
			if (CurrentImage.x >= ImageCount.x)
			{
				CurrentImage.x = 0;

			}

		}


		uvRect.top = CurrentImage.y * uvRect.height;

		if (faceRight)
		{
			uvRect.left = (CurrentImage.x ) * uvRect.width;
			uvRect.width = abs(uvRect.width);
		}
		else
		{
			uvRect.left = (CurrentImage.x +1) * abs(uvRect.width);
			uvRect.width = -abs(uvRect.width);
		}






	}
}