#pragma once
#include"State.h"
#include "Game.h"

namespace Engine {

	class SplashScreenState : public State
	{
	public:

		SplashScreenState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:

		GameDataRef _data;


		sf::Sprite bck;
		sf::Texture tex;

		sf::Clock _clock;



		int time;

		bool isClicked;
		bool isKeyReleased;

	};

}

