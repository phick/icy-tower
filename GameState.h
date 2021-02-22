#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "State.h"
#include "Game.h"
#include "Maps.h"
#include "Player.h"
#include"Platform.h"
#include"Collider.h"


namespace Engine {




	class GameState : public State
	{
	public:

		GameState(GameDataRef data);
		

		

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void initPlatform();

		void initMusic();

		


		Maps map1;
		
		Player player;

		Platform o1;
		Platform oT[124][15];

		//Collider p1;

		

		
	private:

		void initUIButtons();
		void initViews();
		void handleUIInputs();
		void handlePlayerInputs();
		void handlePlayerView(float dt);
		void checkCollision();

		GameDataRef _data;
		double viewPla;



		// EXAMPLE
		sf::Font gameFont;
		sf::Text gameText, gameText2, pauseText;

		sf::Sprite _pauseButton;
		sf::View view, viewUI, viewMiniMap;
		sf::Vector2f direction;
		bool faceRight;
		bool isJumping = false;
		float Acc = 1.1f;
		int GroundHeight;
		sf::Vector2f velocity;
		bool canJump;
		float jumpHeight;

		//int gameState;

		//bool isClicked;


		sf::Sound sound;
		sf::SoundBuffer buffer;

		double viewSpeed;



	};




	
}
