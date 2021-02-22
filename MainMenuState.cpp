#include "MainMenuState.h"
#include "GameState.h"
#include <iostream>
#include "DEFINITIONS.h"



namespace Engine{

	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
		isClicked = false;

	}


	void MainMenuState::Init() {

		_scaleVector = sf::Vector2f(0.5, 0.5);

		initButtons();

		initFonts();
		initMusic();


	}

	void MainMenuState::HandleInput()
	{

		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
		

			handleClickingButtons();

			handleLightingButtons();

			


		}
	}




	void MainMenuState::Update(float dt) {

		//std::cout << " UPDATING FROM MENU" << std::endl;

	}

	void MainMenuState::Draw(float dt) {
     
		
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(_background);
		this->_data->window.draw(_playButton);
		this->_data->window.draw(_optionsButton);
		this->_data->window.draw(_exitButton);
		this->_data->window.draw(_playText);
		this->_data->window.draw(_exitText);
		this->_data->window.draw(_optionsText);
		

		this->_data->window.display();
	}


	void MainMenuState::initButtons() {

		this->_data->asset.LoadTextures("button", "b_1.png");
		this->_playButton.setTexture(this->_data->asset.GetTexture("button"));
		this->_optionsButton.setTexture(this->_data->asset.GetTexture("button"));
		this->_exitButton.setTexture(this->_data->asset.GetTexture("button"));


		this->_playButton.setScale(_scaleVector);
		//this->_playButton.setOrigin(, this->_playButton.getGlobalBounds().height / 2);
		this->_playButton.setPosition((SCREEN_WIDTH / 2) - this->_playButton.getGlobalBounds().width / 2, 0.4 * SCREEN_HEIGHT);



		this->_optionsButton.setScale(_scaleVector);
		//this->_optionsButton.setOrigin(this->_optionsButton.getGlobalBounds().width / 2, this->_optionsButton.getGlobalBounds().height / 2);
		this->_optionsButton.setPosition(SCREEN_WIDTH / 2 - this->_optionsButton.getGlobalBounds().width / 2, 0.6 * SCREEN_HEIGHT);

		this->_exitButton.setScale(_scaleVector);
		//this->_exitButton.setOrigin(this->_exitButton.getGlobalBounds().width / 2, this->_exitButton.getGlobalBounds().height / 2);
		this->_exitButton.setPosition(SCREEN_WIDTH / 2 - this->_exitButton.getGlobalBounds().width / 2, 0.8 * SCREEN_HEIGHT);
		
		
		tex.loadFromFile(MENU_BCK);
		this->_background.setTexture(tex);
		this->_background.setOrigin(this->_background.getGlobalBounds().width / 2, (this->_background.getGlobalBounds().height / 2));
		this->_background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
			
	}

	void MainMenuState::initFonts() {

		if (!menuFont.loadFromFile("arial.ttf"))
		{

		}

		_playText.setFont(menuFont);
		_playText.setFillColor(sf::Color::White);
		_playText.setString("PLAY");
		_playText.setCharacterSize(70);
		//_playText.setOrigin(_playText.getGlobalBounds().width / 2, _playText.getGlobalBounds().height / 2);
		_playText.setPosition(_playButton.getPosition().x + _playButton.getGlobalBounds().width / 2 - _playText.getGlobalBounds().width / 2, _playButton.getPosition().y + _playButton.getGlobalBounds().height / 2 - _playText.getGlobalBounds().height);


		_optionsText.setFont(menuFont);
		_optionsText.setFillColor(sf::Color::White);
		_optionsText.setString("OPTIONS");
		_optionsText.setCharacterSize(70);
		//_optionsText.setOrigin(_optionsText.getGlobalBounds().width / 2, _optionsText.getGlobalBounds().height / 2);
		_optionsText.setPosition(_optionsButton.getPosition().x + _optionsButton.getGlobalBounds().width / 2 - _optionsText.getGlobalBounds().width / 2, _optionsButton.getPosition().y + _optionsButton.getGlobalBounds().height / 2 - _optionsText.getGlobalBounds().height);



		_exitText.setFont(menuFont);
		_exitText.setFillColor(sf::Color::White);
		_exitText.setString("EXIT");
		_exitText.setCharacterSize(70);
		//_exitText.setOrigin(_exitText.getGlobalBounds().width / 2, _exitText.getGlobalBounds().height / 2);
		_exitText.setPosition(_exitButton.getPosition().x + _exitButton.getGlobalBounds().width / 2 - _exitText.getGlobalBounds().width / 2, _exitButton.getPosition().y + _exitButton.getGlobalBounds().height / 2 - _exitText.getGlobalBounds().height);

	}

	void MainMenuState::handleClickingButtons() {

		if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
		{
			sound.stop();

			this->_data->machine.AddState(StateRef(new GameState(this->_data)));

		}


		if (this->_data->input.isSpriteClicked(this->_optionsButton, sf::Mouse::Left, this->_data->window))
		{

			//this->_data->machine.AddState(StateRef(new GameState(_data)), true);

		}

		if (this->_data->input.isSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
		{

			this->_data->window.close();

		}

	}



	void MainMenuState::handleLightingButtons() {


		if (this->_data->input.isSpriteLighted(this->_playButton, this->_data->window))
		{

			_playText.setFillColor(sf::Color::White);

		}
		else
			_playText.setFillColor(sf::Color::Color(255, 153, 0));


		if (this->_data->input.isSpriteLighted(this->_optionsButton, this->_data->window))
		{

			_optionsText.setFillColor(sf::Color::White);

		}
		else
			_optionsText.setFillColor(sf::Color::Color(255, 153, 0));


		if (this->_data->input.isSpriteLighted(this->_exitButton, this->_data->window))
		{

			_exitText.setFillColor(sf::Color::White);

		}
		else
			_exitText.setFillColor(sf::Color::Color(255, 153, 0));


	}


	void MainMenuState::initMusic() {


		if (!buffer.loadFromFile("res/music/MainTheme.wav"))
		{
			std::cout << "cant load audio" << std::endl;
		}



		sound.setBuffer(buffer);
		sound.play();



	}


	


}

