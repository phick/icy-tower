#pragma once
#include<memory>
#include<string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "Asset.h"
#include "Input.h"
#include "Maps.h"

namespace Engine {

	struct GameData {
		
		StateMachine machine;
		sf::RenderWindow window;
		Asset asset;
		Input input;
		//Maps map1;
	};

	typedef std::shared_ptr<GameData> GameDataRef;


	class Game {

	public:
		Game(int width, int height, std::string tittle);




	private:
		const float dt = 1.0f / 60.0f;

		sf::Clock _clock;
		
		GameDataRef _data = std::make_shared<GameData>();

		void Run();

	};




}