#include "Asset.h"

namespace Engine {


	void Asset::LoadTextures(std::string name, std::string filename) {

		sf::Texture tex;
		if ( tex.loadFromFile(filename) )
		{
			this->_textures[name] = tex;
		}



	}

	sf::Texture &Asset::GetTexture(std::string name) {

		return this->_textures.at(name);
	}


	void Asset::LoadFont(std::string name, std::string filename) {

		sf::Font font;
		if (font.loadFromFile(filename))
		{
			this->_fonts[name] = font;

		}



	}

	sf::Font &Asset::GetFont(std::string name) {

		return this->_fonts.at(name);
	}

























}