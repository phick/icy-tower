#include "GameState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "DEFINITIONS.h"
#include<iostream>
#include "GameOverState.h"
#include "WinGameState.h"






namespace Engine {


	GameState::GameState(GameDataRef data) : _data(data)
	{


	}



	void GameState::Init() {
		this->_data->window.setFramerateLimit(300);

		initUIButtons();

		initViews();

		initPlatform();

		initMusic();



		if (!gameFont.loadFromFile("arial.ttf"))
		{

		}



		map1.loadTextures();
		map1.initMap();

		player.initPlayer();
		player.setPosition(sf::Vector2f(450,3000));


		viewSpeed = 0.3;



		o1.setProp(nullptr, sf::Vector2f(50, 400), sf::Vector2f(player.getPosition().x + 50, player.getPosition().y - 100));




	}


	void GameState::HandleInput() {

		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{



		
			handleUIInputs();


		}

	}

	void GameState::Update(float dt) {


		//std::cout << player.getPosition().y/30<< " . " << player.getPosition().y/25 << std::endl;

	}

	void GameState::Draw(float dt) {

		this->_data->window.clear(sf::Color::Black);
		this->_data->window.setView(this->view);


		


		map1.drawMap(this->_data->window);

		checkCollision();

			player.Update(dt);
		
		player.Draw(this->_data->window);

		// handle player view
		handlePlayerView(dt);
	


		this->_data->window.setView(viewUI);
		this->_data->window.draw(this->_pauseButton);
		this->_data->window.draw(this->pauseText);

		
		this->_data->window.display();
		
	}

	void GameState::initUIButtons() {


		this->_data->asset.LoadTextures("pauseButton", "b_8.png");

		this->_pauseButton.setTexture(this->_data->asset.GetTexture("pauseButton"));

		this->_pauseButton.setScale(sf::Vector2f(0.5, 0.5));
		this->_pauseButton.setPosition(SCREEN_WIDTH - _pauseButton.getGlobalBounds().width, 0);



		pauseText.setFont(gameFont);
		pauseText.setString("II");
		pauseText.setCharacterSize(130);
		pauseText.setFillColor(sf::Color::Red);
		pauseText.setOrigin(pauseText.getGlobalBounds().width/ 2, pauseText.getGlobalBounds().height / 2);
		pauseText.setPosition(_pauseButton.getPosition().x +65, _pauseButton.getPosition().y );

	 

	}
	void GameState::initViews() {


		this->view.setSize(SCREEN_WIDTH/1.5, SCREEN_HEIGHT/1.5);
		//this->view.setCenter(600,25*128);
		this->view.setCenter(900,3500);
		
		this->viewUI.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
		this->viewUI.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);


		this->viewMiniMap.setViewport(sf::FloatRect(0.7f, 0.f, 0.25f, 0.25f));
	}


	void GameState::handleUIInputs() {


		if (this->_data->input.isSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
		{

			sound.stop();
			this->_data->machine.AddState(StateRef(new PauseState(_data)));

		}

		if (this->_data->input.isSpriteLighted(this->_pauseButton, this->_data->window))
		{

			pauseText.setFillColor(sf::Color::White);

		}
		else
			pauseText.setFillColor(sf::Color::Color(255, 153, 0));


	}


	void GameState::handlePlayerView(float dt) {

		if (this->view.getCenter().y  > player.getPosition().y +200)
			this->view.setCenter(490, player.getPosition().y +200);
		else
			this->view.setCenter(490, this->view.getCenter().y);




	

		this->view.setCenter(this->view.getCenter().x,(viewPla = this->view.getCenter().y - viewSpeed * dt));
		this->viewSpeed *= 1.0004;

		if ((this->view.getCenter().y + SCREEN_HEIGHT/2 -150) < (player.getPosition().y ))
		{
			sound.stop();
			this->_data->machine.AddState(StateRef(new GameOverState(this->_data)));
		}

		if (player.getPosition().y <20)
		{

			std::cout << "WINN" << std::endl;
			sound.stop();
			this->_data->machine.AddState(StateRef(new WinGameState(this->_data)));
			
		}


	}

	void GameState::checkCollision() 
	{


		Collider p1 = player.GetCollider();


			for (int i = (int)player.getPosition().y/26 ; i < (int)(player.getPosition().y/26 +5); i++)
			{
				for (int j = 0; j < 15; j++)
				{

					oT[i][j].setProp(nullptr, map1.getTileSize(i, j), sf::Vector2f(map1.getTilePosition(i, j).x, map1.getTilePosition(i, j).y -33));
					if (oT[i][j].GetCollider().CheckCollision(p1, direction, 1.0f))
						player.OnCollision(direction);
				}

			}
				

	}

	void GameState::initPlatform() {

		for (int i = 0; i < 124; i++){

			for (int j = 0; j < 15; j++) 
			{

				if (map1.getMapCollision(i, j) != 0) 
				{
					oT[i][j].setProp(nullptr,map1.getTileSize(i,j), map1.getTilePosition(i, j));
				}



		     }


		}
		



	}

	void GameState::initMusic() {

	
		if (!buffer.loadFromFile("res/music/MainTheme.wav"))
		{
			std::cout << "cant load audio" << std::endl;
		}

		

		sound.setBuffer(buffer);
		sound.setLoop(true);
		sound.play();



	}

	

}




