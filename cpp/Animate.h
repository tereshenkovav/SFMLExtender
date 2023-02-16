#ifndef SF_ANIMATE_H
#define SF_ANIMATE_H

#include <SFML\Graphics.hpp>

namespace sf {
class Animate :	public Sprite
{
private:
	Texture * frames ;
	int count ;
	float fps ;
	float tekt ;
public:
	Animate();
	void loadFromFile(const char * filename, int Ax, int Ay, int Aw, int Ah, int Acount, float Afps) ;
	void update(float dt) ;
	~Animate();
};
} 

#endif