#include "Game.h"

char * ExtractFilePath(char * FileName, char * buf)
{  
    int i, len = strlen(FileName);
    for(i=len-1; i>=0; i--)
    {
        if(FileName[i] == '\\')
            break;
    }
    strncpy(buf, FileName, i);
	buf[i]=0 ;
    return buf;
}

Game::Game(void)
{
	char exename[MAX_PATH] ;
	GetModuleFileNameA(0, exename, MAX_PATH);
	ExtractFilePath(exename,path) ;	
	fps = 0 ;
}

char * Game::getFileName(const char * filename) 
{
	strcpy(fullfile,path) ;
	strcat(fullfile,"\\") ;
	strcat(fullfile,filename) ;	
	return fullfile ;
}

sf::String Game::makeString(const char * str) 
{
	return sf::String(str,std::locale("Russian_Russia.1251")) ;
}

void Game::loadFileTo(sf::Sprite & sprite, char * filename) 
{
	sf::Texture * tex = new sf::Texture() ;
	tex->loadFromFile(getFileName(filename)) ;
	sprite.setTexture(*tex) ;
}

unsigned int Game::getFPS() 
{
	return fps ;
}

void Game::setFPS(unsigned int Afps)
{
	fps = Afps ;
}

void Game::drawLabel(sf::RenderTarget & target, const char * str, int x, int y, sf::Font font, int size) 
{
	sf::Text text(makeString(str),font,size) ;
	text.setPosition(x,y) ;
	target.draw(text) ;
}

void Game::drawLabel(sf::RenderTarget & target, const char * fmt, int x, int y, sf::Font font, int size, int args) 
{
	char buf[255] ;
	sprintf(buf,fmt,args) ;
	sf::Text text(makeString(buf),font,size) ;
	text.setPosition(x,y) ;
	target.draw(text) ;
}

void Game::drawLabelW(sf::RenderTarget& target, const std::wstring& wstr, int x, int y, const sf::Font& font, int size,
	sf::Color color)
{
	sf::Text text(wstr, font, size);
	text.setPosition(x, y);
	text.setFillColor(color);
	target.draw(text);
}

Game::~Game(void)
{
}
