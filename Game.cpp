#include  "Game.h"
#include "SplashScreenState.h"
#include "GameState.h"




namespace Engine {

	Game::Game(int width, int height, std::string tittle)
	{

		_data->window.create(sf::VideoMode(width, height), tittle, sf::Style::Close | sf::Style::Titlebar);

		_data->machine.AddState(StateRef(new SplashScreenState(this->_data)));
		//_data->machine.AddState(StateRef(new GameState(this->_data)));

		this->Run();

	}


	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();

		float accumulator = 0.0f;



		while (this->_data->window.isOpen())
		{


			this->_data->machine.ProcessStateChange();

			newTime = this->_clock.getElapsedTime().asSeconds();
		

			
			frameTime = newTime - currentTime;
			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}
			currentTime = newTime;
			accumulator += frameTime;


			while (accumulator >= dt)
			{

				this->_data->machine.getActiveState()->HandleInput();
				this->_data->machine.getActiveState()->Update(dt);

				accumulator -= dt;
			}
			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->Draw(interpolation);
			


			
		}



	}




}