#include "Animate.h"

namespace sf {

Animate::Animate() : Sprite()
{
}

void Animate::loadFromFile(const char * filename, int x, int y, int w, int h, int Acount, float Afps) 
{
	count = Acount ;
	fps = Afps ;
	tekt = 0 ;
	
	Image img ;
	img.loadFromFile(filename) ;
	int imgw = img.getSize().x ;
	int imgh = img.getSize().y ;

	int cnt_per_width = imgw/w ;
	
	frames = new Texture[count] ;	
	int p = 0 ;
	for (int j=0; ; j++) 
		for (int i=0; i<cnt_per_width; i++) {
			frames[p].loadFromImage(img,IntRect(x+i*w,y+j*h,w,h)) ;	
			p++ ;
			if (p==count) goto fin ;
		}
fin:
	update(0) ;
}

void Animate::update(float dt) 
{
	float sec_per_frame = 1.0f/fps ;
	
	tekt+=dt ;
	int tekframe = (int)(tekt/sec_per_frame) ;
	if (tekframe>=count) {
		tekframe = 0 ;
		tekt-=count*sec_per_frame ;
	}
	setTexture(frames[tekframe]) ;
}

Animate::~Animate()
{
}

}