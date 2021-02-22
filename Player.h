#pragma once
#include <SFML/Graphics.hpp>
#include "Asset.h"
#include "DEFINITIONS.h"
#include "Collider.h"
#include "Animation.h"


namespace Engine {

	class Player
	
	{
	public:

		Player();
		~Player();

		void Update(float dt);
		void Draw(sf::RenderWindow& window);
		void initPlayer();
		void animatePlayer();

		void move(sf::Vector2f& movement);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f speed);
		void initAnimation();
		sf::FloatRect getGlobalBounds();
		Collider GetCollider() { return Collider(body); };
		void OnCollision(sf::Vector2f direction);

		Animation animation, aStand, aWalk;
		

	private:

		sf::Texture tex, pWalk, pStand;
		sf::RectangleShape body;
		sf::IntRect rect;
		sf::IntRect animRect;
		

		int row;
		float speed;
		
		float acc = 1.1f;
		int groundHeight;

		sf::Vector2f pMovement;

		time_t startJumpTime;

		
		

		bool faceRight;
		bool isJumping = false;
		float Acc = 1.1f;
		int GroundHeight;
		sf::Vector2f velocity;
		bool canJump;
		float jumpHeight;

		
	
	};


}
