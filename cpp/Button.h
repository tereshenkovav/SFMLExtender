#ifndef SF_BUTTON_H
#define SF_BUTTON_H

#include <SFML\Graphics.hpp>

namespace sf {

class Button :
	public sf::Drawable
{
protected:
	virtual void draw (RenderTarget &target, RenderStates states) const ;
private:
	Text text ;
	RectangleShape shape ;
public:
	Button() ;
	bool isMouseOver(int x, int y) ;
	void setButton(String caption, Color colorback, Color colorborder, Color colorfont, const Font & font, int fontsize,
		int x, int y, int w, int h);
	~Button(void);
};

} 

#endif