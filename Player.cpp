#include "Player.h"
#include <iostream>
#include<time.h>
#include "DEFINITIONS.h"



namespace Engine {

	Player::Player()
	{
	
	
	}


	Player::~Player() {}


	void Player::initPlayer() {

		
		

		tex.loadFromFile(PLAYER_TEXTURE);
		pWalk.loadFromFile(P_WALK);
		pStand.loadFromFile(P_STAND);

		
		aStand.initAnimation(&pStand, sf::Vector2u(3, 1), 50.f);
		aWalk.initAnimation(&pWalk, sf::Vector2u(4, 1), 40.f);

	
	
		body.setSize(sf::Vector2f(75,80));

		this->speed = 7 ; // jak cos to 7 

		this->speed = speed;
		this->jumpHeight = 40; // jak cos to 40
		row = 0;
		
		GroundHeight = 3780;
	}



	void Player::Update(float dt)
	{

		velocity.x = 0.0f;





		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			velocity.x -= speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity.x += speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
		{
			canJump = false;
			velocity.y = -sqrt(3.0f * jumpHeight);

		}
		
		velocity.y += 0.2f * dt;



		if (velocity.y > 1)
			canJump = false;


		
		if (velocity.x != 0.0f)
		{

			this->body.setTexture(&pWalk);
			aWalk.Update(0, dt, faceRight);
			body.setTextureRect(aWalk.uvRect);
			
		}
		else

		this->body.setTexture(&pStand);
		aStand.Update(0, dt, faceRight);
		body.setTextureRect(aStand.uvRect);
		
	


			if (velocity.x > 0.0f)

				faceRight = true;
			else
				faceRight = false;

		
		

		
		body.move(velocity * dt);

	}



	void Player::Draw(sf::RenderWindow& window)
	{
		
		window.draw(this->body);

	}



	sf::Vector2f Player::getPosition()
	{
		return sf::Vector2f(this->body.getPosition());
	}



	sf::FloatRect Player::getGlobalBounds()
	{
		return sf::FloatRect();
	}


	void Player::setPosition(sf::Vector2f pos) {

		this->body.setPosition(pos);


	}


	void Player::initAnimation() {

		this->animRect.height = tex.getSize().y / 15;
		this->animRect.width = tex.getSize().x / 15;
		this->animRect.left = 0;
		this->animRect.top = 0;


	}



	void Player::animatePlayer()
	{
	


		this->body.setTextureRect(animRect);


	
	}

	void Player::OnCollision(sf::Vector2f direction)
	{
		if (direction.x < 0.0f)

			velocity.x = 0.0f;

		else if (direction.x > 0.0f)
			velocity.x = 0.0f;

		if (direction.y < 0.0f)
		{
			velocity.y = 0.0f;
			canJump = true;
		}
		else if (direction.y > 0.0f)
		{
			velocity.y = 0.0f;

		}
	}

	
	




}

