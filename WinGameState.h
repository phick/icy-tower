#pragma once
#include <SFML/Graphics.hpp>
#include"State.h"
#include"Game.h"


namespace Engine {

	class WinGameState : public State
	{
	public:

		WinGameState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:

		void initButtons();
		void initText();
		void initSound();


		GameDataRef _data;
		sf::Text _resumeText, _exitText, _pauseText, _barText;
		sf::Font pauseFont;
		sf::Sprite _resumeButton, _exitButton, _pauseBackground, _pauseBar;

		bool isClicked;
		bool isKeyReleased;

	};

}