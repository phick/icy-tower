#include "SplashScreenState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"



namespace Engine {

	SplashScreenState::SplashScreenState(GameDataRef data) : _data(data)
	{
		

	}

	void SplashScreenState::Init() {

	
		
		tex.loadFromFile(SPLASH_BCK);
		bck.setTexture(tex);
		bck.setOrigin(bck.getGlobalBounds().width / 2, bck.getGlobalBounds().height / 2);
		bck.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);



	}


	void SplashScreenState::HandleInput()
	{


	}

	void SplashScreenState::Update(float dt) {

		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

		}


	}

	void SplashScreenState::Draw(float dt) {


		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(bck);
		this->_data->window.display();
	}




}
