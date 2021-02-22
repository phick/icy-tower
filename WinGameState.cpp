#include "WinGameState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "GameState.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"
#include <iostream>



namespace Engine {

	WinGameState::WinGameState(GameDataRef data) : _data(data)
	{
		isClicked = false;

	}

	void WinGameState::Init() {

		initButtons();
		initText();


	}


	void WinGameState::HandleInput()
	{

		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{


			if (this->_data->input.isSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{

				this->_data->machine.AddState(StateRef(new MainMenuState(_data)));

			}


			if (this->_data->input.isSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{

				this->_data->machine.AddState(StateRef(new GameState(_data)));

			}



			if (this->_data->input.isSpriteLighted(this->_exitButton, this->_data->window))
			{

				this->_exitText.setFillColor(sf::Color::White);
			}
			else
			{
				this->_exitText.setFillColor(sf::Color::Color(255, 153, 0));;
			}

			if (this->_data->input.isSpriteLighted(this->_resumeButton, this->_data->window))
			{

				this->_resumeText.setFillColor(sf::Color::White);
			}
			else
			{
				this->_resumeText.setFillColor(sf::Color::Color(255, 153, 0));
			}



		}
	}




	void WinGameState::Update(float dt) {

	

	}



	void WinGameState::Draw(float dt) {


		this->_data->window.clear(sf::Color::Yellow);


		this->_data->window.draw(_pauseBackground);
		this->_data->window.draw(_exitButton);
		this->_data->window.draw(_exitText);
		



		this->_data->window.draw(_resumeButton);
		this->_data->window.draw(_resumeText);
		



		this->_data->window.display();
	}




	void WinGameState::initButtons()
	{

		// loading textures
		this->_data->asset.LoadTextures("_resumeButton", "b_7.png");
		this->_data->asset.LoadTextures("_exitButton", "b_6.png");
		this->_data->asset.LoadTextures("_pauseBackground",GAME_WIN_BCK);
		this->_data->asset.LoadTextures("barTexture", "bar_1.png");





		// setting textures
		this->_resumeButton.setTexture(this->_data->asset.GetTexture("_resumeButton"));
		this->_exitButton.setTexture(this->_data->asset.GetTexture("_exitButton"));
		this->_pauseBackground.setTexture(this->_data->asset.GetTexture("_pauseBackground"));
		//this->_pauseBar.setTexture(this->_data->asset.GetTexture("barTexture"));
		//this->_pauseBar.setScale(sf::Vector2f(0.5, 0.5));



		// positioning buttons

	//	this->_pauseBackground.setScale(0.9, 0.9);
		this->_pauseBackground.setOrigin(_pauseBackground.getLocalBounds().width / 2, _pauseBackground.getLocalBounds().height / 2);
		this->_pauseBackground.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);



		this->_pauseBar.setOrigin(_pauseBar.getLocalBounds().width / 2, _pauseBar.getGlobalBounds().height / 2);
		this->_pauseBar.setPosition(SCREEN_WIDTH / 2, _pauseBar.getGlobalBounds().height);



		this->_resumeButton.setPosition(SCREEN_WIDTH - _resumeButton.getGlobalBounds().width * 2, SCREEN_HEIGHT - _resumeButton.getGlobalBounds().height * 1.5);
		this->_exitButton.setPosition(_exitButton.getGlobalBounds().width, SCREEN_HEIGHT - _exitButton.getGlobalBounds().height * 1.5);





	}

	void WinGameState::initText() {



		// loading font
		this->_data->asset.LoadFont("arial", "arial.ttf");


		//setting text
		_resumeText.setFont(this->_data->asset.GetFont("arial"));
		_resumeText.setFillColor(sf::Color::White);
		_resumeText.setString("PLAY AGAIN");
		_resumeText.setCharacterSize(80);
		_resumeText.setPosition(_resumeButton.getPosition().x - 50, _resumeButton.getPosition().y - _resumeText.getGlobalBounds().height * 1.5 +400);


		// setting text
		_exitText.setFont(this->_data->asset.GetFont("arial"));
		_exitText.setFillColor(sf::Color::White);
		_exitText.setString("EXIT");
		_exitText.setCharacterSize(80);
		_exitText.setPosition(_exitButton.getPosition().x, _exitButton.getPosition().y - _exitText.getGlobalBounds().height * 1.5 + 400);

	}


}