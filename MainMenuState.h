#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"State.h"
#include"Game.h"


namespace Engine {

	class MainMenuState : public State
	{
	public:

		MainMenuState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void initButtons();
		void initFonts();
		void handleClickingButtons();
		void handleLightingButtons();
		void initMusic();
	private:

		GameDataRef _data;


		sf::Sprite _playButton, _optionsButton, _exitButton, _background;

		sf::Text _playText, _optionsText, _exitText;
		sf::Texture tex;
		
		sf::Font menuFont;

		sf::Vector2f _scaleVector;

		bool isClicked;
		//bool isKeyReleased;

		sf::Sound sound;
		sf::SoundBuffer buffer;

	};

}