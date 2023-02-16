#ifndef GAME_H
#define GAME_H

#include <Windows.h>
#include <vector>

#include <SFML\Graphics.hpp>

class Game
{
private:
	char fullfile[MAX_PATH] ;
	char path[MAX_PATH] ;
	unsigned int fps ;	
protected:
	char * getFileName(const char * filename) ;
	unsigned int getFPS() ;
	void drawLabel(sf::RenderTarget & target, const char * str, int x, int y, sf::Font font, int size) ;
	void drawLabel(sf::RenderTarget & target, const char * fmt, int x, int y, sf::Font font, int size, int args) ;
public:
	Game(void);
	static sf::String makeString(const char * str) ;
	void loadFileTo(sf::Sprite & sprite, char * filename) ;
	void setFPS(unsigned int Afps) ;	
	virtual bool Init() = 0 ;
	virtual bool Frame(float dt, std::vector<sf::Event> events, int mx, int my) = 0 ;
	virtual bool Render(sf::RenderTarget & target) = 0 ;
	virtual bool UnInit() = 0 ;
	~Game(void);
};

#endif
