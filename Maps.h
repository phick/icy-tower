#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace Engine {


	class Maps
	{
	public:
		Maps();
		void loadTextures();
		void initMap();
		void initMapCollision(int map[124][15]);

		int getMapCollision(int i, int j);
		
		void drawMap(sf::RenderWindow& window);
		
		sf::Vector2f getTilePosition(int i, int j);
		sf::Vector2f getTileSize(int i, int j);

		void initBackgroundTiles();

	private:

		

	


		//int mapLegend[10][10];
		sf::Sprite backgroundTiles[8];
		sf::Sprite mapTiles[124][15];

		sf::Texture mapBck, mapBck2,mapBrick;
		sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;

		sf::IntRect rectBrick, rectIce, rectGold,rectRed;

		int mapCollision[124][15];

	};

}

